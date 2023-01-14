#include <iostream>
#include <string>

using namespace std;
 
// Essa questao pelo métodos de inserir e colocar somente no final, lembra uma estrutura de dados chamada pilha (LIFO) , e eu segui essa linha de raciocínio.

// Minha função faz somente "pops" na pilha, na parte de acrescentar eu faço alguns cálculos para confirmar se retorno "yes" ou "no" .


string ConcatRemove(string s, string t, int k) {
    
    string t_auxiliar, s_auxiliar; 
    int flag_ok=0, interacoes=0;
  
    t_auxiliar = t; // copia da string t
    s_auxiliar = s ; // copia de string s
    
    while(s_auxiliar.find(t_auxiliar)){   // Eu provo que existe substring
        t_auxiliar.pop_back();  // Retiro a última letra da string
    }
    
    while(s_auxiliar!=t_auxiliar){  // Eu vejo o numero de alteracoes feitas
        s_auxiliar.pop_back();
        interacoes++; // Conto o número interações de remoção
    }
    
    int valor_restante = t.length() - s_auxiliar.length() ; // Guarda o valor das tentativas restantes
    
    // Avaliador de condicoes
    
    if (valor_restante == (k-interacoes)) flag_ok = 1; // Se for o caso de o número de inserções depois das remoções for igual ao valor restante

    else if (s==t and k >= 2 * s.length()) flag_ok=1; // No caso das palavras serem iguais, tratanto a ideia de remoções no vazio.
    
    else if ((interacoes%2 == k%2) and (valor_restante+s_auxiliar.length()) == k) flag_ok=1; // Questao de remocao e adicao em sequencia várias vezes ou uma vez
        
    else if (s_auxiliar == t_auxiliar and (k-(valor_restante+interacoes))%2==0 and valor_restante+interacoes < k) flag_ok=1; // Essa função é um caso especial da de cima
    
    if (flag_ok) return "yes";
        
    else return "no";
    
}

int main()
{
    string s, t;
    int k,restricoes=0,i;

    cin >> s;
    cin >> t;
    cin >> k;
   
    if (s.length() < 1 or s.length() > 100) restricoes++;
    if (t.length() < 1 or t.length() > 100) restricoes++;
    if (k < 1 or k > 100) restricoes++;
    
    for(i=0;i<s.length();i++){
        if (isupper(s[i])) restricoes++;
    }
    
    for(i=0;i<t.length();i++){
        if (isupper(t[i])) restricoes++;
    }
   
    if (restricoes){  cout << "Erro no input";
    }
    else cout << ConcatRemove(s, t, k);
  
}
