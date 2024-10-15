#include <iostream>
#include <string>
using namespace std;

#include "LinkedListT.h"

int main(void)
{
    LinkedListT<string> listaSoldados; 
    string nombre, nombres[8] = {"Francisco", "Jorge", "Luis", "Sergio", "Ricardo", "Salvador", "Diego", "Mario"}; 

    cout << "Lista: \n";
    for(string nom: nombres)  
    {
        listaSoldados.addLast(nom); 
        cout << nom << endl; 
    }
    cout << endl; 

    int numero, size, contador, index;
    bool found;

    do
    {

        size = listaSoldados.getSize();
        contador = size; 
        do
        {
            cout << "Dime el nUmero: ";
            cin >> numero; 
            if(numero > size || numero < 1)
                cout << "NUmero invAlido, por favor ingrese un valor menor/igual a " << size << endl << endl;
        } while (numero > size || numero < 1);

        do
        {
            cout << "Dime el nombre del soldado: ";
            cin >> nombre; 
            index = 0;  
            found = false; 
            for(int i = 0; i < size; i++)
            {
                if(listaSoldados.getData(i) == nombre)
                {
                    index = i;
                    found = true; 
                }
            }
            if(!found)
                cout << "Nombre no encontrado\n\n";
        } while (!found);
        
        if(size == numero && index == 0)
        {
            cout << "\nAdiOs " << listaSoldados.getData(size - index - 1) << endl << endl;
            listaSoldados.deleteAt(size - index - 1);
        }
        else if((index + numero) > size)
        {
            cout << "\nAdiOs " << listaSoldados.getData(index + numero - size - 1) << endl << endl;
            listaSoldados.deleteAt(index + numero - size - 1); 
        }
        else
        {
            cout << "\nAdiOs " << listaSoldados.getData(index + numero - 1) << endl << endl;
            listaSoldados.deleteAt(index + numero - 1);  
        }
        contador--;

        cout << "Lista: \n";
        listaSoldados.printList();
        
    }while(contador > 1);

    cout << listaSoldados.getData(0) << " entregarA el mensaje. \n\n";

    return 0; 
}