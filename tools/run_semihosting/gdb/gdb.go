package gdb

import (
	"os/exec"
)

func setupCmdGdb(cmd []string) *exec.Cmd {
	command, args := cmd[0], cmd[1:]

	c := exec.Command(command, args...)
	return c
}

func Run() {
	c := setupCmdGdb([]string{"arm-none-eabi-gdb", "--command=stdin.log"})
	// c.Stderr = os.Stderr
	// c.Stdin = os.Stdin
	// c.Stdout = os.Stdout
	c.Run()
}
