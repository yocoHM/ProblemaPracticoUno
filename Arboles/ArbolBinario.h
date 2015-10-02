#include <iostream>
#include "NodoRB.h"

template <class T>
class ArbolBinario
{
  NodoRB<T> * raiz = nullptr;
  
  std::ostream& imprime(std::ostream& os, NodoRB<T> * nodo);
  
public:
  ArbolBinario();
  ArbolBinario(NodoRB<T> * info);
  
  ~ArbolBinario();
  void clear();
  void clear(NodoRB<T> * nodo);
  
  bool empty();
  NodoRB<T> * getRaiz();
  void setRaiz(NodoRB<T> * nodo)
  {
    raiz = nodo;
  }
  bool insert(T value, NodoRB<T> * padre);
  
  void preOrden();
  void preOrden(NodoRB<T> * nodo);
  void preOrden(NodoRB<T> * nodo, T info);
  
  void inOrden();
  void inOrden(NodoRB<T> * nodo);
  
  void revOrden();
  void revOrden(NodoRB<T> * nodo);
  
  void postOrden();
  void postOrden(NodoRB<T> * nodo);
  
  template <typename Tn>
  friend std::ostream& operator<<(std::ostream& os, ArbolBinario<Tn> &arbol);
  
  int nivel(NodoRB<T> * nodo);
  
  NodoRB<T> * suma_ineficiente();
  NodoRB<T> * suma_ineficiente(NodoRB<T> * nodo);
  T suma();
  T suma_eficiente(NodoRB<T> * nodo);
  void suma_eficiente(NodoRB<T> * nodo, NodoRB<T> * acumulador);
  T suma(NodoRB<T> * nodo);
  
  NodoRB<T> * getPadre(T info);
  void hermanos(NodoRB<T> * n1);
  bool sonHermanos(T n1, T n2);
  bool sonHermanos(NodoRB<T> * n1, NodoRB<T> * n2);
  
  void primosHermanos(NodoRB<T> * nodo, NodoRB<T> * raiz);
  void ancestros(NodoRB<T> *nodo);
  
  NodoRB<T> * buscar (T info);
  NodoRB<T> * buscar (T info, NodoRB<T> * nodo);
};

template <class T>
ArbolBinario<T>::ArbolBinario() { }

template <class T>
ArbolBinario<T>::ArbolBinario(NodoRB<T> * info) {
  raiz = info;
}

template <class T>
ArbolBinario<T>::~ArbolBinario() {
  clear(raiz);
}

template <class T>
void ArbolBinario<T>::clear() {
  clear(raiz);
}

template <class T>
void ArbolBinario<T>::clear(NodoRB<T> * nodo) {
  if (nodo) {
    clear(nodo->getIzquierdo());
    clear(nodo->getDerecho());
    
    delete nodo;
  }
}

template <class T>
bool ArbolBinario<T>::empty() {
  return (raiz == nullptr);
}

template <class T>
NodoRB<T> * ArbolBinario<T>::getRaiz() {
  return raiz;
}

template <class T>
bool ArbolBinario<T>::insert(T value, NodoRB<T> * padre) {
  // Insertar la raiz
  if (!padre)
    raiz = new NodoRB<T>(value);
  else {
    if (!padre->getIzquierdo()) {
      NodoRB<T> * nuevo = new NodoRB<T>(value);
      nuevo->setPadre(padre);
      padre->setIzquierdo(nuevo);
    }
    else if (!padre->getDerecho()) {
      NodoRB<T> * nuevo = new NodoRB<T>(value);
      nuevo->setPadre(padre);
      padre->setDerecho(nuevo);
    }
    else
      return false;
  }
  return true;
}

template <class T>
void ArbolBinario<T>::preOrden() {
  preOrden(raiz);
}
//this used to be
template <class T>
void ArbolBinario<T>::preOrden(NodoRB<T> * nodo) {
  if (nodo) {
    std::cout << *nodo << std::endl;
    preOrden(nodo->getIzquierdo());
    preOrden(nodo->getDerecho());
  }
}

template <class T>
void ArbolBinario<T>::preOrden(NodoRB<T> * nodo, T info) {
  if (nodo) {
    if (!(nodo->getInfo() == info))
      std::cout << *nodo->getInfo() << std::endl;
    preOrden(nodo->getIzquierdo());
    preOrden(nodo->getDerecho());
  }
}

template <class T>
void ArbolBinario<T>::inOrden() {
  inOrden(raiz);
}

template <class T>
void ArbolBinario<T>::inOrden(NodoRB<T> * nodo) {
  if (nodo) {
    inOrden(nodo->getIzquierdo());
    std::cout << *nodo << " ";
    inOrden(nodo->getDerecho());
  }
}

template <class T>
void ArbolBinario<T>::revOrden() {
  revOrden(raiz);
}

template <class T>
void ArbolBinario<T>::revOrden(NodoRB<T> * nodo) {
  if (nodo) {
    revOrden(nodo->getDerecho());
    std::cout << *nodo << " ";
    revOrden(nodo->getIzquierdo());
  }
}
template <class T>
void ArbolBinario<T>::postOrden() {
  postOrden(raiz);
}

