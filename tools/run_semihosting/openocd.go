package main

import (
	"os"
	"os/exec"
)

func setupCmdOpenocd(cmd []string) *exec.Cmd {
	command, args := cmd[0], cmd[1:]

	c := exec.Command(command, args...)
	c.Stdin = os.Stdin
	c.Stdout = os.Stdout
	c.Stderr = os.Stderr
	return c
}

func RunOpenocd() {
	c := setupCmdOpenocd([]string{"openocd", "-f", "board/stm32f4discovery.cfg"})
	c.Run()
}
