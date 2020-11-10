/*
Reto 1

María José Mendoza Muñiz    A01652137
Andrea Serrano Diego        A01028728
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Record
{
    public:

    string fecha;
    string hora;
    string nombreFuente;
    string nombreDestino;
    //vector <Record> conexiones;

    Record(string f, string h, string nF, string nD)
    {
        fecha = f;
        hora = h;
        nombreFuente = nF;
        nombreDestino = nD;
    }

    /*
    void imprimirDatos()
    {
        std::cout << fecha << std::endl;
    }*/
};

class Datos
{
    public:
    string path;
    vector<Record> conexiones;

    void leerDatos(string path)
    {
        ifstream fileIn;
        fileIn.open(path); //path es el directorio

        string line, partes;
        vector<string> valores;
        


        while(fileIn.good())
        {
            getline(fileIn, line);
            istringstream sIn(line); //separador de comas

            while(getline(sIn, partes, ','))
            {

                valores.push_back(partes);
            }
            
            if(valores[7].find('\r')!= valores[7].npos)
            {
                valores[7] = valores[7].substr(0, valores[7].size()-1);
            }

            Record r(valores[0], valores[1], valores[4], valores[7]);
            conexiones.push_back(r);
            valores.clear();
        }
    }

    void imprimir()
    {
        std::cout << "Número de registros en archivo" << conexiones.size() << std::endl;
    }

    int compararPorFecha(Record a, Record b)
	{
		if(a.fecha < b.fecha)
		{
			return -1;
		}
		else if (a.fecha == b.fecha)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

    int compararPorNombreFuente(Record a, Record b)
	{
		if(a.nombreFuente < b.nombreFuente)
		{
			return -1;
		}
		else if (a.nombreFuente == b.nombreFuente)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

    int compararPorNombreDestino(Record a, Record b)
	{
		if(a.nombreDestino < b.nombreDestino)
		{
			return -1;
		}
		else if (a.nombreDestino == b.nombreDestino)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}	
};

template<class T>
class Sort
{
    public:
    virtual void sort(vector<T> &data, int comparador(T a, T b)) = 0;

    void intercambiar(vector<T> &data, int posI, int posJ)
    {
        T temp = data[posI];
        data[posI] = data[posJ];
    }

    void imprimir(vector<T> data)
    {
        for (int i = 0; i < data.size(); i++)
        {
            std::cout << data[i] << "," << std::endl;
        }

        std::cout << std::endl;   
    }
};