template <class T>
void ArbolBinario<T>::postOrden(NodoRB<T> * nodo) {
  if (nodo) {
    postOrden(nodo->getIzquierdo());
    postOrden(nodo->getDerecho());
    std::cout << *nodo << " ";
  }
}

template <class T>
int ArbolBinario<T>::nivel(NodoRB<T> *nodo) {
  if (nodo == nullptr)
    return 0;
  
  NodoRB<T> * aux = nodo;
  int nivel = 1;
  while (aux->getPadre()) {
    ++nivel;
    aux = aux->getPadre();
  }
  return nivel;
}


template <class T>
NodoRB<T> * ArbolBinario<T>::buscar(T info)
{
  return buscar(info, raiz);
}

template <class T>
NodoRB<T> * ArbolBinario<T>::buscar(T info, NodoRB<T> * node)
{
  if (node == nullptr)
  {
    return nullptr;
  }
  else
  {
    if (info == node->getInfo())
    {
      return node;
    }
    else if (info < node->getInfo())
    {
      return buscar(info, node->getIzquierdo());
    }
    else {
      return buscar(info, node->getDerecho());
    }
  }
}

template <class T>
NodoRB<T> * ArbolBinario<T>::getPadre(T info) {
  NodoRB<T> * nodo = buscar(info);
  return nodo->getPadre();
}

template <class T>
void ArbolBinario<T>::hermanos(NodoRB<T> * nodo) {
  NodoRB<T> * izquierdo = nodo->getPadre()->getIzquierdo();
  NodoRB<T> * derercho = nodo->getPadre()->getDerecho();
  if (izquierdo && izquierdo != nodo)
    std::cout << *izquierdo->getInfo();
  if (derercho && derercho != nodo)
    std::cout << *derercho->getInfo();
}

template <class T>
bool ArbolBinario<T>::sonHermanos(T n1, T n2) {
  return sonHermanos(buscar(n1), buscar(n2));
}

template <class T>
bool ArbolBinario<T>::sonHermanos(NodoRB<T> * n1, NodoRB<T> * n2) {
  if (n1 == nullptr || n2 == nullptr || n1 == n2)
    return false;
  return (n1->getPadre() == n2->getPadre());
}

template <class T>
void ArbolBinario<T>::primosHermanos(NodoRB<T> *nodo, NodoRB<T> *raiz) {
  if (raiz) {
    if (nivel(nodo) == nivel(raiz) && sonHermanos(nodo->getPadre(), raiz->getPadre())) {
      std::cout << *raiz->getInfo() << std::endl;
    }
    primosHermanos(nodo, raiz->getIzquierdo());
    primosHermanos(nodo, raiz->getDerecho());
  }
}

template <class T>
void ArbolBinario<T>::ancestros(NodoRB<T> *nodo) {
  NodoRB<T> * padre = nodo->getPadre();
  while (padre) {
    std::cout << *padre->getInfo() << std::endl;
    padre = padre->getPadre();
  }
}

template <class T>
NodoRB<T> * ArbolBinario<T>::suma_ineficiente() {
  return suma_ineficiente(raiz);
}

template <class T>
NodoRB<T> * ArbolBinario<T>::suma_ineficiente(NodoRB<T> * nodo) {
  T valor;
  if (nodo) {
    valor = nodo->getInfo();
    NodoRB<T> * suma_ineficiente_izq = suma_ineficiente(nodo->getIzquierdo());
    if (suma_ineficiente_izq) {
      valor += suma_ineficiente_izq->getInfo();
      delete suma_ineficiente_izq;
    }
    
    NodoRB<T> * suma_ineficiente_der = suma_ineficiente(nodo->getDerecho());
    if (suma_ineficiente_der) {
      valor += suma_ineficiente_der->getInfo();
      delete suma_ineficiente_der;
    }
    return new NodoRB<T>(valor);
  }
  return nullptr;
}

template <class T>
T ArbolBinario<T>::suma_eficiente(NodoRB<T> * nodo) {
  NodoRB<T> * acumulador = new NodoRB<T>(0);
  suma_eficiente(nodo, acumulador);
  T valor = acumulador->getInfo();
  delete acumulador;
  return valor;
}

template <class T>
void ArbolBinario<T>::suma_eficiente(NodoRB<T> * nodo, NodoRB<T> * acumulador) {
  if (nodo) {
    acumulador->setInfo(acumulador->getInfo() + nodo->getInfo());
    suma_eficiente(nodo->getIzquierdo(), acumulador);
    suma_eficiente(nodo->getDerecho(), acumulador);
  }
}

template <class T>
T ArbolBinario<T>::suma() {
  return suma(raiz);
}

template <class T>
T ArbolBinario<T>::suma(NodoRB<T> *nodo) {
  static T valor;
  if (nodo) {
    valor += nodo->getInfo();
    suma(nodo->getIzquierdo());
    suma(nodo->getDerecho());
  }
  return valor;
}

template <class T>
std::ostream& ArbolBinario<T>::imprime(std::ostream& os, NodoRB<T> * nodo) {
  if (nodo) {
    os << *nodo;
    imprime(os, nodo->getIzquierdo());
    imprime(os, nodo->getDerecho());
  }
  return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, ArbolBinario<T> &arbol) {
  return arbol.imprime(os, arbol.raiz);
}
