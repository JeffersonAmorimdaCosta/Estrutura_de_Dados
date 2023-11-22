typedef struct trecho {
    int idTrecho;
    char direcao;
    float distancia;
} TipoTrecho;

typedef struct no {
  TipoTrecho trecho;
  struct no *prox;
  struct no *ant;
} No;

typedef struct lista {
  No *inicio;
  No *fim;
  int tamanho;
} ListaDE;

void criar(ListaDE *l); // Cria a lista
int vazia(ListaDE *l); // Verifica se a lista está vazia
int tamanho(ListaDE *l); // Retorna o tamanho atual da lista
int inserirFinal(ListaDE *l, TipoTrecho t); // Insere o trecho no final da lista
int inserirInicio(ListaDE *l, TipoTrecho t); // Insere o trecho no início da lista
int inserirPosicao(ListaDE *l, TipoTrecho t, int pos); // Insere o trecho na lista em uma posição específica
void exibir(ListaDE *l); // Exibe o ID, sentido e distância em metros do trecho
int buscaPorElemento(ListaDE *l, int id); // Busca a posição na lista de um trecho a partir do seu ID
int buscaPorPosicao(ListaDE *l, int pos); // Busca ID, sentido e distância do trecho a partir de sua posição
int removerInicio(ListaDE *l); // Remove um trecho no início da lista
int removerFim(ListaDE *l); // Remove um trecho no final da lista
int remover(ListaDE *l, int id); // Remove um trecho específico na lista pelo seu ID
int percursoTotal(ListaDE *l); // Faz a soma de todas as distâncias e retorna o total a percorrer