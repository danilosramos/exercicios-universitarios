#include <stdio.h>

#define STR 100

typedef char string[STR];

typedef struct dados_pessoa
{
	int identificacao;
	string nome;
	int idade;
	struct dados_pessoa *proximo;
} dados_pessoa;

// Prot�tipo das fun��es auxiliares
int menu();
dados_pessoa *cria_novo_registro();
void ler_dados_pessoa(dados_pessoa *pessoa);
void listar_registros(dados_pessoa *lista);
void mostrar_dados_registro(dados_pessoa *pessoa);
void incluir_registro_lista(dados_pessoa **lista, dados_pessoa *novo);
void incluir_registro_lista_v2(dados_pessoa **lista, dados_pessoa *novo);
dados_pessoa *procura_ultimo_registro_da_lista(dados_pessoa *lista);
dados_pessoa *localiza_pessoa(dados_pessoa *lista);
void excluir_pessoa(dados_pessoa **lista);
void escrever_dados_arquivo(string nome_arquivo, dados_pessoa *pessoa);
void salvar_dados_em_arquivo(string nome_arq, dados_pessoa *lista);
void importar_dados_arquivo(string nome_arq, dados_pessoa **lista);
void exportar_dados_formato_csv(string nome_arq, dados_pessoa *lista);
void salvar_dados_binario(string nome_arq, dados_pessoa *lista);
void importar_dados_binario(string nome_arq, dados_pessoa **lista);

int main()
{
	dados_pessoa *lista = NULL, *aux;
	int opcao, size = 0;
	string nome_arquivo;
	char resposta;

	printf("Deseja importar dados de arquivo texto? ");
	scanf("%c", &resposta);

	if (toupper(resposta) == 'S')
	{
		printf("Qual o nome do arquivo de entrada de dados? ");
		getchar();
		fgets(nome_arquivo, STR, stdin);
		size = strlen(nome_arquivo);
		nome_arquivo[size - 1] = '\0';
		importar_dados_arquivo(nome_arquivo, &lista);
	}

	do
	{
		opcao = menu();

		switch (opcao)
		{
		case 1:
			aux = cria_novo_registro();
			ler_dados_pessoa(aux);
			// incluir_registro_lista(&lista, aux);
			incluir_registro_lista_v2(&lista, aux);
			break;

		case 2:
			listar_registros(lista);
			break;

		case 3:
			aux = localiza_pessoa(lista);
			if (aux)
			{
				mostrar_dados_registro(aux);
			}
			else
			{
				printf("Registro nao cadastrado!\n");
			}
			break;
		case 4:
			excluir_pessoa(&lista);
			break;

		case 5:

			printf("\nDigite o nome do arquivo que voce quer: ");
			getchar();
			fgets(nome_arquivo, STR, stdin);
			size = strlen(nome_arquivo);
			nome_arquivo[size - 1] = '\0';

			escrever_dados_arquivo(nome_arquivo, lista);

			break;

		case 6:
			printf("\nDigite o nome do arquivo que voce quer: ");
			getchar();
			fgets(nome_arquivo, STR, stdin);
			size = strlen(nome_arquivo);
			nome_arquivo[size - 1] = '\0';

			exportar_dados_formato_csv(nome_arquivo, lista);
			break;

		case 7:
			printf("\nDigite o nome do arquivo binario que voce quer: ");
			getchar();
			fgets(nome_arquivo, STR, stdin);
			size = strlen(nome_arquivo);
			nome_arquivo[size - 1] = '\0';

			salvar_dados_binario(nome_arquivo, lista);
			break;

		case 8:
			printf("\nDigite o nome do arquivo binario que voce quer: ");
			getchar();
			fgets(nome_arquivo, STR, stdin);
			size = strlen(nome_arquivo);
			nome_arquivo[size - 1] = '\0';
			strcat(nome_arquivo, ".bin");

			importar_dados_binario(nome_arquivo, &lista);
			break;

		case 0:
			printf("Qual o nome do arquivo onde os dados serao armazenados? ");
			getchar();
			fgets(nome_arquivo, STR, stdin);
			size = strlen(nome_arquivo);
			nome_arquivo[size - 1] = '\0';

			salvar_dados_em_arquivo(nome_arquivo, lista);
			printf("Obrigado por usar nosso sistema!\n");
		}

	} while (opcao != 0);

	return 0;
}

