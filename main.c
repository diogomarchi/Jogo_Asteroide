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




void __interrupt() int_handler(void){

     if(INTCONbits.TMR0IF == 1){
        INTCONbits.TMR0IF = 0;    //limpa flag
        TMR0 = 0xC2F7;    //reinicia timer0
        le_entrada(); 
        col_1 = 0x01;  
    }
}

void main(void) {
    ADCON1 = 0x0F;
    TRISB = 0xF0;      //linha como saida e coluna como entrada
    PORTB = 0xF0;
    TRISD = 0x00;
    
    // habilita interrup??o pino b0 = botão
    INTCONbits.INT0IF = 0;
    INTCONbits.INT0IE = 1;       
  
    T0CON = 0x07;     
    TMR0 = 0xC2F7;
            
    // habilita interrupção global e timer0       
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIE = 1;
         
    lcd = &PORTD;
            
    function_set(lcd, 0, 1, 0);
    display_onoff_control(lcd, 1, 1, 0);
    entry_mode_set(lcd, 1,0);
    //menu(lcd);
    
    ENABLE_TIMER = 1;
     __delay_ms(1000);    
    
    while(1){  
         
    }   
}