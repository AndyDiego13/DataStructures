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
        vector<string> valores;

    }
};



int main()
{
    //leerDatos("/iCloudDrive/Escritorio/RETO_PARTE_2/RETO2/nuevo9.csv");
    unordered_map<string, ConexionesComputadora> cc;

    /*
    for(Record r: conexiones)
    {
        if (r.ipFuente != "-")
        {
            if (cc.find(r.ipFuente)==cc.end())
            {
                ConexionesComputadora cc(r.ipFuente, r.nombreFuente);
                cc[r.ipFuente] = CC;
            }
            cc[r.ipFuente].nuevaSaliente(r.puertoDestino, r.ipDestino, r.nombreDestino); 
        } 
    }
    */
   /*
   for(Record r: conexiones)
   {
       if (r.ipFuente != "-")
       {
           if (cc.find(r.ipFuente) == cc.end())
           {
               //ConexionesComputadora a(r.ipFuente,r.nombreFuente);
               //cc[r.ipFuente] = a;
           } 
       }
   }*/
    
    vector<Record> r;
    /*
    string nIp = "172.18.243";  //ip interna
    string crearIp;
    cout << "Inserta un número entre 1 y 150 para generar una IP: " << endl;
    cin >> crearIp;
    string resultado = nIp + "." + crearIp;
    cout << "La IP generada es: " << endl;
    cout << resultado << endl;
    */
    
    return 0;
}