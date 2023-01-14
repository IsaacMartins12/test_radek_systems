#include <stdio.h>

int main()
{
    int i;
    
    for(i=1;i<=100;i++){ // Repeticao de 1 até 100
        
        if (i%3==0 || i%5==0){ // Eu só precuso checar se é múltiplo de 3 ou de 5, se nao for nem preciso entrar no if
            
        if (i%3==0) printf("Foo");
        
        if (i%5==0) printf("Baa");
        }
        
        else printf("%d",i);
        
        printf("\n");
}
}
