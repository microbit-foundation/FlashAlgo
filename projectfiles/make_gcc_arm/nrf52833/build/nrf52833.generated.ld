SECTIONS
{
    PrgCode 0 : ALIGN_WITH_INPUT
    {
        *(.text*)
        EXCLUDE_FILE (*FlashDev.o) *(.rodata*)
        . = ALIGN(16);
    }
    PrgData : ALIGN_WITH_INPUT
    {
        *(.data*)
        *(.bss*)
        *(.got*)
        *(COMMON)
        . = ALIGN(16);
    }
    DevDscr :
    {
        *FlashDev.o(*)
    }
    /DISCARD/ : {
        *(.ARM.exidx);
        *(.ARM.exidx.*);
        *(.ARM.extab.*);
    }
}
