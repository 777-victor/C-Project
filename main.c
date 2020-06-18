#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente{
    int codigo;
    char nome[250], endereco[250], DTNasc[250],telefone[250];
}Cliente;

typedef struct Funcionario{
    int codigo,tipo;
    char nome[250], funcao[250],salario[250],telefone[250];
}Funcionario;

typedef struct Fornecedor{
    int codigo;
    char nome[250],telefone[250],produto[250];
}Fornecedor;

typedef struct Festa{
    int codigo,convidados;
    char tema[250],data[250],diaSemana[250],horario[250],cliente[250];
}Festa;

int numeroClientes=0;
void cadastraCli();
void cadastraFuncionario();
void cadastraFornecedor();
void cadastraFesta();

void strSplit(char *strTOsplit,char *strArr[], char *strSeparet,int nArr);
void  lerClientes(Cliente VetorClientes[]);
void ListaCompletaClientes(Cliente VetorClientes[]);



int main()
{
   Cliente VetorClientes[1000];
   int i,Opcao;
    int codaux;
    int cod;
    do
    {
        printf("1 - Cadastrar Novo Cliente\n");
        printf("2 - Cadastrar funcionario \n");
        printf("3 - Cadastrar fornecedor \n");
        printf("4 - Cadastrar festa \n");


        printf("8 - Sair\n");
        printf(" Selecione uma opcao por favor: ");
        scanf("%d", &Opcao);
        getchar();

        if (Opcao == 1)
        {
               cadastraCli();


        }
        else if(Opcao == 2)
        {

         cadastraFuncionario();


        }
        else if(Opcao == 3)
        {
           cadastraFornecedor();
        }

        else if(Opcao == 4)
        {
           cadastraFesta();
        }
        }    while (Opcao != 8 || Opcao < 8);


    return 0;
}

void cadastraCli()
{
        Cliente cli;



        cli.codigo++;
        printf("\nDigite o nome: ");
        gets(cli.nome);
        printf("\nDigite o endereco: ");
        gets(cli.endereco);
        printf("\nDigite o telefone: ");
        gets(cli.telefone);
        printf("\nDigite a data de nascimento: ");
        gets(cli.DTNasc);

        FILE *arq1 = fopen("Clientes.txt","a+");

    fprintf(arq1,"%i;%s;%s;%s;%s\n",cli.codigo,cli.nome,cli.endereco,cli.telefone,cli.DTNasc);

    fclose(arq1);
}

void cadastraFuncionario()
{
    Funcionario fcrio;
    fcrio.codigo++;
        printf("\nDigite o nome: ");
        gets(fcrio.nome);
        printf("\nDigite o telefone: ");
        gets(fcrio.telefone);
        printf("\nDigite a funcao: ");
        gets(fcrio.funcao);
        printf("\nDigite o salario: ");
        gets(fcrio.salario);
        printf("\nDigite o tipo: \n1-fixo \n2-temporario ");
        scanf("%i",&fcrio.tipo);

    FILE *arq2 = fopen("Funcionarios.txt","a");

    fprintf(arq2,"%d;%s;%s;%s;%s\n" ,fcrio.codigo,fcrio.nome,fcrio.telefone,fcrio.funcao,fcrio.salario);


    fclose(arq2);


}

void cadastraFornecedor()
{
    Fornecedor forn;
    forn.codigo++;
        printf("\nDigite o nome: ");
        gets(forn.nome);
        printf("\nDigite o telefone: ");
        gets(forn.telefone);
        printf("\nDigite o produto: ");
        gets(forn.produto);
        

    FILE *arq3 = fopen("Fornecedores.txt","a");

    fprintf(arq3,"%d;%s;%s;%s\n" ,forn.codigo,forn.nome,forn.telefone,forn.produto);


    fclose(arq3);


}

void cadastraFesta()
{
    Festa festa;
        festa.codigo++;
        printf("\nDigite o nome do cliente: ");
        gets(festa.cliente);
        printf("\nDigite a quantidade de convidados: ");
        scanf("%d",&festa.convidados);
        fflush(stdin);
        printf("\nDigite o tema: ");
        gets(festa.tema);
        printf("\nDigite a data: ");
        gets(festa.data);
        printf("\nDigite o dia da semana:\n1-domingo \n2-segunda \n3-terca \n4-quarta \n5-quinta \n6-sexta \n7-sabado ");
        gets(festa.diaSemana);
        printf("\nDigite o horario: ");
        gets(festa.horario);
        

    FILE *arq4 = fopen("Festas.txt","a");

    fprintf(arq4,"%d;%d;%s;%s;%s;%s\n" ,festa.codigo,festa.convidados,festa.tema,festa.data,festa.diaSemana,festa.horario);


    fclose(arq4);


}

void strSplit(char *strTOsplit,char *strArr[], char *strSeparet,int nArr)
        {
            int i = 0;
            char * pch;

            pch = strtok (strTOsplit,strSeparet);
            for(i = 0;i < nArr;i++)
            {
               // printf ("%s\n",pch);

                strArr[i] = pch;
                pch = strtok (NULL,strSeparet);
            }
         }

 



void  lerClientes(Cliente VetorClientes[])
        {

            FILE *arquivo;
            arquivo = fopen("Clientes.txt", "r");
            char linha[100];
            char *result;
            char * informacoes_linha[5];
            int i =0;
            while (!feof(arquivo))  // Enquando não chegar no fim do arquivo..
            {
                result = *fgets (linha, 100, arquivo);//Leitura de uma linha do arquivo...
                strSplit(linha, informacoes_linha, ";",5); //Separa os campos e os armazena no vetor de 3 posições chamado informacoes_linha
                //Cada posição do vetor VetorEmpregados guarda não so uma mas tres informações.
                VetorClientes[i].codigo = atoi(informacoes_linha[0]);
                strcpy(VetorClientes[i].nome, (const char*)(informacoes_linha[1]) );
                VetorClientes[i].endereco = atof(informacoes_linha[2]);
                i++;
            }
            numeroClientes = i;
        }


 void ListaCompletaClientes(Cliente VetorClientes[])
        {
			int i;
            for (i = 0; i < numeroClientes; i++)
            {
               printf(" %s : %d : %.2f \n", VetorClientes[i].nome, VetorClientes[i].matricula,VetorEmpregados[i].salario);
            }
        }
