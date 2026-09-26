#include <stdio.h>

int main(void) {
    double distancia;
    double valor_base;
    double subtotal;
    double peso;
    double adicional_peso;
    int modalidade;
    double adicional_modalidade;

    printf("Digite a distancia da entrega: ");
    scanf("%lf", &distancia);
   while (distancia <= 0) {
        printf("Distancia invalida. Digite outra: ");
        scanf("%lf", &distancia);
    }

    if (distancia <= 5) {
        valor_base = 8.00;
    } else if (distancia <= 15) {
        valor_base = 12.00;
    } else if (distancia <= 30) {
        valor_base = 18.00;
    } else {
        valor_base = 25.00;
    }

    subtotal = valor_base + (distancia * 1.20);
     printf("Digite o peso da entrega: ");
    scanf("%lf", &peso);
    while (peso <= 0) {
        printf("Peso invalido. Digite outro: ");
        scanf("%lf", &peso);
    }
    if (peso <= 2) {
        adicional_peso = 0;
    } else if (peso <= 5) {
        adicional_peso = subtotal * 0.05;
    } else if (peso <= 10) {
        adicional_peso = subtotal * 0.10;
    } else {
        adicional_peso = subtotal * 0.20;
    }
    printf("Digite a modalidade: 1-Economica, 2-Expressa e 3-Prioritaria ");
    scanf("%d", &modalidade);
    while (modalidade != 1 && modalidade != 2 && modalidade != 3) {
        printf("Modalidade invalida. Digite 1, 2 ou 3: ");
        scanf("%d", &modalidade);
    }
    
    if (modalidade == 1) {
        adicional_modalidade = 0;
    } else if (modalidade == 2) {
        adicional_modalidade = subtotal * 0.15;
    } else {
        adicional_modalidade = subtotal * 0.30;
    }
    printf("Subtotal inicial: R$ %.2f\n", subtotal);
    printf("Adicional de modalidade: R$ %.2f\n", adicional_modalidade);
    printf("Adicional de peso: R$ %.2f\n", adicional_peso);
     
return 0;
}
