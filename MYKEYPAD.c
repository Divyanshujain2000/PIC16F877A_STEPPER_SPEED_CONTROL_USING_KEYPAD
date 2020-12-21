/*
 * File:   MYKEYPAD.c
 * Author: Divyanshu
 *
 * Created on 19 December, 2020, 7:17 PM
 */


#include <xc.h>
#include "MYKEYPAD.h"
#include "EXTRAS.h"

void init_keypad()
{
    //KeypadPortDirection = 0xF0;
    KeypadPort = 0x00;          // here we had to choose differnt ports as the internal pullup was only available in port B
    TRISCbits.TRISC0 = 0;       //output
    TRISCbits.TRISC1 = 0;       //output
    TRISCbits.TRISC2 = 0;       //output
    TRISCbits.TRISC3 = 0;       //output
    TRISBbits.TRISB4 = 1;       //input
    TRISBbits.TRISB5 = 1;       //input
    TRISBbits.TRISB6 = 1;       //input
    TRISBbits.TRISB7 = 1;       //input
    OPTION_REGbits.nRBPU = 0;   // internal pullup enable in port B
}





char get_value()
{
    X1=0;   X2=1;   X3=1;   X4=1;
    if(Y1 == 0){ while(Y1 == 0); return keypad[0];}
    if(Y2 == 0){ while(Y2 == 0); return keypad[1];}
    if(Y3 == 0){ while(Y3 == 0); return keypad[2];}
    if(Y4 == 0){ while(Y4 == 0); return keypad[3];}
    
    X1=1;   X2=0;   X3=1;   X4=1;
    if(Y1 == 0){ while(Y1 == 0); return keypad[4];}
    if(Y2 == 0){ while(Y2 == 0); return keypad[5];}
    if(Y3 == 0){ while(Y3 == 0); return keypad[6];}
    if(Y4 == 0){ while(Y4 == 0); return keypad[7];}
    
    X1=1;   X2=1;   X3=0;   X4=1;
    if(Y1 == 0){ while(Y1 == 0); return keypad[8];}
    if(Y2 == 0){ while(Y2 == 0); return keypad[9];}
    if(Y3 == 0){ while(Y3 == 0); return keypad[10];}
    if(Y4 == 0){ while(Y4 == 0); return keypad[11];}
    
    X1=1;   X2=1;   X3=1;   X4=0;
    if(Y1 == 0){ while(Y1 == 0); return keypad[12];}
    if(Y2 == 0){ while(Y2 == 0); return keypad[13];}
    if(Y3 == 0){ while(Y3 == 0); return keypad[14];}
    if(Y4 == 0){ while(Y4 == 0); return keypad[15];}
    
    
    return 'n';
}


char get_key()
{
    char key ='n';
    while(key=='n')
        key = get_value();
    
    return key;
}


char * get_str()
{   int i=0;
    char key1;
    char str[10];
    
    key1 = get_key();
    do{ str[i++] = key1;
        
        key1 = get_key();
            
        }while(key1!='S');
        str[i++]='\0';
    return str;    
}
