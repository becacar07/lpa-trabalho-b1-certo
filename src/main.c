#include <stdio.h>

double identificarValorBase(double distancia) {
    double valor_base;

    if (distancia <= 5) {
        valor_base = 8.00;
    } else if (distancia <= 15) {
        valor_base = 12.00;
    } else if (distancia <= 30) {
        valor_base = 18.00;
    } else {
        valor_base = 25.00;
    }

    return valor_base;
}

double calcularAdicionalPeso(double peso, double subtotal) {
    double adicional_peso;

    if (peso <= 2) {
        adicional_peso = 0;
    } else if (peso <= 5) {
        adicional_peso = subtotal * 0.05;
    } else if (peso <= 10) {
        adicional_peso = subtotal * 0.10;
    } else {
        adicional_peso = subtotal * 0.20;
    }

    return adicional_peso;
}

double calcularAdicionalModalidade(int modalidade, double subtotal) {
    double adicional_modalidade;

    if (modalidade == 1) {
        adicional_modalidade = 0;
    } else if (modalidade == 2) {
        adicional_modalidade = subtotal * 0.15;
    } else {
        adicional_modalidade = subtotal * 0.30;
    }

    return adicional_modalidade;
}

void exibirResumo(int total_entregas, double soma_valores, int qtd_economica, int qtd_expressa, int qtd_prioritaria, double maior_valor, double menor_valor) {
    printf("\n===== Resumo da sessao =====\n");
    printf("Entregas processadas: %d\n", total_entregas);
    printf("Valor total: R$ %.2f\n", soma_valores);
    printf("Valor medio: R$ %.2f\n", soma_valores / total_entregas);
    printf("Economicas: %d\n", qtd_economica);
    printf("Expressas: %d\n", qtd_expressa);
    printf("Prioritarias: %d\n", qtd_prioritaria);
    printf("Maior valor: R$ %.2f\n", maior_valor);
    printf("Menor valor: R$ %.2f\n", menor_valor);
}

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

    int total_entregas = 0;
    double soma_valores = 0;
    int qtd_economica = 0;
    int qtd_expressa = 0;
    int qtd_prioritaria = 0;
    double maior_valor;
    double menor_valor;

    do {
        printf("Digite a distancia da entrega: ");
        scanf("%lf", &distancia);
        while (distancia <= 0) {
            printf("Distancia invalida. Digite outra: ");
            scanf("%lf", &distancia);
        }

        valor_base = identificarValorBase(distancia);
        subtotal = valor_base + (distancia * 1.20);

        printf("Digite o peso da entrega: ");
        scanf("%lf", &peso);
        while (peso <= 0) {
            printf("Peso invalido. Digite outro: ");
            scanf("%lf", &peso);
        }
        adicional_peso = calcularAdicionalPeso(peso, subtotal);

        printf("Digite a modalidade: 1-Economica, 2-Expressa e 3-Prioritaria ");
        scanf("%d", &modalidade);
        while (modalidade != 1 && modalidade != 2 && modalidade != 3) {
            printf("Modalidade invalida. Digite 1, 2 ou 3: ");
            scanf("%d", &modalidade);
        }
        adicional_modalidade = calcularAdicionalModalidade(modalidade, subtotal);

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
            printf("Valor invalido. Digite um numero maior ou igual a zero: ");
            scanf("%d", &tentativas);
        }
        valor_tentativas = tentativas * 4.00;

        valor_final = subtotal + adicional_peso + adicional_modalidade + valor_protecao + valor_tentativas;

        printf("Valor final da entrega: R$ %.2f\n", valor_final);

        total_entregas = total_entregas + 1;
        soma_valores = soma_valores + valor_final;

        if (modalidade == 1) {
            qtd_economica = qtd_economica + 1;
        } else if (modalidade == 2) {
            qtd_expressa = qtd_expressa + 1;
        } else {
            qtd_prioritaria = qtd_prioritaria + 1;
        }

        if (total_entregas == 1) {
            maior_valor = valor_final;
            menor_valor = valor_final;
        } else {
            if (valor_final > maior_valor) {
                maior_valor = valor_final;
            }
            if (valor_final < menor_valor) {
                menor_valor = valor_final;
            }
        }

        printf("Deseja processar outra entrega? 1-Sim, 0-Nao: ");
        scanf("%d", &continuar);
        while (continuar != 0 && continuar != 1) {
            printf("Valor invalido. Digite 1 ou 0: ");
            scanf("%d", &continuar);
        }
            exibirResumo(total_entregas, soma_valores, qtd_economica, qtd_expressa, qtd_prioritaria, maior_valor, menor_valor);

    return 0;
}

    } while (continuar == 1);
