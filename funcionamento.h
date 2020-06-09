/* 
 * File:   funcionamentoJogo.h
 * Author: Diogo
 *
 * Created on 26 de Maio de 2020, 19:38
 */

#ifndef FUNCIONAMENTO_H
#define	FUNCIONAMENTO_H
#include <xc.h> // include processor files - each processor file is guarded.  
#include "config.h"
#include "lcd.h"

/**      
    @Description:  mostra o menu do jogo
    @Parameters :  ponteiro do tipo t_display_port,       
    @Returns    :  Void      
 */
void menu(t_display_port *lcd);

/**      
    @Description:  mostra as instrucoes do jogo
    @Parameters :  ponteiro do tipo t_display_port,       
    @Returns    :  Void      
 */
void instrucoes(t_display_port *lcd);

/**      
    @Description:  mostra as autores do jogo
    @Parameters :  ponteiro do tipo t_display_port,       
    @Returns    :  Void      
 */
void creditos(t_display_port *lcd);

/**      
    @Description:  todo o funcionamento do jogo do asteroide
    @Parameters :  ponteiro do tipo t_display_port,       
    @Returns    :  Void      
 */
void jogar(t_display_port *lcd);





#endif	/* FUNCIONAMENTO_H */

