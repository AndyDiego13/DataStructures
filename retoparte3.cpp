/*
Reto parte 2
María José Mendoza Muñiz    A01652137
Andrea Serrano Diego        A01028728
Fernando Santoyo Moncada    A01028389
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

    ///Record()=default;

    Record(string f, string h, string ipF, string pF, string nF, string ipD, string pD, string nD)
    {
        fecha = f;
        hora = h;
        ipFuente = ipF;

        if (pF == "-")
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

        if (pD == "-")
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
    
    string getIpFuente()
    {
        return ipFuente;
    }


    void imprimirNombreFuente()
    {
        std::cout << nombreFuente << std::endl;
    }
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
            //
            Record r(valores[0], valores[1], valores[2], valores[3], valores[4], valores[5], valores[6], valores[7]);
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
    //int i = 0;
    //int j = 0;

    //constructor sin parametros/vacio se utiliza cuando quieres un constructor generico sin importar los parametros
    //
    ConexionesComputadora()
    {
        this -> ip = ip;
        this -> nombre = nombre;  

    }

    //constructor con parametros estrictamente para la implementacion deben de estar todas las variables

    ConexionesComputadora(string iP, string name, list<InfoConexiones> entradas, list<InfoConexiones> salidas)
    {
        ip = iP;
        nombre = name;
        entrantes = entradas;
        salientes = salidas;
    }

    void nuevaEntrante(int puerto, string ip, string nombre)
    {
        InfoConexiones ic(puerto, ip, nombre);
        entrantes.push_back(ic);
        //i++;
    }

    void nuevaSaliente(int puerto, string ip, string nombre)
    {
        InfoConexiones ic(puerto, ip, nombre);
        salientes.push_front(ic);
        ///j++;
    }

    list<InfoConexiones> getCE()
    {
        return entrantes;
    }

    list<InfoConexiones> getCS()
    {
        return salientes;
    }

    void imprimirCc()
    {
       cout << "La IP del usuario es: " << ip << endl;
       cout << "El nombre del usuario es: " << nombre << endl;
       //cout << "Conexiones entrantes: " << i << endl;
       //cout << "Conexiones salientes: " << j << endl;
    }

    /*
    void imprimirConexion()
    {
        operator std::string() const { return std::string(str, len); }


        InfoConexiones * item = new InfoConexiones;

        string ultimaConexion = entrantes.back();
        cout << ultimaConexion << endl;

        delete item;
    }
*/
};



int main()
{
    Datos d;
    d.leerDatos("/Users/andydiego13/Downloads/copianuevo9.csv");
    std::cout << "datosleidos" << std::endl;
    d.imprimir();

    string nIp = "172.18.243";  //ip interna
    string crearIp;
    cout << "Inserta un número entre 1 y 150 para generar una IP: " << endl;
    cin >> crearIp;
    string resultado = nIp + "." + crearIp;
    cout << "La IP generada es: " << endl;
    cout << resultado << endl;

    return 0;
}
