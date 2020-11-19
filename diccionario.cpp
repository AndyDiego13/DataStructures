#include <iostream>
#include <list>

using namespace std;

//Key y el otro pa el valor
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
class Dictionary
{
	public:
	list< Pair<K,V> > *data;
	int size;
    
    //se va inicializar
	Dictionary()
    {
		size=100;
		data= new list< Pair<K,V> >[size];
	}
	
	Dictionary(int s)
    {
		size=s;

        //arreglo de listas
		data= new list< Pair<K,V> >[size];
	}
	
	void insert(K key, V value)
    {
        //hash
		int pos=key%size;
        //iterar para saber que ese valor aun no exista en el diccionario
		//for(Pair<K,V> elemento: data[pos])
        /*
        for(Pair<K,V> elemento: data[pos])
        {
            //insertamos o la sobre escribimosk
            if(elemento.key == key)
            {
                //sobrescribir
                elemento.value = value;
                //no sobre escribir se queda el return solo
                return;
            }
        }
        //si no encontramos esa llave
        Pair<K,V> nuevo(key, value);
        data[pos].push_back(nuevo);
        return;
        //se agrega al final
        
        NO SE PUEDEN MODIFICAR LOS ITERADORES LO QUE SE REGRESA SOLO ES UN COPIA POR ESO NO SE GUARDABA
        */
       //i = interador
		for(auto i=data[pos].begin(); i!=data[pos].end(); i++)
        {
			if(i->key==key)
            {
				i->value=value;
				return;
			}	
		}
		Pair<K,V> nuevo(key, value);
		data[pos].push_back(nuevo);
		return;
	}	
	
	
	void insert(K key, V value, int hash(K llave))
    {
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

	void print()
    {
		for(int i=0; i<size; i++)
        {
			for(Pair<K,V> elemento:data[i])
            {
				cout<<elemento.key<<":"<<elemento.value<<endl;
			}
		}
	}
};


int hashString(string key){
	return key.length();
}

int main(){
	Dictionary<int, string> d;
	d.insert(300, "a");
	d.insert(400, "b");
	d.insert(400, "a");
	d.insert(15623, "c");
	Dictionary<string, int> calificaciones;
	calificaciones.insert("Juan", 95, hashString);
	calificaciones.print();
	
	return 0;
}