#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <conio.h>
using namespace std; 

#include "LinkedListTGP.h"

int main(void)
{
    LinkedListTGP<string> routes;

    ifstream fin; 

    string org, dest, line, word, timeTrain, timeCar, distanceTrain, distanceCar, adjInfo[500][6], nodeInfo[500], aux;
    int count, city = 0, size = 0, opcion; 
    bool flag = false, salir = false; 

    fin.open("EuropeCities.csv", ios::in);

    while(getline(fin, line))
    {
        size++;
        count = 0; 
        if(size > 1)
        {
            while(line != "" && count <= 6)
            {
                if(line.find(",") != -1)
                {
                    word = line.substr(0, line.find(","));
                    line = line.substr(line.find(",")+1, line.size()-1);
                    if(count == 0 && routes.findData(word) == -1)
                    {
                        routes.addFirst(word);
                    }
                    count++;
                }
                else
                {
                    word = line.substr(0, line.size());
                    line = "";
                    count++;
                }
                adjInfo[size-2][count - 1] = word; 
            }
        }
    }

    for(int i = 0; i < size-1; i++)
    {
        routes.insertAdj(adjInfo[i][0], adjInfo[i][1], adjInfo[i][2], adjInfo[i][3], adjInfo[i][4], adjInfo[i][5]);
    }

    do
    {


        system("cls");
        cout << "1. Desplegar lista de adyacencias del grafo.\n";
        cout << "2. Desplegar recorridos del grafo.\n";
        cout << "3. InformaciOn entre dos ciudades.\n";
        cout << "4. Salir.\n";
        cout << "\nIngresa opciOn: ";
        cin >> opcion; 

        switch(opcion)
        {
            case 1:
                system("cls");
                routes.printGraph();
                cout << "Archivo de salida output-1.out creado!\n";
                getch();
                break;

            case 2:
                do
                {
                    system("cls");
                    cout << "Ciudad de origen: ";
                    cin >> aux; 
                    
                    for(int i = 0; i < size; i++)
                    {
                        if(aux == adjInfo[i][0])
                        {
                            flag = true;
                        }
                    }
                    if(flag == false)
                    {
                        system("cls");
                        cout << "Ciudad no encontrada, intente de nuevo. \n";
                        getch();
                    }

                }while(flag == false);

                routes.BFS(aux, 0);
                routes.DFS(aux, 0);
                
                system("cls");
                cout << "Ciudad encontrada. \nArchivo de salida output2.out creado. \nArchivo de salida output3.out creado.\n";
                getch();

                break;
                
            case 3:

                break;

            case 4:
                system("cls");
                cout << "Doy mi palabra que he realizado esta actividad con integridad acadEmica. \n";
                getch();
                salir = true;
                return 0; 
                break;
            default:
                break;
        }

    }while(salir != true);

    fin.close();
    return 0; 
}