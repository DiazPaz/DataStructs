#include "NodeTr.h"

class BST
{
    private: 
        NodeTr *root;   
        int numChild(NodeTr *nodo);
        NodeTr* predecesor(NodeTr* p, NodeTr* &parent);
        NodeTr* sucesor(NodeTr *p, NodeTr *&parent);
        void preorden(NodeTr *p);
        void inorden(NodeTr *p);
        void posorden(NodeTr *p);
    public: 
        BST(){ root = nullptr; }
        void add(int dato);
        bool remove(int dato);
        bool find(int dato);
        void visita(int orden);    

        // calcula la altura del BST 
        int calculaAltura(NodeTr *p); 

        // regresa la altura del BST
        int getAltura();

        // da el contenido de cada nivel por nivel
        void recorridoNivel(NodeTr *p, int nivel);

        // recorre cada nivel del BST para imprimirlo
        void printLevels();

        // función recursiva que regresa un apuntador al padre 
        NodeTr *padre(NodeTr *hijo, int dato); 

        // regresa los ancestros del nodo seleccionado
        int ancestors(int dato);

        // regresa un entero indicando el nivel donde se encuentra el dato deseado
        int whatLevelAmI(int dato);

};


void BST::add(int dato)
{
    if(root == nullptr) // arbol vacío
        root = new NodeTr(dato);
    else
    {
        NodeTr* aux = root; // aux apunta a la raíz
        while(aux != nullptr)
        {
            if(aux->dato == dato)
            {
                cout << "Dato duplicado.\n";
                aux = nullptr; 
            }
            else{
                if(aux->dato > dato)
                {
                    if(aux->left == nullptr)
                    {
                        aux->left = new NodeTr(dato);
                        aux = nullptr; 
                    } 
                    else 
                    {
                        aux = aux->left;
                    }
                }
                else
                {
                    if(aux->right == nullptr)
                    {
                        aux->right = new NodeTr(dato);
                        aux = nullptr; 
                    }
                    else
                    {
                        aux = aux->right; 
                    }
                }
            }
        }
    }
}

/**
 *  @param dato Número el cual el usuario está buscando dentro del árbol. 
 */
bool BST::find(int dato)
{
    if(root == nullptr) // arbol vacío
        return false; 
    else
    {
        NodeTr* aux = root; // aux apunta a la raíz
        while(aux != nullptr)
        {
            if(aux->dato == dato)
                return true; // se encontró el dato
            else
                aux = (aux->dato > dato ? aux->left : aux->right);
        }
        return false;     
    }
}

int BST::numChild(NodeTr *nodo)
{
    if(nodo->left == nullptr && nodo->right == nullptr)
    {
        return 0; 
    }
    else
    {
        if(nodo->left != nullptr && nodo->right != nullptr)
        {
            return 2; 
        }
        else
        {
            return 1;
        }
    }
}

bool BST::remove(int dato)
{
    if(root == nullptr) // arbol vacío
        return false; 
    else
    {
        NodeTr* parent = nullptr; 
        NodeTr* aux = root; // aux apunta a la raíz
        while(aux != nullptr)
        {
            if(aux->dato == dato)
            {
                switch(numChild(aux))
                {
                case 0:
                    if(root == aux)
                        root = nullptr; 
                    else 
                    {
                        if(parent->left == aux)
                            parent->left = nullptr; 
                        else 
                            parent->right = nullptr; 
                    }
                    delete aux;
                    break;
                case 1:
                    if(parent == nullptr)
                    {
                        if(aux->left == nullptr)
                            root = aux->right; 
                        else 
                            root = aux->left;
                    }
                    else
                    {
                        if(parent->left == aux)
                        {
                            if(aux->left == nullptr)
                                parent->left = aux->right; 
                            else
                                parent->left = aux->left; 
                        }
                        else 
                        {
                            if(aux->left == nullptr)
                                parent->right = aux->right;
                            else 
                                parent->right = aux->left; 
                        }
                    }
                    delete aux; 
                    break;
                case 2:
                    int opt; 
                    NodeTr *parent = nullptr, *aux2; 
                    cout << "Desea borrar por predecesor (1) o sucesor (2)? "; cin >> opt; 
                    switch (opt)
                    {
                    case 1:
                        aux2 = predecesor(aux, parent); // El predecesor ya se asigna a aux2 y el valor de parent se actualiza 
                        cout << "Predecesor: " << aux2->dato << endl << "Parent: " << parent->dato << endl << "Dato a cambiar: " << aux->dato << endl; 
                        aux->dato = aux2->dato; // se cambia el valor de aux (el elemento que deseamos cambiar) 
                        // El predecesor es el elemento más grande de los elementos más chicos a la izquierda.
                        // revisar el caso en el que aux2 tiene un hijo a la izquierda
                        if(aux2->left == nullptr)
                        {
                            parent->right = nullptr; 
                        }
                        else
                        {
                            parent->right = aux2->left; 
                        }
                        break;
                    case 2: 
                        aux2 = sucesor(aux, parent); // El predecesor ya se asigna a aux2 y el valor de parent se actualiza 
                        cout << "Sucesor: " << aux2->dato << endl << "Parent: " << parent->dato << endl << "Dato a cambiar: " << aux->dato << endl; 
                        aux->dato = aux2->dato; // se cambia el valor de aux (el elemento que deseamos cambiar) 
                        // El sucesor es el elemento más chico de los elementos más grandes a la derecha. 
                        // revisar el caso en el que aux2 tiene un hijo a la izquierda
                        if(aux2->right == nullptr)
                        {
                            parent->left = nullptr; 
                        }
                        else
                        {
                            parent->left = aux2->right; 
                        }
                        break;
                    default:
                        break;
                    }
                    delete aux2; 
                    break;
                
                // default:
                //     break;
                }
                aux = nullptr; 
                return true; 
            }
            else
            {
                parent = aux; 
                if(aux->dato > dato)
                    aux = aux->left; 
                else
                    aux = aux->right;
            }
        }
        return false;     
    }
}

