#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
typedef struct
{
    cliente unCliente;
    struct nodo1*siguiente;
}nodo1;

///prototipados
nodo1*inicListaSimple();
nodo1*crearNodoSimple(cliente nuevoCliente);
nodo1*agregarPrincipioSimple(nodo1*lista,nodo1*nuevoNodo);
nodo1*buscarUltimoSimple(nodo1*lista);
nodo1*agregarFinalSimple(nodo1*lista,nodo1*nuevoNodo);
void mostrarNodoSimple(nodo1*aMostrar);
void mostrarListaSimple(nodo1*lista);



#endif // LISTASIMPLE_H_INCLUDED
