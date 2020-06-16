/* 
 * File:   task_manager.h
 * Author: Diogo
 *
 * Created on 9 de Junho de 2020, 14:23
 */

#ifndef TASK_MANAGER_H
#define	TASK_MANAGER_H

#include <xc.h>
#include "config.h"
#include "lcd.h"
#include "keyboard.h"


void gerenciador(t_display_port *lcd);


/**      
    @Description:  mostra o menu do jogo
    @Parameters :  ponteiro do tipo t_display_port,       
    @Returns    :  Void      
 */
char menu(t_display_port *lcd);

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

/**      
    @Description:  deixa pic dormindo
    @Parameters :  ponteiro do tipo t_display_port,       
    @Returns    :  Void      
 */
void finaliza(t_display_port *lcd);


#endif	/* TASK_MANAGER_H */

