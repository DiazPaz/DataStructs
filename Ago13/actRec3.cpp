/* 1. Imprime la suma de los números de un entero proporcionado por el usuario */
#include "iostream"
using namespace std;


int suma(int n)
{  
    int sumaI,sumaF;
    if(n==1)
        return 1;
    else
        sumaI = suma(n-1);
        sumaF = n + sumaI;
        cout <<sumaI<<"+"<<n<<"= "<<sumaF<<endl;
        return sumaF;


}




int main(){


    int n, total;
   


    cout<<"Escribe un numero: ";
    cin>>n;




    total=suma(n);
    cout<<"La suma de los numeros de "<<n<<" es: "<<total;


    return 0;
}
