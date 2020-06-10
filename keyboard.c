
#include "keyboard.h"
#include "lcd.h"

t_display_port *lcd;
void le_entrada(){
    clear_display(lcd);
    if(col_1 && controle == 1){
        col_1 = 0x00;
        col_2 = 0x01;
        col_3 = 0x01;
        controle = 2;
        if(linha_2 == 0){
            goto_XY(lcd,3,1);
            write_char(lcd,'<');//entrou
            __delay_ms(1000);
            clear_display(lcd);
        }
        if(linha_4 == 0){
            goto_XY(lcd,3,1);
            write_char(lcd,'E');//entrou
            __delay_ms(1000);
            clear_display(lcd);
        }
    }
    if(col_2 && controle == 2){
        col_1 = 0x01;
        col_2 = 0x00;
        col_3 = 0x01;
        controle = 3;
        if(linha_1 == 0){
            goto_XY(lcd,3,1);
            write_char(lcd,'C');//entrou
            __delay_ms(1000);
            clear_display(lcd);
        }
        if(linha_3 == 0){
            goto_XY(lcd,3,1);
            write_char(lcd,'B');//entrou
            __delay_ms(1000);
            clear_display(lcd);
        }
    }
    if(col_3 && controle == 3){
        col_1 = 0x01;
        col_2 = 0x01;
        col_3 = 0x00;
        controle = 1;
        if(linha_2 == 0){
            goto_XY(lcd,3,1);
            write_char(lcd,'>');//entrou
            __delay_ms(1000);
            clear_display(lcd);
        }
        if(linha_4 == 0){
            goto_XY(lcd,3,1);
            write_char(lcd,'S');//entrou
            __delay_ms(1000);
            clear_display(lcd);
        }
    }
}