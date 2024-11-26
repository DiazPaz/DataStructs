// David Díaz Paz y Puente | 650794 | Estructuras de Datos
// Doy mi palabra que he realizado esta actividad con integridad académica.

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

    string line, word, adjInfo[500][6], aux, aux2;
    int count, size = 0, opcion, timeTrain, timeCar; 
    bool flag = false, flag2 = false, salir = false; 

    fin.open("EuropeCities.csv", ios::in);

    // Lectura del archivo de entrada .csv
    while(getline(fin, line))
    {
        size++;
        count = 0; 
        if(size > 1)
        {
            // Mientras no se termine la linea, y el conteo de columnas sea menor o igual a 6, se añadirán vertices (ciudades) a la lista
            while(line != "" && count <= 6)
            {
                // Delimitamos la coma como separador de los elementos en las filas, si no hay comas tomamos el elemento hasta que el string este vacío
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

    // añadimos las adyacencias a la lista de los vertices con los datos obtenidos de la lectura anterior
    for(int i = 0; i < size-1; i++)
    {
        timeTrain = stoi(adjInfo[i][2].substr(0, adjInfo[i][2].find(":")))*60 + stoi(adjInfo[i][2].substr(adjInfo[i][2].find(":")+1, adjInfo[i][2].size()));
        timeCar = stoi(adjInfo[i][4].substr(0, adjInfo[i][4].find(":")))*60 + stoi(adjInfo[i][4].substr(adjInfo[i][4].find(":")+1, adjInfo[i][4].size()));
        routes.insertAdj(adjInfo[i][0], adjInfo[i][1], timeTrain, stoi(adjInfo[i][3]), timeCar, stoi(adjInfo[i][5]));
    }

    // ciclo del menú
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
                // se genera un archivo de salida con la lista de adyacencias 
                system("cls");
                routes.printGraph();
                cout << "Archivo de salida output-1.out creado!\nSeleccione la opcion 'Salir' para generar archvios...\n";
                cout << "\nPresione ENTER para coninuar\n";
                getch();
                break;

            case 2:
                // ciclo para validar que exista la ciudad de origen para los recorridos BFS y DFS
                flag = false; 
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
                        cout << "\nPresione ENTER para coninuar\n";
                        getch();
                    }

                }while(flag == false);

                routes.BFS(aux, 0);
                routes.DFS(aux, 0);

                system("cls");
                cout << "Ciudad encontrada. \nArchivo de salida output2.out (BFS) listo. \nArchivo de salida output3.out (DFS) listo.\nSeleccione la opcion 'Salir' para generar archvios...\n";
                cout << "\nPresione ENTER para coninuar\n";
                getch();

                break;
                
            case 3:
                // Ciclo para validar que existan las ciudades de origen y de destino. 
                flag = false;
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
                        cout << "\nPresione ENTER para coninuar\n";
                        getch();
                    }

                }while(flag == false);

                flag = false; 
                do
                {
                    system("cls");
                    cout << "Ciudad de destino: ";
                    cin >> aux2; 
                    
                    for(int i = 0; i < size; i++)
                    {
                        if(aux2 == adjInfo[i][0])
                        {
                            flag = true;
                        }
                    }
                    if(flag == false)
                    {
                        system("cls");
                        cout << "Ciudad no encontrada, intente de nuevo. \n";
                        cout << "\nPresione ENTER para coninuar\n";
                        getch();
                    }

                }while(flag == false);
                
                // se realiza Dijkstra para encontrar las rutas más rápidas dependiendo del tiempo y la distancia
                system("cls");
                routes.Dijkstra(aux, aux2);
                cout << "\nPresione ENTER para coninuar\n";
                getch();
                break;

            case 4:
                // se cierra el archivo
                system("cls");
                cout << "Doy mi palabra que he realizado esta actividad con integridad acadEmica. \n";
                cout << "\nPresione ENTER para coninuar\n";
                getch();
                salir = true;
                return 0; 
                break;

            default:
                system("cls");
                cout << "opcion no valida, intente de nuevo...\n";
                cout << "\nPresione ENTER para coninuar\n";
                getch();
                break;
        }

    }while(salir != true);

    fin.close();
    return 0; 
}