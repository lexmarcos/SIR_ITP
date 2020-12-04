#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct parametros{
    double S[10000];
    double I[10000];
    double R[10000];
    double tempo[10000];
  }Parametros;

typedef struct constantes{
    float b;
    float k;
  }Constantes;


float *ler_parametros(FILE *arquivo){
  int is_num = 0;
  int index_do_string_inteiro = 0;
  int index_do_parametros_int = 0;
  char string_inteiro[10];
  char atual_char = fgetc(arquivo);
  float *arquivo_parametros = malloc(sizeof(float) * (12));
  while(atual_char!=EOF){
    if(atual_char == '='){
      is_num = 1;
      atual_char = fgetc(arquivo);
      continue;
    }
    else if(atual_char == ';'){
      is_num = 0;
      if(index_do_string_inteiro==1){
        arquivo_parametros[index_do_parametros_int] = (float)string_inteiro[0] - '0'; 
      }
      else{
        arquivo_parametros[index_do_parametros_int] = atof(string_inteiro); 
      }
      index_do_parametros_int++;
      index_do_string_inteiro = 0;
      string_inteiro[0]='\0';
      memset(string_inteiro, '\0', sizeof string_inteiro);
      atual_char = fgetc(arquivo);
      continue;
    }
    if(is_num == 1){
      string_inteiro[index_do_string_inteiro] = atual_char;
      index_do_string_inteiro++;
    }
    atual_char = fgetc(arquivo);
  }
  printf("\n");
  fclose(arquivo);
  for(int i = 0; i < index_do_parametros_int;i++){
    printf("Vet[%d]: %f\n", i, arquivo_parametros[i]);
  }
  return arquivo_parametros;
}

void imprimeCSV(Parametros data, FILE *CSV, int num_loops){
      fprintf(CSV, "S,I,R,tempo\n");
      for(int i = 0; i<num_loops;i++){
        fprintf(CSV,"%.2f,", data.S[i]);
        fprintf(CSV,"%.2f,", data.I[i]);
        fprintf(CSV,"%.2f,", data.R[i]);
        fprintf(CSV,"%.1f", data.tempo[i]);
        fprintf(CSV,"\n");
      }
  }

void imprimeTXT(Parametros data, FILE *TXT, int num_loops){
     for(int i = 0; i<num_loops;i++){
      fprintf(TXT,"%.2f,", data.S[i]);
      fprintf(TXT,"%.2f,", data.I[i]);
      fprintf(TXT,"%.2f,", data.R[i]);
      fprintf(TXT,"%.1f", data.tempo[i]);
      fprintf(TXT,"\n");
    }
}
// 
void imprimeTerminal(Parametros data, int num_loops){
    for(int i = 0; i<num_loops;i++){
      printf("data.S: %.2f |", data.S[i]);
      printf(" data.I: %.2f |", data.I[i]);
      printf(" data.R: %.2f |", data.R[i]);
      printf(" Tempo: %.1f", data.tempo[i]);
      printf("\n");
    }
}

void criar_constantes(float *parametros_arquivo, Constantes *constantes){
  float N_b = parametros_arquivo[3];
  float T_b = parametros_arquivo[4]; 
  float S_b0 = parametros_arquivo[5]; 
  float I_b0 = parametros_arquivo[6]; 

  float m_k = parametros_arquivo[7];
  float n_k = parametros_arquivo[8];
  float T_k = parametros_arquivo[9]; 

  constantes -> b = (float)N_b/(T_b*S_b0*I_b0);
  constantes -> k = (float)m_k/(n_k*T_k);
}

void simulacao(Parametros *data, float *parametros_arquivo){
  Constantes constantes;
  float h = parametros_arquivo[11];
  criar_constantes(parametros_arquivo, &constantes);
  int tempo_dias = parametros_arquivo[10];
  int num_loops = (tempo_dias*24*10)+1;
  for(int i = 1; i<num_loops;i++){
    data -> S[i] = data -> S[i-1] - h*constantes.b*data -> S[i-1]*data -> I[i-1];
    data -> I[i] = data -> I[i-1] + h*(constantes.b*data -> S[i-1]*data -> I[i-1]-constantes.k*data -> I[i-1]);
    data -> R[i] = data -> R[i-1] + h*constantes.k*data -> I[i-1];
    data -> tempo[i] = data -> tempo[i-1] + h;
  }
}

int main(void) {
  Parametros data;

  FILE *dataFile;
  dataFile = fopen("./dataFile.txt", "r");

  FILE *CSV;
  CSV = fopen("./CSV.csv", "w+");

  FILE *TXT;
  TXT = fopen("./TXT.txt", "w+");
  
  float b, k;
  int N_b, S_b0, I_b0, T_b;
  int m_k, n_k, T_k;
  int tempo_dias;
  float h;

  float *parametros_arquivo = ler_parametros(dataFile);

  data.S[0] = parametros_arquivo[0];
  data.I[0] = parametros_arquivo[1];
  data.R[0] = parametros_arquivo[2];

  tempo_dias = parametros_arquivo[10];
  int num_loops = (tempo_dias*24*10)+1;

  simulacao(&data, parametros_arquivo);  
  imprimeCSV(data, CSV, num_loops);
  imprimeTXT(data, TXT, num_loops);
  imprimeTerminal(data, num_loops);
  
  return 0;
}  
  