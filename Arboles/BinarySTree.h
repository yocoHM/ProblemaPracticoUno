#include "BinaryTree.h"

template <class T>
class BinarySTree: public BinaryTree<T> {
  
  
public:
  BinarySTree();
  ~BinarySTree();
  
  NodoB<T> * buscar(const T info) const;
  NodoB<T> * buscar(const T info, NodoB<T> * nodo) const;
};

template <class T>
BinarySTree<T>::BinarySTree() : BinaryTree<T>(){}

template <class T>
BinarySTree<T>::~BinarySTree()
{
  
}

template <class T>
NodoB<T> * BinarySTree<T>::buscar(const T info) const{
  return buscar(info, this->raiz);
  
}

template <class T>
NodoB<T> * BinarySTree<T>::buscar(const T info, NodoB<T> * nodo)const {
  if (nodo == nullptr)
  {
    return nullptr;
  }
  else {
    T info2 = nodo->getInfo();
    if (info == info2)
    {
      return nodo;
    }
    else if (info < info2)
    {
      return buscar(info, nodo->getIzquierdo());
    }
    else {
      return buscar(info, nodo->getDerecho());
    }
  }
}