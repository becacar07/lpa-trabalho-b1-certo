#include <stdio.h>

int main(void) {
    double distancia;

    printf("Digite a distancia da entrega: ");
    scanf("%lf", &distancia);
   while (distancia <= 0) {
        printf("Distancia invalida. Digite outra: ");
        scanf("%lf", &distancia);
    }

}
