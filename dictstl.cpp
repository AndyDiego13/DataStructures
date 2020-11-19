#include <iostream>
#include <unordered_map>

using namespace std;

class Estudiante{
	public:
	string nombre;
	int matricula;
	
	Estudiante(){
		nombre="";
		matricula=0;
	}
	
	Estudiante(string n, int m){
		nombre=n;
		matricula=m;
	}
	
	bool operator==(const Estudiante& otro) const{
		if(this->matricula==otro.matricula){
			return true;
		}
		return false;
	}
	
	
};

struct HashEstudiante{
	size_t operator()(const Estudiante& e) const{
		return hash<int>()(e.matricula);
	}
};


int main(){
	unordered_map<string, Estudiante> escuela;
	escuela.insert({"juan", Estudiante("juan", 14214)});
	escuela["juan"].matricula=14215;
	cout<<escuela["juan"].matricula<<endl;
	Estudiante a1("juan", 12412);
	Estudiante a2("mercedes", 1231);
	unordered_map<Estudiante, int, HashEstudiante> clase;
	clase.insert({a1, 100}); 
	
	
	/*unordered_map<string, int> cal;
                    llave, valor
    MAPAS DESORDENADOS funciones predeterminadas
	forma 1 cal.insert(pair<string, int>("juan", 95)); mucho texto
	sin una clase cal.insert({"ana", 90});
	como los dic en python cal["jose"]=93;
	//auto es pair<string,int> en un par no quiere decir que el primero sea un llave y el segundo el valor puede variar
	/*for(auto elemento: cal){
		cout<<elemento.first<<":"<<elemento.second<<endl;
	}
	//auto es unodered_map<string, int>::iterator es un interador de ese tipo de diccionario
    //la i es como si fuera un apuntador
	for(auto i=cal.begin(); i!=cal.end(); i++){
        //son las dos formas
		cout<<(*i).first<<":"<<i->second<<endl;
	}
	auto pos=cal.find("joe");
	if(pos!=cal.end()){
		cout<<"El valor de la llave es "<<pos->second<<endl;
	}else{
		cout<<"No se encontro un valor con esa llave"<<endl;
	}*/
	return 0;
}