/**********************************************************************
*
*    Filename        : spi_via_gpio.h
*    Author          : hwyi,
*    Version         : 1.0
*    Description     : 
*
*   ==================================================================
*   DATE                AUTHOR             NOTE
*   ------------------------------------------------------------------
*   2022.06.07          hwyi
*
***********************************************************************/

#ifndef __SPI_VIA_GPIO_H__
#define __SPI_VIA_GPIO_H__
#define HIGH        (1)
#define LOW         (0)

#define NOP_40      asm(" RPT #40 || NOP")
#define NOP_30      asm(" RPT #30 || NOP")
#define NOP_20      asm(" RPT #20 || NOP")
#define NOP_10      asm(" RPT #10 || NOP")
#define NOP_5       asm(" RPT #5 || NOP")
#define NOP_2       asm(" RPT #2 || NOP")
#define NOP_1       asm(" RPT #1 || NOP")


void svg_init();
void svg_write(unsigned char);
unsigned char svg_read();
void svg_set_cs0(unsigned char);
#endif //__SPI_VIA_GPIO_H__
