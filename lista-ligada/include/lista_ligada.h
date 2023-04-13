#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h> 


typedef struct no No;

No* criar_lista();
void destruir_lista(No **ptr_ptr_no);

int tamanho_lista(const No *ptr_no);

void imprimir_lista(No *ptr_no);

void adicionar_inicio_lista(No **ptr_ptr_no, int valor); 
void adicionar_fim_lista(No **p, int valor); 
void adicionar_ordenado_lista(No **ptr_ptr_no, int valor); 

int remover_inicio_lista(No **ptr_ptr_no); // 0 não removeu e 1 removeu
int remover_fim_lista(No **ptr_ptr_no); 
int remover_valor_lista(No **ptr_ptr_no, int valor); 

int buscar_valor_lista(No *ptr_no, int valor);
int buscar_posicao_lista(No *ptr_no, int posicao);
