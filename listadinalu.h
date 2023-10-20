typedef struct student{
    int registration;
    char name[30];
    float grade1, grade2;

} Student;

typedef struct node{
    Student data;
    struct node *next;

} Node;

typedef struct list{
    Node *head;

} StudentList;

// Operações básicas:

void create(StudentList *st_list); // Cria a lista vazia
int size(StudentList *st_list); // Retorna o tamanho da lista
int empty(StudentList *st_list); // Retorna se a lista esta vazia
int serchposregist(StudentList *st_list, int regist, int *pos); // Pesquisa posição pela matrícula - retorna pelo ponteiro pos
int searchstudentpos(StudentList *st_list, int pos, Student *st); // Pesquisa aluno pela posição - retorna pelo ponteiro st
int insertend(StudentList *st_list, Student st); // Insere aluno no final da lista
int removestudentregist(StudentList *st_list); // Remove aluno da lista passando a matricula
void displaystudents(StudentList *st_list); // Exibe a lista de alunos

// Operações avançadas:
