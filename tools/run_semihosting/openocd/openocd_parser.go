package openocd

import (
	"fmt"

	"github.com/hpcloud/tail"
)

type OpenocdParser struct {
	errFileName string
	inFileName  string

	errTail *tail.Tail
	inTail  *tail.Tail
}

func (parser *OpenocdParser) setFileName(errFileName string, inFileName string) {
	parser.errFileName = errFileName
	parser.inFileName = inFileName
}

func (parser *OpenocdParser) setup() error {
	t, err := tail.TailFile(parser.errFileName, tail.Config{Follow: true})
	if err != nil {
		return err
	}
	parser.errTail = t

	t, err = tail.TailFile(parser.inFileName, tail.Config{Follow: true})
	if err != nil {
		return err
	}
	parser.inTail = t

	return nil
}

func (parser *OpenocdParser) run(rdy chan<- int) {
	for line := range parser.errTail.Lines {
		switch line.Text {
		case "Info : Listening on port 3333 for gdb connections":
			rdy <- 1
		}
	}
}

func (parser *OpenocdParser) runIn() {
	for line := range parser.inTail.Lines {
		fmt.Println(line.Text)
	}
}
