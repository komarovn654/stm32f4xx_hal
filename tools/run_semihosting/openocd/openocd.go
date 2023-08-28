package openocd

import (
	"io"
	"os"
	"os/exec"
)

const (
	cmdOpenocd = "openocd"
)

type Openocd struct {
	cfg   string
	flags string

	Parser *OpenocdParser

	proc   *os.Process
	stdin  io.Reader
	stdout io.Writer
	stderr io.Writer
}

type Option = func(*Openocd)

func SetParser(errFileName string, inFileName string) Option {
	return func(oocd *Openocd) {
		oocd.Parser = new(OpenocdParser)
		oocd.Parser.setFileName(errFileName, inFileName)
	}
}

func SetStdStreams(stdin io.Reader, stdout io.Writer, stderr io.Writer) Option {
	return func(oocd *Openocd) {
		oocd.stdin = stdin
		oocd.stdout = stdout
		oocd.stderr = stderr
	}
}

func SetConfig(cfg string) Option {
	return func(oocd *Openocd) {
		oocd.cfg = cfg
	}
}

func SetFlags(flags string) Option {
	return func(oocd *Openocd) {
		oocd.flags = flags
	}
}

func InitOpenocd(opt ...Option) *Openocd {
	oocd := new(Openocd)

	oocd.stdin = os.Stdin
	oocd.stdout = os.Stdout
	oocd.stderr = os.Stderr

	for _, o := range opt {
		o(oocd)
	}

	return oocd
}

func (oocd *Openocd) setupCmd(cmd []string) *exec.Cmd {
	command, args := cmd[0], cmd[1:]

	c := exec.Command(command, args...)
	c.Stdin = oocd.stdin
	c.Stdout = oocd.stdout
	c.Stderr = oocd.stderr
	return c
}

func (oocd *Openocd) setProcess(c *exec.Cmd) {
	oocd.proc = c.Process
}

func (oocd *Openocd) KillProcess() error {
	return oocd.proc.Kill()
}

func (oocd *Openocd) Run() error {
	c := oocd.setupCmd([]string{cmdOpenocd, oocd.flags, oocd.cfg})
	if err := oocd.Parser.setup(); err != nil {
		return err
	}

	pCh := make(chan int)
	go oocd.Parser.run(pCh)
	go oocd.Parser.runIn()

	if err := c.Start(); err != nil {
		return err
	}
	oocd.setProcess(c)

	<-pCh
	return nil

}
