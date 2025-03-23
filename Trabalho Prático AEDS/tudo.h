
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUARTOS 100

void parseDate(const char *dateStr, struct tm *date) {
  sscanf(dateStr, "%d/%d/%d", &date->tm_mday, &date->tm_mon, &date->tm_year);
  date->tm_mon -= 1;
  date->tm_year -= 1900;
  date->tm_hour = 0;
  date->tm_min = 0;
  date->tm_sec = 0;
  date->tm_isdst = -1;
}

int baixarEstadia() {
  FILE *quartos = fopen("quartos.txt", "r+");
  FILE *estad = fopen("estadia.txt", "r");
  if (quartos == NULL || estad == NULL) {
    printf("Erro ao abrir os arquivos de quartos ou estadias.\n");
    return 1;
  }

  char linha[128], *id, *verificar, conversor[10], *entrada_str, *saida_str;
  int quarto, encontrado = 0;
  double preco = 0.0;

  printf("Digite o numero do quarto:\n");
  scanf("%d", &quarto);
  if (quarto < 1 || quarto > MAX_QUARTOS) {
    printf("Esse quarto não existe.\n");
    fclose(quartos);
    fclose(estad);
    return 1;
  }

  sprintf(conversor, "%d", quarto);
  rewind(quartos);

  while (fgets(linha, sizeof(linha), quartos) != NULL) {
    verificar = strtok(linha, ";");
    if (strcmp(conversor, verificar) == 0) {
      verificar = strtok(NULL, ";");
      verificar = strtok(NULL, ";");
      verificar = strtok(NULL, ";");

      if (strcmp(verificar, "ocupado") == 0) {
        encontrado = 1;
        break;
      }
    }
  }

  if (!encontrado) {
    printf("O quarto não está ocupado!\n");
    fclose(quartos);
    fclose(estad);
    return 1;
  }

  rewind(estad);
  encontrado = 0;

  while (fgets(linha, sizeof(linha), estad) != NULL) {
    id = strtok(linha, ";");
    strtok(NULL, ";");
    entrada_str = strtok(NULL, ";");
    saida_str = strtok(NULL, ";");
    verificar = strtok(NULL, ";");

    if (strcmp(verificar, conversor) == 0) {
      encontrado = 1;
      break;
    }
  }

  if (encontrado) {
    struct tm entrada = {0}, saida = {0};
    time_t entrada_tempo, saida_tempo;

    parseDate(entrada_str, &entrada);
    parseDate(saida_str, &saida);

    entrada_tempo = mktime(&entrada);
    saida_tempo = mktime(&saida);

    double diferenca_dias =
        difftime(saida_tempo, entrada_tempo) / (60 * 60 * 24);
    preco = diferenca_dias * 200.0;

    fseek(quartos, 0, SEEK_END);
    fprintf(quartos, "%d;%d;%d;%s\n", quarto, 0, 0, "desocupado");

    printf("O valor final ficará em %.2f reais\n", preco);
  } else {
    printf("Estadia não encontrada para o quarto informado.\n");
  }

  fclose(quartos);
  fclose(estad);
  return 0;
}

int quartos_disponiveis(int *contadores) {
  FILE *quartos = fopen("quartos.txt", "r");
  if (quartos == NULL) {
    perror("Erro ao abrir o arquivo de quartos");
    return 0;
  }

  char linha[128];
  int n_quarto;

  while (fgets(linha, sizeof(linha), quartos) != NULL) {
    char *token = strtok(linha, ";");
    n_quarto = atoi(token);
    if (n_quarto > 0 && n_quarto <= MAX_QUARTOS) {
      contadores[n_quarto - 1]++;
    }
  }

  fclose(quartos);

  for (int i = 0; i < MAX_QUARTOS; i++) {
    if (contadores[i] > 0 && contadores[i] % 2 != 0) {
      printf("Quarto %d: ocupado\n", i + 1);
    } else {
      printf("Quarto %d: desocupado\n", i + 1);
    }
  }
  return 0;
}

