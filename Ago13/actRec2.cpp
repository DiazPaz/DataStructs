#include <iostream>
#include <string>

using namespace std; 

string pali(string palabra)
{
    unsigned largo = palabra.length();
    char c;
    string s; 

    if(largo != 0)
    {
        c = palabra[largo-1];
        s = palabra.substr(0, largo - 1);
        return c + pali(s);    
    }
    
    return ""; 
}

int main(void)
{
    string palabra; 
    getline(cin, palabra);

    if(pali(palabra) == palabra)
        cout << "Es palindromo.\n";
    else
        cout << "No es palindromo.\n";

    return 0; 
}