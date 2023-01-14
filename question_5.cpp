#include <iostream>
#include <cassert>
#include <string>

using namespace std;
 
string ConcatRemove(string s, string t, int k) {
    
    string t_auxiliar, s_auxiliar; 
    int flag_ok=0, interacoes=0;
  
    t_auxiliar = t; // copia de t
    s_auxiliar = s ; // copia de c
    
    while(s_auxiliar.find(t_auxiliar)){   // Eu provo que existe substring
        t_auxiliar.pop_back();
    }
    
    while(s_auxiliar!=t_auxiliar){  // Eu vejo o numero de alteracoes feitas
        s_auxiliar.pop_back();
        interacoes++;
    }
    
    int valor_restante = t.length() - s_auxiliar.length() ;
    
    // Avaliador de condicoes
    
    if (t.length() - s_auxiliar.length() == (k-interacoes)) flag_ok = 1;

    else if (s==t and k >= 2 * s.length()) flag_ok=1;
    
    else if (((interacoes%2!=0 and k%2!=0) or (interacoes%2==0 and k%2==0)) and (valor_restante+s_auxiliar.length()) == k) {
           flag_ok=1;
        }
        
    else if (s_auxiliar == t_auxiliar and (k-(valor_restante+interacoes))%2==0 and valor_restante+interacoes < k) flag_ok=1;
    
  
    if (flag_ok) return "yes";
        
    else return "no";
    
}

int main()
{
    string s, t, resposta;
    int k,restricoes=0,i;

    // teste com palavras iguais e tentativas de sobra
    assert(ConcatRemove("bla","bla",18)=="yes") ; 
    // teste com tentativas insuficientes
    assert(ConcatRemove("blablablabla","blablabcde",6)=="no") ;
    // teste do problema
    assert(ConcatRemove("bla","bla",7)=="yes") ;
    // teste do problema
    assert(ConcatRemove("blablablabla","blablabcde",8)=="yes") ;
    // teste tirando todas as letras e acrescentando
    assert(ConcatRemove("isaacxx","isaac",12)=="yes") ;
    // teste só com retirada
    assert(ConcatRemove("passatempo","passa",5)=="yes") ;
    // teste só colocando
    assert(ConcatRemove("terra","terraform",4)=="yes") ;
    // tirando tudo e acrescentando
    assert(ConcatRemove("xrt","abcxrtterra",14)=="yes") ;
    
    // Só escreve isso se todos os testes passaram
    
    cout << "Passaram todos os testes !" ;
    
  
}
