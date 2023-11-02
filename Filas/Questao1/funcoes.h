typedef struct node{
    char name[50];
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


void start_queue(orderQueue *order_queue, paymentQueue *payment_queue, collectQueue *collect_queue);
void display(orderQueue *queue);
int insert_orderQueue(orderQueue *queue, char name[]);
int remove_paymentQueue(paymentQueue *queue);
int remove_collectQueue(collectQueue *queue);