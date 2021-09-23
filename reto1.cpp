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
            //como los datos son generados en windows y windows usa /r/n ponemos este if 
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
        std::cout << "Número de registros en archivo: " << conexiones.size() << std::endl;
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

template<class T>
class MergeSort: public Sort<T>
{
    public:

    void sort(vector<T> &data, int comparador(T a, T b))
    {
        sortAux(data, 0, data.size() - 1, comparador);
    }

    private:

    void sortAux(vector<T> &data, int lo, int hi, int comparador(T a, T b))
    {
        if (lo >= hi)
        {
            return;
        }

        int mid = (lo+hi)/2;

        sortAux(data, lo, mid, comparador);
        sortAux(data, mid + 1, hi, comparador);
        merge(data, lo, mid, hi, comparador); 
    }

    void merge(vector<T> &data, int low, int mid, int hi, int comparador(T a, T b))
    {
        int sizeA = mid - low + 1;
        int sizeB = hi - mid;

        vector<T> copiaA;
        vector<T> copiaB;

        for (int i = 0; i < sizeA; i++)
        {
            copiaA.push_back(data[low + i]);
        }

        for (int i = 0; i < sizeB; i++)
        {
            copiaB.push_back(data[mid + i + 1]);
        }

        int indexA = 0;
        int indexB = 0;
        int indexData = low;

        while (indexA < sizeA && indexB < sizeB)
        {
            if (comparador(copiaA[indexA], copiaB[indexB]) < 0)
            {
                data[indexData] = copiaA[indexA];
                indexA++;
            }
            else
            {
                data[indexData] = copiaB[indexB];
                indexB++;
            }

            indexData++; 
        }

        while (indexA < sizeA)
        {
            data[indexData] = copiaA[indexA];
            indexA++;
            indexData++;
        }

        while (indexB < sizeB)
        {
            data[indexData] = copiaB[indexB];
            indexB++;
            indexData++;
        }   
    } 
};

vector<Record> conexiones;

template <class T>
int busquedaBinaria(vector<T> a, T buscado, int comparador(T a, T b))
{
    int inicio = 0;
    int fin = a.size() - 1;
    
    while (fin >= inicio)
    {
        int medio = (inicio + fin)/2;
        if (comparador(a[medio], buscado) == 0)
        {
            return medio;
        }
        else if (comparador(buscado, a[medio]) > 0)
        {
            inicio = medio + 1;
        }   
        else
        {
            fin = medio - 1;
        }
    }

    return -1;
};   
    

int compararPorNombreFuente2(Record a, string b)
{
	if(a.nombreFuente<b)
    {
		return -1;
	}
    else if (a.nombreFuente==b)
    {
	    return 0;
	}
    else
    {
		return 1;
	}
};

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
};

int compararPorNombreDestino2(Record a, string b)
{
	if(a.nombreDestino < b)
	{
		return -1;
	}
	else if (a.nombreDestino == b)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

template <class T, class M>
int busquedaBinaria2(vector<T> a, M buscado, int comparador(T a, M b))
{
	int inicio=0;
	int fin=a.size()-1;
	while(fin>=inicio)
	{
		int medio=(inicio+fin)/2;
		if(comparador(a[medio],buscado)==0)
		{
			return medio;
		}
		else if(comparador(a[medio], buscado)<0)
		{
			inicio=medio+1;
		}
		else
		{
			fin=medio-1;
		}
	}
	return -1;
} 



int main()
{
    
    Datos d;
    d.leerDatos("/Users/andydiego13/Downloads/equipo7.csv");
    //Pregunta 1 (¿Cuantos registros tiene tu archivo?)
    std::cout << "Datos Leídos" << std::endl;
    d.imprimir();

    MergeSort<Record> s;

    s.sort(conexiones, compararPorNombreFuente);
    std::cout << "datosordenados " << std::endl;

    //Record r (" ", " ", "jeffrey.reto.com", " ");
    //Record r (" ", " ", "betty.reto.com", " ");
    //Record r (" ", " ", "katherine.reto.com"," ");
    //Record r (" ", " ", "scott.reto.com", " ");
    //Record r (" ", " ", "benjamin.reto.com", " ");
    //Record r (" ", " ", "samuel.reto.com", " ");
    //Record r(" ", " ", "raymond.reto.com", " ");
    //Record r (" ", " ", "brandon.reto.com", " ");

    //Record r(" ", " ", "server.reto.com", " ");
    //Record r(" ", " ", "protonmail.com", " ");

   //int pos = busquedaBinaria(conexiones, r, compararPorNombreFuente);
   
    //std::cout << "ENCONTRADO" << pos << std::endl;
   
    //esto fue lo que hicimos para busqueda binaria 2 pero no me gusto(aka no funciono tho) y preferi la busqueda binaria 1 
    //string a = "jeffrey.reto.com";
    //string a = "betty.reto.com";
    //string a = "katherine.reto.com";
    //string a = "scott.reto.com";
    //string a = "benjamin.reto.com";
    //string a = "samuel.reto.com";
    //string a = "raymond.reto.com";
    //string a = "brandon.reto.com";

    //Pregunta 5
    //string a = "server.reto.com";
    //s//td::cout << a << std::endl;

    //Pregunta 6
    //string a = "protonmail.com";

    std::string a = "freemailserver.com";
    
    int pos = busquedaBinaria2(d.conexiones, a, compararPorNombreDestino2);
    if(pos != -1)
    {
        std::cout << "Encontrado" << std::endl;
    }
    

   //string a = "scott.reto.com";
    /*
    int pos2 = busquedaBinaria2(d.conexiones,a,compararPorNombreFuente2);
    if (pos2 != -1)
    {
        std::cout << "Encontrado" << std::endl;
    }
    */
    

    return 0;
}




