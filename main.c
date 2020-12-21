/*
 * File:   main.c
 * Author: Divyanshu
 *
 * Created on 15 December, 2020, 10:33 PM
 */
/*
 
 WORKING : SPEED CONTROL OF STEPPER MOTOR USING KEYPAD TO ENTER SPEED
 

 
 
 
 */


#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 20000000

#include <xc.h>
#include "MYSTEPPER.h"
#include "EXTRAS.h"
#include "HARDWARE_INTRP.h"
#include "MYKEYPAD.h"
#include "lcd_hd44780_pic16.h"

long unsigned int s=1;
char * a;
void INTR_CALL_WORK()
{   //STOP();
    LCDClear();
    init_keypad();
    LCDWriteString("ENTER RPM");
    int num=0; 
    a= get_str();
    if(*a=='x')
    {    
        STOP();
        LCDClear();
        LCDWriteString("STOP");
    }
    else if(*a=='=')
    {   
        INITSTEPPER();
        LCDClear();
        LCDWriteString("START");
    }
    else
    {
        int i=0;
        int flag=1;
        if(*(a)=='-')   // to check for minus sign if yes then do the required to get neg num
        {
            flag=-1;
            i++;
        }
        while(*(a+i)!='\0')
        {   
            num = num*10+((*(a+i))-48)*flag;
            i++;
        }
        s=num;
        LCDClear();
        LCDWriteString("VALUE: ");
        //LCDWriteString(a);
        LCDWriteInt(num,3);
        LCDWriteString(" Rpm");
    }
}
void __interrupt() Timer_isr ()
{
    GIE = 0;
    if(INTF == 1)
    { 
        INTR_CALL_WORK();
        INTF = 0;
    }
      GIE = 1;
}
void main() {
    INITSTEPPER();
    INITH();
    LCDInit(LS_NONE);
    SETSPEED(&s);
}