// Implementa��o das fun��es auxiliares
int menu()
{
	int opcao;

	printf("1.Incluir novo registro\n");
	printf("2.Listar registros cadastrados\n");
	printf("3.Localizar registro\n");
	printf("4.Excluir registro\n");
	printf("5.Exportar para arquivo\n");
	printf("6.Exportar para formato csv\n");
	printf("7.Salvar dados em binario\n");
	printf("8.Importar dados binario\n");
	printf("0.Sair do programa (tchau!!!)\n");

	printf(":? ");
	scanf("%d", &opcao);

	return opcao;
}

dados_pessoa *cria_novo_registro()
{
	dados_pessoa *novo = (dados_pessoa *)malloc(sizeof(dados_pessoa));
	novo->proximo = NULL;

	return novo;
}

void ler_dados_pessoa(dados_pessoa *pessoa)
{
	int size;

	printf("Identificacao.........: ");
	scanf("%d", &pessoa->identificacao);
	getchar();
	printf("Nome..................: ");
	fgets(pessoa->nome, STR, stdin);
	size = strlen(pessoa->nome);
	pessoa->nome[size - 1] = '\0';
	printf("Idade.................: ");
	scanf("%d", &pessoa->idade);
}

void listar_registros(dados_pessoa *lista)
{
	dados_pessoa *aux = lista;

	while (aux != NULL)
	{
		mostrar_dados_registro(aux);
		aux = aux->proximo;
	}
}

void mostrar_dados_registro(dados_pessoa *pessoa)
{
	printf("Identificacao.........: %d\n", pessoa->identificacao);
	printf("Nome..................: %s\n", pessoa->nome);
	printf("Idade.................: %d\n", pessoa->idade);
	printf("Meu endereco..........: %p\n", pessoa);
	printf("Endereco do proximo...: %p\n", pessoa->proximo);
	printf("\n");
}

void incluir_registro_lista(dados_pessoa **lista, dados_pessoa *novo)
{
	dados_pessoa *aux = NULL;

	// Lista vazia
	// O registro sera o primeiro
	if (*lista == NULL)
	{
		*lista = novo;
	}
	else
	{
		// Alocar o registro no fim da fila
		// Procura o fim da fila
		aux = procura_ultimo_registro_da_lista(*lista);
		aux->proximo = novo;
	}
}
void incluir_registro_lista_v2(dados_pessoa **lista, dados_pessoa *novo)
{
	dados_pessoa *aux = NULL;
	if (*lista == NULL)
	{
		*lista = novo;
	}
	else
	{
		novo->proximo = *lista;
		*lista = novo;
	}
}

dados_pessoa *procura_ultimo_registro_da_lista(dados_pessoa *lista)
{
	dados_pessoa *aux = lista;

	// Procura o ultimo registro da fila
	while (aux)
	{
		if (aux->proximo == NULL)
		{
			return aux;
		}
		aux = aux->proximo;
	}

	return aux;
}

dados_pessoa *localiza_pessoa(dados_pessoa *lista)
{

	int size;
	dados_pessoa *aux = lista;
	string nome_comp;

	printf("Digite o nome a ser procurado: ");
	getchar();
	fgets(nome_comp, STR, stdin);
	size = strlen(nome_comp);
	nome_comp[size - 1] = '\0';

	while (aux)
	{
		if (!strcmp(aux->nome, nome_comp))
		{
			return aux;
		}
		aux = aux->proximo;
	}

	return NULL;
}

void excluir_pessoa(dados_pessoa **lista)
{
	dados_pessoa *anterior = NULL, *atual = NULL;
	int size;
	string nome_comp;

	printf("Digite o nome a ser procurado: ");
	getchar();
	fgets(nome_comp, STR, stdin);
	size = strlen(nome_comp);
	nome_comp[size - 1] = '\0';

	anterior = *lista;
	atual = *lista;

	while (atual)
	{
		if (!strcmp(atual->nome, nome_comp))
		{
			mostrar_dados_registro(atual);
			if (*lista != atual)
			{
				anterior->proximo = atual->proximo;
			}
			else
			{
				*lista = atual->proximo;
			}
			free(atual);
			break;
		}
		anterior = atual;
		atual = atual->proximo;
	}
}

