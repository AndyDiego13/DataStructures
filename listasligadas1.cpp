#include <iostream>

using namespace std;

template <class T> 
class Nodo
{
    public:
    T value;
    //apuntador al siguiente nodo
    Nodo<T> *next;

    Nodo(T val)
    {
        value = val;
        //NULL es cuando no le podemos decir a donde apuntar apunta a NADA
        next = NULL;
    }
};

template <class T>
class LinkedList
{
    public:
    ///otro nodo apuntador el raíz/cabeza
    Nodo<T> *root; 

    LinkedList()
    {
        root = NULL;
    }

    //append/insert
    void append(Nodo<T> *nuevo)//obtienes la direccion del nodo que vas a agregar
    {
        if (root = NULL)
        {
            root = nuevo;
        }
        //problema cuando agregamos un nodo al final
        //tenemos que llegar pasando por todos los nodos
        else
        {
            
        }
        
        
    }
};

int main()
{
    
    return 0;
}
