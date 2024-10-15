#include <iostream>
#include <fstream>
#include "calificacion.h"

using namespace std;
using std::string;

double promedio(double c1, double c2, double c3)
{
    return (c1 * 0.3 + c2 * 0.3 + c2 * 0.4);
}

int main(void)
{
    Calificacion grupo[18];
    ifstream entrada("calificaciones (3).txt");
    string nombre; 
    double calA, calE, calP, prom; 
    unsigned cont = 0; 
    int opcion; 

    while(entrada >> nombre >> calA >> calE >> calP)
    {
        grupo[cont].setNombreAlumno(nombre);
        grupo[cont].setExamen(calE);
        grupo[cont].setActividades(calA);
        grupo[cont].setCalProyecto(calP);
        cont++; 
    }
    entrada.close();

    do
    {
        cout << "\n1) listado de alumnos\n";
        cout << "2) alumnos con promedio mayor a 85\n";
        cout << "3) salir\n";
        cin >> opcion; 

        if(opcion == 1)
            for(Calificacion i: grupo)
            {
                cout << i.getNombreAlumno() << endl;
                cout << "Actividades: " << i.getActividades() << endl;
                cout << "Proyecto: " << i.getCalProyecto() << endl;
                cout << "Examen: " << i.getExamen() << endl;
                cout << "Promedio: " << promedio(i.getActividades(), i.getExamen(), i.getCalProyecto()) << endl;
            }

        if(opcion == 2)
        {
            for(Calificacion i: grupo)
            {
                prom = promedio(i.getActividades(), i.getExamen(), i.getCalProyecto());
                if(prom > 85)
                    cout << i.getNombreAlumno() << " " << prom << endl; 
            }
        }

    } while (opcion != 3);
    
    return 0; 
}