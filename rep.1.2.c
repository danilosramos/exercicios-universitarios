//   Gerenciador de Funcionarios de uma Empresa

#include <stdio.h>
#include <string.h>

struct Funcionario
{
    char nome[64];
    char dataNascimento[12];
    char cidade[64];
    float salario;
};

struct Funcionario funcionarios[100];
int numFuncionarios = 0;

// Menu
int main()
{
    int opcao;
    while (1)
    {
        printf("1. Inserir funcionario\n");
        printf("2. Atualizar dados de um funcionario\n");
        printf("3. Deletar registro de um funcionario\n");
        printf("4. Relatorio de funcionarios\n");
        printf("5. Consulta por nome do funcionario\n");
        printf("6. Relatorio de funcionarios com salario maior ou igual ao salario digitado\n");
        printf("7. Relatorio do numero de funcionarios por salario minimo\n");
        printf("8. Relatorio do numero de funcionarios por cidade\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            inserirFuncionario();
            break;
        case 2:
            atualizarFuncionario();
            break;
        case 3:
            deletarFuncionario();
            break;
        case 4:
            relatorioFuncionarios();
            break;
        case 5:
            consultarFuncionario();
            break;
        case 6:
            relatorioSalarioMaiorIgual();
            break;
        case 7:
            relatorioNumeroFuncionariosPorSalario();
            break;
        case 8:
            relatorioNumeroFuncionariosPorCidade();
            break;
        case 0:
            return 0;
        }
    }

    return 0;
}

// Função 1 para inserir funcionarios
void inserirFuncionario()
{
    if (numFuncionarios < 100)
    {
        struct Funcionario novoFuncionario;
        printf("Nome: ");
        fgets(novoFuncionario.nome, 64, stdin);
        printf("Data de Nascimento (dd/mm/aaaa): ");
        fgets(novoFuncionario.dataNascimento, 12, stdin);
        printf("Cidade: ");
        fgets(novoFuncionario.cidade, 64, stdin);
        printf("Salario: ");
        scanf("%f", &novoFuncionario.salario);
        funcionarios[numFuncionarios] = novoFuncionario;
        numFuncionarios++;
    }
    else
    {
        printf("Limite de Funcionarios Atingido.\n");
    }
}

