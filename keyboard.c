
#include "keyboard.h"
#include "lcd.h"

t_display_port *lcd;
void le_entrada(){
    char control = 0x01;
    if(col_1 && control == 0x01){
        control = 0x02;
        col_1 = 0x00;
        col_2 = 0x01;
        col_3 = 0x01;

        if(!linha_2){//foi apertado a tecla "<"
            goto_XY(lcd,1,1);
            write_char(lcd,'<');
        }
        if(!linha_4){//foi apertado a tecla "enter"
            goto_XY(lcd,2,1);
            write_char(lcd,'E');
        }
    }

    else if(col_2 && control == 0x02){
        control = 0x03;
        col_1 = 0x01;
        col_2 = 0x00;
        col_3 = 0x01;

        if(!linha_1){//foi apertado a tecla "/\"
            goto_XY(lcd,3,1);
            write_char(lcd,'/');
        }
        if(!linha_3){//foi apertado a tecla "\/"
            goto_XY(lcd,4,1);
            write_char(lcd,'\\');
            __delay_ms(1000);
            clear_display(lcd);
        }
    }

    else if(col_3 && control == 0x03){
        control = 0x01;
        col_1 = 0x01;
        col_2 = 0x01;
        col_3 = 0x00;

        if(!linha_2){//foi apertado a tecla ">"
            goto_XY(lcd,1,1);
            write_char(lcd,'>');
        }
        if(!linha_4){//foi apertado a tecla "escape"
            goto_XY(lcd,2,1);
            write_char(lcd,'S');
        }
    }     
}