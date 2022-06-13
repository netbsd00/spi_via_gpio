/**********************************************************************
*
*    Filename        : eeprom_m950x0.h
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

#ifndef __EEPROM_M950X0_H__
#define __EEPROM_M950X0_H__

int m950x0_write(const unsigned char, const unsigned char);
unsigned char m950x0_read(const unsigned char);
unsigned char m950x0_read_status();
void m950x0_write_enable();
void m950x0_write_disable();

#endif //__EEPROM_M950X0_H__
