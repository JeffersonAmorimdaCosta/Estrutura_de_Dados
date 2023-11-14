typedef struct node{
    int data;
    struct node *next;

} Node;

typedef struct stack{
    Node *top;

} Stack;

void create(Stack *s); // Inicializa a pilha
int sizeStack(Stack *s); // Retorna o tamanho da pilha
int stackUp(Stack *s, int value); // Empilha um elemento
int unstack(Stack *s); // Desempilha
void displayTop(Stack *s); // Exibe o elemento que está no topo
void display(Stack *s); // Exibe a pilha inteira
int reverse(Stack *s); // Inverte a pilha
void toEmpty(Stack *s); // Esvazia a pilha
