#include<stdio.h>
#include<locale.h>
#include<string.h>

typedef struct{
	char nome[20];
	char descricao[100];
}marca;

typedef struct{
	char nome[20];
	int marca;
	char descricao[100];
	int tipoPlug;
}veiculo;

typedef struct{
	char nome[20];
	char endereco[100];
	int plug1;
	int plug2;
	int plug3;
}ponto;

typedef struct{
	int dia;
	int mes;
	int ano;
}data;

typedef struct{
	int carro;
	int ponto;
	data dataRecarga;
	float consumo;
}recarga;

marca marcas[20];
int posicaoMarcas=0;

veiculo veiculos[20];
int posicaoVeiculos=0;

ponto pontos[20];
int posicaoPontos=0;

recarga recargas[40];
int posicaoRecargas=0;

int plugsVerif[3];

void relatorioMarcas(){

	int i, contador=1;

	system("cls");
	printf("===== Relatório de Marcas =====\n\n");

	printf("Marca           Descrição\n");
	for(i=0;i<posicaoMarcas;i++){
		printf("%d. %-12s %s\n", contador, marcas[i].nome, marcas[i].descricao);
		contador++;
	}

	getche();
}

void relatorioVeiculos(){

	int i, contador=1;

	system("cls");
	printf("===== Relatório de Veículos =====\n\n");

	printf("Marca       Marca          Descrição\n");
	for(i=0;i<posicaoVeiculos;i++){

		printf("%d. %-8s %10s %s", contador, veiculos[i].nome, marcas[veiculos[i].marca].nome, veiculos[i].descricao, veiculos[i].tipoPlug);
		contador++;
	}

	getche();
}

void relatorioPontos(){

	int i, contador=1;

	system("cls");
	printf("===== Relatório de Pontos =====\n\n");

	printf("Local Endereço Tipo2 CCS CHAdeMO\n");

	for(i=0;i<posicaoPontos;i++){
		printf("%d. %-12s %-15s %-5d %-5d %-5d", contador, pontos[i].nome, pontos[i].endereco, pontos[i].plug1, pontos[i].plug2, pontos[i].plug3);
		contador++;
	}

	getche();
}

void relatorioRecargas(){

	int i, contador=1;

	system("cls");
	printf("===== Relatório de Recargas =====\n\n");

	printf("Veículo Local Data\n");

	for(i=0;i<posicaoRecargas;i++){
		printf("%d. %-10s %-10s %-10d/%d/%d", contador, veiculos[recargas[i].carro].nome, pontos[recargas[i].ponto].nome, recargas[i].dataRecarga.dia, recargas[i].dataRecarga.mes, recargas[i].dataRecarga.ano, recargas[i].consumo);
		contador++;
	}

	getche();
}

void cadastraMarca(){

	system("cls");
	printf("===== Cadastro de Marca =====\n\n");

	fflush(stdin);

	printf("Digite o nome da marca: ");
	gets(marcas[posicaoMarcas].nome);

	printf("Digite a descrição da marca: ");
	gets(marcas[posicaoMarcas].descricao);

	posicaoMarcas++;

	printf("\nMarca cadastrada com sucesso! Digite qualquer tecla para continuar\n");

	getche();
}

void cadastraVeiculo(){

	int idMarca, i;

	system("cls");
	printf("===== Cadastro de Modelo =====\n");

	fflush(stdin);

	printf("Digite o nome do modelo: ");
	gets(veiculos[posicaoVeiculos].nome);

	printf("\nMarcas cadastradas: \n");
	for(i=0;i<posicaoMarcas;i++){
		printf("%d. %s\n", i, marcas[i].nome);
	}

    do{
		printf("Digite a marca do modelo: ");
		scanf("%d", &idMarca);

	}while(idMarca<0 || idMarca>=posicaoMarcas);

	printf(" - Marca selecionada: %s\n", marcas[idMarca].nome);

	veiculos[posicaoVeiculos].marca = idMarca;

	fflush(stdin);

	printf("Digite a descrição do modelo: ");
	gets(veiculos[posicaoVeiculos].descricao);

	printf("Digite o tipo de plug: ");
	scanf("%d", &veiculos[posicaoVeiculos].tipoPlug);

	posicaoVeiculos++;

	printf("\nModelo cadastrado com sucesso! Digite qualquer tecla para continuar\n");

	getche();
}

void cadastraPonto(){

	system("cls");
	printf("===== Cadastro Ponto de Recarga =====\n");

	fflush(stdin);

	printf("Digite o nome do ponto de recarga: ");
	gets(pontos[posicaoPontos].nome);

	printf("Digite o endereço do ponto de recarga: ");
	gets(pontos[posicaoPontos].endereco);

	printf("Plug - Tipo 2: ");
	scanf("%d", &pontos[posicaoPontos].plug1);

	if(pontos[posicaoPontos].plug1==1){
		plugsVerif[0] = 1;
	} else
		plugsVerif[0] = 0;

	printf("Plug - CCS: ");
	scanf("%d", &pontos[posicaoPontos].plug2);

	if(pontos[posicaoPontos].plug2==1){
		plugsVerif[1] = 2;
	} else
		plugsVerif[1] = 0;

	printf("Plug - CHAdeMO: ");
	scanf("%d", &pontos[posicaoPontos].plug3);

	if(pontos[posicaoPontos].plug3==1){
		plugsVerif[2] = 3;
	} else
		plugsVerif[2] = 0;

	posicaoPontos++;

	printf("\nMarca cadastrada com sucesso! Digite qualquer tecla para continuar\n");

	getche();
}

