/*
 * File:   task_manager.c
 * Author: Diogo
 *
 * Created on 9 de Junho de 2020, 14:22
 */


#include "task_manager.h"

// opção a ser selecionada no menu
unsigned char op = 0;


void gerenciador(t_display_port *lcd){                        
    while(1){
        menu(lcd);    
        
        if(op==2) creditos(lcd);
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
    
}

void jogar(t_display_port *lcd){
    char vet1[TAM], vet2[TAM], vet3[TAM];    //são os asteroides
    int score = 0, i = 0, j = 0;
    int bateu = 0;
    char nave[3][TAM];
  
    while(bateu == 0){
    //montar os asteroides vindo randomicamente
    //o asteroide sera um "*"
    // a nave sera um ">"
    
    goto_XY(lcd, 2, 1);                 //linha 1, coluna 1
    for(int i = 0; i < TAM; i ++)
        write_char(lcd, vet1[i]);
    
    goto_XY(lcd, 3, 1);                 //linha 1, coluna 1
    for(int i = 0; i < TAM; i ++)
        write_char(lcd, vet2[i]);
    
    goto_XY(lcd, 4, 1);                 //linha 1, coluna 1
    for(int i = 0; i < TAM; i ++)
        write_char(lcd, vet3[i]);
    
    
    if(nave[i][j] == '*')
        bateu = 1;
    
    if(vet1[0] == '*' || vet2[0] == '*' || vet3[0] == '*')
        score ++;
    
    }
    
}

void instrucoes(t_display_port *lcd){
    char palavra[TAM] = "1.SETAS MOVEM A";
    int tamanho = (int)strlen(palavra);   //pega quantidade de caracteres
    
    char palavra2[TAM] = "NAVE";
    int tamanho2 = (int)strlen(palavra2); //pega quantidade de caracteres
    
    char palavra3[TAM] = "2.ESCAPE VOLTA";
    int tamanho3 = (int)strlen(palavra3); //pega quantidade de caracteres
    
    char palavra4[TAM] = "PRO MENU";
    int tamanho4 = (int)strlen(palavra4); //pega quantidade de caracteres
                        
    goto_XY(lcd, 1, 1);                 //linha 1, coluna 1
    for(int i = 0; i < tamanho; i ++)
        write_char(lcd, palavra[i]);

    goto_XY(lcd, 2, 1);                 //linha 2, coluna 1
    for(int i = 0; i < tamanho2; i ++) 
        write_char(lcd, palavra2[i]);

    goto_XY(lcd, 3, 1);                 //linha 3, coluna 1
    for(int i = 0; i < tamanho3; i ++) 
        write_char(lcd, palavra3[i]);

    goto_XY(lcd, 4, 1);                 //linha 4, coluna 1
    for(int i = 0; i < tamanho4; i ++) 
        write_char(lcd, palavra4[i]);
    
    __delay_ms(5000);
    
    //VERIFICA SE ESCAPE FOI APERTADO PARA VOLTAR PRO MENU
    clear_display(lcd);
    menu(lcd);   
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

