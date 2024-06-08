typedef struct DadosAlistamento {

// digite os tipos de dados
char name[50];
float altura;
int idade;
char sexo;
struct DadosAlistamento *next;

} DadosAlistamento;

DadosAlistamento* createDadosAlistamento(char *nome, float altura, int idade, char sexo) {
DadosAlistamento *newDadosAlistamento = (DadosAlistamento*)malloc(sizeof(DadosAlistamento));
strcpy(newDadosAlistamento->name, nome);
newDadosAlistamento->altura = altura;
newDadosAlistamento->idade = idade;
newDadosAlistamento->sexo = sexo;
newDadosAlistamento->next = NULL;
return newDadosAlistamento;
}

