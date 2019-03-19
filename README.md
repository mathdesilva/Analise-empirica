# ANÁLISE EMPÍRICA DE ALGORITMOS DE BUSCA
Este é um projeto da matéria de Estrutura de Dados Básicas I com a finalidade de testar os algoritmos de busca mais comuns para arranjos ordenados.

**Aluno:**
* Matheus de Andrade Silva

## Como compilar:
Será necessário para a compilação do programa:
* `make`
* `g++`

Para compilar basta clonar o repositório, entrar no diretório raiz do projeto e digitar no terminal:

`make`

Para rodar o programa use:
`./bin/analiseEmpirica`

Para deletar os arquivos gerados na compilação use:

`make clear`

Para deletar os arquivos gerados na execução do programa use:

`make cleardata`

## Como usar:
Em `>>> Set the number of tests [30:100]` defina o número de testes que será executado nos algoritmos.

Em `>>> Set the algorithms index` defina os index [1:7] dos algoritmos que deseja testar. Exemplos de entradas válidas:
* `3`
* `1 2 3 5`
* `5 3 1`
* `1235`
* `1523`
* `111222333555`

Ao final de cada teste o programa gera dois arquivos `.txt` na pasta `data`, um com as informações de tempo de execução e outro com informações sobre quantidade de passos. É gerado dois arquivos por algoritmo.

## Tratamento de erros:
O programa foi programado para rodar se o computador conseguir alocar entre 100.000.000 (Cem milhões) e 500.000.0000 (Quinhentos milhões) de long int's, ele sempre tentará alocar o máximo entre esse intervalo.

As entradas foram tratadas para só aceitar o que foi pedido, usando sempre a função `getline()` para pegar toda a linha de entrada.

Se tiver alguma falha em alocar o arranjo ou erro na entrada, o programa vai desalocar todo o arranjo alocado antes de terminar a execução.

## Limitações:
O programa não possui suporte para personalizar o intervalo de elementos para testes.

Também não é possível mudar o valor a ser buscado nos algoritmos, assumindo sempre o pior caso de cada.

## Algoritmos testados:
Todos os algoritmos implementados possuem os mesmos argumentos de entrada: arranjo; index do começo do intervalo de busca; index do final do intervalo de busca; valor a ser procurado; contador de passos. 

`int algoritmo(long int arr[], int l, int r, long int value, long int &stepcounter)`

Os seguintes algoritmos foram implementados:
* Busca linear iterativa
* Busca binária iterativa
* Busca binária recursiva
* Busca ternária iterativa
* Busca ternária recursiva
* Jump Search
* Busca Fibonacci