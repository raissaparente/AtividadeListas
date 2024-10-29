 #include <stdio.h>
 #include <stdlib.h>

// Atividade 01 - Estrutura de Dados em C
// Raissa Parente | 24.10.2024

//Estrutura Lista
typedef struct lista {
    int info;
    struct lista *prox; //ponteiro p/ prox no
}Lista;

//Declaracao funcoes
Lista* criarLista();
Lista* inserirLista(Lista *lista, int index);
void exibirLista(Lista *lista); //para verificacao
int verificarVazia(Lista *l);
Lista* buscarLista(Lista *lista, int valor);
Lista* excluirLista(Lista *lista, int valor);
void liberarLista(Lista *lista);
Lista* inserirCrescente(Lista *lista, int info);


Lista* criarLista() {
    return NULL; //lista vazia, ponteiro NULL
}

Lista* inserirLista(Lista *lista, int valor) {
    Lista* novoElemento = (Lista*) malloc(sizeof(Lista)); //aloca espaco p/ elemento
    
    novoElemento->info = valor;
    novoElemento->prox = lista;

    return novoElemento; //ponteiro
}


void exibirLista(Lista *lista) {
    Lista *aux;
    for(aux = lista; aux != NULL; aux = aux->prox) {
        printf("%d\n", aux->info);
    }
}

int verificarVazia(Lista *lista) {
    if(lista == NULL) {
        return 1;
    } else {
        return 0;
    }
}

Lista* buscarLista(Lista *lista, int valor) {
    Lista *aux;
    for(aux=lista; aux != NULL; aux = aux->prox) {
        if(aux->info == valor) {
            return aux;
        }
    }
    return NULL;
}

Lista* excluirLista(Lista *lista, int valor) {
    Lista *ponteiroAnterior = NULL;
    Lista *ponteiroAux;

    //procura elemento e guarda anterior
    while(ponteiroAux != NULL && ponteiroAux->info != valor) {
        ponteiroAnterior = ponteiroAux; //guarda anterior
        ponteiroAux = ponteiroAux->prox; //passa
    }

    //se a lista nao tiver o elemento para aqui
    if(ponteiroAux == NULL) {
        return lista;
    }

    if(ponteiroAnterior == NULL) { 
        //ponteiroAuxiza o segundo ponteiro para ser o primero, "eliminando" o primeiro elemento
        lista = ponteiroAux->prox;
    } else {
        //pula o ponteiro do elemento encontrado, retirando ele do meio da lista
        ponteiroAnterior->prox = ponteiroAux->prox;
    }

    free(ponteiroAux);
    return lista;
}

void liberarLista(Lista *lista) {
    Lista *ponteiroAux = lista;

    while (ponteiroAux != NULL) {
       Lista *proximoPonteiro = ponteiroAux->prox;
       free(ponteiroAux);
       ponteiroAux = proximoPonteiro;
    }
}

Lista* inserirCrescente(Lista *lista, int valor) {
    Lista *novoElemento = (Lista*) malloc(sizeof(Lista));
    novoElemento->info = valor;

    //insere no inicio se: lista for vazia
    //ou se ele for o menor que o primeiro 
    if (lista == NULL || lista->info > valor) {
        novoElemento->prox = lista;
        return novoElemento;
    }

    Lista *ponteiroAux = lista;
    // percorre procurando a posicao
    while (ponteiroAux->prox != NULL && ponteiroAux->prox->info < info) {
        ponteiroAux = ponteiroAux->prox;
    }

    // faz o novo elemento apontar para o local que achou no while, inserindo o novo na lista
    novoElemento->prox = ponteiroAux->prox;
    ponteiroAux->prox = novoElemento;

    return lista;
}
