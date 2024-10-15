#include <iostream>

using namespace std; 

void printAst(int n)
{
    for(int j = 0; j < n; j++)
        cout << "*";
    cout << endl;
}

void printSpa(int n)
{
    for(int j = 0; j < n; j++)
        cout << " ";
}

int tree(int level, int aux, int aux2)
{
    if(aux2 <= level * 2)
    {
        printSpa(aux); 
        printAst(aux2);
        return tree(level, aux - 1, aux2 + 2);
    }
    else
    {
        return 1; 
    }
}

int main(void)
{

    int level; 
    cin >> level;
    tree(level, level, 1);

    return 0; 
}