// Grafo no dirigido en matriz 

class GraphM
{
    public: 
        GraphM(){cantVertices = 0;};
        void insertVertex(char arrv[], int cantVer);
        void insertEdges(char fromVertex, char toVertex);
        void deleteEdges(char fromVertex, char toVertex);
        void print();
    private: 
        bool mat[10][10] = {false};
        char arrVertex[10]; 
        int cantVertices;
        int findPos(char vertex);
};

void GraphM::insertVertex(char arr[], int cantVer)
{
    for(int i = 0; i < cantVer; i++)
        arrVertex[i] = arr[i];
    cantVertices = cantVer; 
}

int GraphM::findPos(char vertex)
{
    int pos = -1; 
    int i = 0; 
    while((pos == -1) && (i < cantVertices))
    {
        if(arrVertex[i] == vertex)
        {
            pos = i; 
        }
        i++;
    }
    return pos;
}

void GraphM::insertEdges(char fromVertex, char toVertex)
{
    int posR = findPos(fromVertex);
    int posC = findPos(toVertex);
    mat[posR][posC] = true; 
    mat[posC][posR] = true; // simetrica
}

void GraphM::deleteEdges(char fromVertex, char toVertex)
{
    int posR = findPos(fromVertex);
    int posC = findPos(toVertex);
    mat[posR][posC] = false; 
    mat[posC][posR] = false; // simetrica
}

void GraphM::print()
{
    for(int i = 0; i < cantVertices; i++)
    {
        cout << arrVertex[i] << " ";
        for(int j = 0; j < cantVertices; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl; 
    }
}