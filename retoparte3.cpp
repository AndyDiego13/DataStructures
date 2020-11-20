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
#include <unordered_set>

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

    vector<string> fuenteEntrantes;
    vector<string> fuenteSaliente;
    vector<string> ipEntrantes;
    vector<string> ipSalientes;

    void nuevaEntrante(string ip, string fuente)
    {
        fuenteEntrantes.push_back(fuente);
        ipEntrantes.push_back(ip);
    }

    void nuevaSaliente(string ip, string fuente)
    {
        fuenteSaliente.push_back(fuente);
        ipSalientes.push_back(ip);
    }

    void entrantes()
    {
        if (fuenteEntrantes.size() > 0)
        {
            for (int i = 0; i < fuenteEntrantes.size(); i++)
            {
                if (i < fuenteEntrantes.size() - 1)
                {
                    std::cout << fuenteEntrantes[i] << "," << std::endl;
                }
                else
                {
                    std::cout << fuenteEntrantes[i] << std::endl;
                }   
            }
        }
        else
        {
            std::cout << "NO HAY CONEXIONES ENTRANTES" << std::endl;
        }  
    }

    void salientes()
    {
        if (fuenteSaliente.size() > 0)
        {
            for (int i = 0; i < fuenteSaliente.size(); i++)
            {
                if (i < fuenteSaliente.size() - 1)
                {
                    std::cout << fuenteSaliente[i] << ", " << std::endl;
                }
                else
                {
                    std::cout << fuenteSaliente[i] << std::endl;
                }   
            }
        }
        else
        {
            std::cout << "NO HAY CONEXIONES SALIENTES" << std::endl;
        }  
    }

    void ipsEntrantes()
    {
        if (ipEntrantes.size() > 0)
        {
            for (int i = 0; i < ipEntrantes.size(); i++)
            {
                if (i < ipEntrantes.size() - 1)
                {
                    std::cout << ipEntrantes[i] << ", " << std::endl;
                }
                else
                {
                    std::cout << ipEntrantes[i] << std::endl;
                }
            } 
        }
        else
        {
            std::cout << "NO HAY CONEXIONES SALIENTES" << std::endl;
        } 
    }

    void ipsSalientes()
    {
        if (ipSalientes.size() > 0)
        {
            for (int i = 0; i < ipSalientes.size(); i++)
            {
                if (i < ipSalientes.size() - 1)
                {
                    std::cout << ipSalientes[i] << ", " << std::endl;
                }
                else
                {
                    std::cout << ipSalientes[i] << std::endl;
                }   
            }
        }
        else
        {
            std::cout << "NO HAY CONEXIONES SALIENTES" << std::endl;
        }  
    }

};

template <class K, class V>
class Pair
{
	public:
	K key;
	V value;
    //constructor vacio
	Pair()
    {
		key=NULL;
		value=NULL;
	}
	//constructor parametros
	Pair(K k, V v)
    {
		key=k;
		value=v;
	}
};

template <class K, class V>
class Dictionary{
	public:
	list< Pair<K,V> > *data;
	int size;
	
	Dictionary(){
		size=100;
		data= new list< Pair<K,V> >[size];
	}
	
	Dictionary(int s){
		size=s;
		data= new list< Pair<K,V> >[size];
	}
	
	void insert(K key, V value){
		int pos=key%size;
		//for(Pair<K,V> elemento: data[pos])
		for(auto i=data[pos].begin(); i!=data[pos].end(); i++){
			if(i->key==key){
				i->value=value;
				return;
			}	
		}
		Pair<K,V> nuevo(key, value);
		data[pos].push_back(nuevo);
		return;
	}	
	
	
	void insert(K key, V value, int hash(K llave)){
		int pos=hash(key)%size;
		//cout<<pos<<endl;
		//for(Pair<K,V> elemento: data[pos])
		for(auto i=data[pos].begin(); i!=data[pos].end(); i++){
			if(i->key==key){
				i->value=value;
				return;
			}	
		}
		Pair<K,V> nuevo(key, value);
		data[pos].push_back(nuevo);
		return;
	}
	
	bool buscar(K key){
		int pos=key%size;
		for(Pair<K,V> elemento: data[pos]){
			if(elemento.key==key){
				return true;
			}
		}
		return false;
	}

	void print(){
		for(int i=0; i<size; i++){
			for(Pair<K,V> elemento:data[i]){
				cout<<elemento.key<<":"<<elemento.value<<endl;
			}
		}
	}
};


int hashString(string key)
{
	return key.length();
}



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

    ConexionesComputadora conexcom;
    Dictionary<string, ConexionesComputadora> diccc;
    diccc.print();

    return 0;
}
