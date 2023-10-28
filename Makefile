load_rcc:
	openocd -f board/stm32f4discovery.cfg -c "program lib/rcc/out/bin/rcc_ut_target_sh.elf verify exit reset"

load_system:
	openocd -f board/stm32f4discovery.cfg -c "program lib/system/out/bin/sys_ut_target_sh.elf verify exit reset"	
