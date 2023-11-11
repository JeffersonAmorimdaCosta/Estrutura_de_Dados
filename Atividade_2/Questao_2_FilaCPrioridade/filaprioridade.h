#include "filapessoas.h"

int size_preg(Queue *queuePregnant); // Mostra a quantidade de pessoas na fila de gestantes
int size_age(Queue *queueAge); // Mostra a quantidade de pessoas na fila de idosos
int insert_preg(Queue *queuePreg, Person p); // Insere na fila de gestantes
int insert_age(Queue *queueAge, Person p); // Insere na fila de idosos
int remove_preg(Queue *queuePreg); // Remove o primeiro na fila de gestantes 
int remove_age(Queue *queueAge); //Remove o primeiro na fila de idosos
