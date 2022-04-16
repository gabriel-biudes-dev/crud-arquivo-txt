#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "main.h"

int mostrarMenu(){
  int opt;
  printf("\n\t[MENU]\n");
  printf(" 1)Cadastrar cliente\n");
  printf(" 2)Cadastrar alimento\n");
  printf(" 3)Mostrar relatório\n");
  printf(" 4)Deletar cliente\n");
  printf(" 5)Deletar alimento\n");
  printf(" 6)Deletar pedido\n");
  printf(" 7)Editar cliente\n");
  printf(" 8)Editar alimento\n");
  printf(" 9)Consultar cliente\n");
  printf("10)Consultar alimento\n");
  printf("11)Sair\n\n");
  printf("Insira a opção: ");
  scanf("%d%*c", &opt);
  return opt;
}

int vazio(char* nomeArquivo){
  FILE *f;
  char buff[255] = "";
  f = fopen(nomeArquivo, "r");
  fscanf(f, "%s", buff);
  if (!*buff)
    return 1;
  else
    return 0;
  fclose(f);
}

void guardarErro(char *msg){
  FILE *f;
  f = fopen("erros.txt", "a");
  fprintf(f, "%s", msg);
  fclose(f);
}

int maiorId(char *arq, int n){
  FILE *f;
  int i, j, maior = 0;
  char *linha = (char*) malloc(1000);
  f = fopen(arq, "r");
  for(i = 0; fgets(linha, 1000, f); i++){
    strtok(linha, "|");
    for(j = 1; j < n; j++) linha = strtok(NULL, "|");
    if(atoi(linha) > maior){
      maior = atoi(linha);
    }
  }
  fclose(f);
  return maior;
}

int maiorString(char *fn, int n){
  int i, j, maior = 0;
  char *linha = (char*) malloc(1000);
  FILE *f = fopen(fn, "r");
  for(i = 0; fgets(linha, 1000, f); i++){
    strtok(linha, "|");
    for(j = 1; j < n; j++){
      linha = strtok(NULL, "|");
    }
    if(strlen(linha) > maior){
      maior = strlen(linha);
    }
  }
  return maior;
}

void removerLinha(char *nomeArquivo, char *idn, int n){
  char *id, *linha, *temp, novoTexto[100000] = "";
  FILE *f;
  int i, j;
  id = (char*) malloc(10);
  linha = (char*) malloc(1000);
  temp = (char*) malloc(1000);
  if(strcmp(idn, "0") == 0){
    printf("\nInsira o ID do registro a ser deletado: ");
    scanf("%s", id);
  }else{
    id = idn;
  }
  f = fopen(nomeArquivo, "r");
  for(i = 0; fgets(linha, 1000, f); i++){
    strcpy(temp, linha);
    strtok(temp, "|");
    for(j = 1; j < n; j++) temp = strtok(NULL, "|");
    if(strcmp(temp, id) != 0){
      strcat(novoTexto, linha);
    }
  }
  while(temp != NULL){
    temp = strtok(NULL, "|");
  }
  free(linha);
  free(temp);
  fclose(f);
  f = fopen(nomeArquivo, "w");
  fprintf(f, "%s", novoTexto);
  fclose(f);
  if(strcmp(nomeArquivo, "alimentos.txt") == 0){
    removerLinha("historico_atual.txt", id, 2);
  }
}

void listarIDS(char *nomeArquivo){
  FILE *f;
  int i;
  char temp[10000] = "[";
  char *linha;
  linha = (char*) malloc(1000);
  f = fopen(nomeArquivo, "r");
  printf("\n\tLISTA DE IDs\n\n");
  if(!vazio(nomeArquivo)){
  for(i = 0; fgets(linha, 1000, f); i++){
    strtok(linha, "|");
    linha = strtok(NULL, "|");
    strcat(temp, linha);
    strcat(temp, ", ");
  }
  while(linha != NULL){
    linha = strtok(NULL, "|");
  }
  *(temp + strlen(temp) - 2) = '\0';
  }
  strcat(temp, "]");
  printf("%s", temp);
  free(linha);
}

