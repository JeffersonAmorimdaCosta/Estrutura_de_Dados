typedef struct person {
    char name[30];
    int cpf;
    int age;
    char isPregnant[3];
} Person;

typedef struct node{
    Person person;
    struct node *next;
} Node;

