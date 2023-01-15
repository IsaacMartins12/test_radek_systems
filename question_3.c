#include <stdio.h>

int main()
{
    int i;
    
    for(i=1;i<=100;i++){ 
        
        if (i%3==0 || i%5==0){ // I just need to check if it's a multiple of 3 or 5, if not, I don't even need to enter the if
            
        if (i%3==0) printf("Foo");
        
        if (i%5==0) printf("Baa");
        }
        
        else printf("%d",i);
        
        printf("\n");
}
}
