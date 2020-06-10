/* 
 * File:   main.c
 * Author: 
 * Diogo Agenor Marchi 
 * George de Borba Nardes
 *          
 *   
 * Created on 1 de Maio de 2020, 08:57
 */

#include <xc.h>
#include "config.h"
#include "keyboard.h"
#include "lcd.h"
#include "funcionamento.h"  
#include <stdio.h>
#include <string.h>

t_display_port *lcd;




//void __interrupt() int_handler(void){
////    if(INTCONbits.INT0IF)
////        INTCONbits.INT0IF = 0;
//     if(INTCONbits.TMR0IF == 1){
//        INTCONbits.TMR0IF = 0;    //limpa flag
//        TMR0 = 0x6C;    //reinicia timer0
////        le_entrada(); 
////        col_1 = 0x01;  
//    }
//}



void main(void) {
    CMCON = 0x07;     //desabilita os comparadores
    INTCONbits.PEIE = 0x01;  //habilita interrupção por perifericos
    INTCONbits.T0IE = 0x01;  //habilita interrupção do timer0
    
    TMR0 = 0x6C;       //inicia timer0
    TRISB = 0xF0;      //linha como saida e coluna como entrada
    PORTB = 0xF0;
    ADCON1 = 0x0F;
    TRISD = 0x00;
    INTCONbits.GIE = 1;   //habilita interrupção global
        
    lcd = &PORTD;
            
    function_set(lcd, 0, 1, 0);
    display_onoff_control(lcd, 1, 1, 0);
    entry_mode_set(lcd, 1,0);
    ENABLE_TIMER = 1;
    menu(lcd);
     __delay_ms(1000);    
    
    while(1){  
        le_entrada(); 
        col_1 = 0x01;  
    }   
}