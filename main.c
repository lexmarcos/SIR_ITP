#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  
  // O símbolo "#" representa que o texto seguinte é uma das mudanças que serão implementadas no Checkpoint 2

  //  LEITURA
  FILE *dataFile;
  dataFile = fopen("./dataFile.txt", "r");

  // Escrita CSV e TXT
  FILE *CSV;
  CSV = fopen("./CSV.csv", "w+");

  FILE *TXT;
  TXT = fopen("./TXT.txt", "w+");

  // DECLARAÇÕES

  // parametros principais
  // # inicialazação e alteração dos vetores utilizando alocação dinamica
  float S[100000];
  float I[100000];
  float R[100000];
  float h = 0.1;
  float tempo[100000];
  float b, k;
  // parametros de B;
  int N_b, S_b0, I_b0, T_b;
  // parametros de K;
  int m_k, n_k, T_k;
  // tempo em dias
  int dT;

  // COLETA DE DADOS VIA txt
  int isNum = 0;
  int index_do_string_inteiro = 0;
  int index_do_parametrosInt = 0; 
  char string_inteiro[10]; // int armezanado como str
  char atual_char = fgetc(dataFile); // checagem char por char
  long parametrosInt[11]; // #malloc?

  while(atual_char!=EOF){
    if(atual_char == '='){
      isNum = 1;
      atual_char = fgetc(dataFile);
      continue;
    }
    else if(atual_char == ';'){
      isNum = 0;
      // se o tamanho do num for 1
      if(index_do_string_inteiro==1){
        parametrosInt[index_do_parametrosInt] = (int)string_inteiro[0] - '0'; 
      }
      // senão, segue normal, utilizando conversão com atoi
      else{
        parametrosInt[index_do_parametrosInt] = atoi(string_inteiro); 
      }
      index_do_parametrosInt++;
      index_do_string_inteiro = 0;
      string_inteiro[0] = '\0';
      atual_char = fgetc(dataFile);
      printf("\n--------------\n");
      continue;
    }
    if(isNum==1){
      printf("%c", atual_char);
      string_inteiro[index_do_string_inteiro] = atual_char;
      index_do_string_inteiro++;
    }
    atual_char = fgetc(dataFile);
  }
  printf("\n");
  fclose(dataFile);
  for(int i = 0; i < index_do_parametrosInt;i++){
    printf("Vet[%d]: %d\n", i, parametrosInt[i]);
  }

  // INICIALIZAÇÕES 
  // SIR
  S[0] = parametrosInt[0];
  I[0] = parametrosInt[1];
  R[0] = parametrosInt[2];
  tempo[0] = h;
  // b 
  N_b = parametrosInt[3];
  T_b = parametrosInt[4]; 
  S_b0 = parametrosInt[5]; 
  I_b0 = parametrosInt[6]; 

  // k
  m_k = parametrosInt[7];
  n_k = parametrosInt[8];
  T_k = parametrosInt[9]; 
  // tempo em dias
  dT = parametrosInt[10];
  dT = dT*24*10; // tempo em dias * horas dia * fracao da hora 
  

  
  // equações 
  b = (float)N_b/(T_b*S_b0*I_b0);
  k = (float)m_k/(n_k*T_k);


  // # Transformar a simulação em uma função
  
  // simulação
  
  // for(int i = 1; i<dT;i++){
  //   S[i] = S[i-1] - h*b*S[i-1]*I[i-1];
  //   I[i] = I[i-1] + h*(b*S[i-1]*I[i-1]-k*I[i-1]);
  //   R[i] = R[i-1] + h*k*I[i-1];
  //   tempo[i] = tempo[i-1] + h;
  // }

  // // # Transformar os generates e imprimir em funções

  // // GENERATE CSV
  // fprintf(CSV, "S,I,R,tempo\n");
  // for(int i = 0; i<dT;i++){
  //   fprintf(CSV,"%.2f,", S[i]);
  //   fprintf(CSV,"%.2f,", I[i]);
  //   fprintf(CSV,"%.2f,", R[i]);
  //   fprintf(CSV,"%.1f", tempo[i]);
  //   fprintf(CSV,"\n");
  // // 
  // }
  // // GENERATE TXT
  //   for(int i = 0; i<dT;i++){
  //     fprintf(TXT,"%.2f,", S[i]);
  //     fprintf(TXT,"%.2f,", I[i]);
  //     fprintf(TXT,"%.2f,", R[i]);
  //     fprintf(TXT,"%.1f", tempo[i]);
  //     fprintf(TXT,"\n");
  //   }

  // // IMPRESSÃO TERMINAL
  //  for(int i = 0; i<dT;i++){
  //   printf("S: %.2f |", S[i]);
  //   printf(" I: %.2f |", I[i]);
  //   printf(" R: %.2f |", R[i]);
  //   printf(" Tempo: %.1f", tempo[i]);
  //   printf("\n");
  //  }
  //

  return 0;
}