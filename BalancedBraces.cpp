
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

bool isPair(char first, char last){

    if(first == '{' && last == '}')
        return true;
    else if(first == '[' && last == ']')
        return true;
    else if(first == '(' && last == ')')
        return true;
    else
        return false;
}

bool is_balanced(string exp) {
    
    if(exp.size() == 0 || exp.size() == 1)
        return false;
    
    stack<char> sc;
    char first = 'a';
    
    for(int i = 0; i < exp.size(); ++i){

        if(exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
            sc.push(exp[i]);
        else if(exp[i] == ']' || exp[i] == '}' || exp[i] == ')'){          
            
            if(!sc.empty()){
                  first = sc.top();
                  sc.pop();

                  if(!isPair(first, exp[i]))
                     return false;
            }                
            else
                return false;         
        }            
    }
    return sc.empty();    
   
}

int main(){
   
   cout<<"Please enter a valid string of braces : ";
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    
    return 0;
}