// Função 2 para atualizar funcionarios
void atualizarFuncionario()
{
    char nomeBusca[64];
    printf("Nome do funcionario a ser atualizado: ");
    fgets(nomeBusca, 64, stdin);
    int encontrado = 0;
    for (int i = 0; i < numFuncionarios; i++)
    {
        if (strcasecmp /*comparacao sem diferenciação do modo caixa alta ou baixa*/ (funcionarios[i].nome, nomeBusca) == 0)
        {
            printf("Novo nome: ");
            fgets(funcionarios[i].nome, 64, stdin);
            printf("Nova data de Nascimento (dd/mm/aaaa): ");
            fgets(funcionarios[i].dataNascimento, 12, stdin);
            printf("Nova cidade: ");
            fgets(funcionarios[i].cidade, 64, stdin);
            printf("Novo salario: ");
            scanf("%f", &funcionarios[i].salario);
            printf("Dados do funcionario atualizados!\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
    {
        printf("Funcionario nao encontrado.\n");
    }
}

// Função 3 para excluir um funcionario
void deletarFuncionario()
{
    char nomeBusca[64];
    printf("Nome do funcionario a ser excluido: ");
    fgets(nomeBusca, 64, stdin);
    int j = 0;
    int encontrado = 0;
    for (int i = 0; i < numFuncionarios; i++)
    {
        if (strcasecmp(funcionarios[i].nome, nomeBusca) == 0)
        {
            for (j = i; j < numFuncionarios - 1; j++)
            {
                funcionarios[j] = funcionarios[j + 1];
            }
            numFuncionarios--;
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
    {
        printf("Funcionario nao encontrado\n");
    }
}

// Função 4 para exibir um relatorio dos funcionarios
void relatorioFuncionarios()
{
    int diaAtual, mesAtual, anoAtual, dia, mes, ano;

    printf("Data do relatorio (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &diaAtual, &mesAtual, &anoAtual);

    for (int i = 0; i < numFuncionarios; i++)
    {
        sscanf(funcionarios[i].dataNascimento, "%d/%d/%d", &dia, &mes, &ano);

        int idade = calcularIdade(diaAtual, mesAtual, anoAtual, dia, mes, ano);

        printf("\nNome: %sIdade: %d\nCidade: %sSalario: %.2f\n",
               funcionarios[i].nome, idade, funcionarios[i].cidade, funcionarios[i].salario);
    }
}
// Função para calcular a idade (usada na função 4)
int calcularIdade(int diaAtual, int mesAtual, int anoAtual, int dia, int mes, int ano)
{
    int idade = anoAtual - ano;

    if (mesAtual < mes || (mesAtual == mes && diaAtual < dia))
    {
        idade--;
    }

    return idade;
}
// Função 5 para consultar um funcionario pelo nome
void consultarFuncionario()
{
    char nomeBusca[64];
    printf("Nome do funcionario a ser consultado: ");
    fgets(nomeBusca, 64, stdin);
    int encontrado = 0;
    for (int i = 0; i < numFuncionarios; i++)
    {
        if (strcasecmp(funcionarios[i].nome, nomeBusca) == 0)
        {
            printf("Nome: %sData de Nascimento: %sCidade: %sSalario: %.2f\n",
                   funcionarios[i].nome, funcionarios[i].dataNascimento, funcionarios[i].cidade, funcionarios[i].salario);
            encontrado = 1;
        }
    }
    if (!encontrado)
    {
        printf("Funcionario nao encontrado\n");
    }
}

// Função 6 do relatorio de salario maior ou igual ao digitado
void relatorioSalarioMaiorIgual()
{
    float salarioLimite;
    printf("Informe o valor do salario base: ");
    scanf("%f", &salarioLimite);
    for (int i = 0; i < numFuncionarios; i++)
    {
        if (funcionarios[i].salario >= salarioLimite)
        {
            printf("Nome: %sSalario: %.2f\n", funcionarios[i].nome, funcionarios[i].salario);
        }
    }
}

// Função 7 para relatorio do numero de funcionarios por salario minimo
void relatorioNumeroFuncionariosPorSalario()
{
    int salariop1 = 0, salariop2 = 0, salariop3 = 0;
    float salarioMinimo;

    printf("Digite o salario minimo atual: ");
    scanf("%f", &salarioMinimo);
    getchar();

    for (int i = 0; i < numFuncionarios; i++)
    {
        if (funcionarios[i].salario <= salarioMinimo)
        {
            salariop1++;
        }
        else if (funcionarios[i].salario <= (salarioMinimo * 3))
        {
            salariop2++;
        }
        else
        {
            salariop3++;
        }
    }

    printf("1. Ganham 1 salario minimo ou menos: %d funcionarios\n", salariop1);
    printf("2. Mais de 1 salario minimo a 3 salarios minimos: %d funcionarios\n", salariop2);
    printf("3. Mais que 3 salarios minimos: %d funcionarios\n", salariop3);
}

// Função 8 para relatorio do numero de funcionarios por cidade
void relatorioNumeroFuncionariosPorCidade()
{

    struct CidadeFuncionarios
    {
        char cidade[64];
        int numFuncionarios;
    };

    struct CidadeFuncionarios cidades[64];
    int numCidades = 0;
    int i, j;
    for (i = 0; i < numFuncionarios; i++)
    {
        int cidadeEncontrada = 0;
        for (j = 0; j < numCidades; j++)
        {
            if (strcasecmp(funcionarios[i].cidade, cidades[j].cidade) == 0)
            {
                cidades[j].numFuncionarios++;
                cidadeEncontrada = 1;
                break;
            }
        }
        if (!cidadeEncontrada)
        {
            strcpy(cidades[numCidades].cidade, funcionarios[i].cidade);
            cidades[numCidades].numFuncionarios = 1;
            numCidades++;
        }
    }

    for (int i = 0; i < numCidades; i++)
    {
        printf("%s %d funcionarios\n", cidades[i].cidade, cidades[i].numFuncionarios);
    }
}
