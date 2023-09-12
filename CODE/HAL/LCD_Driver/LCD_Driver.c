/*
 * LCD_Driver.c
 *
 *  Created on: Aug 18, 2023
 *      Author: hany nagy
 */

#include "LCD_Driver.h"


#if (LCD_MODE == 8)
void LCD_WriteCommand(uint8_t command)
{
    DIO_WritePin(RS, LOW);
    DIO_WritePin(RW, LOW);
//    DIO_WritePort(LCD_PORT, command);

    DIO_WritePin(D7, READ_BIT(command,7));
    DIO_WritePin(D6, READ_BIT(command,6));
    DIO_WritePin(D5, READ_BIT(command,5));
    DIO_WritePin(D4, READ_BIT(command,4));
    DIO_WritePin(D3, READ_BIT(command,3));
    DIO_WritePin(D2, READ_BIT(command,2));
    DIO_WritePin(D1, READ_BIT(command,1));
    DIO_WritePin(D0, READ_BIT(command,0));

    DIO_WritePin(EN, HIGH);
    _delay_ms(2);
    DIO_WritePin(EN, LOW);
    _delay_ms(2);

}

void LCD_WriteData(uint8_t data)
{
    DIO_WritePin(RS,HIGH);
    DIO_WritePin(RW,LOW);
//    DIO_WritePort(LCD_PORT,data);

    DIO_WritePin(D7, READ_BIT(data,7));
    DIO_WritePin(D6, READ_BIT(data,6));
    DIO_WritePin(D5, READ_BIT(data,5));
    DIO_WritePin(D4, READ_BIT(data,4));
    DIO_WritePin(D3, READ_BIT(data,3));
    DIO_WritePin(D2, READ_BIT(data,2));
    DIO_WritePin(D1, READ_BIT(data,1));
    DIO_WritePin(D0, READ_BIT(data,0));

    DIO_WritePin(EN, HIGH);
    _delay_ms(2);
    DIO_WritePin(EN, LOW);
    _delay_ms(2);
}
void LCD_Init(void)
{
    DIO_InitPin(RS, OUTPUT);
    DIO_InitPin(RW, OUTPUT);
    DIO_InitPin(EN, OUTPUT);
    DIO_InitPin(D7, OUTPUT);
    DIO_InitPin(D6, OUTPUT);
    DIO_InitPin(D5, OUTPUT);
    DIO_InitPin(D4, OUTPUT);
    DIO_InitPin(D3, OUTPUT);
    DIO_InitPin(D2, OUTPUT);
    DIO_InitPin(D1, OUTPUT);
    DIO_InitPin(D0, OUTPUT);

    _delay_ms(10);
    LCD_WriteCommand(0x38); //select 8 bit mode,font 5*7,select 2 lines
    _delay_ms(1);
    LCD_WriteCommand(0x0c); //cursor  0x0c,0x0e,0x0f
    _delay_ms(1);
    LCD_WriteCommand(0x01); //clear lcd
    _delay_ms(2);
    LCD_WriteCommand(0x06); //DDRAM address increase
    _delay_ms(1);

}
#elif (LCD_MODE == 4)
void LCD_WriteCommand(uint8_t command)
{

    DIO_WritePin(RS, LOW);
    DIO_WritePin(RW, LOW);
    DIO_WritePin(D7, READ_BIT(command,7));
    DIO_WritePin(D6, READ_BIT(command,6));
    DIO_WritePin(D5, READ_BIT(command,5));
    DIO_WritePin(D4, READ_BIT(command,4));
    DIO_WritePin(EN, HIGH);
    _delay_ms(1);
    DIO_WritePin(EN, LOW);
    _delay_ms(1);
    DIO_WritePin(D7, READ_BIT(command,3));
    DIO_WritePin(D6, READ_BIT(command,2));
    DIO_WritePin(D5, READ_BIT(command,1));
    DIO_WritePin(D4, READ_BIT(command,0));
    DIO_WritePin(EN, HIGH);
    _delay_ms(1);
    DIO_WritePin(EN, LOW);
    _delay_ms(1);
}

