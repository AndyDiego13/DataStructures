#ifndef Libro_hpp
#define Libro_hpp

#include <iostream>

class Libro {

    std::string isbn;
    std::string titulo;
    int paginas;
    
public:
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
};


#endif /* Libro_hpp */