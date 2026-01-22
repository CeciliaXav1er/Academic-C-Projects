#include <stdio.h>
#include <string.h>
/*
Codifique uma função semelhante à strlen(s), que devolve o número de caracteres armazenados na string s. 
Lembre-se de que o terminador '\0' não faz parte da string e, portanto, não deve ser contado.
*/

int main() {
    
    int len=0;
    //Não atribui um valor à arr[] pq assim seria mt obvio o valor de len. Assim pode ser colocado qualquer coisa.
    char arr[]={"BANANA\0"}; 
    while (!(arr[len] == '\0')) {
        len++;
    }

    printf("%d", len);
    return 0;
}