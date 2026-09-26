#include <stdio.h>

int main(void) {
    double distancia;

    printf("Digite a distancia da entrega: ");
    scanf("%lf", &distancia);
   while (distancia <= 0) {
        printf("Distancia invalida. Digite outra: ");
        scanf("%lf", &distancia);
    }

    if (distancia <= 5) {
        valor_base = 8.00;
    } if (distancia <= 15) {
        valor_base = 12.00;
    } else if (distancia <= 30) {
        valor_base = 18.00;
    } else {
        valor_base = 25.00;
    }

    subtotal = valor_base + (distancia * 1.20);

    printf("Subtotal inicial: R$ %.2f", subtotal);

}
