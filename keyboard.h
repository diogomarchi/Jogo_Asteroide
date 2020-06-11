/* 
 * File:   keyboard.h
 * Author: George
 *
 * Created on 9 de Junho de 2020, 13:17
 */

#ifndef KEYBOARD_H
#define	KEYBOARD_H

#include <pic18f4520.h>

#define linha_4 PORTBbits.RB4
#define linha_3 PORTBbits.RB5
#define linha_2 PORTBbits.RB6
#define linha_1 PORTBbits.RB7

typedef struct {
    char U:1;
    char D:1;
    char L:1;
    char R:1;
    char Enter:1;
    char Esc:1;
}t_botoes;


/**      
    
    @Description: le qual botão foi pressionado  
    @Parameters : nenhum
    @Returns    : Void      
 */
void le_entrada(t_botoes *botoes);

#endif	/* KEYBOARD_H */

