#include "lista_encadeada_03.h"
#include <stdio.h>
#include <stdlib.h>

//static -> limita a função para esse arquivo (Essa função não pode ser chamada de outro arquivo / Ela não aparece no .h)
//Cria um novo nó da lista, inicializado corretamente, e devolve um ponteiro para ele.
//Ela sera usada internamente com as funções que estão na interface .h
static  NoSimples* ls_cria_no(int valor) {

    //Alocação dinamica(Como não sei quantos nós vai ter eu faço essa alocação dinamica)
    //O cast (NoSimples*) é opcional em C, mas comum em códigos didáticos.
    //malloc reserva memória no heap
    NoSimples* n = (NoSimples*) malloc(sizeof(NoSimples));

    //Caso aconteça erro (Se malloc falhar, retorna NULL)
    //!n é o mesmo que n == NULL
    if(!n) {
        //stderr → saída de erro
        fprintf(stderr, "Erro: Sem memoria ao criar o nó");

        //exit(EXIT_FAILURE) encerra o programa imediatamente
        exit(EXIT_FAILURE);
    }
    //dado recebe o valor passado
    n->dado = valor;

    //o nó ainda não aponta para ninguém
    n->proximo = NULL;

    return n;
}

/*
Sem essa função eu teria esse código espalhado por diversos arquivos
NoSimples* n = malloc(sizeof(NoSimples));
if (!n) { ... }
n->dado = valor;
n->proximo = NULL;


Como ela é usada na prática (A função só cria, não decide onde entra)
Exemplo:
void ls_inserir_inicio(NoSimples** head, int valor) {
    NoSimples* novo = ls_cria_no(valor);
    novo->proximo = *head;
    *head = novo;
}
*/

/*
Diferença real entre malloc e calloc

<malloc> :
NoSimples* n = malloc(sizeof(NoSimples));
- Reserva memória
- Não inicializa → pode conter lixo
- Mais rápido (não zera memória)
- Você define explicitamente os valores


<calloc> :
NoSimples* n = calloc(1, sizeof(NoSimples));
- Reserva memória
- Zera todos os bytes (0x00)
- Ponteiros → NULL
- Inteiros → 0
- Um pouco mais lento (tem que zerar)

Então por que muitos usam malloc?
- Inicialização explícita é mais clara
n->dado = valor;
n->proximo = NULL;
- Quem lê o código entende exatamente o estado inicial do nó.
Com calloc, o NULL fica implícito.

- calloc pode esconder bugs
Exemplo clássico:
n->proximo = outro_no; // esqueci isso
Com calloc → funciona “por acaso”
Com malloc → bug aparece cedo (melhor!)
- Em C, bugs que aparecem cedo são bons bugs.

- Performance (em estruturas grandes)
calloc sempre faz um memset
Em listas pequenas → irrelevante
Em estruturas grandes / loops → diferença real
Por isso, bibliotecas padrão costumam usar malloc.


Quando calloc faz sentido? ✅
Use calloc quando:
✔️ Você quer tudo zerado por padrão
✔️ A struct tem muitos campos
✔️ Zero é um estado válido inicial
✔️ O custo extra não importa

Quando malloc é melhor? ✅
Use malloc quando:
✔️ Você vai inicializar tudo manualmente
✔️ Quer evitar dependência de valores implícitos
✔️ Quer detectar erros cedo
✔️ Está estudando estrutura de dados (seu caso)
*/


//Iniciando a construção da lista e inserindo no inicio
void ls_inserir_inicio(NoSimples** head, int valor) {

    //criando o nó
    NoSimples* n = ls_cria_no(valor);

    //Fazendo com que o nó aponte para o head
    n->proximo = *head;

    //atualizar o head para o novo nó
    *head = n;
}


void ls_inserir_fim(NoSimples** head, int valor) {

    //criando o nó
    NoSimples* n = ls_cria_no(valor);

    //verificar o primeiro elemento da lista
    if(*head == NULL) {
        //Caso estiver null (vazia)
        *head = n;

        //returno pra ele não percorrer algo que nao existe
        return;
    }

    //Caso a lista não estiver vazia eu vou percorrer ela
    //Pegando referencia do primeiro nó
    NoSimples* p = *head;
    while(p->proximo != NULL) { //Aqui eu verifico se nao e o ultimo elemento
        p = p->proximo;
    }

    p->proximo = n;
}

//Busca
NoSimples* ls_buscar(NoSimples* head, int valor) {

    //referencia
    NoSimples* p = head;

    //NULL -> Enquanto a lista nao estiver vazia
    while(p != NULL) {
        if(p->dado == valor) {
            //Caso encontrar o dado que estou buscando ele retorna ele
            return p;
        }
        
        //Caso ainda nao achou o dado que estou buscando ele vai para o proximo
        p = p->proximo;
    }
    
    //Caso sair do while ele nao existe então é NULL
    return NULL;
}

bool ls_atualizar_primeiro(NoSimples* head, int valorAntigo, int valorNovo) {
    //criando o nó
    NoSimples* n = ls_buscar(head, valorAntigo);

    //Caso não encontrar o nó
    if(!n) {
        return false;
    }

    //Caso encontrar o dado ele atualiza com o valorNovo
    n->dado = valorNovo;

    return true;
}

bool ls_remover_valor(NoSimples** head, int valor) {

    //referencia do 1 elemento
    NoSimples* p = *head;

    //armazena o nó anterior
    NoSimples* anterior = NULL;

    //Caso a lista seja vazia ou o dado é diferente do valor do parametro
    while(p != NULL && p->dado != valor) {
        //atualizo o anterior com o nó atual
        anterior = p; //(se eu remove o 1 elemento aqui ele nem é atualizado)

        //Atualizando o p (continua)
        p = p->proximo;
    }

    if(p == NULL) {
        //p é nullo
        return false;
    }

    //o p não é null e o elemento de remoção da no 1 elemento da lista
    if(anterior == NULL) {
        //vou indica que o 2 elemento é o 1 elemento da lista
        *head = p->proximo;
    } else {
        anterior->proximo = p->proximo;
        //1(anterior) - 2(p) - 3
        //vou atualizar o anterior para pegar o '3' que é o proximo de p
    }

    //liberar memoria do removido
    free(p);

    return true;
}

void ls_exibir(const NoSimples* head) {
    const NoSimples* p = head;

    while(p != NULL) {
        printf("%d -> ", p->dado);
        p = p->proximo;
    }

    printf("NULL");
}

void ls_limpar_lista(NoSimples** head) {
     NoSimples* p = *head;

     while (p != NULL)
     {
        //criando ponteiro dentro para manter a informação do proximo para poder liberar e informação do ponteiro atual
        NoSimples* armazenarProximo = p->proximo;

        free(p);

        //atualuzar o p com a referencia do proximo
        p = armazenarProximo;
     }

     *head = NULL;     
}