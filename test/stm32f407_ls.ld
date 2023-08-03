ENTRY(ResetHandler)

MEMORY 
{
  rom (rx)  : org = 0x08000000, len = 1M
  ram (wx)  : org = 0x20000000, len = 196K
}

SECTIONS
{
    .text :
    {
        *(.vector_table)
        *(.text)
        *(.rodata)
        _etext = .;
    } > rom

    .data : 
    {
        _sdata = .;
        *(.text)
        _edata = .;
    } > ram AT > rom

    .bss : 
    {
        _sbss = .;
        *(.text)
        _ebss = .;
    } > ram
    _exit = .;
}
