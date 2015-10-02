#include "BinarySTree.h"

template <class T>
class ArbolAVL : public BinarySTree<T>{
  
public:
  ArbolAVL(){}
  ~ArbolAVL();
  
  void rotacionIzq(NodoB<T> * nodo);
  void rotacionDer(NodoB<T> * nodo);
  void rotacionIzqDer(NodoB<T> * nodo);
  void rotacionDerIzq(NodoB<T> * nodo);
  bool esAVL(NodoB<T> * nodo);
  void insert(NodoB<T> * padre, NodoB<T> * nodo);
  void insert(T value);
  void remove(T value);
  
  NodoB<T> * getMaxMin(NodoB<T> * nodo) const;
  NodoB<T> * getMaxMin() const;
  
};

template <class T>
ArbolAVL<T>::~ArbolAVL(){
  
}

template <class T>
bool ArbolAVL<T>::esAVL(NodoB<T> * nodo){
  
  if (nodo)
  {
    if (abs(this->getFactorBalance(nodo)) > 1 )
    {
      return false;
    }
    return  esAVL(nodo->getDerecho()) && esAVL(nodo->getIzquierdo());
  }
  else
  {
    return true;
  }
  
}

template <class T>
void ArbolAVL<T>::rotacionDer(NodoB<T> * pivote){
  NodoB<T> * temp = pivote->getIzquierdo();
  
  if(pivote->getParent() && pivote->getInfo() <= pivote->getParent()->getInfo() ){
    pivote->getParent()->setLeft(temp);
  }else if (pivote->getParent()){
    pivote->getParent()->setRight(temp);
  }else{
    this->setRaiz(temp);
  }
  
  temp->setParent(pivote->getParent());
  pivote->setParent(temp);
  
  pivote->setLeft(temp->getDerecho());
  
  temp->setRight(pivote);
  
  if(pivote->getIzquierdo())
    pivote->getIzquierdo()->setParent(pivote);
  
}

template <class T>
void ArbolAVL<T>::rotacionIzq(NodoB<T> * pivote){
  NodoB<T> * temp = pivote->getDerecho();
  
  if(pivote->getParent() && pivote->getInfo() <= pivote->getParent()->getInfo() ){
    pivote->getParent()->setLeft(temp);
  }else if (pivote->getParent()){
    pivote->getParent()->setRight(temp);
  }else{
    this->setRaiz(temp);
  }
  
  temp->setParent(pivote->getParent());
  pivote->setParent(temp);
  
  pivote->setRight(temp->getIzquierdo());
  
  temp->setLeft(pivote);
  
  if(pivote->getDerecho())
    pivote->getDerecho()->setParent(pivote);
  
}

template <class T>
void ArbolAVL<T>::rotacionIzqDer(NodoB<T> * pivote){
  NodoB<T> * temp = pivote->getDerecho();
  rotacionIzq(pivote);
  rotacionDer(temp->getParent());
}

template <class T>
void ArbolAVL<T>::rotacionDerIzq(NodoB<T> * pivote){
  NodoB<T> * temp = pivote->getIzquierdo();
  rotacionDer(pivote);
  rotacionIzq(temp->getParent());
}

template <class T>
void ArbolAVL<T>::insert(NodoB<T> * padre, NodoB<T> * nodo){
  
  if (this->empty())
  {
    this->setRaiz(nodo);
    
  }
  else
  {
    if(nodo->getInfo() < padre->getInfo())
    {
      
      if (padre->getIzquierdo() == nullptr)
      {
        padre->setLeft(nodo);
        nodo->setParent(padre);
        
      }
      else
      {
        insert(padre->getIzquierdo(), nodo);
      }
    }
    else if(nodo->getInfo() > padre->getInfo())
    {
      if (padre->getDerecho() == nullptr)
      {
        padre->setRight(nodo);
        nodo->setParent(padre);
        
      }
      else
      {
        insert(padre->getDerecho(), nodo);
      }
    } else {
      return;
    }
    
    
    if(this->getFactorBalance(padre->getParent()) == -2 && this->getFactorBalance(padre->getParent()->getIzquierdo())== -1){
      rotacionDer(padre->getParent());
    }
    if(this->getFactorBalance(padre->getParent()) == -2 && this->getFactorBalance(padre->getParent()->getIzquierdo())== 1){
      rotacionIzqDer(padre);
    }
    if(this->getFactorBalance(padre->getParent()) == 2 && this->getFactorBalance(padre->getParent()->getDerecho())== 1){
      rotacionIzq(padre->getParent());
    }
    if( (this->getFactorBalance(padre->getParent()) == 2 && this->getFactorBalance(padre->getParent()->getDerecho())== -1)){
      rotacionDerIzq(padre);
    }
    
  }
  
}


