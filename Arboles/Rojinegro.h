#include "ArbolBinarioBusqueda.h"

template<class T>
class Rojinegro : public ArbolBinarioBusqueda<T>
{
public:
  Rojinegro();
  
  NodoRB<T> * abuelo(NodoRB<T> * nodo);
  NodoRB<T> * tio(NodoRB<T> * nodo);
  NodoRB<T> * hermano(NodoRB<T> * nodo);
  
  NodoRB<T> * nodoMaximo(NodoRB<T> * nodo);
  
  void verificar(NodoRB<T> * raiz);
  void checarPropiedadUno(NodoRB<T> * nodo);
  void checarPropiedadDos(NodoRB<T> * nodo);
  void checarPropiedadTres(NodoRB<T> * nodo);
  void checarPropiedadCuatro(NodoRB<T> * root);
  void checarPropiedadCuatroHelper(NodoRB<T> * nodo, int contNegros, int& blackPath);
  
  std::string color(NodoRB<T> * nodo);
  
  void rotarIzq(Rojinegro * arbol, NodoRB<T> * nodo);
  void rotarDer(Rojinegro * arbol, NodoRB<T> * nodo);
  
  void RBinsert(T valor);
  void insertarCasoUno(Rojinegro * arbol, NodoRB<T> * nodo);
  void insertarCasoDos(Rojinegro * arbol, NodoRB<T> * nodo);
  void insertarCasoTres(Rojinegro * arbol, NodoRB<T> * nodo);
  void insertarCasoCuatro(Rojinegro * arbol, NodoRB<T> * nodo);
  void insertarCasoCinco(Rojinegro * arbol, NodoRB<T> * nodo);
  
  void RBdelete(T valor);
  void borrarCasoUno(Rojinegro * arbol, NodoRB<T> * nodo);
  void borrarCasoDos(Rojinegro * arbol, NodoRB<T> * nodo);
  void borrarCasoTres(Rojinegro * arbol, NodoRB<T> * nodo);
  void borrarCasoCuatro(Rojinegro * arbol, NodoRB<T> * nodo);
  void borrarCasoCinco(Rojinegro * arbol, NodoRB<T> * nodo);
  void borrarCasoSeis(Rojinegro * arbol, NodoRB<T> * nodo);
  
  
  void verificarArbol(NodoRB<T>* raiz);
};

template<class T>
Rojinegro<T>::Rojinegro() : ArbolBinarioBusqueda<T>() {}

template<class T>
NodoRB<T> * Rojinegro<T>::abuelo(NodoRB<T> * nodo)
{
  if(nodo != nullptr && nodo->getPadre() != nullptr)
    return nodo->getPadre()->getPadre();
  else
    return nullptr;
}

template<class T>
NodoRB<T> * Rojinegro<T>::tio(NodoRB<T> * nodo)
{
  NodoRB<T> * abu = abuelo(nodo);
  
  if(abu == nullptr)
    return nullptr;
  else if(nodo->getPadre() == abu->getIzquierdo())
    return abu->getDerecho();
  else
    return abu->getIzquierdo();
}

template<class T>
NodoRB<T> * Rojinegro<T>::hermano(NodoRB<T> * nodo)
{
  if(nodo != nullptr && nodo->getPadre() != nullptr)
  {
    if(nodo == nodo->getPadre()->getIzquierdo())
      return nodo->getPadre()->getDerecho();
    else
      return nodo->getPadre()->getIzquierdo();
  }
  else
    return nullptr;
}

template<class T>
NodoRB<T> * Rojinegro<T>::nodoMaximo(NodoRB<T> * nodo)
{
  while (nodo->getDerecho() != nullptr)
  {
    nodo = nodo->getDerecho();
  }
  return nodo;
}

template<class T>
void Rojinegro<T>::verificar(NodoRB<T>* raiz)
{
  checarPropiedadUno(raiz);
  checarPropiedadDos(raiz);
  checarPropiedadTres(raiz);
  checarPropiedadCuatro(raiz);
}

template<class T>
void Rojinegro<T>::checarPropiedadUno(NodoRB<T> * nodo)
{
  if(nodo == nullptr)
    return;
  
  checarPropiedadUno(nodo->getIzquierdo());
  checarPropiedadUno(nodo->getDerecho());
}

template<class T>
void Rojinegro<T>::checarPropiedadDos(NodoRB<T> * nodo)
{
  
}

template<class T>
void Rojinegro<T>::checarPropiedadTres(NodoRB<T> * nodo)
{
  if (nodo == nullptr)
    return;
  
  
  checarPropiedadTres(nodo->getIzquierdo());
  checarPropiedadTres(nodo->getDerecho());
}

template <class T>
void Rojinegro<T>::checarPropiedadCuatro(NodoRB<T> * root)
{
  
  int blackPath = -1;
  std::string mensaje="";
  
  return checarPropiedadCuatroHelper(root, 0, blackPath);
}

