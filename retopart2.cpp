/*
Reto parte 2

María José Mendoza Muñiz    A01652137
Andrea Serrano Diego        A01028728
Fernando Santoyo
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class Record
{
    public:

    string fecha;
    string hora;
    string ipFuente;
    int puertoFuente;
    string nombreFuente;
    string ipDestino;
    int puertoDestino;
    string nombreDestino;

    Record(string f, string h, string ipF, string pF, string nF, string ipD, string pD, string nD)
    {
        fecha = f;
        hora = h;
        ipFuente = ipF;

        if (pF == '-')
        {
            puertoFuente = 0;
        }
        else
        {
            try
            {
                puertoFuente = stoi(pF);
            }
            catch(const std::invalid_argument& ia)
            {
                puertoFuente = 0;
                std::cout << "ERROR" << pD << std::endl;
            } 
        }

        nombreFuente = nF;
        ipDestino = ipD;

        if (pD == '-')
        {
            puertoDestino = 0;
        }
        else
        {
            try
            {
                puertoDestino = stoi(pD);
            }
            catch(const std::invalid_argument& ia)
            {
                puertoDestino = 0;
                std::cout << "ERROR" << pD << std::endl;
            } 
        }

        nombreDestino = nD;  
    }

    void imprimirNombreFuente()
    {
        std::cout << nombreFuente << std::endl;
    }
};

vector<Record>conexiones;

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

        Record r(valores[0], valores[1], valores[2], valores[3], valores[4], valores[5], valores[6], valores[7]);
        conexiones.push_back(r);
        valores.clear();
    }
}

class InfoConexiones
{
    public:

    int puertoRemoto;
    string ipRemota;
    string nombreRemoto;

    InfoConexiones(int pR, string ipR, string nR) //constructor 
    {
        puertoRemoto = pR;
        ipRemota = ipR;
        nombreRemoto = nR;
    }
};

class ConexionesComputadora
{
    public:

    string ip;
    string nombre;
    list <InfoConexiones> entrantes;
    list <InfoConexiones> salientes;
}



int main()
{
    conexionesComputadora<int> cc;
    /* code */
    return 0;
}


