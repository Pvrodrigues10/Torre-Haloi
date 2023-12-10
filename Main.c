#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"



int main() {
    int estado = 1;    
    int discos = 0; 
    Pilha * A = criar();
    Pilha * B = criar();
    Pilha * C = criar();
    while(estado != 1000){
        switch(estado){
            case 1 :
                estado = inicializar(A, &discos);     
                break;
            case 2:
                mostrarPinos(A,B,C); 
            case 3 :
                mostrarPossibilidades(A,B,C);
            case 4 :                
                estado = movimentar(A, B, C);                
                break;            
            case 5 :
                if(tamanho(C) == discos){
                    estado = 6;
                }
                else{
                    estado = 2;   
                }
                break;  
            case 6 :
                terminar(A, B, C);
                estado = 1000;
                break;            
        }

    }
    printf("Parabens, voce venceu!!! Jogo finalizado!!");
}



