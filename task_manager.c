/*
 * File:   task_manager.c
 * Author: Diogo
 *
 * Created on 9 de Junho de 2020, 14:22
 */


#include "task_manager.h"
#include <time.h>

// opção a ser selecionada no menu
unsigned char op = 0,x = 1, y = 0, contador = 0;

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
    Sleep();
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

void jogar(t_display_port *lcd){
    srand(time(NULL));    
    int bateu = 0, qtd_asteroide = 20, velocidade = 4;
    int linha_aleatoria = 0;
    int nivel2 = 1;
    
    //tela inicial
    strcpy(mat_disp[0], "     SCORE:     ");
    strcpy(mat_disp[1], "                ");
    strcpy(mat_disp[2], "                ");
    strcpy(mat_disp[3], "                ");
    
    // pontuações iniciais 
    mat_disp[0][15-1] = 0x30;
    mat_disp[0][14-1] = 0x30;
    mat_disp[0][13-1] = 0x30;
    mat_disp[0][12-1] = 0x30;
    
    print_mat(lcd); 
    
    //enquanto nao apertar esc e nao bater, fica no jogo 
    while(!botoes.Esc && bateu == 0){
        contador ++;
        if(contador%qtd_asteroide == 0){//pra nao vir um seguido do outro
            linha_aleatoria = (rand()%3) + 1 ;  //cria linha aleatoria pra aparecer o asteroide
            mat_disp[linha_aleatoria][15] = '*';//na ultima coluna da linha randomica, cria o asteroide
        }
        if(contador%velocidade == 0){
            for(int i = 1; i <= 3; i++){//passa todas as casas 1 para o aldo esquerd
                for(int j = 0; j < 15; j++)
                    mat_disp[i][j] = mat_disp[i][j+1];
                mat_disp[i][15] = ' ';
            }
            mat_disp[x][y-1] = ' '; //nave continua no lugar dela
            mat_disp[x][y] = '>';   //nave continua no lugar dela
            
            if(mat_disp[1][0] == '*' || mat_disp[2][0] == '*' || mat_disp[3][0] == '*')//se na coluna zero tiver asteroide, pontuação ++
            {
                mat_disp[0][15-1]++;
                if(mat_disp[0][15-1]==0x3A)
                {  
                    mat_disp[0][15-1] = 0x30;
                    mat_disp[0][14-1]++;

                    if(mat_disp[0][14-1]==0x3A)
                    {
                        mat_disp[0][14-1] = 0x30;
                        mat_disp[0][13-1]++;

                        if(mat_disp[0][13-1]==0x3A)
                        {
                            mat_disp[0][13-1] = 0x30;
                            mat_disp[0][12-1]++;

                            if(mat_disp[0][12-1]==0x3A)
                                mat_disp[0][12-1] = 0x30;
                        }
                    }
                }
            }
        }
                
        // printa matriz de elementos apos deslocamento
        print_mat(lcd); 
        
        if(mat_disp[0][14-1] == 0x31 && mat_disp[0][15-1] == 0x30 && nivel2 == 1){//se pontuação maior que 10, aumenta velocidade e quantidade de asteroides
            strcpy(mat_disp[1], "   NIVEL 2      ");
            strcpy(mat_disp[2], "                ");
            strcpy(mat_disp[3], "                ");
            print_mat(lcd);
            nivel2 = 0;
            int cont = 0;
            while(cont<50){//espera um pouco
                cont++;
            }
            strcpy(mat_disp[1], "                ");
            velocidade = 2;
            qtd_asteroide = 15;
        }
                
        //se colidiu
        if(mat_disp[x][y] == '>' && mat_disp[x][y+1] == '*')
            bateu = 1;
         
        if((botoes.U) && (x > 1)){//se apertou para cima
            if(mat_disp[x][y] == '>' && mat_disp[x-1][y] == '*')//quando ele clica, e na linha de cima tem asteroide = bateu
                bateu = 1;
            mat_disp[x][y] = ' ';
            x--; 
            botoes.U = 0;
            mat_disp[x][y] = '>';           
        }
        if((botoes.D) && (x < 3)){//se apertou para baixo
            if(mat_disp[x][y] == '>' && mat_disp[x+1][y] == '*')//quando ele clica, e na linha de baixo tem asteroide = bateu
                bateu = 1;
            mat_disp[x][y] = ' ';
            x++; 
            botoes.D = 0;
            mat_disp[x][y] = '>';            
        }
        if((botoes.R) && (y < 15)){//se apertou para direita
            mat_disp[x][y] = ' ';
            y++; 
            botoes.R = 0;
            mat_disp[x][y] = '>';            
        }
        if((botoes.L) && (y > 0)){//se apertou para esquerda
            mat_disp[x][y] = ' ';
            y--; 
            botoes.L = 0;
            mat_disp[x][y] = '>';                     
        }
    }
    
    char pont4 = mat_disp[0][14], pont3 = mat_disp[0][13], pont2 = mat_disp[0][12], pont1 = mat_disp[0][11];
    if(bateu == 1){//se bateu, mostra frase no display
            strcpy(mat_disp[0], "!!!VOCE BATEU!!!");
            strcpy(mat_disp[1], "SCORE:          ");
            strcpy(mat_disp[2], "APERTE ESC      ");
            strcpy(mat_disp[3], "PARA SAIR       ");
            mat_disp[1][6] = pont1;
            mat_disp[1][7] = pont2;
            mat_disp[1][8] = pont3;
            mat_disp[1][9] = pont4;
            print_mat(lcd);
        while(!botoes.Esc);
    }
    //zerando posição inicial da nave
    x = 1;
    y = 0;
    contador = 0;
}



