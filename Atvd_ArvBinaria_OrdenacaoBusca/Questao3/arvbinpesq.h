typedef struct funcionario{
    char nome[50];
    float valor_hora;
    int horas_mes;

} Funcionario;

typedef struct noarv {
  struct noarv *esq;
  struct noarv *dir;
  Funcionario dado;
  int chave;
} NoArv;

typedef struct arvore {
  NoArv *raiz;
} Arvore;

void criar(Arvore *a);
void exibir(NoArv *raiz, int n);
// void exibir2(NoArv *r);
int inserir(Arvore *a, Funcionario func, int matricula);
NoArv *inserir_rec(NoArv *raiz, Funcionario func, int matricula);
void insere(Arvore *a, Funcionario func, int matricula);
int busca(NoArv *raiz, int matricula);
NoArv *sucessor(NoArv *atual);
int remover(Arvore *a, int matricula);