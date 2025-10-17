#include <stdio.h>
#include <string.h>
#include <math.h> // Adicionado para cálculos

// --- DEFINIÇÃO DA FUNÇÃO AUXILIAR ---
// 1. Alteração: Função auxiliar 'exibir_comparacao' definida para uso no main().
void exibir_comparacao(const char *atributo_nome, const char *cidade1, const char *cidade2, float valor1, float valor2, int regra_menor_vence) {
    
    int vencedor = 0;
    
    if (regra_menor_vence) { 
        if (valor1 < valor2) vencedor = 1;
        else if (valor2 < valor1) vencedor = 2;
    } else { 
        if (valor1 > valor2) vencedor = 1;
        else if (valor2 > valor1) vencedor = 2;
    }

    printf("--- Comparação: %s ---\n", atributo_nome);
    
    // Formatação de saída
    if (strcmp(atributo_nome, "População") == 0) {
        printf("  Carta 1 (%s): %.0f hab.\n", cidade1, valor1);
        printf("  Carta 2 (%s): %.0f hab.\n", cidade2, valor2);
    } else if (strcmp(atributo_nome, "PIB (Bilhões R$)") == 0) {
        printf("  Carta 1 (%s): R$ %.2f Bi\n", cidade1, valor1);
        printf("  Carta 2 (%s): R$ %.2f Bi\n", cidade2, valor2);
    } else if (strcmp(atributo_nome, "Super Poder") == 0) {
        printf("  Carta 1 (%s): %.4f\n", cidade1, valor1);
        printf("  Carta 2 (%s): %.4f\n", cidade2, valor2);
    } else {
        printf("  Carta 1 (%s): %.2f\n", cidade1, valor1);
        printf("  Carta 2 (%s): %.2f\n", cidade2, valor2);
    }

    if (vencedor == 1) {
        printf("  Resultado: 🏆 Carta 1 (%s) venceu! (Regra: %s)\n\n", cidade1, regra_menor_vence ? "MENOR valor" : "MAIOR valor");
    } else if (vencedor == 2) {
        printf("  Resultado: 🏆 Carta 2 (%s) venceu! (Regra: %s)\n\n", cidade2, regra_menor_vence ? "MENOR valor" : "MAIOR valor");
    } else {
        printf("  Resultado: 🤝 Empate.\n\n");
    }
}


int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    
    // 2. Alteração: estado1 e estado2 alterados para char[3] para ler o código do estado (Ex: SP).
    char estado1[3];
    char codigo1[4]; 
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    char estado2[3];
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // Variáveis para atributos CALCULADOS (Já estavam corretamente declaradas)
    float densidadePopulacional1;
    float pibPerCapita1;
    float superPoder1;

    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;
    
    // Linha removida: "exibir_comparacao" solta, que causava erro de sintaxe.
    
    // --- Coleta de dados para a primeira carta ---
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Digite o estado (Ex: SP): ");
    scanf("%s", estado1); // 3. Alteração: Usa %s para array de char
    printf("Digite o código da carta (Ex: C01): ");
    scanf("%s", codigo1);
    printf("Digite o nome da cidade: ");
    while (getchar() != '\n'); // Limpa buffer
    scanf(" %[^\n]", nomeCidade1);
    printf("Digite a população: ");
    scanf("%d", &populacao1);
    printf("Digite a área em km²: ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhões de R$): ");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // --- Coleta de dados para a segunda carta ---
    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Digite o estado (Ex: RJ): ");
    scanf("%s", estado2); // 4. Alteração: Usa %s para array de char
    printf("Digite o código da carta (Ex: C02): ");
    scanf("%s", codigo2);
    printf("Digite o nome da cidade: ");
    while (getchar() != '\n'); // Limpa buffer
    scanf(" %[^\n]", nomeCidade2);
    printf("Digite a população: ");
    scanf("%d", &populacao2);
    printf("Digite a área em km²: ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhões de R$): ");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);


    // --- CÁLCULO DOS ATRIBUTOS DERIVADOS E SUPER PODER ---
    // 5. Alteração: Adicionada a lógica de cálculo (crucial para o programa funcionar).
    
    // CÁLCULO CARTA 1
    densidadePopulacional1 = (area1 > 0) ? (float)populacao1 / area1 : 0.0;
    pibPerCapita1 = (populacao1 > 0) ? (pib1 * 1000000000.0) / (float)populacao1 : 0.0;
    float inversoDensidade1 = (densidadePopulacional1 > 0) ? 1.0 / densidadePopulacional1 : 0.0;

    // CÁLCULO CARTA 2
    densidadePopulacional2 = (area2 > 0) ? (float)populacao2 / area2 : 0.0;
    pibPerCapita2 = (populacao2 > 0) ? (pib2 * 1000000000.0) / (float)populacao2 : 0.0;
    float inversoDensidade2 = (densidadePopulacional2 > 0) ? 1.0 / densidadePopulacional2 : 0.0;

    // CÁLCULO FINAL DO SUPER PODER
    superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontosTuristicos1 + pibPerCapita1 + inversoDensidade1;
    superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontosTuristicos2 + pibPerCapita2 + inversoDensidade2;


    // --- COMPARAÇÃO DE TODOS OS ATRIBUTOS ---
    printf("\n======================================================\n");
    printf("  RESULTADOS: SUPER TRUNFO DE CIDADES\n");
    printf("======================================================\n\n");
    
    // As chamadas 'exibir_comparacao' agora funcionam pois a função foi definida e as variáveis calculadas.
    exibir_comparacao("População", nomeCidade1, nomeCidade2, (float)populacao1, (float)populacao2, 0);
    exibir_comparacao("Área (km²)", nomeCidade1, nomeCidade2, area1, area2, 0);
    exibir_comparacao("PIB (Bilhões R$)", nomeCidade1, nomeCidade2, pib1, pib2, 0);
    exibir_comparacao("Dens. Populacional", nomeCidade1, nomeCidade2, densidadePopulacional1, densidadePopulacional2, 1); 
    exibir_comparacao("PIB per capita", nomeCidade1, nomeCidade2, pibPerCapita1, pibPerCapita2, 0);

    // --- Batalha Final: SUPER PODER (MAIOR vence) ---
    printf("======================================================\n");
    printf("--- Batalha Final: SUPER PODER ---\n");
    
    printf("  Super Poder de %s: %.4f\n", nomeCidade1, superPoder1);
    printf("  Super Poder de %s: %.4f\n", nomeCidade2, superPoder2);
    
    printf("\n");
    if (superPoder1 > superPoder2) {
        printf("🎉 **VENCEDOR GERAL: Carta 1 (%s)** com o MAIOR Super Poder!\n", nomeCidade1);
    } else if (superPoder2 > superPoder1) {
        printf("🎉 **VENCEDOR GERAL: Carta 2 (%s)** com o MAIOR Super Poder!\n", nomeCidade2);
    } else {
        printf("🤝 **EMPATE GERAL** no Super Poder!\n");
    }
    printf("======================================================\n");

    return 0;
}
