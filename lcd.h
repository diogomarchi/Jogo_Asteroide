/* 
 * File:   lcd_hd_44780.h
 * Author: 
 * Diogo Agenor Marchi 
 * George de Borba Nardes
 *          
 *  
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "config.h"

typedef struct {
    char RS:1;
    char R_W:1;
    char E:1;
    char NA:1;
    char data:4;
}t_display_port;


char mat_disp [4][TAM];


/**      
    
    @Description: define a largura de dados, qtd de linhas e fonte
      
    @Parameters : ponteiro do tipo t_display_port, 
                  data_lenght: 1 para 8bit; 0 para 4bit 
                * data_lenght de 8bit não implementado - não usar *
                  num_lines: 1 para 2 linha; 0 para 1 linha
    @Returns    : Void      
 */
void function_set(t_display_port *lcd, char data_lenght, 
        char num_lines, char char_font);

/**      
    
    @Description: Habilita display e o cursor. Também define se o caracter
                  indicado pelo cursor irá piscar
 
    @Parameters :ponteiro do tipo t_display_port, 
                 diplay_on: 1 habilita; 0 desabilita
                 cusor_on: 1 habilita; 0 desabilita
                 blink: 1 habilita; 0 desabilita
    @Returns    :Void      
 */
void display_onoff_control(t_display_port *lcd, char display_on,
        char cursor_on, char blink);

/**      
    
    @Description: define se o endereco DDRAM será incrementado ou decrementado
                  e se o diplay será deslocado ou não
    @Parameters : ponteiro do tipo t_display_port, 
                  move_direction: 1 para esquerda; 0 para direita
                  display_shift: 1 habilita; 0 desabilita
    @Returns    : Void      
 */
void entry_mode_set(t_display_port *lcd,char move_direction, 
        char display_shift);

/**      
    
    @Description: Posicionar o cursor no lugar que quiser
      
    @Parameters : ponteiro do tipo t_display_port, 
                  x: é linha
                  y: é coluna
    @Returns    : Void      
 */
void goto_XY(t_display_port *lcd,
        unsigned char x, unsigned char y);

/**      
    
    @Description: faz o comando mandado  
 *       
    @Parameters : ponteiro do tipo t_display_port, 
                  c: é o comando
    @Returns    : Void      
 */
void lcd_cmd(t_display_port *lcd, char c);

/**      
    
    @Description: escreve no display
      
    @Parameters :  ponteiro do tipo t_display_port, 
                   c: caracter a ser escrito
    @Returns    :  Void      
 */
void write_char(t_display_port *lcd, char c);

/**      
    
    @Description:  limpa o display      
    @Parameters :  ponteiro do tipo t_display_port,                 
    @Returns    :  Void      
 */
void clear_display(t_display_port *lcd);



/**      
    @Description:  Retorna ao endereço DDRAM para 0
    @Parameters :  ponteiro do tipo t_display_port,       
    @Returns    :  Void      
 */
void return_home(t_display_port *lcd);


void print_mat(t_display_port *lcd);


#endif	/* XC_HEADER_TEMPLATE_H */