void LCD_WriteData(uint8_t data)
{
    DIO_WritePin(RS, HIGH);
    DIO_WritePin(RW, LOW);
    DIO_WritePin(D7, READ_BIT(data,7));
    DIO_WritePin(D6, READ_BIT(data,6));
    DIO_WritePin(D5, READ_BIT(data,5));
    DIO_WritePin(D4, READ_BIT(data,4));
    DIO_WritePin(EN, HIGH);
    _delay_ms(1);
    DIO_WritePin(EN, LOW);
    _delay_ms(1);
    DIO_WritePin(D7, READ_BIT(data,3));
    DIO_WritePin(D6, READ_BIT(data,2));
    DIO_WritePin(D5, READ_BIT(data,1));
    DIO_WritePin(D4, READ_BIT(data,0));
    DIO_WritePin(EN, HIGH);
    _delay_ms(1);
    DIO_WritePin(EN, LOW);
    _delay_ms(1);
}
void LCD_Init(void)
{
    DIO_InitPin(RS, OUTPUT);
    DIO_InitPin(RW, OUTPUT);
    DIO_InitPin(EN, OUTPUT);
    DIO_InitPin(D7, OUTPUT);
    DIO_InitPin(D6, OUTPUT);
    DIO_InitPin(D5, OUTPUT);
    DIO_InitPin(D4, OUTPUT);

    _delay_ms(50);
    LCD_WriteCommand(0x02);
    _delay_ms(1);
    LCD_WriteCommand(0x28);     //select 4bit mode,font 5*7,select 2 lines
    _delay_ms(1);
    LCD_WriteCommand(0x0c);     //cursor  0x0c,0x0e,0x0f
    _delay_ms(1);
    LCD_WriteCommand(0x01);     //clear lcd
    _delay_ms(2);
    LCD_WriteCommand(0x06);     //DDRAM address increase
    //_delay_ms(1);
    //LCD_WriteCommand(0x80);
}
#endif


/******************************************** FUNCTONS ********************************************/


void LCD_WriteChar(uint8_t ch)
{
    LCD_WriteData(ch);
}


void LCD_WriteString(uint8_t *str)
{
    uint8_t i;
    for(i=0;str[i];i++)
    {
        LCD_WriteData(str[i]);
    }

}

void LCD_WriteNumber(int32_t num)
{
    uint8_t i=0,j,arr[16]={0};
        if (num==0)
        {
            LCD_WriteData('0');
        }
        else
        {
            if (num<0)
            {
                LCD_WriteData('-');
                num=num*(-1);
            }

            while(num>0)
            {
                arr[i]=(num%10)+'0';
                i++;
                num=num/10;
            }
            for (j=i;j>0;j--)
            {
                LCD_WriteData(arr[j-1]);
            }
        }

}

void LCD_WriteNumberInBinary(uint8_t num)
{
    int i, flag=0;
    for(i=7; i>=0 ;i--)
    {
        if (((num>>i)&1)==1)
        {
            flag=1;
        }
        if (flag==1)
        {
                LCD_WriteData(((num>>i)&1)+'0');
        }

    }
}

void LCD_Clear(void)
{
    LCD_WriteCommand(0X01);
}

void LCD_SetCursor(uint8_t Line, uint8_t x)
{
    if (Line==0)
    {
        LCD_WriteCommand(0x80+x);
    }
    else if (Line==1)
    {
        LCD_WriteCommand(0x80+0x40+x);
    }

}


void LCD_WriteNumber_4D(uint16_t num)
{
        LCD_WriteData(((num%10000)/1000)+'0');
        LCD_WriteData(((num%1000)/100)+'0');
        LCD_WriteData(((num%100)/10)+'0');
        LCD_WriteData(((num%10)/1)+'0');
}

void LCD_WriteNumber_3D(uint16_t num)
{
        LCD_WriteData(((num%1000)/100)+'0');
        LCD_WriteData(((num%100)/10)+'0');
        LCD_WriteData(((num%10)/1)+'0');
}


void LCD_WriteNumber_2D(uint16_t num)
{
        LCD_WriteData(((num%100)/10)+'0');
        LCD_WriteData(((num%10)/1)+'0');
}
