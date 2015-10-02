#include "NodoB.h"
#include <iostream>


template <class T>
class BinaryTree {
protected:
  NodoB<T> * raiz = nullptr;
  
public:
  BinaryTree() {}
  virtual ~BinaryTree();
  
  bool empty();
  
  void clear();
  void clear(NodoB<T> * node);
  
  NodoB<T> * getRaiz() const;
  void setRaiz(NodoB<T> * node);
  
  
  virtual void insert(T value);
  virtual void insert(NodoB<T> * parent, NodoB<T> * node);
  
  
  void preOrder() const;
  void preOrder(NodoB<T> * node) const;
  
  
  void inOrder() const;
  void inOrder(NodoB<T> * node) const;
  
  void reverseInOrder() const;
  void reverseInOrder(NodoB<T> * node) const;
  
  void postOrder() const;
  void postOrder(NodoB<T> * node) const;
  
  void esHoja() const;
  void esHoja(NodoB<T> * node) const;
  
  void ancestros(NodoB<T> * node) const;
  
  int getAltura() const;
  int getAltura(NodoB<T> * node) const ;
  
  int getProfundidad() const;
  int getProfundidad(NodoB<T> * node) const;
  
  int getNivel() const;
  int getNivel(NodoB<T> * node) const;
  
  int getFactorBalance() const;
  int getFactorBalance(NodoB<T> * node) const ;
  
};


template <class T>
BinaryTree<T>::~BinaryTree()
{
  clear();
}

template <class T>
bool BinaryTree<T>::empty()
{
  return raiz == nullptr;
}

template <class T>
void BinaryTree<T>::clear()
{
  clear(raiz);
}

template <class T>
void BinaryTree<T>::clear(NodoB<T> * node)
{
  if (node) {
    clear(node->getIzquierdo());
    clear(node->getDerecho());
    
    delete node;
  }
}

template <class T>
NodoB<T> * BinaryTree<T>::getRaiz() const
{
  return raiz;
}

template <class T>
void BinaryTree<T>::setRaiz(NodoB<T> * node)
{
  raiz = node;
}


template <class T>
void BinaryTree<T>::insert(T value){
  NodoB<T> * node = new NodoB<T>(value);
  insert(this->raiz, node);
}

template <class T>
void BinaryTree<T>::insert(NodoB<T> * parent, NodoB<T> * node){
  if (empty())
  {
    setRaiz(node);
  }
  else
  {
    if(node->getInfo() < parent->getInfo())
    {
      
      if (parent->getIzquierdo() == nullptr)
      {
        parent->setLeft(node);
        node->setParent(parent);
        
      }
      else
      {
        insert(parent->getIzquierdo(), node);
      }
    }
    else
    {
      if (parent->getDerecho() == nullptr)
      {
        parent->setRight(node);
        node->setParent(parent);
        
      }
      else
      {
        insert(parent->getDerecho(), node);
      }
    }
  }
}



template <class T>
void BinaryTree<T>::preOrder() const
{
  preOrder(raiz);
}

template <class T>
void BinaryTree<T>::preOrder(NodoB<T> * node) const
{
  if (node) {
    std::cout << *node << std::endl;
    
    preOrder(node->getIzquierdo());
    preOrder(node->getDerecho());
    
  }
}

template <class T>
void BinaryTree<T>::inOrder() const
{
  inOrder(raiz);
}

template <class T>
void BinaryTree<T>::inOrder(NodoB<T> * node) const
{
  if (node) {
    
    inOrder(node->getIzquierdo());
    
    std::cout << *node << " ";
    
    inOrder(node->getDerecho());
  }
}

template <class T>
void BinaryTree<T>::reverseInOrder() const{
  reverseInOrder(raiz);
  
}
template <class T>
void BinaryTree<T>::reverseInOrder(NodoB<T> * node) const{
  
  if (node) {
    reverseInOrder(node->getDerecho());
    std::cout << *node << " ";
    reverseInOrder(node->getIzquierdo());
  }
}

template <class T>
void BinaryTree<T>::postOrder() const
{
  postOrder(raiz);
}

template <class T>
void BinaryTree<T>::postOrder(NodoB<T> * node) const
{
  if (node) {
    postOrder(node->getIzquierdo());
    postOrder(node->getDerecho());
    
    std::cout << *node << std::endl;
  }
}

template <class T>
void BinaryTree<T>::esHoja() const
{
  esHoja(raiz);
}

template <class T>
void BinaryTree<T>::esHoja(NodoB<T> * node) const
{
  if (node) {
    if (!node->getIzquierdo() && !node->getDerecho()) {
      std::cout << *node << std::endl;
    }
    else {
      esHoja(node->getIzquierdo());
      esHoja(node->getDerecho());
    }
  }
}

template <class T>
void BinaryTree<T>::ancestros(NodoB<T> * node) const
{
  if (node) {
    std::cout << *node << " -> ";
    ancestros(node->getParent());
  }
}

template <class T>
int BinaryTree<T>::getAltura() const
{
  return getAltura(raiz);
}

template <class T>
int BinaryTree<T>::getAltura(NodoB<T> * node) const
{
  if (node == nullptr)
  {
    return -1;
  }
  else
  {
    int leftCount = getAltura(node->getIzquierdo());
    int rightCount = getAltura(node->getDerecho());
    
    if (leftCount <= rightCount)
    {
      return rightCount +1;
    }
    else
    {
      return leftCount +1;
    }
  }
}

template <class T>
int BinaryTree<T>::getNivel() const
{
  return getNivel(raiz);
}

template <class T>
int BinaryTree<T>::getNivel(NodoB<T> * node) const
{
  if (node == nullptr)
  {
    return 0;
  }
  else
  {
    return getNivel(node->getParent()) + 1;
  }
}

template <class T>
int BinaryTree<T>::getProfundidad() const
{
  return getProfundidad(raiz);
}

template <class T>
int BinaryTree<T>::getProfundidad(NodoB<T> * node) const
{
  return getNivel(node) - 1;
}

template <class T>
int BinaryTree<T>::getFactorBalance() const
{
  return getFactorBalance(raiz);
}

template <class T>
int BinaryTree<T>::getFactorBalance(NodoB<T> * node) const
{
  if (node)
  {
    return getAltura(node->getDerecho()) - getAltura(node->getIzquierdo());
  }
  return 0;
}