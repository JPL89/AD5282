// @File		AD5282.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		19/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef AD5282_H
#define AD5282_H

// SLAVE ADDRESS: SEE DATASHEET
#define AD5282_SLA_W 0x58
#define AD5282_SLA_R 0x59

// INSTRUCTION BYTE; SEE DATASHEET
#define AD5282_CHANNEL_A 0x00
#define AD5282_CHANNEL_B 0x80
#define AD5282_RS 0x60
#define AD5282_SD 0x40
#define AD5282_O1 0x10
#define AD5282_O2 0x08

// Reading Data from a Previously 
// Selected RDAC Register in Write Mode
unsigned char AD5282_Read(void)
{
    unsigned char data = 0x00;
    
	Wire_Start();
	Wire_Write(AD5282_SLA_R);
    data = Wire_Nack();
	Wire_Stop();   
    
    return ((unsigned char) data);
}

// DATA = 0..255 (256 POSITIONS: SEE DATASHEET)
void AD5282_write(unsigned char instruction, unsigned char data)
{
	Wire_Start();
	Wire_Write(AD5282_SLA_W);
	Wire_Write(instruction);
	Wire_Write(data);
	Wire_Stop();
}

#endif
