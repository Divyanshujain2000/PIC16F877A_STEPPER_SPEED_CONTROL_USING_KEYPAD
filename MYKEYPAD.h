/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: DIVYANSHU
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "EXTRAS.h"
// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

/*
    #define X1  RB0 
    #define X2  RB1
    #define X3  RB2
    #define X4  RB3
 
    #define Y1  RB4
    #define Y2  RB5
    #define Y3  RB6
    #define Y4  RB7
    #define KeypadPort PORTB // or any port of your choice
    #define KeypadPortDirection TRISB 
 * 
 * 
 * 
 * 
 * 
 * OR
 * 
 * 
 * 
    *  #define KEYPAD_PORT C                           // or any port of your choice
    #define X1  PORTBIT(KEYPAD_PORT,0)
    #define X2  PORTBIT(KEYPAD_PORT,1)
    #define X3  PORTBIT(KEYPAD_PORT,2)
    #define X4  PORTBIT(KEYPAD_PORT,3)
 
    #define Y1  PORTBIT(KEYPAD_PORT,4)
    #define Y2  PORTBIT(KEYPAD_PORT,5)
    #define Y3  PORTBIT(KEYPAD_PORT,6)
    #define Y4  PORTBIT(KEYPAD_PORT,7)
    #define KeypadPort PORT(KEYPAD_PORT) 
    #define KeypadPortDirection TRIS(KEYPAD_PORT) 
 */
    
    #define X1  RC0 
    #define X2  RC1
    #define X3  RC2
    #define X4  RC3
 
    #define Y1  RB4             // here we had to choose differnt ports as the internal pullup was only available in port B
    #define Y2  RB5
    #define Y3  RB6
    #define Y4  RB7
    #define KeypadPort PORTC // or any port of your choice
    #define KeypadPortDirection TRISC

char keypad[16] = 
{   '7'   ,   '8'   ,   '9'   ,   '/'   ,   
    '4'   ,   '5'   ,   '6'   ,   'x'   ,   
    '1'   ,   '2'   ,   '3'   ,   '-'   ,   
    'S'   ,   '0'   ,   '='   ,   '+'   };

void init_keypad();
char get_value();
char get_key();
char * get_str();

