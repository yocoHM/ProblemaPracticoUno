#include <iostream>
#include <iterator>
#include <cstring>
#include <chrono>

#include "ArbolDosTres.h"
#include "Rojinegro.h"
#include "ArbolB.h"
#include "ArbolAVL.h"

int main()
{
  ArbolDosTres<int> * dosTres = new ArbolDosTres<int>();
  Rojinegro<int> * rojiNegro = new Rojinegro<int>();
  ArbolB<int> * bTree = new ArbolB<int>(3);
  ArbolAVL<int> * arbolAVL = new ArbolAVL<int>();
  
  srand((int) time(NULL));
  
  const int N = 20;
  
  int numeros[N];
  int busqueda[10];
  
  //- - - - - - - - - - - - - - - - - - - Generar los numeros random - - - - - - - - - - - - - - - - - - - - -
  for(int i=0;i<N;i++) {
    numeros[i] = rand()%100;
  }
  
  //- - - - - - - - - - - - - - - - - - - Elementos buscados - - - - - - - - - - - - - - - - - - - - -
  for(int i=0;i<10;i++) {
    busqueda[i] = numeros[i];
  }
  
  //- - - - - - - - - - - - - - - - - - - Árbol AVL - - - - - - - - - - - - - - - - - - - - -
  
  std::cout << "- - - - - Arbol AVL - - - - -" << std::endl;
  
  std::cout << std::endl;
  
  //inserción
  std::cout << "Se insertan " << N << " valores al árbol" << std::endl;
  
  for(int i=0; i<N; i++) {
    arbolAVL->insert(numeros[i]);
  }
  
  std::cout << std::endl;
  
  //busqueda
  std::cout << "Se busca el valor: " << busqueda[0] << " en el árbol" << std::endl;
  
  bool found = false;
  found = arbolAVL->buscar(busqueda[0]);
  if (found) {
    std::cout << "Se encontró el valor: " << busqueda[0] << " en el árbol" << std::endl;
  }
  else {
    std::cout << "No se encontró el valor en el árbol" << std::endl;
  }
  
  std::cout << std::endl;
  
  //impresión descendente
  std::cout << "Impresión de los valores del árbol en orden descendente" << std::endl;
  arbolAVL->reverseInOrder();
  
  std::cout << "\n" << std::endl;
  
  //altura
  std::cout << "Altura de la raíz: " << arbolAVL->getAltura() << std::endl;
  
  std::cout << std::endl;
  
  //profundidad
  std::cout << "Profundidad de la raíz: " << arbolAVL->getProfundidad() << std::endl;
  
  std::cout << std::endl;
  
  //nivel
  std::cout << "Nivel de la raíz: " << arbolAVL->getNivel() << std::endl;
  
  std::cout << std::endl;
  
  //verificar árbol
  std::cout << "Verificación del árbol:" << std::endl;
  
  if (arbolAVL->esAVL(arbolAVL->getRaiz())) {
    std::cout << "El árbol es AVL" << std::endl;
  }
  else {
    std::cout << "El árbol NO es AVL" << std::endl;
  }
  
  std::cout << std::endl;
  
  //impresión ascendente
  std::cout << "Impresión ascendente del árbol antes de borrar" << std::endl;
  arbolAVL->inOrder();
  
  std::cout << "\n" << std::endl;
  
  //borrado
  std::cout << "Borrar el elemento: " << busqueda[1] << std::endl;
  arbolAVL->remove(busqueda[1]);
  
  std::cout << std::endl;
  
  std::cout << "Impresión ascendente del árbol después de borrar" << std::endl;
  arbolAVL->inOrder();
  
  std::cout << "\n" << std::endl;
  
  
  //- - - - - - - - - - - - - - - - - - - B-Tree - - - - - - - - - - - - - - - - - - - - -
  std::cout << "- - - - - B-Tree - - - - -" << std::endl;
  std::cout << std::endl;
  
  //inserción
  std::cout << "Se insertan " << N << " valores al árbol" << std::endl;
  
  for(int i=0; i<N; i++) {
    bTree->Insertar(numeros[i]);
  }
  
  std::cout << std::endl;
  
  //busqueda
  std::cout << "Se busca el valor: " << busqueda[0] << " en el árbol" << std::endl;
  
  bTree->Buscar(busqueda[0]);
  
  std::cout << std::endl;
  
  //impresión ascendente
  std::cout << "Impresión de los valores del árbol en orden ascendente" << std::endl;
  bTree->printAsc();
  
  std::cout << std::endl;
  
  //impresión descendente
  std::cout << "Impresión de los valores del árbol en orden descendente" << std::endl;
  bTree->printDesc();
  
  std::cout << std::endl;
  
  std::cout << "Impresión ascendente del árbol antes de borrar" << std::endl;
  bTree->printAsc();
  
  std::cout << std::endl;
  
  //borrado
  std::cout << "Borrar el elemento: " << busqueda[1] << std::endl;
  bTree->Borrar(busqueda[1]);
  
  std::cout << std::endl;
  
  std::cout << "Impresión ascendente del árbol después de borrar" << std::endl;
  bTree->printAsc();
  
  std::cout << std::endl;
  
  //- - - - - - - - - - - - - - - - - - - Árbol Rojinegro - - - - - - - - - - - - - - - - - - - - -
  std::cout << "- - - - - Arbol Rojinegro - - - - -" << std::endl;
  
  std::cout << std::endl;
  
  //inserción
  std::cout << "Se insertan " << N << " valores al árbol" << std::endl;
  
  for(int i=0; i<N;i++) {
    rojiNegro->RBinsert(numeros[i]);
  }
  
  std::cout << std::endl;
  
  //busqueda
  std::cout << "Se busca el valor: " << busqueda[0] << " en el árbol" << std::endl;
  
  found = false;
  found = rojiNegro->buscar(busqueda[0]);
  if (found) {
    std::cout << "Se encontró el valor: " << busqueda[0] << " en el árbol" << std::endl;
  }
  else {
    std::cout << "No se encontró el valor en el árbol" << std::endl;
  }
  
  std::cout << std::endl;
  
  //impresión ascendente
  std::cout << "Impresión de los valores del árbol en orden ascendente" << std::endl;
  rojiNegro->inOrden();
  
  std::cout << "\n" << std::endl;
  
  //impresión descendente
  std::cout << "Impresión de los valores del árbol en orden descendente" << std::endl;
  rojiNegro->revOrden();
  
  std::cout << "\n" << std::endl;
  
  std::cout << "Impresión ascendente del árbol antes de borrar" << std::endl;
  rojiNegro->inOrden();
  
  std::cout << "\n" << std::endl;
  
  //borrado
  std::cout << "Borrar el elemento: " << busqueda[1] << std::endl;
  rojiNegro->RBdelete(busqueda[1]);
  
  std::cout << std::endl;
  
  std::cout << "Impresión ascendente del árbol después de borrar" << std::endl;
  rojiNegro->inOrden();
  
  std::cout << "\n" << std::endl;
  
  //- - - - - - - - - - - - - - - - - - - Árbol 2-3 - - - - - - - - - - - - - - - - - - - - -
  
  std::cout << "- - - - - Arbol 2-3 - - - - -" << std::endl;
  std::cout << std::endl;
  
  //inserción
  std::cout << "Se insertan " << N << " valores al árbol" << std::endl;
  
  for(int i=0; i<N; i++)
  {
    dosTres->insertar23(numeros[i]);
  }
  
  std::cout << std::endl;
  
  //busqueda
  std::cout << "Se busca el valor: " << busqueda[0] << " en el árbol" << std::endl;
  
  found = false;
  found = dosTres->buscar(busqueda[0]);
  if (found) {
    std::cout << "Se encontró el valor: " << busqueda[0] << " en el árbol" << std::endl;
  }
  else {
    std::cout << "No se encontró el valor en el árbol" << std::endl;
  }
  
  std::cout << std::endl;
  
  //impresión ascendente
  std::cout << "Impresión de los valores del árbol en orden ascendente" << std::endl;
  dosTres->printAsc();
  
  std::cout << std::endl;
  
  //impresión descendente
  std::cout << "Impresión de los valores del árbol en orden descendente" << std::endl;
  dosTres->printDesc();
  
  std::cout <<  std::endl;

  //verificacion
  std::cout << "Verificación del árbol:" << std::endl;
  if (dosTres->esDosTres()) {
    std::cout << "El árbol es 2-3" << std::endl;
  }
  else {
    std::cout << "El árbol NO es 2-3" << std::endl;
  }
  
  std::cout << std::endl;
  
  std::cout << "Impresión ascendente del árbol antes de borrar" << std::endl;
  dosTres->printAsc();
  
  std::cout << std::endl;
  
  //borrado
  std::cout << "Borrar el elemento: " << busqueda[1] << std::endl;
  dosTres->borrar(busqueda[1]);
  
  std::cout << std::endl;
  
  std::cout << "Impresión ascendente del árbol después de borrar" << std::endl;
  dosTres->printAsc();
  
  std::cout << std::endl;
  
  delete dosTres;
  delete rojiNegro;
  delete bTree;
  delete arbolAVL;
  
  return 0;
}
