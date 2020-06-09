/*
 * File:   funcionamentoJogo.c
 * Author: Diogo
 *         George
 * Created on 26 de Maio de 2020, 19:37
 */
#include <stdio.h>
#include <string.h>
#include "funcionamento.h"
#define TAM 16


void creditos(t_display_port *lcd){
    char palavra[TAM] = "1.DIOGO MARCHI";
    int tamanho = (int)strlen(palavra);   //pega quantidade de caracteres
    
    char palavra2[TAM] = "2.GEORGE NARDES";
    int tamanho2 = (int)strlen(palavra2); //pega quantidade de caracteres
                        
    goto_XY(lcd, 1, 1);                 //linha 1, coluna 1

    for(int i = 0; i < tamanho; i ++)
        write_char(lcd, palavra[i]);

    goto_XY(lcd, 2, 1);                 //linha 2, coluna 1

    for(int i = 0; i < tamanho2; i ++) 
        write_char(lcd, palavra2[i]);

    
    __delay_ms(5000);
    
    //VERIFICA SE ESCAPE FOI APERTADO PARA VOLTAR PRO MENU
    clear_display(lcd);
    menu(lcd);
    
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

void menu(t_display_port *lcd){
    char palavra[TAM] = "1.JOGAR";
    int tamanho = (int)strlen(palavra);   //pega quantidade de caracteres
    
    char palavra2[TAM] = "2.INSTRUCOES";
    int tamanho2 = (int)strlen(palavra2); //pega quantidade de caracteres
    
    char palavra3[TAM] = "3.CREDITOS";
    int tamanho3 = (int)strlen(palavra3); //pega quantidade de caracteres
    
    char palavra4[TAM] = "4.FINALIZAR";
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
    
    //__delay_ms(5000);
    
    int opcao = 0;
    //chamar função verifica, pra ver em qual função ele parou
    //opção = verifica();
    switch(opcao){
        case 1:
            clear_display(lcd);
            //jogar();
            break;
        case 2:
            clear_display(lcd);
            //instrucoes();
            break;
        case 3:
            clear_display(lcd);
            //creditos();
            break;
        case 4:
            clear_display(lcd);
            //finaliza();
            break;
    }
    
}