char* consultarRegistro(char* nomeArquivo, char *id){
  FILE *f;
  int i, val = 0;
  char *linha, *temp;
  f = fopen(nomeArquivo, "r");
  if(!vazio(nomeArquivo)){
    linha = (char*) malloc(1000);
    temp = (char*) malloc(1000);
    for(i = 0; fgets(linha, 1000, f); i++){
      strcpy(temp, linha);
      strtok(temp, "|");
      temp = strtok(NULL, "|");
      if(strcmp(temp, id) == 0){
        return linha;
      }
    }
    while(temp != NULL){
      temp = strtok(NULL, "|");
    }
  }
  fclose(f);
  free(linha);
  free(temp);
  return "";
}

void mostrarPedido(char *str){
  int maior, i;
  char *temp = (char*) malloc(1000);
  maior = maiorString("historico_completo.txt", 4);
  strcpy(temp, str);
  strtok(temp, "|");
  printf("%3d          ", atoi(temp));
  temp = strtok(NULL, "|");
  printf("%3d            ", atoi(temp));
  temp = strtok(NULL, "|");
  temp = strtok(NULL, "|");
  printf("%s  ", temp);
  for(i = 0; i < (maior - strlen(temp)); i++) printf(" ");
  for(i = maior; i < 18; i++) printf(" ");
  temp = strtok(NULL, "|");
  printf("%s", temp);
  while(temp != NULL){
    temp = strtok(NULL, "|");
  }
  free(temp);
}

void mostrarPedidos(char *nomeArquivo, char *id){
  FILE *f;
  char *linha, *temp;
  int i;
  linha = (char*) malloc(1000);
  temp = (char*) malloc(1000);
  f = fopen(nomeArquivo, "r");
  printf("[ID_PEDIDO]  ");
  printf("[ID_ALIMENTO]  ");
  printf("[NOME DO ALIMENTO]  ");
  printf("[NOME DO CLIENTE]\n");
  if(!vazio(nomeArquivo)){
    for(i = 0; fgets(linha, 1000, f); i++){
      strcpy(temp, linha);
      strtok(temp, "|");
      temp = strtok(NULL, "|");
      temp = strtok(NULL, "|");
      if(strcmp(id, "0") == 0){
        mostrarPedido(linha);
      }else{
        if(strcmp(temp, id) == 0) mostrarPedido(linha);
      }
    }
    while(temp != NULL){
      temp = strtok(NULL, "|");
    }
  }
  free(temp);
  free(linha);
}

void consultar(char* nomeArquivo){
  char *id, *registro;
  id = (char*) malloc(10);
  registro = (char*) malloc(1000);
  printf("\nInsira o ID do registro: ");
  scanf("%s", id);
  registro = consultarRegistro(nomeArquivo, id);
  if(strlen(registro) < 1){
    printf("\nNenhum registro com esse ID foi encontrado\n");
  }else{
    if(strcmp(nomeArquivo, "clientes.txt") == 0){
      strtok(registro, "|");
      registro = strtok(NULL, "|");
      printf("\n[CLIENTE ENCONTRADO]\n");
      printf("ID: %s\n", registro);
      registro = strtok(NULL, "|");
      printf("Nome: %s\n", registro);
      registro = strtok(NULL, "|");
      printf("Nascimento: %02d/", atoi(registro));
      registro = strtok(NULL, "|");
      printf("%02d/", atoi(registro));
      registro = strtok(NULL, "|");
      printf("%04d\n", atoi(registro));
      registro = strtok(NULL, "|");
      printf("Viagens: %s\n", registro);
      printf("\n[HISTÓRICO COMPLETO DE PEDIDOS]\n\n");
      mostrarPedidos("historico_completo.txt", id);
      printf("\n[HISTÓRICO ATUAL DE PEDIDOS]\n\n");
      mostrarPedidos("historico_atual.txt", id);
    }
    if(strcmp(nomeArquivo, "alimentos.txt") == 0){
      strtok(registro, "|");
      registro = strtok(NULL, "|");
      printf("\n[ALIMENTO ENCONTRADO]\n");
      printf("ID: %s\n", registro);
      registro = strtok(NULL, "|");
      printf("Nome: %s\n", registro);
      registro = strtok(NULL, "|");
      printf("Marca: %s\n", registro);
      registro = strtok(NULL, "|");
      printf("Valor calórico: %.2f\n", atof(registro));
      registro = strtok(NULL, "|");
      printf("Preço: %.2f\n", atof(registro));
    }
  }
}

