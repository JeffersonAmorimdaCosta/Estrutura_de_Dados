#include "filaprioridade.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void start_Queue(Queue *filaNormal, Queue *filaIdosos, Queue *filaGestantes) {
    /*
    Explicação: aqui as filas serã inicializadas, sendo declarados seus inícios e finais como NULL e seus 
    tamanhos como 0.
    */
    filaNormal->head = filaNormal->end = NULL;
    filaIdosos->head = filaIdosos->end = NULL;
    filaGestantes->head = filaGestantes->end = NULL;
    filaNormal->tamanho = 0;
    filaIdosos->tamanho = 0;
    filaGestantes->tamanho = 0;
}

int size_queue(Queue *queueNormal, Queue *queueAge, Queue *queuePreg) {
    /*
    Aqui, basicamente são utilizados os tamanhos armazenados nas filas, sendo somados e retornando
    como uma só variável.
    */
    int cont = 0;

    cont = queueNormal->tamanho + queueAge->tamanho + queuePreg->tamanho;

    return cont;
}

int insert_Queue(Queue *filaNormal, Queue *filaIdosos, Queue *filaGestantes, Person p) {
    /*
    Aqui, primeiramente como eu não quero deixar o IF muito grande, coloquei já para toda a string ser 
    maiúscula com o toupper. Segue o funcionamento do restante:
    - No primeiro caso, a função analisará se a pessoa inserida é gestante. Caso seja, será utilizada a
    função de inserir gestantes e, caso retorne 1, a inserção foi um sucesso. Isso se repetirá no segundo IF
    onde caso não seja gestante, será analisado se a pessoa é idosa, entrando na função especificada para
    inserção de idosos caso seja. Se não se enquadrar em nenhum dos casos, será inserido na fila normal, com
    a rotina já conhecida. Ao fim, em todos os casos o tamanho da fila respectiva será incrementado.
    */
    for(int i = 0; p.isPregnant[i]; i++) {
      p.isPregnant[i] = toupper(p.isPregnant[i]);
    }

    if(strcmp(p.isPregnant, "SIM") == 0) {
        if(insert_preg(filaGestantes, p) == 1) {
            filaGestantes->tamanho++;
            return 1;
        }
    }
    if(p.age >= 65) {
        if(insert_age(filaIdosos, p) == 1) {
            filaIdosos->tamanho++;
            return 1;
        }
    }
    if (strcmp(p.isPregnant, "NAO") == 0 && p.age < 65) {
        Node *new_node = (Node*) malloc(sizeof(Node));
        new_node->next = NULL;

        if(new_node == NULL) {
            return 0;
        }

        strcpy(new_node->person.name, p.name);
        strcpy(new_node->person.isPregnant, p.isPregnant);
        new_node->person.age = p.age;
        strcpy(new_node->person.cpf, p.cpf);

        if (size_queue(filaNormal, filaIdosos, filaGestantes) == 0) {
            filaNormal->head = filaNormal->end = new_node;
            filaNormal->tamanho++;
            return 1;
        }

        filaNormal->end->next = new_node;
        filaNormal->end = new_node;
        filaNormal->tamanho++;
        return 1;
    }
}

void display_first(Queue *fila, Queue *filaIdosos, Queue *filaGestantes) {
  /*
  A lógica dessa função é bem simples: se houver pessoas na fila de gestantes, imprime-se os dados do "head"
  da fila de gestantes. Se não houverem gestantes, então será printado o "head" da fila de idosos, e caso os
  primeiros casos não sejam verdadeiros, printará o "head" da fila normal.
  */
  if(size_preg(filaGestantes) > 0) {
    printf("CPF: %s\n", filaGestantes->head->person.cpf);
    printf("Nome: %s\n", filaGestantes->head->person.name);
    printf("Idade: %d\n", filaGestantes->head->person.age);
    printf("Gestante: %s\n", filaGestantes->head->person.isPregnant);
  }
  else if(size_age(filaIdosos) > 0 ) {
    printf("CPF: %s\n", filaIdosos->head->person.cpf);
    printf("Nome: %s\n", filaIdosos->head->person.name);
    printf("Idade: %d\n", filaIdosos->head->person.age);
    printf("Gestante: %s\n", filaIdosos->head->person.isPregnant);
  }
  else if(size_queue(fila, filaIdosos, filaGestantes) > 0) {
    printf("CPF: %s\n", fila->head->person.cpf);
    printf("Nome: %s\n", fila->head->person.name);
    printf("Idade: %d\n", fila->head->person.age);
    printf("Gestante: %s\n", fila->head->person.isPregnant);
  }
}

void display(Queue *filaNormal, Queue *filaIdosos, Queue *filaGestantes) {
  /*
  Aqui, defini um counter para me ajudar a enumerar as pessoas da fila. Após isso, declarei uma
  variável auxiliar para percorrer a fila. Então, para que pudesse de forma correta printar o necessário,
  utilizei um for para percorrer todas as três listas, printando todos os nomes que estão dentro delas.
  Para que estivesse tudo na ordem correta, primeiro foi a lista de gestantes, depois a de idosos e por fim
  a normal.
  */
  
  int counter = 1;
  Node *aux;

  for(aux = filaGestantes->head; aux != NULL; aux = aux->next, counter++) {
    printf("%d. %s\n", counter, aux->person.name);
  }
  for(aux = filaIdosos->head; aux != NULL; aux = aux->next, counter++) {
    printf("%d. %s\n", counter, aux->person.name);
  }
  for(aux = filaNormal->head; aux != NULL; aux = aux->next, counter++) {
    printf("%d. %s\n", counter, aux->person.name);
  }
}

int remove_queue(Queue *fila, Queue *filaIdosos, Queue *filaGestantes) {
  /*
  Seguindo a lógica que fiz no display, aqui acontece o seguinte: se o tamanho da lista de gestantes
  for maior que 0, então será removido o primeiro dessa fila através da função especificada para
  essa fila, decrementando o tamanho da mesma.
  Isso se aplicará para as seguintes: se não for gestante e tiver mais de 65 anos, o mesmo funcionamento
  valerá para a fila de idosos, e caso não atenda nenhum dos dois casos, será feito a operação normal de
  remoção na fila normal.
  */

  if(size_preg(filaGestantes) > 0) {
    if(remove_preg(filaGestantes) == 1) {
        filaGestantes->tamanho--;
        return 1;
    }
  }
  else if(size_age(filaIdosos) > 0) {
    if(remove_age(filaIdosos) == 1) {
        filaIdosos->tamanho--;
        return 1;
    }
  }
  else if(size_age(filaIdosos) == 0 && size_preg(filaGestantes) == 0) {
    if (size_queue(fila, filaIdosos, filaGestantes) == 0) {
      return 0;
    }
    Node *temp = fila->head;
    fila->head = fila->head->next;
    free(temp);
    fila->tamanho--;
    return 1;
  }
}
