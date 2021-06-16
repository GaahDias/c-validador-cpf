#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char cpf[11];
    int resPrimeiroDig = 0, resSegundoDig = 0, valDig = 11;

    printf("Insira um CPF (Máximo de 11 digitos, e apenas números): ");
    fgets(cpf, 12, stdin);

    for(int i = 0; i < (strlen(cpf) - 1); i++) {
        if(i < (strlen(cpf) - 2)) {
            resPrimeiroDig += (cpf[i] - '0') * (valDig - 1);
        }
        resSegundoDig += (cpf[i] - '0') * valDig;

        valDig--;
    }

    resPrimeiroDig = (resPrimeiroDig * 10) % 11;
    resSegundoDig = (resSegundoDig * 10) % 11;

    if(resPrimeiroDig == cpf[strlen(cpf) - 2] - '0' && resSegundoDig == cpf[strlen(cpf) - 1] - '0') {
        printf("\nO CPF inserido é válido!\n");
    } else {
        printf("\nOops... parece que esse CPF não é válido.\n");
    }
    
    return 0;
}