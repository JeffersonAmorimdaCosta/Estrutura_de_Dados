typedef struct node{
    char name[30];
    struct node *next; 

} Node;

typedef struct queue{ // Fila de pedido
    Node *head;
    Node *end;

} Queue;

void start_queue(Queue *order_queue, Queue *payment_queue, Queue *collect_queue); // Cria as filas de pedido, pagamento e coletagem
void display(Queue *queue); // Mostra a fila de pedido
int size_queue(Queue *queue); // Mostra o tamanho da fila de pedido
int insert_orderQueue(Queue *queue, char name[]); // Insere na fila de pedido
int remove_queue(Queue *previousQueue, Queue *nextQueue); // Remove de uma fila e coloca em outra (proxima)
int remove_collectQueue(Queue *collect, char *name_removed); // Remove da fila de coletagem