void escolher_quarto(int *quartos_disp, int quant_hos, char *idCl,
                     time_t entrada_tempo, time_t saida_tempo) {
  FILE *quartos = fopen("quartos.txt", "a+");
  FILE *estad = fopen("estadia.txt", "a+");
  int opcao, sem_hospedagem = quant_hos;

  if (quartos == NULL || estad == NULL) {
    perror("Erro ao abrir os arquivos");
    return;
  }

  do {
    printf("Cada quarto suporta 4 hospedes:\n");
    printf("Total de hospedes: %d\n", sem_hospedagem);
    printf("Selecione uma opcao dentre os quais estao desocupados (1 a %d):\n",
           MAX_QUARTOS);
    scanf("%d", &opcao);
    if (opcao < 1 || opcao > MAX_QUARTOS || quartos_disp[opcao - 1] % 2 != 0) {
      printf("Opcao invalida ou quarto ocupado. Escolha novamente.\n");
    } else if (sem_hospedagem > 4) {
      sem_hospedagem -= 4;
      quartos_disp[opcao - 1] = 1;
      fprintf(quartos, "%d;%d;%f;%s\n", opcao, 4,
              200 * difftime(saida_tempo, entrada_tempo) / (60 * 60 * 24),
              "ocupado");
      fprintf(estad, "%d;", opcao);
      printf("Voce escolheu o quarto %d\n\n", opcao);
    } else if (sem_hospedagem <= 4) {
      quartos_disp[opcao - 1] = 1;
      fprintf(quartos, "%d;%d;%f;%s\n", opcao, sem_hospedagem,
              200 * difftime(saida_tempo, entrada_tempo) / (60 * 60 * 24),
              "ocupado");
      fprintf(estad, "%d;\n", opcao);
      sem_hospedagem = 0;
      printf("Voce escolheu o quarto %d\n\n", opcao);
    }
    printf("%d hospedes restantes\n\n", sem_hospedagem);
  } while (sem_hospedagem > 0);
  fclose(quartos);
  fclose(estad);
}

const char *cadastrarEstadia() {
  char linha[128], *idArq, idCl[10], estad_cod[20];
  int quant_hos, clienteEncontrado = 0, quartos_disp[MAX_QUARTOS] = {0};

  struct tm entrada = {0}, saida = {0};

  time_t segundos;
  time(&segundos);
  struct tm *data = localtime(&segundos);

  time_t data_atual = mktime(data);

  FILE *arq = fopen("cadastroUsuario.txt", "r");
  FILE *estad = fopen("estadia.txt", "a+");

  if (arq == NULL || estad == NULL) {
    perror("Erro ao abrir os arquivos");
    return "Erro ao abrir os arquivos.";
  }

  printf("Digite o ID do cliente cadastrado:\n");
  scanf("%s", idCl);
  while (fgets(linha, sizeof(linha), arq) != NULL) {
    idArq = strtok(linha, ";");
    if (strcmp(idArq, idCl) == 0) {
      clienteEncontrado = 1;
      printf("Cliente %s encontrado nos registros.\n\n", idArq);
      break;
    }
  }

  if (!clienteEncontrado) {
    printf("Nao ha cliente com esse ID.\n");
    fclose(arq);
    fclose(estad);
    return "Nao ha cliente com esse ID.";
  }

  fclose(arq);
  sprintf(estad_cod, "QE:%s;", idCl);
  fputs(estad_cod, estad);

  printf("Digite a quantidade de hospedes:\n");
  scanf("%d", &quant_hos);
  if (quant_hos <= 0) {
    printf("Quantidade invalida.");
    fclose(estad);
    return "Quantidade invalida.";
  }

  printf("Digite a data de entrada (dd mm aaaa):\n");
  scanf("%d %d %d", &entrada.tm_mday, &entrada.tm_mon, &entrada.tm_year);
  entrada.tm_mon -= 1;
  entrada.tm_year -= 1900;
  char bufferEntrada[80];
  strftime(bufferEntrada, sizeof(bufferEntrada), "%d/%m/%Y", &entrada);
  time_t entrada_tempo = mktime(&entrada);
  int diferenca_dias = difftime(entrada_tempo, data_atual) / (60 * 60 * 24);
  if (diferenca_dias < 0) {
    printf("Data Invalida!\n");
    fclose(estad);
    return "Data Invalida.";
  }

  printf("Digite a data de saida (dd mm aaaa):\n");
  scanf("%d %d %d", &saida.tm_mday, &saida.tm_mon, &saida.tm_year);
  saida.tm_mon -= 1;
  saida.tm_year -= 1900;
  char bufferSaida[80];
  strftime(bufferSaida, sizeof(bufferSaida), "%d/%m/%Y", &saida);
  time_t saida_tempo = mktime(&saida);
  diferenca_dias = difftime(saida_tempo, entrada_tempo) / (60 * 60 * 24);
  if (diferenca_dias < 1) {
    printf("Data Invalida!\n");
    fclose(estad);
    return "Data Invalida.";
  }

  fputs(bufferEntrada, estad);
  fputs(";", estad);
  fputs(bufferSaida, estad);
  fputs(";", estad);
  fprintf(estad, "%d;", diferenca_dias);
  fputs(idCl, estad);
  fputs(";", estad);
  fclose(estad);

  quartos_disponiveis(quartos_disp);
  escolher_quarto(quartos_disp, quant_hos, idCl, entrada_tempo, saida_tempo);

  printf("Data de entrada: %s\n", bufferEntrada);
  printf("Data de saida: %s\n", bufferSaida);

  return "Estadia cadastrada\n";
}

