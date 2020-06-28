#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>


typedef struct Cliente{
    int codigo;
    char nome[250], endereco[250], DTNasc[250],telefone[250];
}Cliente;

typedef struct Funcionario{
    int codigo;
    char nome[250], funcao[250],salario[250],telefone[250],tipo[150];
}Funcionario;

typedef struct Fornecedor{
    int codigo;
    char nome[250],telefone[250],produto[250];
}Fornecedor;

typedef struct Festa{
    int codigo,convidados,diaSemana,horario;
    char tema[250],data[250],cliente[250],status[250];
}Festa;

typedef struct Contrato{
    int num,pagamento,codigo,status;
    float desconto,valorFinal,valorTotal;
}Contrato;


int numeroClientes=0;
int numeroFuncionarios=0;
int numeroFornecedores=0;
int numeroFestas=0;
int numeroContratos=0;
float preco=0;



void cadastraCli();
void cadastraFuncionario();
void cadastraFornecedor();
void cadastraFesta();

int Search_in_File(char *fname);
void strSplit(char *strTOsplit,char *strArr[], char *strSeparet,int nArr);


void calculaPreco(Festa vetorFestas[]);

void  lerClientes(Cliente VetorClientes[]);
void  lerFuncionario(Funcionario vetorFuncionario[]);
void  lerFornecedor(Fornecedor vetorFornecedor[]);
void  lerFesta(Festa vetorFesta[]);
void  lerContrato(Contrato vetorContrato[]);



void verificaFestaData(Festa vetorFesta[],char data[20],int horario,int diaSemana);
void informacoesFuncionarios(Funcionario vetorFuncionario[]);
void informacoesFornecedores(Fornecedor vetorFornecedor[]);
void buscaFesta(Festa vetorFestas[]);
void attContrato(Contrato vetorContrato[]);
void buscaFestaData(Festa vetorFesta[]);







   Cliente VetorClientes[400];
   Funcionario vetorFuncionario[400];
   Fornecedor vetorFornecedor[400];
   Festa vetorFesta[400];
   Contrato vetorContrato[400];




int main()
{


    int i,Opcao,Op2;
    int cod;
    do
    {
        printf("1 - Cadastrar Novo Cliente\n");
        printf("2 - Cadastrar funcionario \n");
        printf("3 - Cadastrar fornecedor \n");
        printf("4 - Cadastrar festa \n");
        printf("5 - Realizar contrato\n");
        printf("6 - atualizar contrato\n");
        printf("7 - informacoes\n");
        printf("8 - Lista festas\n");
        printf("9 - Lista festa e contrato\n");
        printf("10 - Sair\n");
        printf(" Selecione uma opcao por favor: ");
        scanf("%d", &Opcao);
        getchar();

        if (Opcao == 1)
        {
               cadastraCli();
              // lerClientes(VetorClientes);


        }
        else if(Opcao == 2)
        {

         cadastraFuncionario();
         lerFuncionario(vetorFuncionario);


        }
        else if(Opcao == 3)
        {
           cadastraFornecedor();
           lerFornecedor(vetorFornecedor);
        }

        else if(Opcao == 4)
        {
           cadastraFesta();
           lerFesta(vetorFesta);

        }

        else if(Opcao == 5 )
        {
            calculaPreco(vetorFesta);
        }
        else if(Opcao ==6)
        {
          attContrato(vetorContrato);
        }

        else if(Opcao == 7 )
        {
            printf("\n1-Informacoes de cliente \n2-informacoes de funcionarios \n3-informacoes de fornecedores");
            scanf("%d",&Op2);
            getchar();
            if(Op2 == 1){
            informacoesCliente(VetorClientes);
            }
            else if(Op2 == 2){
              informacoesFuncionarios(vetorFuncionario);
            }
            else if(Op2 == 3){
                informacoesFornecedores(vetorFornecedor);
            }

        }
        else if(Opcao == 8)
        {
                       buscaFesta(vetorFesta);

        }
        else if(Opcao == 9)
        {
                 buscaFestaData(vetorFesta);
        }

        }    while (Opcao != 10 || Opcao < 10);


    return 0;
}

