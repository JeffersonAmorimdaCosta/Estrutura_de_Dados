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
void display_order(orderQueue *queue);
void display_payment(paymentQueue *queue);
void display_collect(collectQueue *queue);
int empty_order(orderQueue *queue);
int empty_payment(paymentQueue *queue);
int empty_collect(collectQueue *queue);
int insert_orderQueue(orderQueue *queue, char name[]);
int remove_orderQueue(orderQueue *order, paymentQueue *payment);
int remove_paymentQueue(paymentQueue *payment, collectQueue *collect);
int remove_collectQueue(collectQueue *queue);