#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char cpf[11];
    int res, resPD = 0, resSD = 0, valDig = 11;

    printf("Insira um CPF (Máximo de 11 digitos, e apenas números): ");
    fgets(cpf, 12, stdin);

    for(int i = 0; i < (strlen(cpf) - 1); i++) {
        if(i < (strlen(cpf) - 2)) {
            int cpfPrimeiroDig = cpf[i] - '0';
            resPD += cpfPrimeiroDig * (valDig - 1);
        }

        int cpfSegundoDig = cpf[i] - '0';
        resSD += cpfSegundoDig * valDig;

        valDig--;
    }

    resPD = (resPD * 10) % 11;
    resSD = (resSD * 10) % 11;

    if(resPD == cpf[strlen(cpf) - 2] - '0' && resSD == cpf[strlen(cpf) - 1] - '0') {
        printf("\nO CPF inserido é válido!\n");
    } else {
        printf("\nOops... parece que esse CPF não é válido.\n");
    }
    
    return 0;
}