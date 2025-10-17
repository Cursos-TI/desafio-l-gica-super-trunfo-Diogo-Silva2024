#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

     // Declaração da primeira carta
    char estado1;
    char codigo1[4]; // Ex: A01
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // Declaração da segunda carta
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Área para entrada de dados

    // --- Coleta de dados para a primeira carta ---
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Digite o estado (A-Z): ");
    scanf(" %c", &estado1);
    printf("Digite o código da carta (Ex: C01): ");
    scanf("%s", codigo1);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("Digite a população: ");
    scanf("%d", &populacao1);
    printf("Digite a área em km²: ");
    scanf("%f", &area1);
    printf("Digite o PIB: ");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

        // --- Coleta de dados para a segunda carta ---
    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Digite o estado (A-Z): ");
    scanf(" %c", &estado2);
    printf("Digite o código da carta (Ex: C02): ");
    scanf("%s", codigo2);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("Digite a população: ");
    scanf("%d", &populacao2);
    printf("Digite a área em km²: ");
    scanf("%f", &area2);
    printf("Digite o PIB: ");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);


    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // --- COMPARAÇÃO DE TODOS OS ATRIBUTOS ---
    printf("\n======================================================\n");
    printf("  RESULTADOS: SUPER TRUNFO DE CIDADES\n");
    printf("======================================================\n\n");
    
    // 1. População (Maior vence - 0)
    exibir_comparacao("População", nomeCidade1, nomeCidade2, (float)populacao1, (float)populacao2, 0);

    // 2. Área (Maior vence - 0)
    exibir_comparacao("Área (km²)", nomeCidade1, nomeCidade2, area1, area2, 0);

    // 3. PIB (Maior vence - 0)
    exibir_comparacao("PIB (Bilhões R$)", nomeCidade1, nomeCidade2, pib1, pib2, 0);

    // 4. Densidade Populacional (Menor vence - 1)
    exibir_comparacao("Dens. Populacional", nomeCidade1, nomeCidade2, densidadePopulacional1, densidadePopulacional2, 1); 

    // 5. PIB per capita (Maior vence - 0)
    exibir_comparacao("PIB per capita", nomeCidade1, nomeCidade2, pibPerCapita1, pibPerCapita2, 0);

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}
