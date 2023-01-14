#include <iostream>
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
    
    int valor_restante = t.length() - s_auxiliar.length() ; // Guarda o valor das tentativas restantes
    
    // Avaliador de condicoes
    
    if (t.length() - s_auxiliar.length() == (k-interacoes)) flag_ok = 1;

    else if (s==t and k >= 2 * s.length()) flag_ok=1;
    
    else if ((interacoes%2 == k%2) and (valor_restante+s_auxiliar.length()) == k) flag_ok=1;
        
    else if (s_auxiliar == t_auxiliar and (k-(valor_restante+interacoes))%2==0 and valor_restante+interacoes < k) flag_ok=1;
    
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
