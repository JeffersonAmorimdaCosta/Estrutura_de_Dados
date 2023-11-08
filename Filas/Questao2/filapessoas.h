typedef struct person {
    char name[30];
    char cpf[12];
    int age;
    char isPregnant[4];
} Person;

typedef struct node{
    Person person;
    struct node *next;
} Node;

typedef struct queue {
    Node *head;
    Node *end;
} Queue;

void start_Queue(Queue *queueNormal, Queue *queueElderly, Queue *queuePregnant); // Cria a queue
void display(Queue *queue, Queue *queueElderly, Queue *queuePregnant); // Mostra a queue
void display_first(Queue *queue, Queue *queueElderly, Queue *queuePregnant); // Mostra o primeiro da queue
int size_queue(Queue *queueNormal, Queue *queueAge, Queue *queuePreg); // Mostra o tamanho da queue
int insert_Queue(Queue *queue, Queue *queueElderly, Queue *queuePregnant, Person p); // Insere na queue
int remove_queue(Queue *queue, Queue *queueElderly, Queue *queuePregnant); // Remove da queue