int Search_in_File(char *fname) {
	FILE *fp;
	if((fp = fopen(fname, "r")) == NULL) {
		return 1;
	}
	else{

	if(fp) {
		fclose(fp);
	}
	return 2;

	}

}


void cadastraCli()
{

        Cliente cli;
        if(Search_in_File("Clientes.txt")==2)
        {
            lerClientes(VetorClientes);
            cli.codigo = numeroClientes+1;
        }
        else{
            cli.codigo=1;
        }


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
     if(Search_in_File("Funcionarios.txt")==2)
        {
            lerFuncionario(vetorFuncionario);
            fcrio.codigo = numeroFuncionarios+1;
        }
        else{
            fcrio.codigo=1;
        }
        printf("\nDigite o nome: ");
        gets(fcrio.nome);
        printf("\nDigite o telefone: ");
        gets(fcrio.telefone);
        printf("\nDigite a funcao: ");
        gets(fcrio.funcao);
        printf("\nDigite o salario: ");
        gets(fcrio.salario);
        printf("\nDigite o tipo: \n1-fixo \n2-temporario ");
        gets(fcrio.tipo);
        fflush(stdin);

    FILE *arq2 = fopen("Funcionarios.txt","a");

    fprintf(arq2,"%d;%s;%s;%s;%s;%s\n" ,fcrio.codigo,fcrio.nome,fcrio.telefone
            ,fcrio.funcao,fcrio.salario,fcrio.tipo);


    fclose(arq2);


}

void cadastraFornecedor()
{
    Fornecedor forn;
     if(Search_in_File("Fornecedores.txt")==2)
        {
            lerFornecedor(vetorFornecedor);
            forn.codigo = numeroFornecedores+1;
        }
        else{
            forn.codigo=1;
        }

        fflush(stdin);
        printf("\nDigite o nome: ");
        gets(forn.nome);
        printf("\nDigite o telefone: ");
        gets(forn.telefone);
        printf("\nDigite o produto: ");
        gets(forn.produto);
            fflush(stdin);



    FILE *arq3 = fopen("Fornecedores.txt","a");

    fprintf(arq3,"%i;%s;%s;%s\n" ,forn.codigo,forn.nome,forn.telefone,forn.produto);


    fclose(arq3);


}

void cadastraFesta()
{
    Festa festa;
    char nome[100];
    int i,j,valor,V;
         if(Search_in_File("Clientes.txt")==2){
        if(Search_in_File("Festas.txt")==2)
        {
            lerFesta(vetorFesta);
            festa.codigo = numeroFestas+1;
        }
        else{
            festa.codigo=1;
        }
        lerClientes(VetorClientes);


        printf("\nDigite o nome do cliente: ");
        gets(festa.cliente);

        strcpy(nome,festa.cliente);
        for(i = 0; nome[i]; i++){
            nome[i] = tolower(nome[i]);
           }
         for (i = 0; i <numeroClientes; i++)
            {
                          for(j = 0; VetorClientes[i].nome[j]; j++){
            VetorClientes[i].nome[j] = tolower(VetorClientes[i].nome[j]);
           }
                           valor = strcmp(nome, VetorClientes[i].nome);
                           if(valor == 0)
                           {
                            printf("\nCliente encontrado.");
                            V=1;
                           }

            }

        if(V != 1)
        {
            printf("Cliente nao encontrado cadastrado.\n");
            main();
        }

        printf("\nDigite a quantidade de convidados: ");
        scanf("%d",&festa.convidados);
        fflush(stdin);
        printf("\nDigite o tema: ");
        gets(festa.tema);
        printf("\nDigite a data: ");
        gets(festa.data);
        printf("\nDigite o dia da semana:\n1-domingo \n2-segunda \n3-terca \n4-quarta \n5-quinta \n6-sexta \n7-sabado ");
        scanf("%d",&festa.diaSemana);
        fflush(stdin);
        if(festa.diaSemana == 7)
        {
        printf("\nas 12 ou 18 horas:");
        scanf("%i",&festa.horario);
        fflush(stdin);
        if(festa.horario != 12 && festa.horario !=18)
        {
            printf("horario indisponivel\n");
            main();
        }
        }else{
        printf("\nDigite a hora de inicio: ");
        scanf("%i",&festa.horario);

        }
        fflush(stdin);

        verificaFestaData(vetorFesta,festa.data,festa.horario,festa.diaSemana);



    FILE *arq4 = fopen("Festas.txt","a");

    fprintf(arq4,"%d;%s;%d;%s;%s;%d;%i\n" ,festa.codigo,festa.cliente,festa.convidados,festa.tema,festa.data,festa.diaSemana,festa.horario);


    fclose(arq4);


         }
         else{
             printf("Nenhum cliente cadastrado\n");
         }
}

