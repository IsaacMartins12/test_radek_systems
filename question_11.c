#include <stdio.h>
#include <string.h>

int main()
{
    int i,cont=0,tamanho_da_palavra;
    char palavra[120];
    
    gets(palavra);
    
    tamanho_da_palavra = strlen(palavra)-1 ;
    
    for (i=tamanho_da_palavra;i>=0;i--){
         printf("%c",palavra[i]);
    }
}
