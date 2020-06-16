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
#include "task_manager.h"

/* precisa ser declarado aqui pra passar por parametro. 
 tentei declarar no lcd.h para n precisar passar por parametro e deu 
 o erro "Looping around allocGlobals" que parece ser um erro do compilador
 quando tem muitos calculos de endereco para fazer
 https://www.todopic.com.ar/foros/index.php?topic=42822.0*/
t_display_port *lcd = &PORTD;

void __interrupt() int_handler(void){
    if(INTCONbits.TMR0IF == 1){        
        TMR0L = 0x63;             //reinicia timer0
        le_entrada();         
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
                    
    function_set(lcd, 0, 1, 0);
    display_onoff_control(lcd, 1, 1, 0);
    entry_mode_set(lcd, 1,0);
        
    ENABLE_TIMER = 1;
         
    gerenciador(lcd);        
}