void strSplit(char *strTOsplit,char *strArr[], char *strSeparet,int nArr)
        {
            int i = 0;
            char * pch;

            pch = strtok (strTOsplit,strSeparet);
            for(i = 0;i < nArr;i++)
            {
              //printf ("%s\n",pch);

                strArr[i] = pch;
                pch = strtok (NULL,strSeparet);
            }
         }



void  lerClientes(Cliente VetorClientes[])
        {
            FILE *arquivo;
            arquivo = fopen("Clientes.txt", "r");
            char linha[100];
            struct stat buf;
            stat("Clientes.txt", &buf);
            char *result;
            char * informacoes_linha[5];
            int i =0;
            while (ftello(arquivo) != buf.st_size)  // Enquando não chegar no fim do arquivo..
            {
                result = *fgets (linha, 100, arquivo);//Leitura de uma linha do arquivo...
                strSplit(linha, informacoes_linha, ";",5); //Separa os campos e os armazena no vetor de 3 posições chamado informacoes_linha
                //Cada posição do vetor VetorEmpregados guarda não so uma mas tres informações.
                VetorClientes[i].codigo = atoi(informacoes_linha[0]);
                strcpy(VetorClientes[i].nome, (const char*)(informacoes_linha[1]) );
                strcpy(VetorClientes[i].endereco, (const char*)(informacoes_linha[2]) );
                strcpy(VetorClientes[i].telefone, (const char*)(informacoes_linha[3]) );
                strcpy(VetorClientes[i].DTNasc, (const char*)(informacoes_linha[4]) );


                i++;

            }
            numeroClientes = i;
        }

void  lerFuncionario(Funcionario vetorFuncionario[])
{


            FILE *arquivo;
            arquivo = fopen("Funcionarios.txt", "r");
            char linha[100];
            struct stat buf;
            stat("Funcionarios.txt", &buf);
            char *result;
            char * informacoes_linha[6];
            int i =0;
             while (ftello(arquivo) != buf.st_size)  // Enquando não chegar no fim do arquivo..
            {
                result = *fgets (linha, 100, arquivo);//Leitura de uma linha do arquivo...
                strSplit(linha, informacoes_linha, ";",6); //Separa os campos e os armazena no vetor de 3 posições chamado informacoes_linha
                //Cada posição do vetor VetorEmpregados guarda não so uma mas tres informações.
                vetorFuncionario[i].codigo = atoi(informacoes_linha[0]);
                strcpy(vetorFuncionario[i].nome, (const char*)(informacoes_linha[1]) );
                strcpy(vetorFuncionario[i].telefone, (const char*)(informacoes_linha[2]) );
                strcpy(vetorFuncionario[i].funcao, (const char*)(informacoes_linha[3]) );
                strcpy(vetorFuncionario[i].salario, (const char*)(informacoes_linha[4]) );
                strcpy(vetorFuncionario[i].tipo, (const char*)(informacoes_linha[5]) );


                i++;
            }
            numeroFuncionarios = i;



}

void  lerFornecedor(Fornecedor vetorFornecedor[])

 {

            FILE *arquivo;
            arquivo = fopen("Fornecedores.txt", "r");
            char linha[100];
            struct stat buf;
            stat("Fornecedores.txt", &buf);
            char *result;
            char * informacoes_linha[4];
            int i =0;
             while (ftello(arquivo) != buf.st_size)   // Enquando não chegar no fim do arquivo..
            {
                result = *fgets (linha, 100, arquivo);//Leitura de uma linha do arquivo...
                strSplit(linha, informacoes_linha, ";",4); //Separa os campos e os armazena no vetor de 3 posições chamado informacoes_linha
                //Cada posição do vetor VetorEmpregados guarda não so uma mas tres informações.
                vetorFornecedor[i].codigo = atoi(informacoes_linha[0]);
                strcpy(vetorFornecedor[i].nome, (const char*)(informacoes_linha[1]) );
                strcpy(vetorFornecedor[i].telefone, (const char*)(informacoes_linha[2]) );
                strcpy(vetorFornecedor[i].produto, (const char*)(informacoes_linha[3]) );




                i++;
            }
            numeroFornecedores = i;

}

