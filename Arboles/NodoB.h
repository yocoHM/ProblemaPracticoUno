#include <iostream>

template <class T>
class NodoB {
protected:
  NodoB<T> * padre = nullptr;
  NodoB<T> * izquierdo = nullptr;
  NodoB<T> * derecho = nullptr;
  
  T info;
  
public:

  NodoB() { }
  NodoB(const T & _info) : info (_info) { }
  NodoB(const NodoB<T> & );
  
  virtual ~NodoB();
  
  T getInfo() const {
    return info;
  }
  
  void setInfo(const T & value) {
    info = value;
  }
  
  NodoB<T> * getIzquierdo() const {
    return izquierdo;
  }
  
  void setLeft(NodoB<T> * value) {
    izquierdo = value;
  }
  
  NodoB<T> * getDerecho() const {
    return derecho;
  }
  
  void setRight(NodoB<T> * value) {
    derecho = value;
  }
  
  NodoB<T> * getParent() const {
    return padre;
  }
  
  void setParent(NodoB<T> * value) {
    padre = value;
  }
  
  template <typename Tn>
  friend std::ostream & operator << (std::ostream & os, const NodoB<Tn>  & nodo);
};

template <class T>
NodoB<T>::NodoB(const NodoB<T> & nodo)
{
  info = nodo.info;
  izquierdo = nodo.izquierdo;
  derecho = nodo.derecho;
  padre = nodo.padre;
}

template <class T>
NodoB<T>::~NodoB()
{
  info.~T();
  izquierdo = derecho = padre = nullptr;
}


template <class T>
std::ostream & operator << (std::ostream & os, const NodoB<T>  & nodo)
{
  os << nodo.info;
  
  return os;
}