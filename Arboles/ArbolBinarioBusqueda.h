#include <iostream>
#include "ArbolBinario.h"

template<class T>
class ArbolBinarioBusqueda : public ArbolBinario<T>
{
public:
  ArbolBinarioBusqueda();
  virtual NodoRB<T>* insertar(T valor);
  NodoRB<T> * removeNodo(NodoRB<T> * nodo, T valor);
  
  NodoRB<T> * minNodo(NodoRB<T> * nodo)
  {
    NodoRB<T> * actual = nodo;
    
    while (actual->getIzquierdo() != nullptr)
      actual = actual->getIzquierdo();
    
    return actual;
  }
  
  void print();
};

template<class T>
ArbolBinarioBusqueda<T>::ArbolBinarioBusqueda() : ArbolBinario<T>()
{
  
}

template<class T>
NodoRB<T>* ArbolBinarioBusqueda<T>::insertar(T valor)
{
  NodoRB<T> * nodo = new NodoRB<T>(valor);
  NodoRB<T> * padre;
  
  nodo->setDerecho(nullptr);
  nodo->setIzquierdo(nullptr);
  
  padre = nodo->getPadre();
  
  if(this->empty())
  {
    this->setRaiz(nodo);
  }
  else
  {
    NodoRB<T> * actual = new NodoRB<T>();
    
    actual = this->getRaiz();
    
    while (actual)
    {
      padre = actual;
      
      if(nodo->getInfo() >= actual->getInfo())
      {
        actual = actual->getDerecho();
      }
      else
      {
        actual = actual->getIzquierdo();
      }
    }
    
    if(nodo->getInfo() >= padre->getInfo())
    {
      padre->setDerecho(nodo);
      nodo->setPadre(padre);
    }
    else
    {
      padre->setIzquierdo(nodo);
      nodo->setPadre(padre);
    }
  }
  return nodo;
  
  
}

template<class T>
void ArbolBinarioBusqueda<T>::print()
{
  std::cout<<*this;
}