int validarCliente(Cliente *cliente){
  char *mensagem = (char*) malloc(500);
  if(strlen(cliente->nome_completo) < 1){
    printf("\nERRO: preencha o nome do cliente\n");
    strcpy(mensagem, "O nome do cliente não foi preenchido\n");
    guardarErro(mensagem);
    return 0;
  }
  if(cliente->dia < 1 || cliente->dia > 31){
    printf("\nERRO: o dia deve estar entre 1 e 31\n");
    strcpy(mensagem, "Um valor inválido para o dia de nascimento foi digitado\n");
    guardarErro(mensagem);
    return 0;
  }
  if(cliente->mes < 1 || cliente->mes > 12){
    printf("\nERRO: o mês deve estar entre 1 e 12\n");
    strcpy(mensagem, "Um valor inválido para o mês de nascimento foi digitado\n");
    guardarErro(mensagem);
    return 0;
  }
  if(cliente->ano < 1900 || cliente ->ano > 2022){
    printf("\nERRO: insira um ano de nascimento correto\n");
    strcpy(mensagem, "Um valor inválido para o ano de nascimento foi digitado\n");
    guardarErro(mensagem);
    return 0;
  }
  if(cliente->viagens < 0){
    printf("\nERRO: insira uma quantidade de viagens correta\n");
    strcpy(mensagem, "Um valor inválido para a quantidade de viagens foi digitado\n");
    guardarErro(mensagem);
    return 0;
  }
  free(mensagem);
  return 1;
}

void registrar(char *nomeArquivo, char* registro){
  FILE *f;
  f = fopen(nomeArquivo, "a");
  fprintf(f, "%s", registro);
  fclose(f);
}

void registrarPedidos(Cliente *cliente, int id){
  int id_pedido;
  char *str, *registro, *aux;
  char registro_final[1000] = "";
  str = (char*) malloc(sizeof(1000));
  registro = (char*) malloc(sizeof(1000));
  aux = (char*) malloc(sizeof(1000));

  printf("\nInsira o ID de um alimento pedido pelo cliente (aperte apenas enter para finalizar): ");
  while(scanf("%[^\n]%*c", str)){
    registro = consultarRegistro("alimentos.txt", str);
    if(strlen(registro) < 1){
      printf("Não há nenhum alimento com esse ID cadastrado\n");
    }else{
      id_pedido = maiorId("historico_completo.txt", 1) + 1;
      sprintf(aux, "%d", id_pedido);
      strcat(registro_final, aux);
      strcat(registro_final, "|");
      strtok(registro, "|");
      registro = strtok(NULL, "|");
      strcat(registro_final, registro);
      strcat(registro_final, "|");
      sprintf(aux, "%d", id);
      strcat(registro_final, aux);
      strcat(registro_final, "|");
      registro = strtok(NULL, "|");
      strcat(registro_final, registro);
      strcat(registro_final, "|");
      strcat(registro_final, cliente->nome_completo);
      strcat(registro_final, "\n");
      registrar("historico_completo.txt", registro_final);
      registrar("historico_atual.txt", registro_final);
      strcpy(registro_final, "");
    }
  }
  free(str);
  free(registro);
  free(aux);
}

void registrarCliente(Cliente *cliente){
  int id, maior_id = 0;
  maior_id = maiorId("clientes.txt", 2);
  id = maior_id + 1;
  FILE *f;
  if(validarCliente(cliente)){
    f = fopen("clientes.txt", "a");
    fprintf(f, "CLIENTE|%d|%s|%d|%d|%d|%d\n", id, cliente->nome_completo, cliente->dia, cliente->mes, cliente->ano, cliente->viagens);
    fclose(f);
    registrarPedidos(cliente, id);
  }
}

void cadastrarCliente(){
  Cliente *cliente;
  cliente = (Cliente*) malloc(sizeof(Cliente));
  char str[1000] = "";
  printf("%s", str);
  char *nome, *temp;
  int dia, mes, ano;
  temp = (char*) malloc(1000);
  strcpy(temp, "");
  printf("\nInsira o nome do cliente: ");
  scanf("%[^\n]%*c", str);
  nome = (char*) malloc(strlen(str) + 1);
  strcpy(nome, str);
  cliente->nome_completo = nome;
  printf("\nInsira a quantidade de viagens do cliente: ");
  scanf("%[^\n]%*c", temp);
  cliente->viagens = atoi(temp);
  printf("\nInsira a data de nascimento (dd/mm/yy): ");
  scanf("%d%*c", &cliente->dia);
  scanf("%d%*c", &cliente->mes);
  scanf("%d%*c", &cliente->ano);
  registrarCliente(cliente);

  free(nome);
  free(cliente);
  free(temp);
}

