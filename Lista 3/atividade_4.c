#include <stdio.h>

int main() {
    int casos, clocks;
    char fio[61];      // Buffer para o fio atual
    char gigante[10001]; // Buffer para a luz gigante final
    int tam_gigante = 0; // Controla onde estamos na luz gigante

    scanf("%d", &casos);

    for (int c = 0; c < casos; c++) {
        scanf("%s %d", fio, &clocks);

        // Lógica dos fios individuais
        for (int j = 0; j < clocks; j++) {
            int i = 0;
            int deve_inverter = 1; // O primeiro sempre inverte no clock

            while (fio[i] != '\0' && deve_inverter) {
                char estado_antes = fio[i];

                // Inverte o estado
                if (fio[i] == 'X') {
                    fio[i] = 'O';
                } else {
                    fio[i] = 'X';
                }

                // Se continua invertendo o sucessor se o atual foi desligado 
                if (estado_antes == 'O' && fio[i] == 'X') {
                    deve_inverter = 1;
                } else {
                    deve_inverter = 0;
                }
                i++;
            }
            
        }

        // Logica do conjunto de lampadas
        if (tam_gigante > 0) {
            char ultimo_gigante = gigante[tam_gigante - 1];
            char primeiro_fio = fio[0];
            char ornamento;

            if (tam_gigante % 2 == 0) { // Tamanho Par
                if (ultimo_gigante == primeiro_fio) {
                    ornamento = '@';
                } else {
                    ornamento = '$';
                }
            } else { // Tamanho impar
                if (ultimo_gigante == primeiro_fio) {
                    ornamento = '#';
                } else {
                    ornamento = '%';
                }
            }
            
            // Adiciona o ornamento na gigante e atualiza o tamanho
            gigante[tam_gigante] = ornamento;
            tam_gigante++;
        }

        // Copia o fio processado para o final da luz gigante
        int j = 0;
        while (fio[j] != '\0') {
            gigante[tam_gigante] = fio[j];
            tam_gigante++;
            j++;
        }
        
        //print dos fios
        printf("%s\n", fio);
        
        // Garante que a string gigante sempre termine com o caractere nulo
        gigante[tam_gigante] = '\0';
    }

    printf("%s\n", gigante);

    return 0;
}
