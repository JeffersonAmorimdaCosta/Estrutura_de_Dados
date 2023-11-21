// número máximo de nós na fila
#define MAX 8

// Definição da estrutura Fila Seq. Circular

typedef struct filacircular {
  int elementos[MAX]; // vetor que vai armazenar os elementos
  int inicio; // variável usada para controlar o início (posição) da fila
  int fim;    // variável usada para controlar o final (posição) da fila
  int tam;    // número de elementos na fila
} FilaSeqCir;

//************ A interface de uso do TAD Fila Seq. Circular **********//

/* Criar uma fila sequencial circular vazia */
void criarFila(FilaSeqCir *f);

/* Verificar se a fila circular está vazia */
int filaVazia(FilaSeqCir *f);

/* Verificar se a fila circular está cheia */
int filaCheia(FilaSeqCir *f);

/* Consultar o elemento que está no início da fila circular */
/*Parâmetros: a fila passada por referência e um * ponteiro "de retorno" que
 * guardará o primeiro da fila*/
int primeiro(FilaSeqCir *f, int *valor);

/* Consultar o elemento que está no fim da fila circular */
/*Parâmetros: a fila passada por referência e um * ponteiro "de retorno" que
 * guardará o ultimo da fila*/
int ultimo(FilaSeqCir *f, int *valor);

/* Inserir (enfileirar/entrar) um elemento na fila circular */
int entrar(FilaSeqCir *f, int elemento);

/* Retirar (desenfileirar/sair) um elemento da fila circular */
/*Parâmetros: a fila passada por referência e um * ponteiro "de retorno" que
 * guardará o elemento que saiu da fila*/
int sair(FilaSeqCir *f, int *valor);

/* Exibir o conteúdo da fila circular */
void exibir(FilaSeqCir *f);