void mostrarClientes(){
  FILE *f;
  int i, j, maiorNcliente;
  char *linha = (char*) malloc(1000);

  maiorNcliente = maiorString("clientes.txt", 3);
  f = fopen("clientes.txt", "r");
  printf("\n\tLISTA DE CLIENTES\n\n");
  printf("[ID]  ");
  printf("[NOME]  ");
  for(i = 0; i < maiorNcliente - 7; i++) printf(" ");
  printf("[NASCIMENTO]  ");
  printf("[VIAJENS]");
  printf("\n");

  for(i = 0; fgets(linha, 1000, f); i++){
    strtok(linha, "|");
    linha = strtok(NULL, "|");
    printf("%3d", atoi(linha));
    linha = strtok(NULL, "|");
    printf("   %s ", linha);
    for(i = 0; i < (maiorNcliente - strlen(linha)); i++) printf(" ");
    for(i = maiorNcliente; i <= 6; i++) printf(" ");
    linha = strtok(NULL, "|");
    printf("%02d/", atoi(linha));
    linha = strtok(NULL, "|");
    printf("%02d/", atoi(linha));
    linha = strtok(NULL, "|");
    printf("%04d", atoi(linha));
    linha = strtok(NULL, "|");
    printf("     %2d", atoi(linha));
    printf("\n");
  }
}

void editarCliente(char *registro){
  Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));
  FILE *f;
  int opt, valor;
  char *novoNome, temp[1000] = "";
  char temp2[50], id[50];
  novoNome = (char*) malloc(500);
  strtok(registro, "|");
  strcat(temp, registro);
  strcat(temp, "|");
  printf("Qual o campo a ser alterado?\n");
  printf("\n1)Nome\n");
  printf("2)Dia de nascimento\n");
  printf("3)Mês de nascimento\n");
  printf("4)Ano de nascimento\n");
  printf("5)Quantidade de viagens\n");
  printf("\nInsira a opção: ");
  scanf("%d%*c", &opt);
  registro = strtok(NULL, "|");
  strcpy(id, registro);
  strcat(temp, registro);
  strcat(temp, "|");
  registro = strtok(NULL, "|");
  if(opt == 1){
    printf("\nInsira o novo nome: ");
    scanf("%[^\n]%*c", novoNome);
    strcat(temp, novoNome);
    strcat(temp, "|");
    cliente->nome_completo = novoNome;
  }else{
    strcat(temp, registro);
    strcat(temp, "|");
    cliente->nome_completo = registro;
  }
  registro = strtok(NULL, "|");
  if(opt == 2){
    printf("\nInsira o novo dia: ");
    scanf("%d", &valor);
    sprintf(temp2, "%d", valor);
    strcat(temp, temp2);
    strcat(temp, "|");
    cliente->dia = valor;
  }else{
    strcat(temp, registro);
    strcat(temp, "|");
    cliente->dia = atoi(registro);
  }
  registro = strtok(NULL, "|");
  if(opt == 3){
    printf("\nInsira o novo mês: ");
    scanf("%d", &valor);
    sprintf(temp2, "%d", valor);
    strcat(temp, temp2);
    strcat(temp, "|");
    cliente->mes = valor;
  }else{
    strcat(temp, registro);
    strcat(temp, "|");
    cliente->mes = atoi(registro);
  }
  registro = strtok(NULL, "|");
  if(opt == 4){
    printf("\nInsira o novo ano: ");
    scanf("%d", &valor);
    sprintf(temp2, "%d", valor);
    strcat(temp, temp2);
    strcat(temp, "|");
    cliente->ano = valor;
  }else{
    strcat(temp, registro);
    strcat(temp, "|");
    cliente->ano = atoi(registro);
  }
  registro = strtok(NULL, "|");
  if(opt == 5){
    printf("\nInsira a nova quantidade de viagens: ");
    scanf("%d", &valor);
    sprintf(temp2, "%d", valor);
    strcat(temp, temp2);
    cliente->viagens = valor;
  }else{
    strcat(temp, registro);
    cliente->viagens = atoi(registro);
  }
  if(validarCliente(cliente)){
    removerLinha("clientes.txt", id, 2);
    f = fopen("clientes.txt", "a");
    fprintf(f, "%s", temp);
    fclose(f);
  }
  free(cliente);
  free(novoNome);
}