int comparadorIdUs(int id) {
  char *aux, linha[128];
  FILE *cadClient = fopen("cadastroUsuario.txt", "r");
  if (cadClient == NULL) {
    perror("Erro ao abrir o arquivo de cadastro de usuarios");
    return id;
  }
  while (fgets(linha, sizeof(linha), cadClient) != NULL) {
    aux = strtok(linha, ":");
    aux = strtok(NULL, ":");
    if (aux != NULL) {
      int idAux = atoi(aux);
      if (idAux == id) {
        id++;
      }
    }
  }
  fclose(cadClient);
  return id;
}

int comparadorIdFu(int id) {
  char *aux, linha[128];
  FILE *cadClient = fopen("cadastroFuncionario.txt", "r");
  if (cadClient == NULL) {
    perror("Erro ao abrir o arquivo de cadastro de funcionarios");
    return id;
  }
  while (fgets(linha, sizeof(linha), cadClient) != NULL) {
    aux = strtok(linha, ":");
    aux = strtok(NULL, ":");
    if (aux != NULL) {
      int idAux = atoi(aux);
      if (idAux == id) {
        id++;
      }
    }
  }
  fclose(cadClient);
  return id;
}

int cadastrarCliente() {
  int id = 1;
  char nome[64], enderecoCL[64], idCL[10], telefone[13];

  FILE *cadClient = fopen("cadastroUsuario.txt", "a+");
  if (cadClient == NULL) {
    perror("Erro no cadastro de cliente!");
    exit(1);
  }
  id = comparadorIdUs(id);
  sprintf(idCL, "CL:%d;", id);

  printf("Nome do Cliente:\n");
  scanf(" %[^\n]", nome);

  printf("Endereco do Cliente(Estado, Cidade, Bairro, Rua, numero):\n");
  scanf(" %[^\n]", enderecoCL);

  printf("Telefone do Cliente:\n");
  scanf(" %[^\n]", telefone);

  fputs(idCL, cadClient);
  fputs(nome, cadClient);
  fputs(";", cadClient);
  fputs(enderecoCL, cadClient);
  fputs(";", cadClient);
  fputs(telefone, cadClient);
  fputs(";", cadClient);
  fputs("\n", cadClient);

  fclose(cadClient);
  printf("O cliente %s foi cadastrado!\n\n", nome);
  return 0;
}

