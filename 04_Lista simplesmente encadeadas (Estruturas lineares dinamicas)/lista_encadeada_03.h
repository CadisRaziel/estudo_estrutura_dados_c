#ifndef lista_encadeada_03
#define lista_encadeada_03
#include <stdbool.h> //Booleanos no C (pois C não possui isso nativo)

//Aqui no .h vai ter structs e interface pra funções

typedef struct NoSimples
{
    int dado;
    struct NoSimples* proximo;   
} NoSimples;

//Inserir na lista
//Inserir no inicio -> O(1)
//Inserir no fim -> O(n)*
void ls_inserir_inicio(NoSimples** head, int valor);
void ls_inserir_fim(NoSimples** head, int valor);

//Funcao de buscar (repare que como não vou alterar nada eu só utilizo um ponteiro *)
//O(n)
NoSimples* ls_buscar(NoSimples* head, int valor);

//Atualizar a função com um novo valor que conter o 'valorAntigo' ou seja valorAntigo = 5 (ele vai pegar o 5 e atualizar com o meu valorNovo) OBS: vai pegar o primeiro que encontar!!
//O(n)
bool ls_atualizar_primeiro(NoSimples* head, int valorAntigo, int valorNovo);

//Remover um dado da minha lista (como vou alterar preciso usar dois ponteiro **)
//O(1)
bool ls_remover_valor(NoSimples** head, int valor);

//Exibir todas informações da lista
//O(n)
void ls_exibir(const NoSimples* head);

//Limpar a struct (como vou alterar tenho que usar dois ponteiro **)
void ls_limpar_lista(NoSimples** head);

//** -> se eu por apenas 1 * ele só muda a copia local dentro da função (ls_inserir_inicio)
//** -> altera o ponteiro real que esta no main
//* → aponta para um nó
//** → aponta para o ponteiro do nó
//Usamos ** para modificar head ou tail fora da função que esta no .h
#endif

/*
#include "lista.h"
#include "outra_coisa.h" // que também inclui lista.h

Se o mesmo .h for processado duas vezes, o compilador pode gerar erros como:
redefinição de structs
redefinição de funções
redefinição de macros
-> #ifndef + #define evitam isso

#ifndef -> If Not Defined/Se NÃO estiver definido
#ifndef 03_lista_encadeada_H
Ou seja:
“Se 03_lista_encadeada_H ainda não foi definido, execute o código abaixo.”

Objetivo -> Evitar inclusão múltipla de .h

*/