void  lerFesta(Festa vetorFesta[])
{


            FILE *arquivo;
            arquivo = fopen("Festas.txt", "r");
            char linha[100];
            struct stat buf;
            stat("Festas.txt", &buf);
            char *result;
            char * informacoes_linha[7];
            int i =0;
             while (ftello(arquivo) != buf.st_size)   // Enquando não chegar no fim do arquivo..
            {
                result = *fgets (linha, 100, arquivo);//Leitura de uma linha do arquivo...
                strSplit(linha, informacoes_linha, ";",7); //Separa os campos e os armazena no vetor de 3 posições chamado informacoes_linha
                //Cada posição do vetor VetorEmpregados guarda não so uma mas tres informações.
                vetorFesta[i].codigo = atoi(informacoes_linha[0]);
                strcpy(vetorFesta[i].cliente, (const char*)(informacoes_linha[1]) );
                vetorFesta[i].convidados = atoi(informacoes_linha[2]);
                strcpy(vetorFesta[i].tema, (const char*)(informacoes_linha[3]) );
                strcpy(vetorFesta[i].data, (const char*)(informacoes_linha[4]) );
                vetorFesta[i].diaSemana = atoi(informacoes_linha[5]);
                vetorFesta[i].horario = atoi(informacoes_linha[6]);


                i++;
            }
            numeroFestas = i;

}

void  lerContrato(Contrato vetorContrato[])
{


            FILE *arquivo;
            arquivo = fopen("Contratos.txt", "r");
            char linha[100];
            struct stat buf;
            stat("Contratos.txt", &buf);
            char *result;
            char * informacoes_linha[7];
            int i =0;
             while (ftello(arquivo) != buf.st_size)   // Enquando não chegar no fim do arquivo..
            {
                result = *fgets (linha, 100, arquivo);//Leitura de uma linha do arquivo...
                strSplit(linha, informacoes_linha, ";",7); //Separa os campos e os armazena no vetor de 3 posições chamado informacoes_linha
                //Cada posição do vetor VetorEmpregados guarda não so uma mas tres informações.
                vetorContrato[i].num = atoi(informacoes_linha[0]);
                vetorContrato[i].valorTotal = atof(informacoes_linha[1]);
                vetorContrato[i].desconto = atof(informacoes_linha[2]);
                vetorContrato[i].valorFinal = atof(informacoes_linha[3]);
                vetorContrato[i].pagamento = atoi(informacoes_linha[4]);
                vetorContrato[i].status = atoi(informacoes_linha[5]);
                vetorContrato[i].codigo = atoi(informacoes_linha[6]);


                i++;
            }
            numeroContratos = i;

}




