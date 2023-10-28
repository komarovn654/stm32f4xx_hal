package main

import (
	"fmt"
	"log"
	"os"
	"time"

	"github.com/komarovn654/stm32f4xx_hal/tools/run_semihosting/gdb"
	"github.com/komarovn654/stm32f4xx_hal/tools/run_semihosting/openocd"
)

const (
	oocdStderrFile = "oocd_stderr"
	oocdStdinFile  = "oocd_stdin"
)

func main() {
	ferr, err := os.Create(oocdStderrFile)
	if err != nil {
		log.Fatal(err)
	}

	fin, err := os.Create(oocdStdinFile)
	if err != nil {
		log.Fatal(err)
	}
	_ = fin

	oocd := openocd.InitOpenocd(
		openocd.SetConfig("board/stm32f4discovery.cfg"),
		openocd.SetFlags("-f"),
		openocd.SetStdStreams(os.Stdin, nil, ferr),
		openocd.SetParser(oocdStderrFile, oocdStdinFile),
	)

	if err := oocd.Run(); err != nil {
		log.Fatal(err)
	}
	defer oocd.KillProcess()
	fmt.Println("rdy")

	gdb.Run()

	t := time.Now()

	for true {
		if time.Since(t) > time.Second*60 {
			break
		}
	}
}
