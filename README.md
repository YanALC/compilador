# INTERPRETADOR DE CALCULADORA

## Interpretador feito com as bibliotecas FLEX e BISON da linguagem C++.

### Para dar build no projeto tenha o LEX ou o FLEX e o YACC ou o BISON instalados.
### Os comandos são os seguintes (entre na pasta `src`): 
- (*Windows*)
`win_bison -d calc.y`
`win_flex calc.l`
`gcc lex.yy.c calc.tab.c -o calc`
- (*Linux*)
`bison -d calc.y`
`flex calc.l`
`gcc lex.yy.c calc.tab.c -o calc`
### Para rodar o comando é: `.\calc.exe` ou `.\calc`.
- Se for rodar com arquivo o comando é o seguinte: `type arquivo.txt | .\calc.exe`

## Tipos de dados: `number` e `text`
## Comando de print: `print <var | op_aritmetica | literal>;`
## Parser reconhece:
- if
- else
- for
- while
- declaração e manuseio de variáveis
- declaração de funções
- operações aritméticas