template <class T>
void Rojinegro<T>::checarPropiedadCuatroHelper(NodoRB<T> * nodo, int contNegros, int& blackPath)
{
  std::string color;
  
  
  if (nodo != nullptr) {
    color = nodo->getColor();
  }
  else{
    color = "";
  }
  
  if (color == "negro")
  {
    contNegros++;
  }
  if (nodo == nullptr)
  {
    if (blackPath == -1)
    {
      blackPath = contNegros;
    }
    else
    {
      if (contNegros != blackPath)
      {
        std::cout << "No es Rojinegro" << std::endl;
      }
    }
    return;
  }
  checarPropiedadCuatroHelper(nodo->getIzquierdo(),  contNegros, blackPath);
  checarPropiedadCuatroHelper(nodo->getDerecho(), contNegros, blackPath);
  
  return;
}

template<class T>
std::string Rojinegro<T>::color(NodoRB<T> * nodo)
{
  if(nodo == nullptr)
    return "negro";
  else
    return nodo->getColor();
}

template<class T>
void Rojinegro<T>::rotarIzq(Rojinegro * arbol, NodoRB<T> * node_x)
{
  NodoRB<T> *node_y;
  
  if(node_x->getDerecho() == NULL){
    return;
  }
  
  node_y = node_x->getDerecho();
  
  if(node_y->getIzquierdo() != NULL){
    node_y->getIzquierdo()->setPadre(node_x);
    node_x->setDerecho(node_y->getIzquierdo());
  }
  
  node_y->setPadre(node_x->getPadre());
  
  if(node_x->getPadre() == NULL){
    this->setRaiz(node_y);
  }else if(node_x == node_x->getPadre()->getIzquierdo()){
    node_x->getPadre()->setIzquierdo(node_y);
  }else{
    node_x->getPadre()->setDerecho(node_y);
  }
  
  node_x->setDerecho(node_y->getIzquierdo());
  node_y->setIzquierdo(node_x);
  node_x->setPadre(node_y);
  
}

template<class T>
void Rojinegro<T>::rotarDer(Rojinegro * arbol, NodoRB<T> * node_y)
{
  NodoRB<T> *node_x;
  
  if(node_y->getIzquierdo() == NULL){
    return;
  }
  
  node_x = node_y->getIzquierdo();
  
  if(node_x->getDerecho() != NULL){
    node_x->getDerecho()->setPadre(node_y);
    node_y->setIzquierdo(node_x->getDerecho());
  }
  
  node_x->setPadre(node_y->getPadre());
  
  if(node_y->getPadre() == NULL){
    this->setRaiz(node_x);
  }else if(node_y == node_y->getPadre()->getIzquierdo()){
    node_y->getPadre()->setIzquierdo(node_x);
  }else{
    node_y->getPadre()->setDerecho(node_x);
  }
  
  node_y->setIzquierdo(node_x->getDerecho());
  node_x->setDerecho(node_y);
  node_y->setPadre(node_x);
}

template<class T>
void Rojinegro<T>::RBinsert(T valor)
{
  NodoRB<T> * nodo = this->insertar(valor);
  nodo->setColor("rojo");
  insertarCasoUno(this, nodo);
  verificar(this->getRaiz());
  
}

template<class T>
void Rojinegro<T>::insertarCasoUno(Rojinegro * arbol, NodoRB<T> * nodo)
{
  if(nodo->getPadre() == nullptr)
    nodo->setColor("negro");
  else
    insertarCasoDos(this, nodo);
}

template<class T>
void Rojinegro<T>::insertarCasoDos(Rojinegro * arbol, NodoRB<T> * nodo)
{
  if(nodo->getPadre()->getColor() == "negro")
    return;
  else
    insertarCasoTres(this, nodo);
}

template<class T>
void Rojinegro<T>::insertarCasoTres(Rojinegro * arbol, NodoRB<T> * nodo)
{
  if(color(tio(nodo)) == "rojo")
  {
    nodo->getPadre()->setColor("negro");
    tio(nodo)->setColor("negro");
    abuelo(nodo)->setColor("rojo");
    insertarCasoUno(arbol, abuelo(nodo));
  }
  else
  {
    insertarCasoCuatro(arbol, nodo);
  }
}

template<class T>
void Rojinegro<T>::insertarCasoCuatro(Rojinegro * arbol, NodoRB<T> * nodo)
{
  if(nodo == nodo->getPadre()->getDerecho() && nodo->getPadre() == abuelo(nodo)->getIzquierdo())
  {
    rotarIzq(arbol, nodo->getPadre());
    nodo = nodo->getIzquierdo();
  }
  else if(nodo == nodo->getPadre()->getIzquierdo() && nodo->getPadre() == abuelo(nodo)->getDerecho())
  {
    rotarDer(arbol, nodo->getPadre());
    nodo = nodo->getDerecho();
  }
  insertarCasoCinco(arbol, nodo);
}

template<class T>
void Rojinegro<T>::insertarCasoCinco(Rojinegro * arbol, NodoRB<T> * nodo)
{
  nodo->getPadre()->setColor("negro");
  abuelo(nodo)->setColor("rojo");
  if (nodo == nodo->getPadre()->getIzquierdo() && nodo->getPadre() == abuelo(nodo)->getIzquierdo())
  {
    rotarDer(arbol, abuelo(nodo));
  }
  else
  {
    rotarIzq(arbol, abuelo(nodo));
  }
}

