#include <iostream>

template <class T>
class NodoRB;
template <class T>
std::ostream& operator<<(std::ostream&, NodoRB<T>&);

template <class T>
class NodoRB {
  T info;
  NodoRB<T> * derecho;
  NodoRB<T> * izquierdo;
  NodoRB<T> * padre;
  std::string color;
  
public:
  NodoRB();
  NodoRB(T info);
  ~NodoRB();
  
  T getInfo();
  void setInfo(T value);
  
  NodoRB<T> * getDerecho();
  void setDerecho(NodoRB<T> * value);
  
  NodoRB<T> * getIzquierdo();
  void setIzquierdo(NodoRB<T> * value);
  
  NodoRB<T> * getPadre();
  void setPadre(NodoRB<T> * value);
  
  void setColor(std::string color);
  std::string getColor();
  
  friend std::ostream& operator<< <>(std::ostream&, NodoRB<T>&);
};

template <class T>
NodoRB<T>::NodoRB() {
  this->izquierdo = this->derecho = this->padre = nullptr;
}

template <class T>
NodoRB<T>::NodoRB(T info) : info(info) {
  this->derecho = this->izquierdo = this->padre = nullptr;
}

template <class T>
NodoRB<T>::~NodoRB() {
  izquierdo = derecho = padre = nullptr;
}

template <class T>
T NodoRB<T>::getInfo() {
  return info;
}

template <class T>
void NodoRB<T>::setInfo(T value) {
  info = value;
}

template <class T>
NodoRB<T> * NodoRB<T>::getDerecho() {
  return derecho;
}

template <class T>
void NodoRB<T>::setDerecho(NodoRB<T> * value) {
  derecho = value;
}

template <class T>
NodoRB<T> * NodoRB<T>::getIzquierdo() {
  return izquierdo;
}

template <class T>
void NodoRB<T>::setIzquierdo(NodoRB<T> * value) {
  izquierdo = value;
}

template <class T>
NodoRB<T> * NodoRB<T>::getPadre() {
  return padre;
}

template <class T>
void NodoRB<T>::setPadre(NodoRB<T> * value) {
  padre = value;
}

template <class T>
std::ostream& operator <<(std::ostream& os, NodoRB<T>& NodoRB) {
  os << NodoRB.info;
  return os;
}

template <class T>
void NodoRB<T>::setColor(std::string color)
{
  this->color = color;
}

template <class T>
std::string NodoRB<T>::getColor()
{
  return color;
}



