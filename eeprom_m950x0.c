/**********************************************************************
*
*    Filename        : eeprom_m950x0.c
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

#define CMD_WREN    (0b00000110)
#define CMD_WRDI    (0b00000100)
#define CMD_RDSR    (0b00000101)
#define CMD_WRSR    (0b00000001)
#define CMD_READ    (0b00000011)
#define CMD_WRTE    (0b00000010)

unsigned char m950x0_read_status()
{
    unsigned char data = 0xFF;

    svg_set_cs0(LOW);
    svg_write(CMD_RDSR);
    data = svg_read();
    svg_set_cs0(HIGH);

    return data;
}

void m950x0_write_enable()
{
    svg_set_cs0(LOW);
//    NOP_20;
    svg_write(CMD_WREN);
//    NOP_20;
    svg_set_cs0(HIGH);
}

void m950x0_write_disable()
{
    svg_set_cs0(LOW);
//    NOP_20;
    svg_write(CMD_WRDI);
//    NOP_20;
    svg_set_cs0(HIGH);
}

int m950x0_write(const unsigned char addr, const unsigned char data)
{
    m950x0_write_enable();
    svg_set_cs0(LOW);
    svg_write(CMD_WRTE);
    svg_write(addr);
    svg_write(data);
    while((m950x0_read_status() & 0x01) == 0x01)
    {
    }
    svg_set_cs0(HIGH);
    m950x0_write_disable();
    return 1;
}

unsigned char m950x0_read(const unsigned char addr)
{
    unsigned char data = 0xFF;

    svg_set_cs0(LOW);
    svg_write(CMD_READ);
    svg_write(addr);
    data = svg_read();
    svg_set_cs0(HIGH);

    return data;
}
