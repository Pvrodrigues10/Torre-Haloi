#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

#define TAM_MAX 100

struct pilha {
  int itens[TAM_MAX];
  int tp; 
};

Pilha * criar() {
  Pilha * p = (Pilha *)malloc(sizeof(Pilha));
  p->tp = 0;
  return p;
}

void destruir(Pilha * p) {
  if (p != NULL) {
    free(p);
  }
}

int desempilhar(Pilha * p) {
  if (p->tp == 0) {
    printf("Pilha vazia");
    return -1;
  }
  return p->itens[--p->tp];
}

void empilhar(Pilha * p, int x) {
  if (p->tp == TAM_MAX) {
    printf("Pilha Cheia!");
    return;
  }
  p->itens[p->tp++] = x;
}

int tamanho(Pilha * p) {
  return p->tp;
}

int topo(Pilha * p) {
  if (p->tp == 0) {
    //printf("Pilha vazia");
    return -1;
  }
  return p->itens[p->tp-1];
}

void imprimir(Pilha * p) {
  int i;
  printf("[ ");
  for(i=0; i<p->tp; i++) {
    printf("%d ", p->itens[i]);
  }
  printf("]\n");
}


int inicializar(Pilha * pino1, int * discos){    
    printf("\nTorre de Hanoi, Desenvolvido por Paulo Vitor, Peddro Reimberg, Amon Lemes\n");
	printf("Regras:\n1- Apenas um numero pode ser movido por vez\n2- Nunca um numero maior deve ficar por cima de um numero menor\n3- O jogo termina apenas quando mover todos os numeros para a pilha C");
    printf("\nVoce quer jogar com quantos discos?\n");
    scanf("%d", discos);
    if(*discos < 0){
        return 1;
    }
    int aux = *discos;
    while(aux > 0){
        empilhar(pino1, aux);    
        aux = aux - 1;    
    }
    return 2;
}
void terminar(Pilha * pino1, Pilha * pino2, Pilha * pino3){
    destruir(pino1);
    destruir(pino2);
    destruir(pino3);
}

int movimentar(Pilha * pino1, Pilha * pino2, Pilha * pino3){    
    char movimento[3] = {0,0,'\0'};
    printf("Digite o proximo movimento: \n");
    scanf(" %c%c", movimento, movimento + 1);
    switch(movimento[0]){
        case 'A':
            switch(movimento[1]){
                case 'B':
                    if(mover(pino1, pino2) == 0)
                        return 4;
                    break;
                case 'C':
                    if(mover(pino1, pino3) == 0)
                        return 4;
                    break;
                default:
                    printf("Movimento invalido!\n");
                        return 4;
            }
            break;
        case 'B':
            switch(movimento[1]){
                case 'A':
                    if(mover(pino2, pino1) == 0)
                        return 4;
                    break;
                case 'C':
                    if(mover(pino2, pino3) == 0)
                        return 4;
                    break;
                default:
                    printf("Movimento invalido!\n");
                    return 4;
            }
            break;
        case 'C':
            switch(movimento[1]){
                case 'A':
                    if(mover(pino3, pino1) == 0)
                        return 4;
                    break;
                case 'B':
                    if(mover(pino3, pino2) == 0)
                        return 4;
                    break;
                default:
                    printf("Movimento invalido!\n");
                    return 4;
                }
                break;
        default:
            printf("Movimento invalido!\n");
            return 4;
            break;         
    }
    return 5;
}

int mover(Pilha *origem, Pilha *destino){    
    if(tamanho(origem) > 0 && (tamanho(destino) <= 0 || topo(origem) < topo(destino))){
        empilhar(destino,desempilhar(origem));
        return 1;
    }
    else {
        printf("Nao e possivel fazer este movimento.\n");
        return 0;
    }
}

void mostrarPinos(Pilha * pino1, Pilha * pino2, Pilha * pino3){
    printf("A: ");
    imprimir(pino1);
    printf("B: ");
    imprimir(pino2);
    printf("C: ");
    imprimir(pino3);
}

void mostrarPossibilidades(Pilha * pino1, Pilha * pino2, Pilha * pino3){
    printf("Voce pode fazer esses movimentos: ");
    if((topo(pino1) < topo(pino2) || tamanho(pino2) == 0) && tamanho(pino1) > 0){
            printf(" AB ");
    }
    if((topo(pino1) < topo(pino3) || tamanho(pino3) == 0) && tamanho(pino1) > 0){
            printf(" AC ");
    }
    if((topo(pino2) < topo(pino1) || tamanho(pino1) == 0) && tamanho(pino2) > 0){
            printf(" BA ");
    }
    if((topo(pino2) < topo(pino3) || tamanho(pino3) == 0) && tamanho(pino2) > 0){
            printf(" BC ");        
    }
    if((topo(pino3) < topo(pino1) || tamanho(pino1) == 0) && tamanho(pino3) > 0){
            printf(" CA ");
    }
    if((topo(pino3) < topo(pino2) || tamanho(pino2) == 0) && tamanho(pino3) > 0){
            printf(" CB ");
    }
    printf("\n");
}