template <class T>
void ArbolAVL<T>::insert(T value){
  NodoB<T> * nodo = new NodoB<T>(value);
  insert(this->raiz, nodo);
}

template <class T>
void ArbolAVL<T>::remove(T value){
  NodoB<T> * nodo = this->buscar(value);
  
  if(nodo){
    
    NodoB<T> * padre = nodo->getParent();
    NodoB<T> * nnodo = getMaxMin(nodo);
    
    if(nnodo){
      nnodo->setRight(nodo->getDerecho());
      if(nnodo->getDerecho())
        nnodo->getDerecho()->setParent(nnodo);
      nnodo->getParent()->setRight(nnodo->getIzquierdo());
      nnodo->setParent(nodo->getParent());
    
      if(nodo->getIzquierdo() == nnodo){
        if(!nnodo->getIzquierdo())
          nnodo->setLeft(nullptr);
      }
      else{
        nnodo->setLeft(nodo->getIzquierdo());
      }
      
    }
    
    if(!nodo->getParent()){
      BinaryTree<T>::setRaiz(nnodo);
    }else if(nodo->getInfo() <= nodo->getParent()->getInfo()){
      nodo->getParent()->setLeft(nnodo);
    } else{
      nodo->getParent()->setRight(nnodo);
    }
    
    
    delete nodo;
    
    
    if(this->getFactorBalance(padre) == -2 && this->getFactorBalance(padre->getIzquierdo()) == -1){
      rotacionDer(padre);
    }
    if(this->getFactorBalance(padre) == -2 && this->getFactorBalance(padre->getIzquierdo())== 1){
      rotacionIzqDer(padre->getIzquierdo());
    }
    if(this->getFactorBalance(padre) == 2 && this->getFactorBalance(padre->getDerecho())== 1){
      rotacionIzq(padre);
    }
    if( (this->getFactorBalance(padre) == 2 && this->getFactorBalance(padre->getDerecho())== -1)){
      rotacionDerIzq(padre->getDerecho());
    }
    padre =  padre->getParent();
    
    
    if(this->getFactorBalance(nnodo) == -2 && this->getFactorBalance(nnodo->getIzquierdo()) == -1){
      rotacionDer(nnodo);
    }
    if(this->getFactorBalance(nnodo) == -2 && this->getFactorBalance(nnodo->getIzquierdo())== 1){
      rotacionIzqDer(nnodo->getIzquierdo());
    }
    if(this->getFactorBalance(nnodo) == 2 && this->getFactorBalance(nnodo->getDerecho())== 1){
      rotacionIzq(nnodo);
    }
    if( (this->getFactorBalance(nnodo) == 2 && this->getFactorBalance(nnodo->getDerecho())== -1)){
      rotacionDerIzq(nnodo->getDerecho());
    }
    
  }
  
}

template <class T>
NodoB<T> * ArbolAVL<T>::getMaxMin() const
{
  return getMaxMin(this->raiz);
}


template <class T>
NodoB<T> * ArbolAVL<T>::getMaxMin(NodoB<T> * nodo) const
{
  if (nodo)
  {
    NodoB<T> * workingNode = nodo->getIzquierdo();
    if(workingNode){
      while (workingNode->getDerecho() != nullptr)
      {
        workingNode = workingNode->getDerecho();
      }
      return workingNode;
    }
    return nullptr;
    
  } else{
    return nullptr;
  }
  
}