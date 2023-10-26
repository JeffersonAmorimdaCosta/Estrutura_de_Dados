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
int size_list(StudentList *st_list); // Retorna o tamanho da lista
int empty(StudentList *st_list); // Retorna se a lista esta vazia
int searchPosRegist(StudentList *st_list, int regist, int *pos); // Pesquisa posição pela matrícula - retorna pelo ponteiro pos
int searchStudentPos(StudentList *st_list, int pos, Student *st); // Pesquisa aluno pela posição - retorna pelo ponteiro st
int insertEnd(StudentList *st_list, Student st); // Insere aluno no final da lista
int removeStudentRegist(StudentList *st_list, int regist); // Remove aluno da lista passando a matricula
void displayStudents(StudentList *st_list); // Exibe a lista de alunos

// Operações avançadas:

int insertStudentPos(StudentList *st_list, Student st, int pos); // Inserir um aluno numa posicao
int insertSortLowerId(StudentList *st_list, int regist); // Inserir um aluno com matricula menor ficando antes de matricula de maior valor
int removeStudentPos(StudentList *st_list, int pos); // Remover um aluno em uma posicao especifica
int schStudentNameEnrollment(StudentList *st_list, void *data, int type); // Pesquisar um aluno pela matricula ou pelo nome se pesquisar por nome e tiver mais de um aluno com os mesmo nome mostrar o dado de todos, tipo = 0 (matricula), tipo = 1 (nome)