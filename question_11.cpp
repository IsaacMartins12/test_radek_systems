#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i=0,tamanho_da_palavra;
    string palavra;
    
    cin >> palavra;
    
    tamanho_da_palavra = palavra.length(); 
   
    for(i=tamanho_da_palavra-2;i>=0;i--){
        palavra += palavra[i];
    }
    
    palavra = palavra.substr(tamanho_da_palavra-1,palavra.length());
    cout << palavra << endl;
}
