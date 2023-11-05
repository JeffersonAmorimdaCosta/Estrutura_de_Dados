typedef struct person {
    char name[30];
    int cpf;
    int age;
    char isPregnant[3];
} Person;

typedef struct node{
    Person person[30];
    struct node *next;
} Node;

typedef struct queue {
    Node *head;
    Node *end;
} Queue;

void start_Queue(Queue *fila); // Cria a fila
void display(Queue *fila); // Mostra a fila
int size_Queue(Queue *fila); // Mostra o tamanho da fila
int insert_Queue(Queue *fila, Person p); // Insere na fila
int remove_Queue(Queue *fila); // Remove da fila