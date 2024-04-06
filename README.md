# Trabalho de Implementação de Instruções em Linguagem de Montagem

Este é um projeto de implementação de instruções em linguagem de montagem. O objetivo é ler um arquivo de entrada contendo instruções em linguagem de montagem e gerar um arquivo de saída contendo o código de máquina correspondente para cada instrução, de acordo com as especificações fornecidas.

## Estrutura do Projeto

O projeto é organizado da seguinte maneira:

- **main.c**: O arquivo principal do programa, que contém o loop principal para processar as instruções do arquivo de entrada.
- **instrucoes.c**: Este arquivo contém as funções relacionadas à manipulação das instruções, incluindo a conversão de registradores e imediatos para representação binária, bem como a escrita do código de máquina no arquivo de saída.
- **instrucoes.h**: O arquivo de cabeçalho que contém as definições das estruturas e protótipos de função usados nos arquivos de código-fonte.
- **entrada.asm**: O arquivo de entrada contendo as instruções em linguagem de montagem a serem processadas.
- **saida.asm**: O arquivo de saída onde o código de máquina correspondente a cada instrução será gerado.

## Compilação e Execução
- **1º:** gcc instrucoes.c main.c tipoI.c tipoR.c tipoS.c tipoSB.c -o main
- **2º:** ./main
