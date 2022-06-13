/**********************************************************************
*
*    Filename        : spi_via_gpio.c
*    Author          : hwyi,
*    Version         : 1.0
*    Description     : 
*
*   ==================================================================
*   DATE                AUTHOR             NOTE
*   ------------------------------------------------------------------
*   2022.06.07          hwyi               理쒖큹 �깮�꽦
*
***********************************************************************/

#include "DSP28x_Project.h"
#include "spi_via_gpio.h"

#define CS0         (GpioDataRegs.GPADAT.bit.GPIO19)
#define CLK         (GpioDataRegs.GPADAT.bit.GPIO0)
#define MISO        (GpioDataRegs.GPADAT.bit.GPIO18)
#define MOSI        (GpioDataRegs.GPADAT.bit.GPIO1)
#define CLK_HIGH    {asm(" RPT #3 || NOP"); CLK = HIGH;}
#define CLK_LOW     {asm(" RPT #3 || NOP"); CLK = LOW;}
#define CLK_TICK    {asm(" RPT #3 || NOP"); CLK = HIGH; asm(" RPT #3 || NOP"); CLK = LOW;}

void svg_init()
{
    CS0 = HIGH;
    CLK = LOW;
    MOSI = LOW;
}

void svg_write(const unsigned char c)  // 1.2MHz
{
    MOSI = (c >> 7) & 0x01;
    CLK_TICK;

    MOSI = (c >> 6) & 0x01;
    CLK_TICK;

    MOSI = (c >> 5) & 0x01;
    CLK_TICK;

    MOSI = (c >> 4) & 0x01;
    CLK_TICK;

    MOSI = (c >> 3) & 0x01;
    CLK_TICK;

    MOSI = (c >> 2) & 0x01;
    CLK_TICK;

    MOSI = (c >> 1) & 0x01;
    CLK_TICK;

    MOSI = (c) & 0x01;
    CLK_TICK;
#if 0
    register unsigned char msk = 0x80;

    while(msk >= 0x01)
    {
        if((c & msk) == 0x00)       {MOSI = LOW;}
        else                        {MOSI = HIGH;}
        asm(" RPT #2 || NOP");
        msk = msk >> 1;
        CLK = HIGH;
        asm(" RPT #43 || NOP");
        CLK = LOW;
    }
#endif
}

unsigned char svg_read()
{
    register char i;
    register unsigned char read_byte = 0;

    CLK_HIGH;
    read_byte = read_byte | (MISO << 7);
    CLK_LOW;

    CLK_HIGH;
    read_byte = read_byte | (MISO << 6);
    CLK_LOW;

    CLK_HIGH;
    read_byte = read_byte | (MISO << 5);
    CLK_LOW;

    CLK_HIGH;
    read_byte = read_byte | (MISO << 4);
    CLK_LOW;

    CLK_HIGH;
    read_byte = read_byte | (MISO << 3);
    CLK_LOW;

    CLK_HIGH;
    read_byte = read_byte | (MISO << 2);
    CLK_LOW;

    CLK_HIGH;
    read_byte = read_byte | (MISO << 1);
    CLK_LOW;

    CLK_HIGH;
    read_byte = read_byte | (MISO);
    CLK_LOW;

#if 0
for(i=7; i>=0; i--)
{
    CLK = HIGH;
    asm(" RPT #32 || NOP");
    read_byte = read_byte | (MISO << i);
    CLK = LOW;
    asm(" RPT #20 || NOP");
}
#endif
    return read_byte;
}

void svg_set_cs0(unsigned char bin)
{
    CS0 = (bin == LOW)? LOW : HIGH;
    CLK_LOW;
}
