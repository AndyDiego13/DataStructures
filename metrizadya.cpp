#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template<class T>
class Nodo
{
    public:
    ///id es la posición
    int id;
    //value no se puede ser igual no puede haber dos PUEBLAS
    T value;

    Nodo()
    {
        //esta clase
        this -> id = 0;
        this -> value = NULL;
    }

    Nodo(int id, T value)
    {
        this -> id = id;
        this -> value = value;
    }

};

template<class T>
class Graph
{
    public:
    unordered_map<T, Nodo<T>> nodos;
    vector<vector<int>> matrix;
    int idActual;

    Graph()
    {
        idActual = 0;

    }

    void agregarNodo(T value)
    {
        if (nodos.find(value) == nodos.end)
        {
            Nodo<T> nuevo(idActual, value);
            nodos[value] = nuevo;
            idActual++;
            vector<int> nuevaFila;
            for (int i = 0; i < idActual; i++)
            {
                matrix[i].push_back(0);
                nuevaFila.push_back(0);
            }
            //para agregar la nueva fila dentro de la matriz
            //nuevaFila es el vector dentro del vector matrix
            nuevaFila.push_back(0);
            matrix.push_back(nuevaFila);
        }
    }
};

int main()
{
    vector<vector<int>> m;
    vector<int> n;

    n.push_back(0);
    n.push_back(1);

    m.push_back(n);

    for(auto fila: m)
    {
        for(int valor: fila)
        {
            std::cout << valor << "," << std::endl;
        }
        std::cout << "    " << std::endl;
    }



    return 0;
}
