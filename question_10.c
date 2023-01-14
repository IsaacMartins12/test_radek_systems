#include <stdio.h>

int main()
{
    int i,cont=0;
    char palavra[120];
    
    gets(palavra);
    
      while(palavra[i] != '\0'){
        i++;
        cont++;
    }
    printf("%d",cont);
}

