#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED
#include "cliente.h"
typedef struct
{
    cliente unCliente;
    struct nodo2*siguiente;
    struct nodo2*anterior;

}nodo2;
///prototipado
nodo2*inicListaDoble();
nodo2*crearNodoDoble(cliente nuevoCliente);
nodo2*agregarPrincipioDoble(nodo2*lista,nodo2*nuevoNodo);
nodo2*buscarUltimo(nodo2*lista);
nodo2*agregarFinalDoble(nodo2*lista,nodo2*nuevoNodo);
void mostrarNodoDoble(nodo2*aMostrar);
void mostrarListaDoble(nodo2*lista);
nodo2*agregarOrdenadoDoble(nodo2*lista,nodo2*nuevoNodo);
#endif // LISTA2_H_INCLUDED
