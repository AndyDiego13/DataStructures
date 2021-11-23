#include <iostream>
#include <map>
#include "Libro.hpp"

//esto es para el reto
std::map< std::string, int> conexionesPorDia(std::string fecha)
{
    //Creamos el mapa
    std::map< std::string, int> conexiones;

    //procesamiento

    //Se regresa el mapa
    return conexiones;
}

int main(int argc, char const *argv[])
{
    // Creamos un mapa de personas
    std::map< int, std::string> personas;

    // Creamos un stl para cada persona que queramos tener
    std::pair< int, std::string> p1(1,"Maria");
    // Las insertamos en el mapa
    personas.insert(p1);

    std::pair< int, std::string> p2(10,"Camila");
    personas.insert(p2);

    personas[3] = "Raúl";

    for ( auto elem : personas)
    {
        std::cout << "Key: " << elem.first << ", Value: " << elem.second << std::endl;
    }

    std::cout << "=== Busca un valor ===" << std::endl;

    // buscamos una persona creando un mapa iterador
    std::map< int, std::string>::iterator it;
    it = personas.find(20);

    if (it == personas.end())
    {
        std::cout << "La persona buscada no se encontró" << std::endl;
    }
    else
    {
        std::cout << "La persona buscada es: " << it->second << std::endl;
    }

    std::cout << "=== Mapa de Libros ===" << std::endl;

    // Creamos un mapa de libros
    std::map< std::string, Libro> libros;

    // Le asignamos la key y el contenido con el constructor de libros
    libros["5"] = Libro("5", "El señor de los anillos", 700);
    libros["2"] = Libro("2", "El capital", 550);
    libros["3"] = Libro("3", "El arte de la guerra", 345);

    for( auto elem : libros)
    {
        std::cout << "ISBN: " << elem.first << ", Libro: " << elem.second << std::endl;
    } 

    std::cout << "=== Buscar un valor ===" << std::endl;

    // Creamos un segundo iterador para ahora encontrar los libros
    std::map< std::string, Libro>::iterator it2;

    it2 = libros.find("3");

    if (it2 == libros.end())
    {
        std::cout << "El libro no se encontró" << std::endl;
    }
    else
    {
        std::cout << "El libro es: " << it2->second << std::endl;
    }

    /* Mapa con una estructura lineal */
    // std::map< std::string, std::vector<Libro>> combinado;

    //Para el reto
    std::map< std::string, int> m = conexionesPorDia("10-11-2021");

    return 0;
}
