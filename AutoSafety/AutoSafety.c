/*******************************************************
This program was created by the CodeWizardAVR V3.51 
Automatic Program Generator
© Copyright 1998-2023 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro

Project : 
Version : 
Date    : 5/18/2023
Author  : 
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>

int count;
char buff[10];
float jarak;
float jrk;
unsigned char sensor_jarak(){
count = 0;
PORTB.6 =1;
delay_us(15);
PORTB.6=0;
delay_ms(2);
while(PINB.7 ==0){}
while(PINB.7 ==1){
    count++;
}
jrk=count*0.0036;
return jrk;}

void main(void)
{
DDRB=0x00;
PORTB=0xC0;

DDRC=0xFF;
PORTC=0x03;

lcd_init(32);

while (1)
      {
      // Place your code here
                jarak = sensor_jarak();
               lcd_clear();
               lcd_gotoxy(0,0);
               lcd_putsf("SENSOR GEMPA");
               lcd_gotoxy(0,1);
               lcd_putsf("Kekuatan gempa: ");
               itoa (jarak, buff);
               lcd_gotoxy(16,1);
               lcd_puts (buff);
               lcd_gotoxy(18,1);
               lcd_putsf("Magnitudo");
               delay_ms(200);
               if (jarak <= 0){
               lcd_clear();
               PORTC.0 =1;
               PORTC.1 =0;
                   
               lcd_clear();
               lcd_gotoxy(0,0);
               lcd_putsf("Kondisi aman");
               lcd_gotoxy(0,1);
               lcd_putsf("Lanjutkan pekerjaan Anda : ");
               delay_ms(100);
               }       
               
               else if(jarak>0)
               {     
               lcd_clear();
               lcd_putsf("Gempa terjadi");
               lcd_gotoxy(0,1);
               lcd_putsf("Segera melarikan diri ke tempat aman : ");
               PORTC.0=0;
               PORTC.1=1;
               delay_ms(16);
               PORTC.1=0; 
               delay_ms(16);
               PORTC.1=1;
               delay_ms(16);
               PORTC.1=0; 
               delay_ms(16);
               PORTC.1=1;
               delay_ms(16);
               PORTC.1=0; 
               delay_ms(16); 
               PORTC.1=0; 
               delay_ms(16);
               PORTC.1=1;
               delay_ms(16);
               PORTC.1=0; 
               delay_ms(16);
               PORTC.2=1;
               lcd_gotoxy(0,0);
               
               
               }
               else {
               PORTC.0=0;
               PORTC.1=0;
               lcd_clear();}
      }
}
