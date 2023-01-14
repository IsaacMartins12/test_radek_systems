#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i=0,tamanho_da_palavra;
    string palavra;
    
    cin >> palavra;
    
    tamanho_da_palavra = palavra.length(); 
    
    // o meu método de pensamento pra nao usar variavel auxilar foi a de jogar pra depois da palavra original, a palavra de forma invertida
    // Se eu pegar a string "pesado", eu transformo ela em "pesadoodasep" com esse for abaixo.
   
    for(i=tamanho_da_palavra-2;i>=0;i--){
        palavra += palavra[i];
    }
    // E aqui nessa linha, eu só pego a substring que me interessa, que é a que fica depois da palavra original.
    palavra = palavra.substr(tamanho_da_palavra-1,palavra.length());
    
    cout << palavra << endl;
}
