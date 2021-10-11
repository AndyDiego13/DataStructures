#include <iostream>
using namespace std;

template <class T>
class Nodo{
	public:
	T value;
	Nodo<T> *izq;
	Nodo<T> *der;
	
	Nodo(){
		value=NULL;
		izq=NULL;
		der=NULL;
	}
	
	Nodo(T val){
		value=val;
		izq=NULL;
		der=NULL;
	}
};

template <class T>
class BST{
	public:
	Nodo<T> *root;
	
	BST(){
		root=NULL;
	}
	
	void insertar(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		if(root==NULL){
			root=nuevo;
		}else{
			insertar(nuevo, root);
		}
	}
	
	void insertar(Nodo<T> *nuevo, Nodo<T> *temp){
		if(nuevo->value==temp->value){	//si el valor es igual, terminamos
			return;
		}else if(nuevo->value<temp->value){//si el valor es menor que el valor de temp
			if(temp->izq==NULL){//si el izquierdo es nulo, ahi agregamos
				temp->izq=nuevo;
			}else{
				insertar(nuevo, temp->izq);//sino, temp=temp->izq
			}
		}else{//si el valor es mayor que el valor de temp
			if(temp->der==NULL){	//si el derecho es nulo, ahi agregamos
				temp->der=nuevo;
			}else{
				insertar(nuevo, temp->der);//sino, temp=temp->der
			}
		}
	}
	
	void inorder(){
		inorder(root);
		cout<<endl;
	}

	
	void inorder(Nodo<T> *temp){
		if(temp!=NULL){
			inorder(temp->izq);
			cout<<temp->value<<" ";
			inorder(temp->der);
		}
	}
	
	
	Nodo<T> *buscarIterativo(T value){
		Nodo<T> *temp=root;
		while(temp!=NULL){
			if(temp->value==value){
				return temp;
			}else if(value<temp->value){
				temp=temp->izq;
			}else{
				temp=temp->der;
			}
		}
		return NULL;
	}
	
	bool buscarRecursivo(T value){
		if(root==NULL){
			return false;
		}else{
			return buscarRecursivo(value, root);
		}
	}
	
	bool buscarRecursivo(T value, Nodo<T> *temp){
		if(temp==NULL){
			return false;
		}else if(temp->value==value){
			return true;
		}else if(value<temp->value){
			return buscarRecursivo(value, temp->izq);
		}else{
			return buscarRecursivo(value, temp->der);
		}
	}
	
	void eliminar(T value){
		if(root==NULL){
			return;
		}else{
			root=eliminar(value, root);
		}
	}
	
	Nodo<T> *eliminar(T value, Nodo<T> *temp){
		if(temp==NULL){
			return NULL;
		}else if(value<temp->value){
			temp->izq=eliminar(value, temp->izq);
		}else if(value>temp->value){
			temp->der=eliminar(value, temp->der);
		}else{//Si el valor es igual
			if(temp->izq==NULL && temp->der==NULL){//el nodo es una hoja
				delete temp;
				return NULL;
			}else if(temp->izq!=NULL &&temp->der==NULL){//temp tiene hijo izquierdo pero no derecho
				Nodo<T> *regresar=temp->izq;
				delete temp;
				return regresar;
			}else if(temp->izq==NULL &&temp->der!=NULL){
				Nodo<T> *regresar=temp->der;
				delete temp;
				return regresar;
			}else{//el nodo a borrar tiene 2 hijos
				Nodo<T> *sucesor=temp->der;
				while(sucesor->izq!=NULL){
					sucesor=sucesor->izq;
				}
				temp->value=sucesor->value;
				temp->der=eliminar(temp->value, temp->der);
			}
		}
		return temp;
	}
	
	
	int profundidad(T value){
		Nodo<T> *temp=root;
		int prof=0;
		while(temp!=NULL){
			if(temp->value==value){
				return prof;
			}else if(value<temp->value){
				temp=temp->izq;
				prof++;
			}else{
				temp=temp->der;
				prof++;
			}
		}
		return -1;
	}
	
	
	int alturaArbol(){
		if(root!=NULL){
			return altura(root);
		}
		return -1;
	}

	int altura(Nodo<T> *temp){
		if(temp==NULL){
			return -1;
		}else if(temp->izq==NULL && temp->der==NULL){
			return 0;
		}else{
			int pIzq=altura(temp->izq);
			int pDer=altura(temp->der);
			if(pIzq>pDer){
				return pIzq+1;
			}else{
				return pDer+1;
			}
		}
	}
	
	void inorderNivel(int buscado){
		inorderNivel(root, 1, buscado);
		cout<<endl;
	}
	
	void inorderNivel(Nodo<T> *temp, int nivel, int nivelBuscado){
		if(temp!=NULL){
			inorderNivel(temp->izq, nivel+1, nivelBuscado);
			if(nivelBuscado==nivel){
				cout<<temp->value<<" ";
			}
			inorderNivel(temp->der, nivel+1, nivelBuscado);
		}
	}

};

int main(){
	BST<int> tree;
	tree.insertar(50);
	tree.insertar(20);
	tree.insertar(70);
	tree.insertar(10);
	tree.insertar(30);
	tree.insertar(60);
	tree.insertar(80);
	//tree.inorder();
	//cout<<tree.profundidadArbol()<<endl;
	tree.inorderNivel(2);
	return 0;
}