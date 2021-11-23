#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <vector>

int main()
{
    std::map<int, std::vector<std::string>> calificaciones;

    calificaciones[100].push_back("Lorena");
    calificaciones[90].push_back("Yahir");
    calificaciones[75].push_back("Juan");
    calificaciones[100].push_back("Karla");

    for ( auto it = calificaciones.rbegin(); it != calificaciones.rend(); it++)
    {
        std::cout << it->first << ":" <<std::endl;

        for ( std::string persona:calificaciones[it->first])
        {
            std::cout << persona << "," << std::endl;
        }
        std::cout << std::endl;
    }
    
    return 0;
}