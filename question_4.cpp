#include <iostream>
#include <string>

using namespace std;
 
// This question about the methods of inserting and placing only at the end, reminds me of a data structure called stack (LIFO), and I followed this line of reasoning.

// My function only makes "pops" on the stack, in the add part I do some calculations to confirm whether I return "yes" or "no".


string ConcatRemove(string s, string t, int k) {
    
    string t_auxiliar, s_auxiliar; 
    int flag_ok=0, interacoes=0;
  
    t_auxiliar = t; // copy the string t
    s_auxiliar = s ; // copy the string s
    
    while(s_auxiliar.find(t_auxiliar)){   // I prove that substring exists
        t_auxiliar.pop_back();  // Remove the last letter of the string
    }
    
    while(s_auxiliar!=t_auxiliar){  
        s_auxiliar.pop_back();
        interacoes++; // I see the number of "pops" made
    }
    
    int valor_restante = t.length() - s_auxiliar.length() ; // Stores the value of the remaining attempts
    
    // Condition evaluator
    
    if (valor_restante == (k-interacoes)) flag_ok = 1; // If the number of insertions after removals is equal to the remaining value

    else if (s==t and k >= 2 * s.length()) flag_ok=1; // In case the words are the same, I treat the idea of removals in the void.
    
    else if ((interacoes%2 == k%2) and (valor_restante+s_auxiliar.length()) == k) flag_ok=1; // Removing and adding question in sequence multiple times or once
        
    else if (s_auxiliar == t_auxiliar and (k-(valor_restante+interacoes))%2==0 and valor_restante+interacoes < k) flag_ok=1; // This function is a special case of the one above.
    
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
 
    // From here on down, the restrictions imposed on the issue are discussed.
 
    if (s.length() < 1 or s.length() > 100) restricoes++;
    if (t.length() < 1 or t.length() > 100) restricoes++;
    if (k < 1 or k > 100) restricoes++;
    
    for(i=0;i<s.length();i++){
        if (isupper(s[i])) restricoes++;
    }
    
    for(i=0;i<t.length();i++){
        if (isupper(t[i])) restricoes++;
    }
   
    if (restricoes){  cout << "Input error !";
    }
    else cout << ConcatRemove(s, t, k);
  
}
