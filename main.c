 #include <stdio.h>
 #include <stdlib.h>
 #include "methods.h"

  int main(){

    Lista* lista;
    
    lista = criarLista();

    int respostaVazia = verificarVazia(lista);
    printf("Verificar se esta vazia: %d", respostaVazia);


    lista = inserirLista(lista, 28);
    lista = inserirLista(lista, 13);



    lista = inserirLista(lista, 11);
    imprimirLista(lista);

    respostaVazia = verificarVazia(lista);
    printf("Verificar se esta vazia apos inserçao: %d", respostaVazia);

    return 0;
 }