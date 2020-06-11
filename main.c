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
t_botoes *botoes;

void __interrupt() int_handler(void){

     if(INTCONbits.TMR0IF == 1){        
        TMR0L = 0x63;    //reinicia timer0
        le_entrada(botoes);         
        INTCONbits.TMR0IF = 0;    //limpa flag
    }
}

void main(void) {
    // Portas Digitais
    ADCON1 = 0x0F;
    
    //linha como saida e coluna como entrada
    // RB7 -> RB0
    // 0000 1111
    TRISB = 0x0F;      
    
    //Iniciando
    PORTB = 0x00;
    
    //Saida display
    TRISD = 0x00;             
  
    // TMR0ON T08BIT T0CS T0SE PSA T0PS2 T0PS1 T0PS0
    T0CON = 0x47; // configurado timer 8 bit, prescaler 256
    
    // 99 como valor inicial 
    TMR0L = 0x63;
            
    // habilita interrupção global e timer0
    INTCONbits.TMR0IF = 0;    //limpa flag
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIE = 1;
    
    lcd = &PORTD;
            
    function_set(lcd, 0, 1, 0);
    display_onoff_control(lcd, 1, 1, 0);
    entry_mode_set(lcd, 1,0);
        
    ENABLE_TIMER = 1;
         
    while(1){          
        if(botoes->U){
            goto_XY(lcd, 3, 2);
            write_char(lcd,'*');
        }
        if(botoes->D){
            goto_XY(lcd, 2, 2);
            write_char(lcd,'*');
        }        
        if(botoes->L){
            goto_XY(lcd, 1, 2);
            write_char(lcd,'*');
        }
        if(botoes->R){
            goto_XY(lcd, 1, 3);
            write_char(lcd,'*');
        }
        __delay_ms(80);
        clear_display(lcd);
    }   
}