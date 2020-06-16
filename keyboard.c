
#include "keyboard.h"

//estado anterior botoes
t_botoes botoes_ant;

unsigned char cont_u = 0;
unsigned char cont_d = 0;
unsigned char cont_l = 0;
unsigned char cont_r = 0;

void le_entrada(){   
    LINHA_1 = 1;    
    if((botoes_ant.U==0 && PORTBbits.RB1==1) || cont_u > 50){//botao de subida
        botoes.U = 1; 
        botoes_ant.U = 1; 
        cont_u = 0;
    }else if(botoes_ant.U==1 && PORTBbits.RB1==0){
        botoes.U = 0; 
        botoes_ant.U = 0; 
        cont_u = 0;
    }else if(PORTBbits.RB1==1) cont_u++;        
    LINHA_1 = 0; 
    
    LINHA_2 = 1;
    if((botoes_ant.L==0 && PORTBbits.RB0==1) || cont_l > 50){//botao esquerda
        botoes.L = 1; 
        botoes_ant.L = 1; 
        cont_l = 0;
    }else if(botoes_ant.L==1 && PORTBbits.RB0==0){
        botoes.L = 0; 
        botoes_ant.L = 0; 
        cont_l = 0;
    }else if(PORTBbits.RB0==1) cont_l++;        
       
    if((botoes_ant.R==0 && PORTBbits.RB2==1) || cont_r > 50){
        botoes.R = 1; 
        botoes_ant.R = 1; 
        cont_r = 0;
    }else if(botoes_ant.R==1 && PORTBbits.RB2==0){
        botoes.R = 0; 
        botoes_ant.R = 0; 
        cont_r = 0;
    }else if(PORTBbits.RB2==1) cont_r++;                        
    LINHA_2 = 0;        
       
    LINHA_3 = 1;    
    if((botoes_ant.D==0 && PORTBbits.RB1==1) || cont_d > 50){
        botoes.D = 1; 
        botoes_ant.D = 1; 
        cont_d = 0;
    }else if(botoes_ant.D==1 && PORTBbits.RB1==0){
        botoes.D = 0; 
        botoes_ant.D = 0; 
        cont_d = 0;
    }else if(PORTBbits.RB1==1) cont_d++;                    
    LINHA_3 = 0;        
    
    LINHA_4 = 1;
    botoes.Enter = PORTBbits.RB0;
    botoes.Esc = PORTBbits.RB2;
    LINHA_4 = 0;                
}