int validarAlimento(Alimento *alimento){
  char *mensagem = (char*) malloc(500);
  if(strlen(alimento->nome) < 1){
    printf("\nERRO: preencha o nome do alimento\n");
    strcpy(mensagem, "O nome do alimento não foi preenchido\n");
    guardarErro(mensagem);
    return 0;
  }
  if(alimento->valor_calorico <= 0){
    printf("\nERRO: preencha o valor calórico do alimento corretamente\n");
    strcpy(mensagem, "Um valor inválido para o valor calorico do alimento foi digitado\n");
    guardarErro(mensagem);
    return 0;
  }
  if(alimento->preco < 0){
    printf("\nERRO: preencha o custo do alimento corretamente\n");
    strcpy(mensagem, "Um valor inválido para o custo do alimento foi digitado\n");
    guardarErro(mensagem);
    return 0;
  }
  free(mensagem);
  return 1;
}

void registrarAlimento(Alimento *alimento){
  int id, maior_id = 0;
  maior_id = maiorId("alimentos.txt", 2);
  id = maior_id + 1;
  FILE *f;
  if(validarAlimento(alimento)){
    f = fopen("alimentos.txt", "a");
    fprintf(f, "ALIMENTO|%d|%s|%s|%.2f|%.2f\n", id, alimento->nome, alimento->marca, alimento->valor_calorico, alimento->preco);
    fclose(f);
  }
}

void cadastrarAlimento(){
  Alimento *alimento;
  alimento = (Alimento*) malloc(sizeof(Alimento));
  char str[1000] = "";
  char *nome;
  char *marca;
  printf("\nInsira o nome do alimento: ");
  scanf("%[^\n]%*c", str);
  nome = (char*) malloc(strlen(str) + 1);
  strcpy(nome, str);
  strcpy(str, "");
  alimento->nome = nome;
  printf("Insira o valor calórico do alimento: ");
  scanf("%f", &alimento->valor_calorico);
  printf("Insira o preço do alimento: ");
  scanf("%f%*c", &alimento->preco);
  printf("Insira a marca (aperte enter caso não exista): ");
  scanf("%[^\n]%*c", str);
  marca = (char*) malloc(strlen(str) + 1);
  strcpy(marca, str);
  if(strlen(marca) == 0){
    strcpy(marca, "nenhuma");
  }
  alimento->marca = marca;
  registrarAlimento(alimento);
  free(marca);
  free(nome);
  free(alimento);
}

void mostrarAlimentos(){
  FILE *f;
  int i, j, maiorNalimento, maiorNmarca;
  char *linha = (char*) malloc(1000);

  maiorNalimento = maiorString("alimentos.txt", 3);
  maiorNmarca = maiorString("alimentos.txt", 4);
  f = fopen("alimentos.txt", "r");
  printf("\n\tLISTA DE ALIMENTOS\n\n");
  printf("[ID]  ");
  printf("[NOME]  ");
  for(i = 0; i < (maiorNalimento - 6); i++) printf(" ");
  printf("[MARCA]  ");
  for(i = 0; i < (maiorNmarca - 7); i++) printf(" ");
  printf("[VALOR CALORICO]");
  printf("  [CUSTO]");
  printf("\n");

  for(i = 0; fgets(linha, 1000, f); i++){
    strtok(linha, "|");
    linha = strtok(NULL, "|");
    printf("%3d", atoi(linha));
    linha = strtok(NULL, "|");
    printf("   %s  ", linha);
    for(i = 0; i < (maiorNalimento - strlen(linha)); i++) printf(" ");
    for(i = maiorNalimento; i < 6; i++) printf(" ");
    linha = strtok(NULL, "|");
    printf("%s  ", linha);
    for(i = 0; i < (maiorNmarca - strlen(linha)); i++) printf(" ");
    for(i = maiorNmarca; i < 7; i++) printf(" ");
    linha = strtok(NULL, "|");
    printf("%.2f", atof(linha));
    linha = strtok(NULL, "|");
    printf("\t\t    R$ %.2f", atof(linha));
    printf("\n");
  }
}

