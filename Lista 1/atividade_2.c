#include <stdio.h>

int main()
{
    // Uso do tipo long long para evitar overflow de variavel
    long long N, A, B, soma;
    long long multiploA, multiploB, multiploAB;

    scanf("%lld", &N);
    scanf("%lld %lld", &A, &B);

    // Soma de 1 até o número N pela formula de P.A
    soma = (1 + N) * N / 2;

    // Condições de multiplos de A, B e AB
    multiploA = A * (N / A) * ((N / A) + 1) / 2;
    multiploB = B * (N / B) * ((N / B) + 1) / 2;
    multiploAB = (A * B) * (N / (A * B)) * ((N / (A * B)) + 1) / 2;

    soma = soma - multiploA - multiploB + multiploAB;

    printf("%lld\n", soma);

    if (soma % 2 == 0) {
        printf("Lá ele!!!");
    } else {
        printf("Opa xupenio AULAS...");
    }

    return 0;


}
