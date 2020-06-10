/* 
 * File:   keyboard.h
 * Author: George
 *
 * Created on 9 de Junho de 2020, 13:17
 */

#ifndef KEYBOARD_H
#define	KEYBOARD_H

#define col_1 PORTBbits.RB0
#define col_2 PORTBbits.RB1
#define col_3 PORTBbits.RB2
#define linha_1 PORTBbits.RB4
#define linha_2 PORTBbits.RB5
#define linha_3 PORTBbits.RB6
#define linha_4 PORTBbits.RB7

unsigned char controle = 1;

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
void le_entrada();

#endif	/* KEYBOARD_H */

