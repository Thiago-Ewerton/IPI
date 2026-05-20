#include <stdio.h>
#include <stdint.h>


union Sensor {

    uint8_t bruto;

    struct {
        unsigned erro    : 1; // bit 0
        unsigned modo    : 3; // bits 1-3
        unsigned leitura : 4; // bits 4-7
    } campos;

};

int main() {

    union Sensor sensor;

    int entrada;

    scanf("%d", &entrada);

    sensor.bruto = entrada;

    printf("Byte bruto: %u | ", sensor.bruto);
    printf("Erro: %u | ", sensor.campos.erro);
    printf("Modo: %u | ", sensor.campos.modo);
    printf("Leitura: %u\n", sensor.campos.leitura);

    return 0;
}