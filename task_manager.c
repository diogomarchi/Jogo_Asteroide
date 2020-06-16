/*
 * File:   task_manager.c
 * Author: Diogo
 *
 * Created on 9 de Junho de 2020, 14:22
 */


#include "task_manager.h"

// opção a ser selecionada no menu
unsigned char op = 0,x = 1, y = 0;


void gerenciador(t_display_port *lcd){                        
    while(1){
        menu(lcd);
        if(op == 0) jogar(lcd);
        else if(op == 1) instrucoes(lcd);
        else if(op == 2) creditos(lcd);
        else if(op == 3) finaliza(lcd);
        /* chamadas de funções a partir da opção selecionada */
    }    
}


void creditos(t_display_port *lcd){    
    
    strcpy(mat_disp[0], "1.DIOGO MARCHI.");
    strcpy(mat_disp[1], "2.GEORGE NARDES");
    strcpy(mat_disp[2], "               ");
    strcpy(mat_disp[3], "               ");                                          
    print_mat(lcd);    
    while(!botoes.Esc);
}

void finaliza(t_display_port *lcd){
    strcpy(mat_disp[0], "HIBERNANDO.....");
    strcpy(mat_disp[1], "               ");
    strcpy(mat_disp[2], "               ");
    strcpy(mat_disp[3], "               ");                                          
    print_mat(lcd);    
    while(!botoes.Esc);
}

void jogar(t_display_port *lcd){
    int score = 0;
    int bateu = 0;
  
    // pos inicial
    strcpy(mat_disp[0], "       SCORE:   ");
    strcpy(mat_disp[1], "                ");
    strcpy(mat_disp[2], "                ");
    strcpy(mat_disp[3], "                ");
    mat_disp[1][0] = '>';
    print_mat(lcd);
            
    while(!botoes.Esc){
        if((botoes.U) && (x > 1)){
            mat_disp[x][y] = ' ';
            x--; 
            botoes.U = 0;
            mat_disp[x][y] = '>';
            print_mat(lcd);            
        }
        if((botoes.D) && (x < 3)){
            mat_disp[x][y] = ' ';
            x++; 
            botoes.D = 0;
            mat_disp[x][y] = '>';
            print_mat(lcd);            
        }
        if((botoes.R) && (y < 15)){
            mat_disp[x][y] = ' ';
            y++; 
            botoes.R = 0;
            mat_disp[x][y] = '>';
            print_mat(lcd);            
        }
        if((botoes.L) && (y > 0)){
            mat_disp[x][y] = ' ';
            y--; 
            botoes.L = 0;
            mat_disp[x][y] = '>';
            print_mat(lcd);            
        }
    }
    
}

void instrucoes(t_display_port *lcd){
    strcpy(mat_disp[0], "1.SETAS MOVEM A");
    strcpy(mat_disp[1], "NAVE           ");
    strcpy(mat_disp[2], "2.ESCAPE VOLTA ");
    strcpy(mat_disp[3], "MENU           ");                                          
    print_mat(lcd);    
    while(!botoes.Esc);
}

char menu(t_display_port *lcd){
    strcpy(mat_disp[0], "1.JOGAR.........");
    strcpy(mat_disp[1], "2.INSTRUCOES....");
    strcpy(mat_disp[2], "3.CREDITOS......");
    strcpy(mat_disp[3], "4.FINALIZAR.....");                
    
    // pos inicial
    mat_disp[op][15] = '<';
    print_mat(lcd);
            
    while(!botoes.Enter){
        if((botoes.U) && (op > 0)){
            mat_disp[op][15] = '.';
            op--; 
            botoes.U = 0;
            mat_disp[op][15] = '<';
            print_mat(lcd);            
        }
        if((botoes.D) && (op < 3)){
            mat_disp[op][15] = '.';
            op++; 
            botoes.D = 0;
            mat_disp[op][15] = '<';
            print_mat(lcd);            
        }
    }
    
    return op;    
}