void cadastraRecarga(){

	int idCarro, idRecarga, x, i, compatibilidade=0;

	system("cls");
	printf("===== Cadastro de Recarga =====\n");

	printf("\nModelos cadastrados: \n");
	for(i=0;i<posicaoVeiculos;i++){
		printf("%d. %s\n", i, veiculos[i].nome);
	}

	do{
		printf("Digite o modelo do carro: ");
		scanf("%d", &idCarro);

	}while(idCarro<0 || idCarro>=posicaoVeiculos);

	printf(" - Carro selecionado: %s\n", veiculos[idCarro].nome);

	recargas[posicaoRecargas].carro = idCarro;

	printf("\nPontos cadastrados: \n");
	for(i=0;i<posicaoPontos;i++){
		printf("%d. %s\n", i, pontos[i].nome);
	}

	do{
		printf("Digite o ponto de recarga: ");
		scanf("%d", &idRecarga);

	}while(idRecarga<0 || idRecarga>=posicaoPontos);

	printf(" - Ponto de recarga selecionado: %s\n", pontos[idRecarga].nome);

	recargas[posicaoRecargas].ponto = idRecarga;

	printf("Digite a data da recarga: ");
	scanf("%d", &recargas[posicaoRecargas].dataRecarga.dia);
	scanf("%d", &recargas[posicaoRecargas].dataRecarga.mes);
	scanf("%d", &recargas[posicaoRecargas].dataRecarga.ano);

	printf("Digite o consumo: ");
	scanf("%f", &recargas[posicaoRecargas].consumo);

		if(pontos[idRecarga].plug1==1 && veiculos[idCarro].tipoPlug==0 ||
            pontos[idRecarga].plug2==1 && veiculos[idCarro].tipoPlug==1 ||
            pontos[idRecarga].plug3==1 && veiculos[idCarro].tipoPlug==2){
            printf(" - O carro é compativel");
            }else{
            printf(" - O carro não é compativel");
            }




	printf("\nMarca cadastrada com sucesso! Digite qualquer tecla para continuar\n");

	getche();

}

void filtrarCarros(){

}

void filtrarRecargas(){

}

void filtrarPontos(){

}

void aplicarFiltros(){

	int op2;

	do{
		system("cls");
		printf("===== Aplicar filtros =====\n\n");

		printf("1. Filtrar carros\n");
		printf("2. Filtrar recargas\n");
		printf("3. Filtrar pontos\n");
		printf("4. Voltar\n");

		printf("\nDigite um número para filtrar uma informação: ");
		scanf("%d", &op2);

		switch(op2){

			case 1:
				filtrarCarros();
				break;

			case 2:
				filtrarRecargas();
				break;

			case 3:
				filtrarPontos();
				break;

			case 4:

				break;

			default:
				printf("Opção Inválida\n");
		}

	}while(op2!=4);
}

void exibirRelatorios(){

	int op;

	do{
		system("cls");
		printf("===== Menu de Relatórios =====\n\n");

		printf("1. Relatório de Marcas\n");
		printf("2. Relatório de Veículos\n");
		printf("3. Relatório de Pontos de Recarga\n");
		printf("4. Relatório de Recargas\n");
		printf("5. Aplicar filtros\n");

		printf("\nDigite um número para acessar um relatório: ");
		scanf("%d", &op);

		switch(op){

			case 1:
				relatorioMarcas();
				break;

			case 2:
				relatorioVeiculos();
				break;

			case 3:
				relatorioPontos();
				break;

			case 4:
				relatorioRecargas();
				break;

			case 5:
				aplicarFiltros();
				break;

			case 6:

				break;

			default:
				printf("Opção Inválida\n");
		}

	}while(op!=6);
};

main(){

	int op1;

	setlocale(LC_ALL, "Portuguese");

	do{

	system("cls");
	printf("====== Menu de Opções ======\n\n");
	printf("1. Cadastrar uma marca\n");
	printf("2. Cadastrar um modelo\n");
	printf("3. Cadastrar um ponto de recarga\n");
	printf("4. Cadastrar uma recarga\n");
	printf("5. Exibir relatórios\n");
	printf("6. Voltar\n");

	printf("\nDigite um número: ");

	scanf("%d", &op1);

	switch(op1){

		case 1:
			cadastraMarca();
			break;

		case 2:
			cadastraVeiculo();
			break;

		case 3:
			cadastraPonto();
			break;

		case 4:
			cadastraRecarga();
			break;

		case 5:
			exibirRelatorios();
			break;

		case 6:

			break;

		default:
			printf("TESTE");
	}

	}while(op1!=6);

}
