#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada_03.h"


//Sempre se atende aos '*'
// NoSimples* -> lista
// NoSimples** -> &lista (dois asterisco eu preciso pegar a referencia)

int main() {
    NoSimples* lista = NULL;

    //Inserir no inicio e fim
    ls_inserir_inicio(&lista, 10);
    ls_inserir_fim(&lista, 20);
    ls_inserir_fim(&lista, 20);
    ls_inserir_fim(&lista, 30);
    ls_inserir_fim(&lista, 30);

    //Exibir
    ls_exibir(lista);
    
    //Buscar
    int x = 20;
    NoSimples* achado = ls_buscar(lista, x);
    printf("\nBusca por %d: %s\n", x, achado ? "encontrado" : "nao encontrado");
    
    //atualizar (se encontrar o 20 ele atualiza)
    if(ls_atualizar_primeiro(lista, 20, 50)) {
        printf("Primeiro valor atualizado\n");
        ls_exibir(lista);
    }    

    //Remover (se encontrar o 30 remove)
    if(ls_remover_valor(&lista, 30)) {
        printf("\nRemover primeiro valor encontrado\n");
        ls_exibir(lista);
    }


    //Limpar
    ls_limpar_lista(&lista);
    printf("\nLista vazia! -> ");
    ls_exibir(lista);

    return 0;
}