#include <iostream>
#include <unordered_map>

using namespace std;

//class Queu maybe??

template<class T>
class Nodo
{
    public:
    //diccionario de adyacencia pero no sabe cual bien solo el siguiente
    //un solo nodo que te apunta los siguientes
    T value;
    unordered_map<Nodo<T> *, int> siguientes;

    Nodo(T val)
    {
        value = val;

    }

    void agregarArcoDirigidoConPeso(Nodo<T> *sig, int peso)
    {
        ///si no lo tenemos insertamos
        if(siguientes.find(sig) == siguientes.end())
        {
            siguientes[sig] = peso;
        }
    }

    void agregarArcoDirigido(Nodo<T> *sig)
    {
        agregarArcoDirigidoConPeso(sig, 1);
    }

    void imprimirNodo()
    {
        std::cout << value << ":" << std::endl;
        //interando el siguiente 
        //un apuntador a un pair o sea el diccionario 
        //for (Pair<Nodo<T> *, int> 
        //mejor auto
        for(auto nodoSiguiente: siguientes)
        {
            std::cout << nodoSiguiente.first -> value << ";" << nodoSiguiente.second << ";" <<std::endl;
        }
        std::cout << std::endl;
        
    }

    bool conexion(Nodo<T> *nodo, Nodo<T> *sig)//EVALUAR LOS DOS NODOS
    {
        if(siguientes.find(sig) == siguientes.end() && siguientes.find(nodo) == siguientes.end())
        {
            return true;
        }
        else 
        {
            return false;
        }

	}
};

//otro diccionario donde vamos a tener el valor y otro apuntador a un Nodo
//guardara todo los nodos que tenemos 
template<class T>
class Graph
{
    public:
    //por cada    valor un nodo
    unordered_map<T, Nodo<T> *> nodos;

    //solo se preocupara por los valores 

    void agregarNodo(T value)
    {
        //solo cuando no existe el nodo se agrega un Nodo
        if (nodos.find(value) == nodos.end())
        {
            Nodo<T> *nuevo = new Nodo<T>(value);
            nodos[value] = nuevo;
            
        }
    }

    void agregarArcoDirigidoConPeso(T nodo1, T nodo2, int peso)
    {
        //checar si existen
        if (nodos.find(nodo1) != nodos.end() && nodos.find(nodo2) != nodos.end())
        {
            //nodos[nodo1] apuntador a un nodo       traes el apuntador a nodo2
            nodos[nodo1]->agregarArcoDirigidoConPeso(nodos[nodo2], peso);
        }
    }

    void agregarArcoDirigido(T nodo1, T nodo2)
    {
        agregarArcoDirigidoConPeso(nodo1, nodo2, 1);
    }

    void agregarArcoConPeso(T nodo1, T nodo2, int peso)
    {
        agregarArcoDirigidoConPeso(nodo1, nodo2, peso);
        agregarArcoDirigidoConPeso(nodo2, nodo1, peso);
    }

    void agregarArco(T nodo1, T nodo2)
    {
        agregarArcoConPeso(nodo1, nodo2, 1);
    }

    void imprimirGrafo()
    {
        for(auto parValorNodo: nodos)
        {
            nodos.second->imprimirNodo();
        }
    }

    /*//modificar valor recibiera los dos nodos
    void modificar(T nodo1, T nodo2)
    {
        //encontrar que existan
        //buscar hay 
    }
    */
};


int main()
{
    /*
    Nodo<string> *a = new Nodo<string> ("CDMX");
    Nodo<string> *b = new Nodo<string> ("Tlaxcala");

    a->agregarArcoDirigidoConPeso(b,5);
    a->imprimirNodo();
    */

   Graph<string> g;
   g.agregarNodo("CDMX");
   g.agregarNodo("Tlaxcala");
   g.agregarNodo("Puebla");
   g.agregarNodo("Toluca");

   g.agregarArcoDirigidoConPeso("CDMX", "Tlaxcala", 50);
   g.agregarArcoConPeso("Cuernavaca", "Puebla", 765);
    return 0;
}
