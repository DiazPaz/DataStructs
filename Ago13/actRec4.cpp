/* 2. Escribe una función recursiva que invierta una cadena (string). */


#include "iostream"
#include "string"
using namespace std;


string invertir(string c)
{  
    char letra;
    string letrasSobrantes;


    if(c.length()==0){
        return "";}
    else{
        letra = c[c.length()-1];
        letrasSobrantes = c.substr(0,c.length()-1);
        return letra + invertir(letrasSobrantes);}


}




int main(){


    string c,cInvertida;
   


    cout<<"Escribe una cadena: ";
    cin>>c;




    cInvertida=invertir(c);
    cout<<"La cadena invertida de "<<c<<" es: "<<cInvertida<<endl;


    return 0;
}
