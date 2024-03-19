// @File		MAIN.C		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		17/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#include "utils.h"
#include "ks0066.h"
#include "wire.h"
#include "ad5282.h"

void main(void)
{
    __delay_ms(500);   
    
    Pic18f2520_init();
    
    Wire_Init();            
    
    KS0066_Init();
    KS0066_Clear(0);
    KS0066_Clear(1);  
    KS0066_Goto(0,0);                       
    
    AD5282_write(AD5242_CHANNEL_A, 35);
    AD5282_write(AD5242_CHANNEL_B, 255);
    
    unsigned int r = AD5282_Read();
        
    KS0066_Char(48 + r / 1000 % 10);
    KS0066_Char(48 + r / 100 % 10);
    KS0066_Char(48 + r / 10 % 10);
    KS0066_Char(48 + r / 1 % 10);
    
    while(1)
    {
        
    }
    
    return;
}
