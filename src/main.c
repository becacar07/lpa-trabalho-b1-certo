#include <stdio.h>

int main(void) {
    double distancia;
    double valor_base;
    double subtotal;
    double peso;
    double adicional_peso;
    int modalidade;
    double adicional_modalidade;
    int protecao;
    double valor_protecao;
    int tentativas;
    double valor_tentativas;
    double valor_final;
    int continuar;

    do {
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
          printf("Deseja contratar protecao? 1-Sim, 0-Nao: ");
        scanf("%d", &protecao);
        while (protecao != 0 && protecao != 1) {
            printf("Valor invalido. Digite 1 ou 0: ");
            scanf("%d", &protecao);
        }
        if (protecao == 1) {
            valor_protecao = 7.50;
        } else {
            valor_protecao = 0;
        }

        printf("Quantas tentativas adicionais? ");
        scanf("%d", &tentativas);
        while (tentativas < 0) {
            printf("Valor invalido.");
            scanf("%d", &tentativas);
        }
        valor_tentativas = tentativas * 4.00;

        valor_final = subtotal + adicional_peso + adicional_modalidade + valor_protecao + valor_tentativas;

        printf("Subtotal inicial: R$ %.2f\n", subtotal);
        printf("Adicional de modalidade: R$ %.2f\n", adicional_modalidade);
        printf("Adicional de peso: R$ %.2f\n", adicional_peso);
        printf("Valor final da entrega: R$ %.2f\n", valor_final);

          printf("Deseja processar outra entrega? 1-Sim, 0-Nao: ");
            scanf("%d", &continuar);
            while (continuar != 0 && continuar != 1) {
                printf("Valor invalido. Digite 1 ou 0: ");
                scanf("%d", &continuar);
            }

        } while (continuar == 1);

      
    return 0;
}
