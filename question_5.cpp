#include <iostream>
#include <cassert> // test library
#include <string>

using namespace std;
 
string ConcatRemove(string s, string t, int k) {
    
    string t_auxiliar, s_auxiliar; 
    int flag_ok=0, interacoes=0;
  
    t_auxiliar = t; // copy of t
    s_auxiliar = s ; // copy of s
    
    while(s_auxiliar.find(t_auxiliar)){   // I prove that substring exists
        t_auxiliar.pop_back();
    }
    
    while(s_auxiliar!=t_auxiliar){  // I see the number of changes made
        s_auxiliar.pop_back();
        interacoes++;
    }
    
    int valor_restante = t.length() - s_auxiliar.length() ;
    
    // evaluation of conditions
    
    if (valor_restante == (k-interacoes)) flag_ok = 1;

    else if (s==t and k >= 2 * s.length()) flag_ok=1;
    
    else if (((interacoes%2!=0 and k%2!=0) or (interacoes%2==0 and k%2==0)) and (valor_restante+s_auxiliar.length()) == k) flag_ok=1;
    
    else if (s_auxiliar == t_auxiliar and (k-(valor_restante+interacoes))%2==0 and valor_restante+interacoes < k) flag_ok=1;
    
  
    if (flag_ok) return "yes";
        
    else return "no";
    
}

int main()
{
    string s, t, resposta;
    int k,restricoes=0,i;

    // test with equal words and extra attempts
    assert(ConcatRemove("bla","bla",18)=="yes") ; 
    // test with insufficient attempts
    assert(ConcatRemove("blablablabla","blablabcde",6)=="no") ;
    // question test
    assert(ConcatRemove("bla","bla",7)=="yes") ;
    // question test
    assert(ConcatRemove("blablablabla","blablabcde",8)=="yes") ;
    // test taking all the letters and adding
    assert(ConcatRemove("isaacxx","isaac",12)=="yes") ;
    // test just removing
    assert(ConcatRemove("passatempo","passa",5)=="yes") ;
    // test just putting
    assert(ConcatRemove("terra","terraform",4)=="yes") ;
    // removing everything and adding
    assert(ConcatRemove("xrt","abcxrtterra",14)=="yes") ;
    
    // It only writes the message if all the tests passed, otherwise the terminal will show the test that was not consistent with what was expected.
    
    cout << "All tests passed!" ;
    
  
}
