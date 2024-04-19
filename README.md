# Trabalho de Implementação de Instruções em Linguagem de Montagem

Este é um projeto de implementação de instruções em linguagem de montagem. O objetivo é ler um arquivo de entrada contendo instruções em linguagem de montagem e gerar um arquivo de saída contendo o código de máquina correspondente para cada instrução, de acordo com as especificações fornecidas.

## Estrutura do Projeto

O projeto é organizado da seguinte maneira:

- **main.c**: O arquivo principal do programa, que contém o loop principal para processar as instruções do arquivo de entrada.
- **include/**: Esta pasta contém os arquivos de cabeçalho.
- **src/**: Esta pasta contém os arquivos de código-fonte.
  - **bin_para_hex**:
      * binarioParaHex: Converte uma string binária em hexadecimal;
      * binParaHex: Lê um arquivo de entrada contendo instruções binárias, converte cada instrução para hexadecimal e escreve no arquivo de saída.
      
  - **instrucoes.c**:
      * converter_offset: Converte um offset (um número inteiro) para sua representação binária de 12 bits, usando complemento de dois se o número for negativo;
      * registrador_para_binario: Converte o número de um registrador para sua representação binária de tamanho variável especificado, começando a partir do índice 1 da string do registrador;
      * inteiro_para_binario: Converte um número inteiro para sua representação binária de um tamanho específico em bits;
      * imediato_para_binario: Converte um imediato (um número inteiro) para sua representação binária de 12 bits, usando complemento de dois se o número for negativo;
      * escrever_no_arquivo: Escreve uma string de código de máquina em um arquivo, seguido de uma nova linha, e verifica se ocorreu algum erro durante a escrita.

  -**tipoI.c**:
      * Implementa a função obterInstrucaoTipoI, responsável por converter e escrever instruções do tipo I em binário no arquivo de saída.
      * Contém funções auxiliares para conversão de registradores e imediatos para binário.
  
  -**tipoR.c**:
      * Implementa a função obterInstrucaoTipoR, responsável por converter e escrever instruções do tipo R em binário no arquivo de saída.
      * Contém funções auxiliares para conversão de registradores para binário.
  
  -**tipoS**:
      * Implementa a função obterInstrucaoTipoS, responsável por converter e escrever instruções do tipo S em binário no arquivo de saída.
      * Contém funções auxiliares para conversão de registradores e offset para binário, além da separação do offset em partes.
  
  -**tipoSB**:
      * Implementa a função obterInstrucaoTipoSB, responsável por converter e escrever instruções do tipo SB em binário no arquivo de saída.
      * Contém funções auxiliares para conversão de registradores e endereço do destino para binário, além da separação do endereço do destino em partes.
  
- **entrada.asm**: O arquivo de entrada contendo as instruções em linguagem de montagem a serem processadas.

- **saida/**: Esta pasta contém os arquivos de saída onde o código de máquina correspondente a cada instrução será gerado.
  
## Compilação e Execução
- **1º:** gcc -o main -Iinclude src/*.c main.c

- **2º:** ./main
