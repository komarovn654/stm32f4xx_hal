package main

import (
	"os/exec"
)

func setupCmdGdb(cmd []string) *exec.Cmd {
	command, args := cmd[0], cmd[1:]

	c := exec.Command(command, args...)
	return c
}

func RunGdb() {
	c := setupCmdGdb([]string{"arm-none-eabi-gdb"})
	c.Run()
}
