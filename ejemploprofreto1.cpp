#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
class Record
{
    //dejamos todo public para no tener que usar getters y setters
	public:
	string fecha;
	string hora;
	string nombreFuente;
	string nombreDestino;
	
	Record(string f, string h, string nF, string nD)
    {
		fecha=f;
		hora=h;
		nombreFuente=nF;
		nombreDestino=nD;
	}
	
	void imprimirRecord()
    {
		cout<<nombreFuente<<endl;
	}
};

vector<Record> conexiones;
void leerDatos(string path)
{
    //input file stream / flujo de archivo de entrada
	ifstream fileIn;
	fileIn.open(path);
	string line, partes;
    //guardar lo que esta leyendo partes elemento por elemento
	vector<string> valores;
    // antes fileIn.good() leera todo hasta que se encuentre un EOF(char end of file)
	while(getline(fileIn, line))//getline(flujo, donde guardar, '/n ó , ó /r')
    {
        //antes getline(fileIn(descriptor de archivo), line)
		istringstream sIn(line);//separador de comas
		while(getline(sIn, partes, ','))
        {
			valores.push_back(partes);
		}
        //como los datos son generados en windows y windows usa /r/n ponemos este if 
		if(valores[7].find('\r')!=valores[7].npos)
        {
			valores[7]=valores[7].substr(0, valores[7].size()-1);
		}
		Record r(valores[0], valores[1], valores[4], valores[7]);
		conexiones.push_back(r);
        //despejar memoria
		valores.clear();
	}
}

//estas funciones son para decirle a mergesort como va a comparar los datos
//el orden es lexico grafico estandar de mergesort
int compararPorNombreFuente(Record a, Record b)
{
	if(a.nombreFuente<b.nombreFuente)
    {
		return -1;
	}
    else if (a.nombreFuente==b.nombreFuente)
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
	if(a.nombreDestino<b.nombreDestino){
		return -1;
	}else if (a.nombreDestino==b.nombreDestino){
		return 0;
	}else{
		return 1;
	}
}



template <class T>
class Sort{
	public:
	virtual void sort(vector<T> &data, int comparador(T a, T b))=0;
	void intercambiar(vector<T> &data, int posI, int posJ){
		T temp=data[posI];
		data[posI]=data[posJ];
		data[posJ]=temp;
	}
	
	void imprimir(vector<T> data){
		for(int i=0; i<data.size(); i++){
			cout<<data[i]<<",";
		}
		cout<<endl;
	}
};


template <class T>
class MergeSort: public Sort<T>{
	
	public:
	void sort(vector<T> &data, int comparador(T a, T b)){
		sortAux(data, 0, data.size()-1, comparador);
	}
	private:
	void sortAux(vector<T> &data, int lo, int hi, int comparador(T a, T b)){
		if(lo>=hi){
			return;
		}
		int mid=(lo+hi)/2;
		sortAux(data, lo, mid, comparador);
		sortAux(data, mid+1, hi, comparador);
		merge(data, lo, mid, hi, comparador);
	}
	
	
	
	void merge(vector<T> &data, int low, int mid, int hi, int comparador(T a, T b)){
	int sizeA=mid-low+1;
	int sizeB=hi-mid;
	vector<T> copiaA;
	vector<T> copiaB;
	
	for(int i=0; i<sizeA; i++){
		copiaA.push_back(data[low+i]);
	}
	
	for(int i=0; i<sizeB; i++){
		copiaB.push_back(data[mid+i+1]);
	}
	
	int indexA=0;
	int indexB=0;
	int indexData=low;
	while(indexA<sizeA&&indexB<sizeB){
		//if(copiaA[indexA]<copiaB[indexB]){ //asi estaba originalmente y en la nueva ya ingresamos el comparador con los valores T
		if(comparador(copiaA[indexA],copiaB[indexB])<0){
			data[indexData]=copiaA[indexA];
			indexA++;
		}else{
			data[indexData]=copiaB[indexB];
			indexB++;
		}
		indexData++;
	}
	
	while(indexA<sizeA){
		data[indexData]=copiaA[indexA];
		indexA++;
		indexData++;
	}
	
	while(indexB<sizeB){
		data[indexData]=copiaB[indexB];
		indexB++;
		indexData++;
	}
}
	
};

int compararPorNombreDestino2(Record a, string b){
	if(a.nombreDestino<b){
		return -1;
	}else if (a.nombreDestino==b){
		return 0;
	}else{
		return 1;
	}
}


template <class T, class M>
int busquedaBinaria2(vector<T> a, M buscado, int comparador(T a, M b)){
	int inicio=0;
	int fin=a.size()-1;
	while(fin>=inicio){
		int medio=(inicio+fin)/2;
		if(comparador(a[medio],buscado)==0){
			return medio;
		}else if(comparador(a[medio], buscado)<0){
			inicio=medio+1;
		}else{
			fin=medio-1;
		}
	}
	return -1;
}

template <class T>
int busquedaBinaria(vector<T> a, T buscado, int comparador(T a, T b)){
	int inicio=0;
	int fin=a.size()-1;
	while(fin>=inicio){
		int medio=(inicio+fin)/2;
		if(comparador(a[medio],buscado)==0){
			return medio;
		}else if(comparador(buscado,a[medio])>0){
			inicio=medio+1;
		}else{
			fin=medio-1;
		}
	}
	return -1;
}

int main(){
	//leerDatos("/mnt/c/Users/L03040561/Desktop/equipo0.csv");
	cout<<"Datos leidos"<<endl;
	MergeSort<Record> s;
    //podemos mandarle los comparadores que necesitemos
	s.sort(conexiones, compararPorNombreDestino);
	cout<<"Datos ordenados"<<endl;
    //el record es para busqueda binaria 1
	Record r("", "", "", "google.com");
    //los string "a" son para busqueda binaria 2
	string a="google.com";
	int pos=busquedaBinaria2(conexiones, a, compararPorNombreDestino2);
	if(pos!=-1){
		cout<<"encontrado"<<endl;
	}
	/*for (int i=0; i<conexiones.size(); i++){
		conexiones[i].imprimirRecord();
	}*/
	return 0;
}