void informacoesCliente(Cliente vetorClientes[])
{           int i,j,valor;
            char nome[50];
             if(Search_in_File("Clientes.txt")==2)
        {
            lerClientes(vetorClientes);

            printf("Digite o nome do cliente: ");
            gets(nome);
            for(i = 0; nome[i]; i++){
            nome[i] = tolower(nome[i]);
           }

   //                 for(j=0;VetorEmpregado[i].nome[j];j++)
  //   {
      //   VetorEmpregado[i].nome[j] = tolower(VetorEmpregado[i].nome[j]);
    // }


            for (i = 0; i <numeroClientes; i++)
            {
                          for(j = 0; vetorClientes[i].nome[j]; j++){
            vetorClientes[i].nome[j] = tolower(vetorClientes[i].nome[j]);
           }
                           valor = strcmp(nome, vetorClientes[i].nome);
                           if(valor == 0)
                           {
                            printf("\nCodigo:%i\nNome:%s\nEndereco: %s\nTelefone: %s\nData de nascimento: %s\n",
                                    vetorClientes[i].codigo, vetorClientes[i].nome,vetorClientes[i].endereco,vetorClientes[i].telefone,vetorClientes[i].DTNasc);
                           }

            }
        }
        else
        {
            printf("Nenhum cliente cadastrado.\n");
            main();
        }



}
void informacoesFuncionarios(Funcionario vetorFuncionario[])
{
            int i,j,valor;
            char nome[50];
            if(Search_in_File("Funcionarios.txt")==2)
        {
            lerFuncionario(vetorFuncionario);

            printf("Digite o nome do funcionario: ");
            gets(nome);
            for(i = 0; nome[i]; i++){
            nome[i] = tolower(nome[i]);
           }



            for (i = 0; i <numeroFuncionarios; i++)
            {
                for(j = 0; vetorFuncionario[i].nome[j]; j++){
            vetorFuncionario[i].nome[j] = tolower(vetorFuncionario[i].nome[j]);
           }
                           valor = strcmp(nome, vetorFuncionario[i].nome);
                           if(valor == 0)
                           {
                            printf("\nCodigo: %i \nNome:%s \nTelefone: %s\nFuncao: %s\nTipo 1 fixo e 2 para temporario: %s\n",
                                    vetorFuncionario[i].codigo, vetorFuncionario[i].nome,
                                    vetorFuncionario[i].telefone,vetorFuncionario[i].funcao,vetorFuncionario[i].tipo);
                           }

            }
        }
        else{
            printf("Nenhum Funcionario cadastrado.\n");
            main();
        }


}

void informacoesFornecedores(Fornecedor vetorFornecedor[])
{
    if(Search_in_File("Fornecedores.txt")==2)
        {
            int i,j,valor;
            char nome[50];
            lerFornecedor(vetorFornecedor);
            printf("Digite o nome do fornecedor: ");
            gets(nome);
            for(i = 0; nome[i]; i++){
            nome[i] = tolower(nome[i]);
           }



            for (i = 0; i <numeroFornecedores; i++)
            {
                for(j = 0; vetorFornecedor[i].nome[j]; j++){
            vetorFornecedor[i].nome[j] = tolower(vetorFornecedor[i].nome[j]);
           }
                           valor = strcmp(nome, vetorFornecedor[i].nome);
                           if(valor == 0)
                           {
                            printf("\nCodigo: %i \nNome: %s \nTelefone: %s\nProduto: %s\n",
                                    vetorFornecedor[i].codigo, vetorFornecedor[i].nome,
                                    vetorFornecedor[i].telefone,vetorFornecedor[i].produto);
                           }

            }
        }
        else{
            printf("Nenhum fornecedor cadastrado.\n");
            main();
        }

}

void buscaFesta(Festa vetorFestas[])
{
            int i,j,valor;
            char nome[50],cliente;
            if(Search_in_File("Festas.txt")==2)
        {
            lerFesta(vetorFestas);

            printf("Digite o nome do cliente: ");
            gets(nome);
            for(i = 0; nome[i]; i++){
            nome[i] = tolower(nome[i]);
           }


            for (i = 0; i <numeroFestas; i++)
            {
                for(j = 0; vetorFestas[i].cliente[j]; j++){
            vetorFestas[i].cliente[j] = tolower(vetorFestas[i].cliente[j]);
           }


                           valor = strcmp(nome, vetorFestas[i].cliente);
                           if(valor == 0)
                           {
                            printf("\nCodigo: %i \nNome:%s \nConvidados: %i\nTema: %s\nData:%s\nDia:%i\nHorario: %i as %i\n",
                                    vetorFestas[i].codigo, vetorFestas[i].cliente,
                                    vetorFestas[i].convidados,vetorFestas[i].tema,vetorFestas[i].data,
                                    vetorFestas[i].diaSemana,vetorFestas[i].horario,vetorFestas[i].horario+4);
                           }

            }
        }
        else{
            printf("Nenhuma festa cadastrada\n");
            main();
        }

}

