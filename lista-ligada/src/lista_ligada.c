#include "lista_ligada.h" 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  

struct no {
    int dados; 
    No *proximo;  
};

No *criar_lista() {
   return NULL;
}

void destruir_recursivo_lista(No *ptr_no) {
    if (ptr_no != NULL) {
       destruir_recursivo_lista(ptr_no->proximo);
       free(ptr_no);          
    }
}

void destruir_interativo_lista(No **ptr_no) {
 
    No *ptr_no_aux;    
    while (*ptr_no != NULL) {
       ptr_no_aux = *ptr_no;
       *ptr_no = (*ptr_no)->proximo;
       free(ptr_no_aux);          
    }
}

void destruir_lista_ligada(No **ptr_no) {
    
    No *atual = *ptr_no;
    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *ptr_no = NULL;
    
}

void imprimir_recursivo_lista(const No *ptr_no) { 

    if (ptr_no != NULL ) {
        printf("%d -> ", ptr_no->dados);
        imprimir_recursivo_lista(ptr_no->proximo);
    }
    else 
        printf("NULL\n");
}

void imprimir_interativo_lista(No *ptr_no) { 
   
   
    /* 
    for ( ; ptr_no != NULL; ptr_no = ptr_no->proximo)
       printf("%d -> ", ptr_no->dados);
    printf("NULL\n\n"); 
    */

    //printf("Lista inicío \n");
    while (ptr_no != NULL) {
       printf("%d -> ", ptr_no->dados );
       //printf("atual: %p valor: %d próximo: %p \n", ptr_no, ptr_no->dados, ptr_no->proximo );

       ptr_no = ptr_no->proximo;

    }
    printf("NULL \n\n");    
    //printf("fim \n\n");
    
}   

void imprimir_lista(No *ptr_no) { 

    //imprimir_recursivo_lista_ligada(ptr_no);
    
    imprimir_interativo_lista(ptr_no);    

}

int tamanho_lista(const No *ptr_no) { 
    
    int tamanho = 0;
    const No *atual = ptr_no;
    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;

}

void adicionar_inicio_lista(No **ptr_ptr_no, int valor) {  //&l

    No *ptr_novo_no = ptr_novo_no = (No*) malloc(sizeof(No));

    if (ptr_novo_no == NULL) {
       perror("malloc");
       exit(EXIT_FAILURE);
    }
    ptr_novo_no->dados = valor;
    ptr_novo_no->proximo = *ptr_ptr_no;
    *ptr_ptr_no = ptr_novo_no;
} 

void adicionar_fim_lista(No **ptr_ptr_no, int valor) { 

    No *ptr_novo_no = (No*) malloc (sizeof(No));

    ptr_novo_no->dados = valor;
    ptr_novo_no->dados = NULL;

    if(ptr_novo_no == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    No *ptr_atual_no = *ptr_ptr_no;
    

} 

void adicionar_ordenado_lista(No **ptr_ptr_no, int valor) {

    No *novo_no = (No*) malloc(sizeof(No));
    novo_no->dados = valor;
    novo_no->proximo = NULL;

    if (*ptr_ptr_no == NULL) {
        *ptr_ptr_no = novo_no;
    } else if (valor <= (*ptr_ptr_no)->dados) {
        novo_no->proximo = *ptr_ptr_no;
        *ptr_ptr_no = novo_no;
    } else {
        No *anterior = *ptr_ptr_no;
        No *atual = anterior->proximo;
        while (atual != NULL && valor > atual->dados) {
            anterior = atual;
            atual = atual->proximo;
        }
        novo_no->proximo = atual;
        anterior->proximo = novo_no;
    }

} 

int remover_inicio_lista(No **ptr_ptr_no) {
 
     if (*ptr_ptr_no == NULL) {
        return -1; 
    }

    No *removido = *ptr_ptr_no;
    int valor = removido->dados;
    *ptr_ptr_no = removido->proximo;
    free(removido);

    return 1;
} 

int remover_fim_lista(No **ptr_ptr_no) {

   if (*ptr_ptr_no == NULL) {
        return -1; 
    }

    No *atual = *ptr_ptr_no;
    No *anterior = NULL;
    while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    int valor = atual->dados;
    if (anterior == NULL) {
        *ptr_ptr_no = NULL;
    } else {
        anterior->proximo = NULL;
    }
    free(atual);
   return 1;

} 

int remover_valor_lista(No **ptr_ptr_no, int valor) { 

    No *ptr_no_atual = *ptr_ptr_no;
    if (ptr_no_atual == NULL) 
       return 0;

    No *ptr_no_anterior;

    while ((ptr_no_atual != NULL) && (ptr_no_atual->dados != valor)) {
       ptr_no_anterior = ptr_no_atual;
       ptr_no_atual = ptr_no_atual->proximo;     
    }
    if (ptr_no_atual == NULL) 
        return 0;

    if (ptr_no_atual == *ptr_ptr_no) 
       *ptr_ptr_no = ptr_no_atual->proximo;
    else 
       ptr_no_anterior->proximo = ptr_no_atual->proximo; 
    
    free(ptr_no_atual);
    
    return 1;

} 

int buscar_valor_lista(No *ptr_ptr_no, int valor) {  // pode retornar a posição, caso o dado fosse um tipo composto retornariamos ele
   
    int index = 0;
    while (ptr_ptr_no != NULL) {
        if (ptr_ptr_no->dados == valor) {
            return index;
        }
        ptr_ptr_no = ptr_ptr_no->proximo;
        index++;
    }
   return -1;

}

int buscar_posicao_lista(No *ptr_ptr_no, int posicao) { //retornar o valor da posição
   int index = 0;
    while (ptr_ptr_no != NULL) {
        if (index == posicao) {
            return ptr_ptr_no->dados;
        }
        ptr_ptr_no = ptr_ptr_no->proximo;
        index++;
    }
   return -1;

}

