
#include "keyboard.h"

void le_entrada(t_botoes *botoes){                    
    linha_1 = 1;    
    botoes->U = PORTBbits.RB1;
    linha_1 = 0; 
    
    linha_2 = 1;
    botoes->L = PORTBbits.RB0;
    botoes->R = PORTBbits.RB2;
    linha_2 = 0;        
       
    linha_3 = 1;
    botoes->D = PORTBbits.RB1;
    linha_3 = 0;        
    
    linha_4 = 1;
    botoes->Enter = PORTBbits.RB0;
    botoes->Esc = PORTBbits.RB2;
    linha_4 = 0;                
}