#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste 
// Sugestão: Defina variáveis separadas para cada atributo da cidade.
// Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
// Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
// Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
// Exibição dos Dados das Cartas:
// Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
// Exiba os valores inseridos para cada atributo da cidade, um por linha.

int main() {
    //Declarando as variaveis
    char estado1, estado2;
    char codigo1[5], codigo2[5]; 
    char nomeCidade1[50], nomeCidade2[50];
    //Populaçao abaixo é "unsigned long int", para caber valor maior.
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    float densidadePopulacional1, densidadePopulacional2;
    float pibPerCapta1, pibPerCapta2;
    int pontosTuristicos1, pontosTuristicos2;
    float superPoder1, superPoder2;
    int resultadoComparacao[7]; //Array para armazenar os resultados da comparaçao.
    
    // Coletando dados da primeira Carta:
    printf ("Digite os dados da primeira carta: \n");

    printf ("Estado (A-H): ");
    scanf (" %c", &estado1);

    printf ("Digite o codigo da carta: ");
    scanf(" %s", codigo1);
    
    printf ("Digite o nome da cidade: ");
    //lendo a string com espacos "   " %[^\n]"   ".
    scanf (" %[^\n]", nomeCidade1);

    printf ("Digite a populaçao da cidade:");
    scanf (" %lu", &populacao1); 

    printf ("Digite a área da cidade: ");
    scanf (" %f", &area1);

    printf ("Digite o PIB da cidade: ");
    scanf (" %f", &pib1);

    printf ("Digite o numero de pontos turisticos: ");
    scanf (" %d", &pontosTuristicos1);

    //Coletando dados da segunda carta
    printf ("Digite os dados da segunda carta: \n");
    printf ("Estado (A-H): ");
    scanf (" %c", &estado2);

    printf ("Digite o codigo da carta: ");
    scanf (" %s", codigo2);
    
    printf ("Digite o nome da cidade: ");
    scanf (" %[^\n]", nomeCidade2);

    printf ("Digite a populaçao da cidade:");
    scanf (" %lu", &populacao2); 

    printf ("Digite a área da cidade: ");
    scanf (" %f", &area2);

    printf ("Digite o PIB da cidade: ");
    scanf (" %f", &pib2);

    printf ("Digite o numero de pontos turisticos: ");
    scanf (" %d", &pontosTuristicos2);

    // Calculando os atributos das cartas:
    densidadePopulacional1 = populacao1/area1;
    densidadePopulacional2 = populacao2/area2;
    
    //pib *1000000000 porque uma unidade digitada pelo usuario representa um bilhao em relaçao ao pib, conbertendo em reais, multiplicando por 1Bi. 
    pibPerCapta1 = (pib1 * 1000000000)/populacao1;
    pibPerCapta2 = (pib2 * 1000000000)/populacao2;

    //Cálculo do Super poder: Soma dos atributos, com a densidade invertida (1/ densidadePopulacional)
    superPoder1 = populacao1 + area1 + pibPerCapta1 + pontosTuristicos1 + (1/ densidadePopulacional1);
    superPoder2 = populacao2 + area2 + pibPerCapta2 + pontosTuristicos2 + (1/ densidadePopulacional2);

    //Comparando atributo a atributo entre as 2 cartas:
    //Array de [6posiçoes] = comparando, (se n1 > n2) mostre 1:senao 0;
    resultadoComparacao[0] = (populacao1 > populacao2)? 1:0;
    resultadoComparacao[1] = (area1 > area2)? 1:0;
    resultadoComparacao[2] = (pibPerCapta1 > pibPerCapta2)? 1:0;
    resultadoComparacao[3] = (pontosTuristicos1 > pontosTuristicos2)? 1:0;
    resultadoComparacao[4] = (densidadePopulacional1 < densidadePopulacional2)? 1:0; // Menor densidade é a que vence
    resultadoComparacao[5] = (superPoder1 > superPoder2)? 1 : 0;

    //Exibindo os dados das cartas
    //Dados da carta 1
    printf ("\n==== Carta 1 ====\n");
    printf ("Estado: %c\n", estado1);
    printf ("Código: %s\n", codigo1);
    printf ("Nome da Cidade %s\n", nomeCidade1);
    //Declaraçao com %lu para numeros maiores
    printf ("Populaçao com %lu habitantes\n", populacao1);
    printf ("Área: %.2f km²\n", area1);
    printf ("PIB: %.2f billoes\n", pib1);
    printf ("Pontos turisticos: %d\n", pontosTuristicos1);
    printf (" O PIB percapta é de: %.2f reais\n", pibPerCapta1);
    printf ("A densidade populacional é de: %.2f hab/km²\n",densidadePopulacional1);
    printf ("Super poder: %.2f\n", superPoder1);
    
    //Dados da carta 2
    printf ("\n==== Carta 2 ====\n");
    printf ("Estado: %c\n", estado2);
    printf ("Código: %s\n", codigo2);
    printf ("Nome da Cidade %s\n", nomeCidade2);
    //Declaraçao com %lu para numeros maiores
    printf ("Populaçao com %lu habitantes\n", populacao2);
    printf ("Área: %.2f km²\n", area2);
    printf ("PIB: %.2f billoes\n", pib2);
    printf ("Pontos turisticos: %d\n", pontosTuristicos2);
    printf ("O PIB percapta é de: %.2f reais\n", pibPerCapta2);
    printf ("A densidade populacional (Vence a de menor valor): %.2f hab/km²\n", densidadePopulacional2);
    printf ("Super poder: %.2f\n", superPoder2);

    //Exibindo os resultados da comparaçao
    printf ("\n ===== Comparaçao das cartas =====\n");
    printf ("Populaçao: %d\n", resultadoComparacao[0]);
    printf ("Área: %d\n", resultadoComparacao[1]);
    printf ("PIB percapta: %d\n",resultadoComparacao[2]);
    printf ("Pontos Turisticos: %d\n", resultadoComparacao[3]);
    printf ("Densidade Populacional: %d\n", resultadoComparacao[4]);
    printf ("Super Poder: %d\n", resultadoComparacao[5]);
       
    return 0;
}