void verificaFestaData(Festa vetorFesta[],char data[20],int horario,int diaSemana)
{
    int i,valor,horarioFesta,HorarioAtual;
    if(Search_in_File("Festas.txt")==2)
        {
            lerFesta(vetorFesta);
            for (i = 0; i <numeroFestas; i++)
            {
                       valor = strcmp(data, vetorFesta[i].data);

                       if(valor == 0)
                       {
                           printf("\nDia ja tem festa");
                           if(diaSemana == 7)
                           {
                               if(vetorFesta[i].horario==horario)
                               {
                                   printf("\ndata indisponivel\n");
                                   main();

                               }
                           }
                           horarioFesta = vetorFesta[i].horario;
                           HorarioAtual = horario;
                           if(horarioFesta>HorarioAtual)
                           {
                               if(horarioFesta - HorarioAtual >= 4)
                               {
                                   printf("\nHorario disponivel\n");
                               }
                               else
                               {
                                  printf("\nHorario indisponivel\n");
                                  main();
                               }

                           }
                          else if(HorarioAtual>horarioFesta)
                           {
                               if(HorarioAtual - horarioFesta >= 4)
                               {
                                   printf("\nHorario disponivel");
                               }
                               else
                               {
                                  printf("\nHorario indisponivel");
                                  main();
                               }

                           }

                           //printf("\ndata nao disponivel");
                          // return 0;
                       }

            }

        }
        else{
            printf("Data disponivel\n");


        }


}




void buscaFestaData(Festa vetorFesta[])
{
            int i,valor,j,hor;
            char data[50],cliente;
            if(Search_in_File("Festas.txt")==2)
        {
            lerFesta(vetorFesta);

            printf("Digite a data nesse modelo dd/mm/aa: ");
            gets(data);
            printf("Horario das festas no dia %s\n",data);
            for ( i = 0; i < numeroFestas; i++)
            {
               valor = strcmp(data, vetorFesta[i].data);
               if(valor == 0)
               {
                   printf("%i\n",vetorFesta[i].horario);
               }

            }
            printf("Digite um horario: ");
            scanf("%d",&hor);

            for ( i = 0; i < numeroFestas; i++)
            {
               valor = strcmp(data, vetorFesta[i].data);
               if(valor == 0)
               {
                   if(vetorFesta[i].horario == hor)
                   {
                        printf("\nCodigo: %i \nNome:%s \nConvidados: %i\nTema: %s\nData:%s\nDia:%i\nHorario: %i as %i\n",
                                    vetorFesta[i].codigo, vetorFesta[i].cliente,
                                    vetorFesta[i].convidados,vetorFesta[i].tema,vetorFesta[i].data,
                                    vetorFesta[i].diaSemana,vetorFesta[i].horario,vetorFesta[i].horario+4);

                                    if(Search_in_File("Contratos.txt")==2)
                                               {
                                                lerContrato(vetorContrato);
                                                for(j = 0;j<numeroContratos;j++)
                                                {

                                               if(vetorContrato[j].codigo == vetorFesta[i].codigo)
                                               {

                                                   printf("Numero do contrato: %i\nValor total: %f\n Desconto: %f \nValor Final : %f\nForma de pagamento: %i Parcela(s)\nStatus 1 para pago 2 para nao pago e 3 para cancelado: %i \nCodigo da festa: %i\n"
                                                          ,vetorContrato[j].num,vetorContrato[j].valorTotal,vetorContrato[j].desconto,vetorContrato[j].valorFinal,vetorContrato[j].pagamento,vetorContrato[j].status,vetorContrato[j].codigo);

                                               }

                                                }
                                               }else{
                                                    printf("Nenhum contrato cadastrado\n");
                                                 main();
                                                }
                   }

               }

            }





        }
        else{
            printf("Nenhuma festa cadastrada\n");
            main();
        }


}