void editarAlimento(char* registro){
  Alimento *alimento = (Alimento*) malloc(sizeof(Alimento));
  FILE *f;
  int opt;
  float valor;
  char *novoNome, temp[1000] = "";
  char temp2[50], id[50];
  novoNome = (char*) malloc(500);
  strtok(registro, "|");
  strcat(temp, registro);
  strcat(temp, "|");
  printf("Qual o campo a ser alterado?\n");
  printf("\n1)Nome\n");
  printf("2)Marca\n");
  printf("3)Valor calórico\n");
  printf("4)Custo\n");
  printf("\nInsira a opção: ");
  scanf("%d%*c", &opt);
  registro = strtok(NULL, "|");
  strcpy(id, registro);
  strcat(temp, registro);
  strcat(temp, "|");
  registro = strtok(NULL, "|");
  if(opt == 1){
    printf("\nInsira o novo nome: ");
    scanf("%[^\n]%*c", novoNome);
    strcat(temp, novoNome);
    strcat(temp, "|");
    alimento->nome = novoNome;
  }else{
    strcat(temp, registro);
    strcat(temp, "|");
    alimento->nome = registro;
  }
  registro = strtok(NULL, "|");
  if(opt == 2){
    printf("\nInsira a nova marca: ");
    scanf("%[^\n]%*c", novoNome);
    strcat(temp, novoNome);
    strcat(temp, "|");
    alimento->nome = novoNome;
  }else{
    strcat(temp, registro);
    strcat(temp, "|");
    alimento->nome = registro;
  }
  registro = strtok(NULL, "|");
  if(opt == 3){
    printf("\nInsira o novo valor calórico: ");
    scanf("%f%*c", &valor);
    sprintf(temp2, "%f", valor);
    strcat(temp, temp2);
    strcat(temp, "|");
    alimento->valor_calorico = valor;
  }else{
    strcat(temp, registro);
    strcat(temp, "|");
    alimento->valor_calorico = atof(registro);
  }
  registro = strtok(NULL, "|");
  if(opt == 4){
    printf("\nInsira o novo custo: ");
    scanf("%f%*c", &valor);
    sprintf(temp2, "%f", valor);
    strcat(temp, temp2);
    alimento->preco = valor;
  }else{
    strcat(temp, registro);
    alimento->preco = atof(registro);
  }
  if(validarAlimento(alimento)){
    removerLinha("alimentos.txt", id, 2);
    f = fopen("alimentos.txt", "a");
    fprintf(f, "%s", temp);
    fclose(f);
  }
  free(alimento);
  free(novoNome);
}

void editar(char* nomeArquivo){
  char *id, *registro;
  id = (char*) malloc(10);
  registro = (char*) malloc(1000);
  printf("\nInsira o ID do registro a ser editado: ");
  scanf("%s", id);
  registro = consultarRegistro(nomeArquivo, id);
  if(strlen(registro) < 1){
    printf("\nERRO: nenhum registro com o ID informado foi encontrado\n");
  }else{
    if(strcmp(nomeArquivo, "clientes.txt") == 0){
      editarCliente(registro);
    }
    if(strcmp(nomeArquivo, "alimentos.txt") == 0){
      editarAlimento(registro);
    }
  }
}

void mostrarRelatorio(){
  mostrarClientes();
  printf("\n");
  printf("[HISTÓRICO COMPLETO]\n\n");
  mostrarPedidos("historico_completo.txt", "0");
  printf("\n");
  printf("[HISTÓRICO ATUAL]\n\n");
  mostrarPedidos("historico_atual.txt", "0");
  printf("\n");
  mostrarAlimentos();
}

int main()
{
  setlocale(LC_ALL, "");
  int opt;
  opt = mostrarMenu();
  while(opt != 11){
    if(opt == 1){
      cadastrarCliente();
      listarIDS("clientes.txt");
    }
    if(opt == 2){
      cadastrarAlimento();
      listarIDS("alimentos.txt");
    }
    if(opt == 3){
      mostrarRelatorio();
    }
    if(opt == 4){
      removerLinha("clientes.txt", "0", 2);
      listarIDS("clientes.txt");
    }
    if(opt == 5){
      removerLinha("alimentos.txt", "0", 2);
      listarIDS("alimentos.txt");
    }
    if(opt == 6){
      removerLinha("historico_atual.txt", "0", 1);
    }
    if(opt == 7){
      editar("clientes.txt");
      listarIDS("clientes.txt");
    }
    if(opt == 8){
      editar("alimentos.txt");
      listarIDS("alimentos.txt");
    }
    if(opt == 9){
      consultar("clientes.txt");
      listarIDS("clientes.txt");
    }
    if(opt == 10){
      consultar("alimentos.txt");
      listarIDS("alimentos.txt");
    }
    printf("\n\n");
    opt = mostrarMenu();
  }
  return 0;
}
