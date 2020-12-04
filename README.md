# Projeto ITP 
## Simulação epidemiológica 🤒

O projeto utiliza do Modelos epidemiológico computacional **Suscetível-Infectado-Removido (SIR)**
## Variáveis do projeto:

| Variáveis | Descrição                                                                             |
|-----------|---------------------------------------------------------------------------------------|
| **S**     | número de indivíduos suscetíveis (que ainda não estão contaminados);                  |
| **I**     | número de indivíduos infectados (capazes de infectar indivíduos S);                   |
| **R**     | número de indivíduos removidos (que se recuperaram, tornaram-se imunes ou faleceram). |
| **h**     | pequeno intervalo de tempo (em horas);                                                |
| **b**     | facilidade de contágio de um indivíduo;                                               |
| **k**     | probabilidade que um indivíduo se recupere;                                           |
| **tempo** | instantes de tempo nos quais o modelo é simulado (em horas).                          |
| **N_b**   | número de pessoas suscetíveis que se infectaram em um intervalo de tempo T_b          |
| **S_b0**  | número de pessoas suscetíveis no início da observação                                 |
| **I_b0**  | número de pessoas infectadas no início da observação                                  |
| **T_k**   | intervalo de tempo                                                                    |
| **m_k**   | Quantos indivíduos se recuperaram no tempo T_k                                        |
| **n_k**   | Número total de indíviduos que existia no tempo T_k                                   |
| **dT**    | Tempo em dias da simulação                                                            |


## Utilizando arquivos:

O programa ler as variáveis através de uma arquivo `.txt` para que haja um sucesso nas leituras de variáveis é necessário
que siga o seguinte modelo de organização do arquivo.txt.

**Nome do arquivo deve ser obrigatoriamente:** `dataFile.txt`

**Estrutura:**

```
S=<valor>;
I=<valor>;
R=<valor>;
N_b=<valor>;
T_b=<valor>;
S_b0=<valor>;
I_b0=<valor>;
m_k=<valor>;
n_k=<valor>;
T_k=<valor>;
dT=<valor>;
```

onde `valor` é o inteiro que será usado na simulação

## Geração de arquivos

Com os valores corretamentes alocados no dataFile.txt o programa pode ser rodado.
Quando o programa terminar de executar ele terá gerado 2 arquivos o `CSV.csv` e `TXT.txt` esses arquivos podem ser
utilizados como bem entender para plotar gráficos ou geração de arquivos `.json` nas ferramentas apropriadas.

**Exemplo De arquivo CSV**

```
S,I,R,tempo
68.00,2.00,0.00,0.1
67.99,2.01,0.00,0.2
67.97,2.02,0.00,0.3
[...]
```
