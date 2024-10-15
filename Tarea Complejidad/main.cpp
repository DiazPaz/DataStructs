#include <iostream>
using namespace std; 

// Escribe un algoritmo que dado un arreglo que contiene enteros 
// positivos, regrese la suma de los enteros impares contenidos en el arreglo.
// a) Realiza el algoritmo en forma iterativa, ¿Cuál es el orden del algoritmo?
// b) Realiza el algoritmos en forma recursiva ¿Cuál es el orden del algoritmo

/**
 * Complejidad de O(n)
 */
int iterativo(int arr[], int n)
{
    int suma = 0; 
    for(int i = 0; i < n; i++)
        if(arr[i] % 2 != 0)
            suma += arr[i];

    return suma; 
}

/**
 * Complejidad de O(n)
 */
int recursivo(int arr[], int n, int i, int suma)
{
    if(i < n)
        if(arr[i] % 2 != 0)
            return recursivo(arr, n, i + 1, suma += arr[i]);
        else
            return recursivo(arr, n, i + 1, suma);
    else 
        return suma;
}

int main(void)
{
    int size = 9, arr[size] = {1,2,3,4,5,6,7,8,9};

    cout << iterativo(arr, size) << endl; 
    cout << recursivo(arr, size, 0, 0) << endl; 

    return 0;
}