typedef struct pilha Pilha;

Pilha * criar();
void destruir(Pilha * p);
int desempilhar(Pilha * p); // ou pop
void empilhar(Pilha * p, int x); // ou push
int tamanho(Pilha * p);
int topo(Pilha * p);
void imprimir(Pilha * p);
int inicializar(Pilha * pino1, int * discos);  
void terminar(Pilha * pino1, Pilha * pino2, Pilha * pino3);
int movimentar(Pilha * pino1, Pilha * pino2, Pilha * pino3);
int mover(Pilha * origem, Pilha * destino);
void mostrarPinos(Pilha * pino1, Pilha * pino2, Pilha * pino3);
void mostrarPossibilidades(Pilha * pino1, Pilha * pino2, Pilha * pino3);