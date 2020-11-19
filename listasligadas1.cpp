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
        if (root == NULL)
        {
            root = nuevo;
        }
        //problema cuando agregamos un nodo al final
        //tenemos que llegar pasando por todos los nodos
        else
        {
            //temporal que apunta a root, apuntadores afuerzas
            Nodo<T> *temp = root;
            while (temp ->next!=NULL)
            {
                temp = temp->next;
            }

            temp->next = nuevo;
        }
    }
    //creamos una sobrecarga porque estamos iniciando con un nuevo root por lo tanto en el main no acepta insertar enteros
    void append(T value)
    {
        Nodo<T> *nuevo = new Nodo<T>(value);
        //no es recursivo porque esta jalando el append del nodo
        append(nuevo);
    }

    void imprimir()
    {
        //creamos nodo temporal
        Nodo<T> *temp = root;
        while (temp!=NULL)
        {
            //imprima lo que tiene en value y avance
            std::cout << temp->value << "," << std::endl; 
            temp = temp->next;
        }
    }
    //
    T getElementAt(int pos)
    {
        //obtener un valor en un posicion,iterar sobre toda la lista
        Nodo<T> *temp = root;
        int i = 0;
        //siempre y cuando este en NULL avanzamos
        while (temp != NULL && i<pos)
        {
            //movernos cuando ya confirme que si hay algo en el nodo anterior si no segmentation fault = F
            temp = temp->next;
            i++;
        }
        if (i == pos)
        {
            return temp->value;
        }
        else
        {
            return NULL;
        }
    }

    void insert(Nodo<T> *nuevo, int pos)
    {
        //caso lista vacia
        if (root == NULL)
        {
            root = nuevo;
        } 
        //inserte en la posicion 0
        else if (pos == 0)
        {
           nuevo->next = root;
           root = nuevo; 
        }
        else
        {
            //estamos haciendo el append si no se cumple la parte de la posicion
            Nodo<T> *temp=root;
			int i=0;
            //pos -1 para que el de antes sepa a donde apuntar
			while(temp->next!=NULL && i<pos-1)
            {
				temp=temp->next;
				i++;
			}
			nuevo->next=temp->next;
			temp->next=nuevo;
        }
        
    }
    
};

int main()
{
    LinkedList<int> list;
    list.append(3);
    list.append(5);
    list.append(7);
    list.imprimir();
    
    return 0;
}
