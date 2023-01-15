#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i=0,tamanho_da_palavra;
    string palavra;
    
    cin >> palavra;
    
    tamanho_da_palavra = palavra.length(); 
    
    // my thought method for not using an auxiliary variable was to put it after the original word, the word inverted
    // If I take a "pesado" string, I turn it into "pesadodasep" with the one below.
   
    for(i=tamanho_da_palavra-2;i>=0;i--){
        palavra += palavra[i];
    }
    // And here in this line, I just get the substring that interests me, which is the one after the original word.
    palavra = palavra.substr(tamanho_da_palavra-1,palavra.length());
    
    cout << palavra << endl;
}