template <class T>
void Rojinegro<T>::RBdelete(T valor)
{
  NodoRB<T> * hijo;
  NodoRB<T> * nodo;
  nodo = this->buscar(valor);
  if (nodo == nullptr)
    return;
  
  if (nodo->getIzquierdo() != nullptr && nodo->getDerecho() != nullptr)
  {
    NodoRB<T> * pred = nodoMaximo(nodo->getIzquierdo());
    nodo->setInfo(pred->getInfo());
    nodo = pred;
  }
  hijo = nodo->getDerecho() == nullptr ? nodo->getIzquierdo()  : nodo->getDerecho();
  if (color(nodo) == "negro")
  {
    nodo->getColor() = color(hijo);
    borrarCasoUno(this, nodo);
  }
  
  
  if (nodo->getPadre() == nullptr)
  {
    this->setRaiz(hijo);
  }
  else
  {
    if (nodo == nodo->getPadre()->getIzquierdo())
      nodo->getPadre()->setIzquierdo(hijo);
    else
      nodo->getPadre()->setDerecho(hijo);
  }
  if (hijo != nullptr)
  {
    hijo->setPadre(nodo->getPadre());
  }
  delete nodo;
  verificar(this->getRaiz());
}

template <class T>
void Rojinegro<T>::borrarCasoUno(Rojinegro * arbol, NodoRB<T> * nodo)
{
  if(nodo->getPadre() == nullptr)
    return;
  else
    borrarCasoDos(this, nodo);
}

template <class T>
void Rojinegro<T>::borrarCasoDos(Rojinegro * arbol, NodoRB<T> * nodo)
{
  if (color(hermano(nodo)) == "rojo")
  {
    nodo->getPadre()->setColor("rojo");
    hermano(nodo)->setColor("negro");
    if (nodo == nodo->getPadre()->getIzquierdo())
      rotarIzq(this, nodo->getPadre());
    else
      rotarDer(this, nodo->getPadre());
  }
  borrarCasoTres(this, nodo);
}

template <class T>
void Rojinegro<T>::borrarCasoTres(Rojinegro * arbol, NodoRB<T> * nodo)
{
  if (color(nodo->getPadre()) == "negro" && color(hermano(nodo)) == "negro" &&
      color(hermano(nodo)->getIzquierdo()) == "negro" && color(hermano(nodo)->getDerecho()) == "negro")
  {
    hermano(nodo)->setColor("rojo");
    borrarCasoUno(this, nodo->getPadre());
  }
  else
    borrarCasoCuatro(this, nodo);
}

template <class T>
void Rojinegro<T>::borrarCasoCuatro(Rojinegro * arbol, NodoRB<T> * nodo)
{
  if (color(nodo->getPadre()) == "rojo" && color(hermano(nodo)) == "negro" &&
      color(hermano(nodo)->getIzquierdo()) == "negro" && color(hermano(nodo)->getDerecho()) == "negro")
  {
    hermano(nodo)->setColor("rojo");
    nodo->getPadre()->setColor("negro");
  }
  else
    borrarCasoCinco(this, nodo);
}

template<class T>
void Rojinegro<T>::borrarCasoCinco(Rojinegro * arbol, NodoRB<T> * nodo)
{
  if (nodo == nodo->getPadre()->getIzquierdo() && color(hermano(nodo)) == "negro" &&
      color(hermano(nodo)->getIzquierdo()) == "rojo" && color(hermano(nodo)->getDerecho()) == "negro")
  {
    hermano(nodo)->setColor("rojo");
    hermano(nodo)->getIzquierdo()->setColor("negro");
    rotarDer(this, hermano(nodo));
  }
  else if (nodo == nodo->getPadre()->getDerecho() && color(hermano(nodo)) == "negro" &&
           color(hermano(nodo)->getDerecho()) == "rojo" && color(hermano(nodo)->getIzquierdo()) == "negro")
  {
    hermano(nodo)->setColor("rojo");
    hermano(nodo)->getDerecho()->setColor("negro");
    rotarIzq(this, hermano(nodo));
  }
  borrarCasoSeis(this, nodo);
}

template<class T>
void Rojinegro<T>::borrarCasoSeis(Rojinegro * arbol, NodoRB<T> * nodo)
{
  hermano(nodo)->setColor(color(nodo->getPadre()));
  nodo->getPadre()->setColor("negro");
  if (nodo == nodo->getPadre()->getIzquierdo())
  {
    hermano(nodo)->getDerecho()->setColor("negro");
    rotarIzq(this, nodo->getPadre());
  }
  else
  {
    hermano(nodo)->getIzquierdo()->setColor("negro");
    rotarDer(this, nodo->getPadre());
  }
}

template<class T>
void Rojinegro<T>::verificarArbol(NodoRB<T>* raiz)
{
  verificar(raiz);
}

