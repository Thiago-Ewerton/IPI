#include <stdio.h>

int main()
{
    long long N, A, B, soma;
    long long multiploA, multiploB, multiploAB;

    scanf("%lld", &N);
    scanf("%lld %lld", &A, &B);

    soma = (1 + N) * N / 2;

    multiploA = A * (N / A) * ((N / A) + 1) / 2;
    multiploB = B * (N / B) * ((N / B) + 1) / 2;
    multiploAB = (A * B) * (N / (A * B)) * ((N / (A * B)) + 1) / 2;

    soma = soma - multiploA - multiploB + multiploAB;

    printf("%lld\n", soma);

    if (soma % 2 == 0) {
        printf("Algo de errado nao esta certo!\n");
    } 

    return 0;


}
