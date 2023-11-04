typedef struct node{
    char name[30];
    struct node *next; 

} Node;

typedef struct order_queue{ // Fila de pedido
    Node *head;
    Node *end;

} orderQueue;

typedef struct payment_queue{ // Fila de pagamento
    Node *head;
    Node *end;

} paymentQueue;

typedef struct collect_queue{ // Fila de coletar a encomenda
    Node *head;
    Node *end;

} collectQueue;


void start_queue(orderQueue *order_queue, paymentQueue *payment_queue, collectQueue *collect_queue); // Cria as filas de pedido, pagamento e coletagem
void display_order(orderQueue *queue); // Mostra a fila de pedido
void display_payment(paymentQueue *queue); // Mostra a fila de pagamento
void display_collect(collectQueue *queue); // Mostra a fila de coletagem
int size_order(orderQueue *queue); // Mostra o tamanho da fila de pedido
int size_payment(paymentQueue *queue); // Mostra o tamanho da fila de pagamento
int size_collect(collectQueue *queue); // Mostra o tamanho da fila de coletagem
int insert_orderQueue(orderQueue *queue, char name[]); // Insere na fila de pedido
int remove_orderQueue(orderQueue *order, paymentQueue *payment); // Remove da fila de pedido
int remove_paymentQueue(paymentQueue *payment, collectQueue *collect); // Remove da fila de pagamento
int remove_collectQueue(collectQueue *collect, char *name_removed); // Remove da fila de coletagem