NodeTr* BST::predecesor(NodeTr *p, NodeTr *&parent)
{
    parent = p; 
    NodeTr *aux = p->left; 
    while(aux->right != nullptr)
    {
        parent = aux; 
        aux = aux->right; 
    }
    return aux; 
}

NodeTr* BST::sucesor(NodeTr *p, NodeTr *&parent)
{
    parent = p; 
    NodeTr *aux = p->right; 
    while(aux->left != nullptr)
    {
        parent = aux; 
        aux = aux->left; 
    }
    return aux; 
}


/**
 * @param orden 1. preorden; 2. inorden; 3. posorden; 4. por nivel; 
 */
void BST::visita(int orden)
{
    switch (orden)
    {
    case 1:
        preorden(root);
        break;
    case 2:
        inorden(root);
        break;
    case 3:
        posorden(root);
        break;
    case 4: 
        printLevels();
        break; 
    
    default:
        break;
    }
}

void BST::preorden(NodeTr *p)
{
    if(p != nullptr)
    {
        cout << p->dato << " ";
        preorden(p->left);
        preorden(p->right);
    }
}


void BST::inorden(NodeTr *p)
{
    if(p != nullptr)
    {
        inorden(p->left);
        cout << p->dato << " ";
        inorden(p->right);
    }
}

void BST::posorden(NodeTr *p)
{
    if(p != nullptr)
    {
        posorden(p->left);
        posorden(p->right);
        cout << p->dato << " ";
    } 
}
  
int BST::calculaAltura(NodeTr *p)
{
    if(p == nullptr)
        return 0; 

    int der = calculaAltura(p->right);
    int left = calculaAltura(p->left);

    return (der > left ? der : left) + 1;
}

int BST::getAltura()
{
    NodeTr *p = root; 
    return calculaAltura(p);
}

void BST::printLevels()
{
    NodeTr *p = root; 
    int altura = this->getAltura();
    for(int nivel = 0; nivel <= altura+1; nivel++)
        recorridoNivel(p, nivel);
}

void BST::recorridoNivel(NodeTr *p, int nivel)
{   
    if(p == nullptr)
        return; 
    else if(nivel == 1)
        cout << p->dato << " "; 
    else if(nivel > 1)
    {
        recorridoNivel(p->left, nivel - 1);
        recorridoNivel(p->right, nivel - 1);
    }
}

NodeTr *BST::padre(NodeTr *hijo, int dato)
{
    if(hijo->dato != dato)
    {
        if(hijo->dato > dato)
        {
            cout << hijo->dato << " ";
            return(padre(hijo->left, dato));
        }
        else
        {
            cout << hijo->dato << " ";
            return(padre(hijo->right, dato));
        }
    }    
    else
    {
        return nullptr; 
    }
}

int BST::ancestors(int dato)
{
    // if(root == nullptr) // arbol vacío
    // {
    //     return -1; 
    // }
    // else
    // {
    //     NodeTr* aux = root; // aux apunta a la raíz
    //     if(this->find(dato)) this->padre(aux, dato); 
    //     return 1; 
    // }
    if(root != nullptr)
    {
        NodeTr* aux = root; // aux apunta a la raíz
        if(this->find(dato)) this->padre(aux, dato); 
        return 1; 
    }
    return -1;
}

int BST::whatLevelAmI(int dato)
{   
    int nivel = 0;
    if(root == nullptr) // arbol vacío
    {
        return -1; 
    }
    else
    {
        NodeTr* aux = root; // aux apunta a la raíz
        while(aux != nullptr)
        {
            if(aux->dato != dato)
            {
                aux = (aux->dato > dato ? aux->left : aux->right);
                nivel++; 
            }
            else
            {
                return nivel;
            }
        }
        return -1; // no se encontró el valor
    }
}