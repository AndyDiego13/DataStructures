#ifndef Libro_hpp
#define Libro_hpp

#include <iostream>

class Libro
{

    std::string isbn;
    std::string titulo;
    int paginas;
    
    public:

        class Persona
        {
            public:

                int key;
                std::string name;
                
                Persona(int _key, std::string _name): 
                key(_key), name(_name)
                {

                }
        }
        Libro()
        {
            Libro("sin definir", "sin definir", 0);
        }
    
        Libro(std::string _isbn, std::string _titulo, int _pags) :
        titulo(_titulo), isbn(_isbn), paginas(_pags)
        {
        
        }
    
        ~Libro() {}
    
        friend std::ostream & operator<<(std::ostream &os, const Libro &libro)
        {
            os << libro.isbn << "-" << libro.titulo << "(" << libro.paginas << ")" << std::endl;

            return os;
        }

        friend std::ostream & operator = (std::ostream &os2, const int &key, const std::string &name, const std::string &isbn, const std::vector<Libro> &libro)
        {
            os = 
        }
};


#endif /* Libro_hpp */