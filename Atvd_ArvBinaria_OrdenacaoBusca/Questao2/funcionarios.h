typedef struct funcionario{
    char nome[50];
    float valor_hora;
    int horas_mes;

} Funcionario;

void ordem_alfabetica_func(int tam, Funcionario *vf);
Funcionario *busca_func(int n, Funcionario *vf, char *nome);
Funcionario *buscabin_func(int n, Funcionario *vf[], char *nome);
Funcionario *exibe_top3_salarios(int n, Funcionario *vf[]);