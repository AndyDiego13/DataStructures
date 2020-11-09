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
    //int i = 0;
    //int j = 0;

    /* constructor sin parametros
    ConexionesComputadora()
    {
        ip;
        nombre = name

    }
    */

    ConexionesComputadora(string iP, string name)
    {
        ip = iP;
        nombre = name;
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
    leerDatos("/iCloudDrive/Escritorio/RETO_PARTE_2/RETO2/nuevo9.csv");
    unordered_map<string, ConexionesComputadora> cc;


    for(Record r: conexiones)
    {
        if (r.ipFuente != "-")
        {
            if (cc.find(r.ipFuente)==cc.end())
            {
                ConexionesComputadora CC(r.ipFuente, r.nombreFuente);
                cc[r.ipFuente] = CC;
            }
            cc[r.ipFuente].nuevaSaliente(r.puertoDestino, r.ipDestino, r.nombreDestino); 
        } 
    }
    
    vector<Record> r;

    string nIp = "172.18.243";  //ip interna
    string crearIp;
    cout << "Inserta un número entre 1 y 150 para generar una IP: " << endl;
    cin >> crearIp;
    string resultado = nIp + "." + crearIp;
    cout << "La IP generada es: " << endl;
    cout << resultado << endl;

    string name;
    list<InfoConexiones> inicio;
    list<InfoConexiones> final;

    //ConexionesComputadora concomp;
    //concomp.imprimirCc();
    
    return 0;
}