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

using namespace std;

class Record
{
    public:

    string fecha;
    string hora;
    string nombreFuente;
    string nombreDestino;

    Record(string f, string h, string nF, string nD) //constructor 
    {
        fecha = f;
        hora = h;
        nombreFuente = nF;
        nombreDestino = nD;
    }

    void imprimirDatos()
    {
        cout << fecha << endl;
    }
};


vector<Record>conexiones;

void leerDatos(string path)//funcion aparte 
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

template <class T>
class Nodo
{
    public:
    T value;
    Nodo<T> *next;
    Nodo<T> *prev;

    Nodo<T>(T val, Nodo<T> *n, Nodo<T> *p)
    {
        value = val;
        next = n;
        prev = p;
    };

    T getVal()
    {
        return value;
    };

    void setVal(T val)
    {
        value = val;
    };

    Nodo<T> *getNext()
    {
        return next;
    };

    void setNext(Nodo<T> *n)
    {
        next = n;
    };

    Nodo<T> *getPrev()
    {
        return prev;
    };

    void setPrev(Nodo<T> *p)
    {
        prev = p;
    };
};

template <class T>
class conexionesComputadora
{
    public:
    Nodo<T> *head;
    Nodo<T> *tail;

    conexionesComputadora()
    {
        head = NULL;
        tail = head;
    }

    int lengthH()
    {
        int length = 0;
        Nodo<T> *n = next;

        while (n != NULL)
        {
            length++;
            n = n ->getNext();
        }

        return length; 
    }

    int lengthT()
    {
        int length = 0;
        Nodo<T> *t = tail;

        while (t != NULL)
        {
            length++;
            t = t -> getNext();
        }

        return length;
    }

    void append(Nodo<T> *nuevo) //append
    {
        if(head==NULL)
        {
			head=nuevo;
			tail=nuevo;
		}
        else
        {
			tail->getNext()=nuevo;
			nuevo->getPrev()=tail;
			tail=nuevo;
		}
        
	}

    void push(T val)
    {
        Nodo<T> *nuevo=new Nodo<T>(val);
		append(nuevo);
	}

    void insert(Nodo<T> *nuevo, int pos) //NODO 
    {
		if(head==NULL)
        {
			head=nuevo;
			tail=nuevo;
		}
        else if(pos==0)
        {
			nuevo->getNext()=head;
			head->getPrev()=nuevo;
			head=nuevo;
		}
        else
        {
			Nodo<T> *h = head;
			int i = 0;
			while(h != NULL && i < pos)
            {
				h = h->getNext();
				i++;
			}
			if(h == NULL)
            {
				tail->getNext()=nuevo;
				nuevo->getPrev()=tail;
				tail=nuevo;
			}
            else
            {
				nuevo->getNext() = h;
				nuevo->getPrev() = h->setPrev();
				h->setPrev()->getNext()=nuevo;
				h->setPrev()=nuevo;
				
			}
		}
	}

    void duplicar()
    {
		Nodo<T> *h = head;
		while(h != NULL)
        {
			Nodo<T> *sig = h ->getNext();
			Nodo<T> *nuevo=new Nodo<T>(t ->getVal());
			nuevo->getNext() = sig;
			nuevo->getPrev() = h;
			h->getNext() = nuevo;
			if(sig != NULL)
            {
				sig->getPrev() = nuevo;
			}
            else
            {
				tail=nuevo;
			}
			h = sig;
		}
	}

    void remove(T value)
    {
		Nodo<T> *h = head;
		while(h != NULL)
        {
			if(h ->getVal() == value)
            {
				if(h->getPrev()==NULL)
                {
					head=h->getNext();
				}
                else
                {
					h->getPrev()->getNext() = h->setNext();
				}
				if(h->getNext() == NULL)
                {
					tail=h->getPrev();
				}
                else
                {
					h->getNext()->getPrev()=h->setPrev();
				}
				delete h;
				return;
			}
			h=h->getNext();
		}
		
	}

    void insert(T value, int pos) // T VALUE
    {
		Nodo<T> *nuevo=new Nodo<T>(value);
		insert(nuevo, pos);
	}

    void print()
    {
		Nodo<T> *r = root;
		while(r!=NULL)
        {
			std::cout << r -> getVal() << "," << std::endl;
			r = r->getNext();
		}	
		std::cout <<    << std::endl;
	}

};

