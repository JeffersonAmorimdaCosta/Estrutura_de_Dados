#include "filapessoas.h"

int insert_by_age(Queue *filaprIdosos, Person p);
int remove_by_age(Queue *filaprIdosos);
int insert_by_preg(Queue *filaprGestantes, Person p);
int remove_by_preg(Queue *filaprGestantes);
void display_by_age(Queue *filaprIdosos);
void display_by_Preg(Queue *filaprGestantes);
int size_Queue_age(Queue *filaprIdosos);
int size_Queue_preg(Queue *filaprGestantes);