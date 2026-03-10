#include <stdio.h>

int main(){

    int premio, px, py, pz;
    int x, y, z;
    int sobra;
    int a = 0, b = 0, c = 0;
    int divisivel = 0;
    int investiu = 0;

    scanf("%d", &premio);
    scanf("%d", &px);
    scanf("%d", &py);
    scanf("%d", &pz);

    x = premio * px/100;
    y = premio * py/100;
    z = premio * pz/100;

    sobra = premio - x - y - z;

    if((premio * px) % 100 == 0 && (premio * py) % 100 == 0 && (premio * pz) % 100 == 0){
        divisivel = 1;
        a = x;
        b = y;
        c = z;
    }

    // Tenta adicionar 1 real
    else if(((premio+1) * px) % 100 == 0 && ((premio+1) * py) % 100 == 0 && ((premio+1) * pz) % 100 == 0){
        premio = premio + 1;
        investiu = 1;
        a = premio * px / 100;
        b = premio * py / 100;
        c = premio * pz / 100;
        sobra = premio - a - b - c;
        if(sobra >= investiu + 1) divisivel = 1;
    }

    // Tenta adicionar 2 reais
    else if(((premio+2) * px) % 100 == 0 && ((premio+2) * py) % 100 == 0 && ((premio+2) * pz) % 100 == 0){
        premio = premio + 2;
        investiu = 2;
        a = premio * px / 100;
        b = premio * py / 100;
        c = premio * pz / 100;
        sobra = premio - a - b - c;
        if(sobra >= investiu + 1) divisivel = 1;
    }

    // Tenta adicionar 3 reais
    else if(((premio+3) * px) % 100 == 0 && ((premio+3) * py) % 100 == 0 && ((premio+3) * pz) % 100 == 0){
        premio = premio + 3;
        investiu = 3;
        a = premio * px / 100;
        b = premio * py / 100;
        c = premio * pz / 100;
        sobra = premio - a - b - c;
        if(sobra >= investiu + 1) divisivel = 1;
    }

    // Dinheiro que Rebeka acumula
    int dinheiro = 3; 
    dinheiro -= investiu;  

    if(divisivel){
        printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", a, b, c);
        // Rebeka fica com a sobra menos o que investiu
        dinheiro += sobra;
    } else {
        printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
    }

    // Provas que Rebeka precisa fazer
    if(investiu == 2){
        char l1, l2, l3;
        scanf(" %c", &l1);
        scanf(" %c", &l2);
        scanf(" %c", &l3);
        // Propriedade da tabela ASCI: Soma do número correspondente a sua posição na tabela
        int soma = (l1 - 'a' + 1) + (l2 - 'a' + 1) + (l3 - 'a' + 1);
        printf("%d\n", soma);
    }
    else if(investiu == 3){
        int i1, i2, i3;
        scanf("%d", &i1);
        scanf("%d", &i2);
        scanf("%d", &i3);
        
        // Verifica se pelo menos uma idade é divisível por 3
        if(i1 % 3 == 0 || i2 % 3 == 0 || i3 % 3 == 0){
            int parcelas = 0;
            // Conta parcelas do 3 em cada idade
            if(i1 % 3 == 0) parcelas += i1 / 3;
            if(i2 % 3 == 0) parcelas += i2 / 3;
            if(i3 % 3 == 0) parcelas += i3 / 3;
            printf("%d\n", parcelas);
        }
    }

    if(dinheiro >= 7){
        printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
    } else {
        printf("E parece que Rebeka vai ter que voltar andando...\n");
    }

    return 0;
}