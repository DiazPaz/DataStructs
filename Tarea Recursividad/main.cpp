#include <iostream>
using namespace std; 

int bacteriaIterativa(unsigned dias, int numBact)
{ 
    int nac;
    int fall;
    for(unsigned i = 0; i < dias; i++)
    {
        nac = ((numBact * 378) / 100);
        fall = ((numBact * 234) / 100);
        numBact = numBact + nac - fall; 
    }
    return numBact; 
}

int bacteriaRecursiva(unsigned dias, int numBact)
{
    int nac = ((numBact * 378) / 100);
    int fall = ((numBact * 234) / 100);
    if(dias > 0)
        return bacteriaRecursiva(dias - 1, numBact + nac - fall); 
    else 
        return numBact;
}

int main(void)
{
    int opc; 
    unsigned dias;
    int numBact = 1; 

    while(true)
    {
        cout << "Elige una opciOn: \n";
        cout << "1. Calcular por iteraciOn. \n";
        cout << "2. Calcular por recursiOn. \n";
        cout << "3. Salir. \n";
        cin >> opc;
        switch(opc)
        {
            case 1: 
                cout << "\nNUmero de dIas: " << endl;
                cin >> dias; 
                cout << "\nNUmero de bacterias: " << endl;
                cout << bacteriaIterativa(dias, numBact) << endl << endl;
                break; 
            case 2: 
                cout << "\nNUmero de dIas: " << endl;
                cin >> dias; 
                cout << "\nNUmero de bacterias: " << endl;
                cout << bacteriaRecursiva(dias, numBact) << endl << endl;
                break; 
            case 3: 
                return false;  
        }
    }
    return 0; 
}