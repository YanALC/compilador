  #####                                                            
 #     #  ####  #    # #####  # #        ##   #####   ####  #####  
 #       #    # ##  ## #    # # #       #  #  #    # #    # #    # 
 #       #    # # ## # #    # # #      #    # #    # #    # #    # 
 #       #    # #    # #####  # #      ###### #    # #    # #####  
 #     # #    # #    # #      # #      #    # #    # #    # #   #  
  #####   ####  #    # #      # ###### #    # #####   ####  #    # 
                                                                   

Compilador feito com as bibliotecas LEX e YACC da linguagem C.

- Para dar build no projeto tenha o LEX ou o FLEX e o YACC ou o BISON instalados.
- Os comandos são os seguintes: 
*Windows*
`win_bison -d compilador.y`
`win_flex compilador.l`
`gcc lex.yy.c compilador.tab.c -o compilador`
*Linux*
`bison -d compilador.y`
`flex compilador.l`
`gcc lex.yy.c compilador.tab.c -o compilador`
- Para rodar o comando é: `.\compilador.exe` ou `.\compilador`

- Tipos de dados: `number` e `text`
- Comando de print: `print <var>`