int cadastrarFunc() {
  int id = 1, n;
  char nome[64], cargo[32], idFU[10], salario[16], telefoneFU[16];

  FILE *cadFunc = fopen("cadastroFuncionario.txt", "a");
  if (cadFunc == NULL) {
    perror("Erro no cadastro de funcionario!");
    exit(1);
  }
  id = comparadorIdFu(id);
  sprintf(idFU, "FU:%d", id);

  printf("Nome do Funcionario:\n");
  scanf(" %[^\n]", nome);
  printf("Telefone do Funcionario:\n");
  scanf(" %[^\n]", telefoneFU);
  printf("Cargo do Funcionario:\n");
  printf(
      "1 - recepcionista\n2 - auxiliar de limpeza\n3 - garcom\n4 - gerente\n");
  scanf("%d", &n);
  switch (n) {
  case 1:
    strcpy(cargo, "recepcionista");
    break;
  case 2:
    strcpy(cargo, "auxiliar de limpeza");
    break;
  case 3:
    strcpy(cargo, "garcom");
    break;
  case 4:
    strcpy(cargo, "gerente");
    break;
  default:
    printf("Opcao invalida!");
    fclose(cadFunc);
    return 0;
  }
  printf("Salario do Funcionario, em reais:\n");
  scanf(" %[^\n]", salario);

  fputs(idFU, cadFunc);
  fputs(";", cadFunc);
  fputs(nome, cadFunc);
  fputs(";", cadFunc);
  fputs(telefoneFU, cadFunc);
  fputs(";", cadFunc);
  fputs(cargo, cadFunc);
  fputs(";", cadFunc);
  fputs(salario, cadFunc);
  fputs(";", cadFunc);
  fputs("\n", cadFunc);

  fclose(cadFunc);
  printf("O funcionario %s foi cadastrado!\n\n", nome);
  return 0;
}

void pesquisarCliente() {
  char idCl[10], linha[128];
  printf("Digite o ID do cliente (CL:X) que deseja pesquisar:\n");
  scanf("%s", idCl);

  FILE *arq = fopen("cadastroUsuario.txt", "r");
  if (arq == NULL) {
    perror("Erro ao abrir o arquivo de cadastro de clientes");
    return;
  }

  int encontrado = 0;
  while (fgets(linha, sizeof(linha), arq) != NULL) {
    if (strstr(linha, idCl) != NULL) {
      printf("Cliente encontrado: %s", linha);
      encontrado = 1;
      break;
    }
  }

  if (!encontrado) {
    printf("Nenhum cliente encontrado com o ID %s.\n", idCl);
  }

  fclose(arq);
}

void pesquisarFuncionario() {
  char idFu[10], linha[128];
  printf("Digite o ID do funcionário (FU:X) que deseja pesquisar:\n");
  scanf("%s", idFu);

  FILE *arq = fopen("cadastroFuncionario.txt", "r");
  if (arq == NULL) {
    perror("Erro ao abrir o arquivo de cadastro de funcionários");
    return;
  }

  int encontrado = 0;
  while (fgets(linha, sizeof(linha), arq) != NULL) {
    if (strstr(linha, idFu) != NULL) {
      printf("Funcionário encontrado: %s", linha);
      encontrado = 1;
      break;
    }
  }

  if (!encontrado) {
    printf("Nenhum funcionário encontrado com o ID %s.\n", idFu);
  }

  fclose(arq);
}

void mostrarEstadiasCliente() {
  char idCl[10], linha[128];
  printf("Digite o ID do cliente (CL:X) que deseja ver as estadias:\n");
  scanf("%s", idCl);

  FILE *arq = fopen("estadia.txt", "r");
  if (arq == NULL) {
    perror("Erro ao abrir o arquivo de estadias");
    return;
  }

  int encontrado = 0;
  while (fgets(linha, sizeof(linha), arq) != NULL) {
    if (strstr(linha, idCl) != NULL) {
      printf("Estadia: %s", linha);
      encontrado = 1;
    }
  }

  if (!encontrado) {
    printf("Nenhuma estadia encontrada para o cliente %s.\n", idCl);
  }

  fclose(arq);
}
