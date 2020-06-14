
#include "keyboard.h"

void le_entrada(){
   
    LINHA_1 = 1;    
    botoes.U = PORTBbits.RB1;
    LINHA_1 = 0; 
    
    LINHA_2 = 1;
    botoes.L = PORTBbits.RB0;
    botoes.R = PORTBbits.RB2;
    LINHA_2 = 0;        
       
    LINHA_3 = 1;
    botoes.D = PORTBbits.RB1;
    LINHA_3 = 0;        
    
    LINHA_4 = 1;
    botoes.Enter = PORTBbits.RB0;
    botoes.Esc = PORTBbits.RB2;
    LINHA_4 = 0;                
}