void escrever_dados_arquivo(string nome_arquivo, dados_pessoa *lista)
{

	dados_pessoa *aux = lista;
	FILE *fp;

	fp = fopen(nome_arquivo, "w+");

	fprintf(fp, "%s", "<table width='500px'>");
	fprintf(fp, "%s", "<tr>");
	fprintf(fp, "<th>Identificacao:</th>");
	fprintf(fp, "<th>Nome:</th>");
	fprintf(fp, "<th>Idade:</th>");
	fprintf(fp, "%s", "</tr>");
	fprintf(fp, "%s", "</table>");

	while (aux != NULL)
	{

		fprintf(fp, "%s", "<html>");
		fprintf(fp, "%s", "<body>");
		fprintf(fp, "%s", "<table width='500px'>");
		fprintf(fp, "%s", "<b>");
		fprintf(fp, "%s", "<tr>");
		fprintf(fp, "<td>%d\n</td>", aux->identificacao);
		fprintf(fp, "<td>%s\n</td>", aux->nome);
		fprintf(fp, "<td>%d\n</td>", aux->idade);
		fprintf(fp, "%s", "</tr>");
		fprintf(fp, "%s", "<br>");
		fprintf(fp, "%s", "</b>");
		fprintf(fp, "%s", "</table>");
		fprintf(fp, "%s", "</body>");
		fprintf(fp, "%s", "</html>");

		aux = aux->proximo;
	}

	fclose(fp);
}

void salvar_dados_em_arquivo(string nome_arq, dados_pessoa *lista)
{
	FILE *fp;

	fp = fopen(nome_arq, "w+");

	if (fp == NULL)
	{
		printf("Nao foi possivel abrir/criar arquivo %s\n", nome_arq);
		exit(0);
	}

	while (lista)
	{
		fprintf(fp, "%d\n", lista->identificacao);
		fprintf(fp, "%s\n", lista->nome);
		fprintf(fp, "%d\n", lista->idade);
		lista = lista->proximo;
	}

	fclose(fp);
}

void importar_dados_arquivo(string nome_arq, dados_pessoa **lista)
{
	FILE *fp;
	string nome;
	int id, idade, size;
	dados_pessoa *aux;

	fp = fopen(nome_arq, "r");

	if (fp == NULL)
	{
		printf("Nao foi possivel abrir/criar arquivo %s\n", nome_arq);
		exit(0);
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d\n", &id);
		fgets(nome, STR, fp);
		size = strlen(nome);
		nome[size - 1] = '\0';

		// Remove enter de nome
		fscanf(fp, "%d\n", &idade);

		// Aloca registro dinamicamente
		aux = cria_novo_registro();
		aux->identificacao = id;
		strcpy(aux->nome, nome);
		aux->idade = idade;

		incluir_registro_lista(lista, aux);
	}

	fclose(fp);
}

void exportar_dados_formato_csv(string nome_arq, dados_pessoa *lista)
{
	FILE *fp;
	string nome;
	int id, idade;
	dados_pessoa *aux;

	strcat(nome_arq, ".csv");

	fp = fopen(nome_arq, "w+");

	if (fp == NULL)
	{
		printf("Nao foi possivel abrir/criar arquivo %s\n", nome_arq);
		exit(0);
	}

	fprintf(fp, "id.;nome;idade\n");

	while (lista)
	{
		fprintf(fp, "%d", lista->identificacao);
		fprintf(fp, "%c", ';');
		fprintf(fp, "%s", lista->nome);
		fprintf(fp, "%c", ';');
		fprintf(fp, "%d", lista->idade);
		fprintf(fp, "%c", ';');
		fprintf(fp, "%c", '\n');
		lista = lista->proximo;
	}

	fclose(fp);
}

void salvar_dados_binario(string nome_arq, dados_pessoa *lista)
{
	FILE *fp;
	fp = fopen(nome_arq, "wb");

	if (fp == NULL)
	{
		printf("Nao foi possivel abrir/criar arquivo %s\n", nome_arq);
		exit(0);
	}

	while (lista)
	{
		fwrite(&lista->identificacao, sizeof(int), 1, fp);
		fwrite(lista->nome, sizeof(char), STR, fp);
		fwrite(&lista->idade, sizeof(int), 1, fp);
		lista = lista->proximo;
	}

	fclose(fp);
}

void importar_dados_binario(string nome_arq, dados_pessoa **lista)
{
	FILE *fp;
	fp = fopen(nome_arq, "rb");

	if (fp == NULL)
	{
		printf("Nao foi possivel abrir/criar arquivo %s\n", nome_arq);
		exit(0);
	}

	while (!feof(fp))
	{
		dados_pessoa *aux = cria_novo_registro();
		fread(&aux->identificacao, sizeof(int), 1, fp);
		fread(aux->nome, sizeof(char), STR, fp);
		fread(&aux->idade, sizeof(int), 1, fp);
		aux->nome[STR - 1] = '\0';

		if (!feof(fp))
		{
			incluir_registro_lista(lista, aux);
		}
		else
		{
			free(aux);
		}
	}

	fclose(fp);
}