void attContrato(Contrato vetorContrato[])
{
     int i,j,num,valor;


            if(Search_in_File("Contratos.txt")==2)
        {
            lerContrato(vetorContrato);
            printf("Digite o numero do contrato: ");
            scanf("%i",&num);
            fflush(stdin);

            for ( i = 0; i < numeroContratos; i++)
            {
                if(vetorContrato[i].num == num)
                {
printf("Numero do contrato: %i\nValor total: %f\n Desconto: %f \nValor Final : %f\nForma de pagamento: %i Parcela(s)\nStatus 1 para pago 2 para nao pago e 3 para cancelado: %i \nCodigo da festa: %i\n"
                                                          ,vetorContrato[i].num,vetorContrato[i].valorTotal,vetorContrato[i].desconto,vetorContrato[i].valorFinal,vetorContrato[i].pagamento,vetorContrato[i].status
                                                          ,vetorContrato[i].codigo);
                          printf("\nVoce deseja pagar o contrato:\n1-sim\n2-nao\n3-cancelado");
                scanf("%i",&vetorContrato[i].status);
                FILE *arq6 = fopen("Contratos.txt","w");
                for(j=0;j<numeroContratos;j++){
        fprintf(arq6,"%i;%f;%f;%f;%i;%i;%i\n",vetorContrato[j].num,vetorContrato[j].valorTotal,vetorContrato[j].desconto,vetorContrato[j].valorFinal,vetorContrato[j].pagamento,vetorContrato[j].status
                                                          ,vetorContrato[j].codigo);
                                                          }

        fclose(arq6);


                }


            }






        }

        else {
            printf("Nenhum contatro cadastrado.\n");
            main();
        }






}





void calculaPreco(Festa vetorFestas[])
{
    int i,cod,parcl;
    if(Search_in_File("Festas.txt")==2)
        {
    Contrato contract;
    printf("Digite o codigo da festa: ");
    scanf("%d",&cod);
    lerFesta(vetorFestas);


    for ( i = 0; i < numeroFestas; i++)
    {
        if(cod==vetorFestas[i].codigo)
        {
            if(vetorFestas[i].convidados<50)
            {
                if(vetorFestas[i].diaSemana >= 2 && vetorFestas[i].diaSemana<6)
                {
                   preco = 1899.00;
                }
                else
                {
                   preco = 2099.00;

                }

            }

            else if(vetorFestas[i].convidados >= 50 && vetorFestas[i].convidados <80)
            {
                if(vetorFestas[i].diaSemana >= 2 && vetorFestas[i].diaSemana<6)
                {
                   preco = 2199.00;
                }
                else
                {
                   preco = 2299.00;

                }

            }

            else if(vetorFestas[i].convidados >= 80 && vetorFestas[i].convidados <100)
            {
                if(vetorFestas[i].diaSemana >= 2 && vetorFestas[i].diaSemana<6)
                {
                   preco = 3199.00;
                }
                else
                {
                   preco = 3499.00;

                }

            }

            else if(vetorFestas[i].convidados >= 100)
            {
                if(vetorFestas[i].diaSemana >= 2 && vetorFestas[i].diaSemana<6)
                {
                   preco = 3799.00;
                }
                else
                {
                   preco = 3999.00;

                }

            }

        }
    }
    if(preco<1800)
    {
        printf("Codigo nao encontrado\n");
        main();
    }

    contract.codigo = cod;
    contract.valorTotal=preco;
    printf("%f\n",preco);

    float valFinal,desconto;
    printf("Qual sua forma de pagamento: \n1- A vista \n2- Duas parcelaas \n3- Tres parcelas \n4- Quatro ou mais parcelas");
    scanf("%i",&parcl);
    fflush(stdin);

    if(parcl==1)
    {
        desconto= ((preco*10.0)/100);
        valFinal = (preco - desconto);
    }
    else if(parcl==2)
    {
        desconto=((preco*5.0)/100);
        valFinal = (preco - desconto);

    }
    else if(parcl==3)
    {
        desconto=((preco*2.0)/100);
        valFinal = (preco - desconto);

    }
    else if(parcl==4)
    {
        valFinal = preco;
    }

    contract.pagamento =parcl;
    contract.desconto = desconto;
    contract.valorFinal = valFinal;
    printf("Deseja realizar o pagamento agora:\n1-Pagar \n2-Nao pagar");
    scanf("%i",&contract.status);
    fflush(stdin);

    printf("O preco e: %4.f\n",valFinal);

    if(Search_in_File("Contratos.txt")==2)
        {
            lerContrato(vetorContrato);
            contract.num = numeroContratos+1;
        }
        else{
            contract.num=1;
        }

        FILE *arq6 = fopen("Contratos.txt","a");
        fprintf(arq6,"%i;%f;%f;%f;%i;%i;%i\n",contract.num,contract.valorTotal,contract.desconto,contract.valorFinal,contract.pagamento,contract.status,contract.codigo);

        fclose(arq6);
        }

        else
        {
            printf("Nenhuma festa cadastrada.\n");
            main();
        }



}


