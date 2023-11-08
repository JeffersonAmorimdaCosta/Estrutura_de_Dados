typedef struct person {
    char name[30];
    long cpf;
    int age;
    char isPregnant[3];
} Person;

typedef struct node{
    Person person;
    struct node *next;
} Node;

typedef struct queue {
    Node *head;
    Node *end;
} Queue;

void start_Queue(Queue *filaNormal, Queue *filaIdosos, Queue *filaGestantes); // Cria a fila
void display(Queue *fila, Queue *filaIdosos, Queue *filaGestantes); // Mostra a fila
void display_first(Queue *fila, Queue *filaIdosos, Queue *filaGestantes);
int size_queue(Queue *queueNormal, Queue *queueAge, Queue *queuePreg); // Mostra o tamanho da fila
int insert_Queue(Queue *fila, Queue *filaIdosos, Queue *filaGestantes, Person p); // Insere na fila
int remove_queue(Queue *fila, Queue *filaIdosos, Queue *filaGestantes); // Remove da fila
