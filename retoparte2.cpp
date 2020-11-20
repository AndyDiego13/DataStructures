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

    Record()=default;

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
                //std::cout << "ERROR" << pD << std::endl;
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
                //std::cout << "ERROR" << pD << std::endl;
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

// usaremos la clase nodo de una linkedlist
template<class T>
class Nodo
{
    public:
    T data;
    Nodo<T> *next;
};

/* Decidimos no tener una clase InfoConexiones porque tenemos más conocimiento de manejar vectores en lugar de listas
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
*/
class ConexionesComputadora
{
    public:

    string ip;
    string nombre;
    int conexionesEntrantes; //indice de conexiones entrantes
    int conexionesSalientes; //indice de conexiones salientes
    Nodo<string> *conexiones_Entrantes;
    Nodo<string> *conexiones_Salientes;


    //constructor sin parametros/vacio se utiliza cuando quieres un constructor generico sin importar los parametros
    ConexionesComputadora()
    {
        //para que en el constructor Record funcione correctamente porque antes nos imprimia el error
        ip = "-"; 
        nombre = " ";
        //indeces antes les habiamos puesto i y j
        conexionesEntrantes = 0;
        conexionesSalientes = 0;
        //para este constructor iniciaremos los nodos en 0 para despues utilizar un adecuado manejo de memoria
        conexiones_Entrantes = 0;
        conexiones_Salientes = 0;
    }

    string crearIP;
    string getCrearIP()
    {
        return crearIP;
    }

    //constructor con parametros estrictamente para la implementacion deben de estar todas las variables que definas
    ConexionesComputadora(string nombre, string crearIP)
    {
        //ip interna
        ip = "172.18.243." + crearIP;
        this ->nombre = nombre;
        //aun no se necesitan
        conexionesEntrantes = 0;
        conexionesSalientes = 0;
        conexiones_Entrantes = 0;
        conexiones_Salientes = 0;
    }

    ConexionesComputadora(string crearIP)
    {
        ip = "172.18.243." + crearIP;
        //aqui no nos interesa el nombre
        nombre = " ";
        conexionesEntrantes = 0;
        conexionesSalientes = 0;
        conexiones_Entrantes = 0;
        conexiones_Salientes = 0;
    }

    //destructor para el manejo de memoria
    ~ConexionesComputadora()
    {
        Nodo<string> *des;
        while (conexiones_Entrantes)
        {
            des = conexiones_Entrantes;
            conexiones_Entrantes = conexiones_Entrantes->next;
            delete des;
        }
        while (conexiones_Salientes)
        {
            des = conexiones_Salientes;
            conexiones_Salientes = conexiones_Salientes->next;
            delete des;
        }

        std::cout << "Depuración de memoria/conexiones" << std::endl;
    }

    void conexionesComputadorasEntrantes()
    {
        string path;
        vector<Record> conexiones;
        fstream fileIn;
        fileIn.open(path); //path es el directorio

        string line, partes;
        int count = 0;
        vector<string> valores;

        while (fileIn.good())
        {
            getline(fileIn, line);
            istringstream sIn(line);

            while (getline(sIn, partes, ','))
            {
                valores[count] = partes;
                count++;
            }
            if (valores[5] == ip)
            {
                if (conexiones_Entrantes == 0)
                {
                    Nodo<string> *nuevo = new Nodo<string>;
                    nuevo->data = valores[2];
                    nuevo->next = 0;
                    conexiones_Entrantes = nuevo;
                }
                else
                {
                    Nodo<string> *nuevo = new Nodo<string>;
                    nuevo->data = valores[2];
                    nuevo->next = conexiones_Entrantes;
                    conexiones_Entrantes = nuevo;
                }
                conexionesEntrantes++;
            }
            count = 0; 
        }
    }

    void conexionesComputadorasSalientes()
    {
        string path;
        vector<Record> conexiones;
        fstream fileIn;
        fileIn.open(path); //path es el directorio

        string line, partes;
        int count = 0;
        vector<string> valores;

        while (fileIn.good())
        {
            getline(fileIn, line);
            istringstream sIn(line);

            while (getline(sIn, partes, ','))
            {
                valores[count] = partes;
                count++;
            }
            if (valores[2] == ip)
            {
                if (conexiones_Salientes == 0)
                {
                    Nodo<string> *nuevo = new Nodo<string>;
                    nuevo->data = valores[5];
                    nuevo->next = 0;
                    conexiones_Salientes = nuevo;
                }
                else
                {
                    Nodo<string> *nuevo = new Nodo<string>;
                    Nodo<string> *ca = conexiones_Salientes;
                    nuevo->data = valores[5];
                    nuevo->next = 0;
                    while (ca->next)
                    {
                        ca = ca->next;
                    }
                    ca->next = nuevo;
                    
                }
                conexionesSalientes++;
            }
            count = 0; 
        }
    }

    void imprimirCE()
    {
        Nodo<string> *ce = conexiones_Entrantes;
        while (ce)
        {
            if (ce->next)
            {
                std::cout << ce->data << ", " << std::endl;
            }
            else
            {
                std::cout << ce->data << "\n" << std::endl;
            }
            ce = ce->next;
        }
        std::cout << "*** Son " << conexionesEntrantes << " conexiones entrantes. ***" << std::endl;
    }

    void imprimirCS()
    {
        Nodo<string> *cs = conexiones_Salientes;
        while (cs)
        {
            if (cs->next)
            {
                std::cout << cs->data << ", " << std::endl;
            }
            else
            {
                std::cout << cs->data << "\n" << std::endl;
            }
            cs = cs->next;
        }
        std::cout << "*** Son " << conexionesSalientes << " conexiones salientes. ***" << std::endl;
    }

    void conexionesRepetidas()
    {
        if (conexiones_Salientes != 0 && conexionesSalientes >= 3)
        {
            Nodo<string> *cs = conexiones_Salientes;
            int counter = 0;
            while (cs->next->next)
            {
                if (cs->data == cs->next->data && cs->next->data == cs->next->next->data)
                {
                    counter++;
                }
                cs = cs->next;    
            }
            if (counter == 0)
            {
                std::cout << "--- No son más de 3 conexiones salientes a una página web. ---" << std::endl;
            }
            else
            {
                std::cout << "--- Son " << counter << " conexiones salientes que se repiten por lo menos 3 veces. ---" << std::endl;
            } 
        }
        else
        {
            std::cout << "+++ No hay más de 3 conexiones salientes desde esta computadora. +++" << std::endl;
        }   
    }
};



int main()
{
    Datos d;
    d.leerDatos("/Users/andydiego13/Downloads/copianuevo9.csv");
    std::cout << "datosleidos" << std::endl;
    d.imprimir();

    string nIp = "172.18.243";  //ip interna
    string crearIp;
    std::cout << "^^^ Ingresa un número entre 1 y 150 para generar una IP: ^^^" << std::endl;
    cin >> crearIp;
    string resultado = nIp + "." + crearIp;
    cout << "La IP generada es: " << endl;
    cout << resultado << endl;

    ConexionesComputadora ri("brian.reto.com", "193");
    ri.conexionesComputadorasEntrantes();
    ri.imprimirCE();
    std::cout << "****************************" << std::endl;
    ri.conexionesComputadorasSalientes();
    ri.imprimirCS();
    std::cout << "****************************" << std::endl;
    ri.conexionesRepetidas();
    return 0;
}