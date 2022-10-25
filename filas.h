#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED
#include "lista2.h"
#include "listaSimple.h"
#include <string.h>
typedef struct
{
    struct nodo2*primero;
    struct nodo2*ultimo;
    int numeroFila;
    char nombreCajero[50];
}fila;
///prototipado
void inicFila();
void agregarFila(fila*filin,cliente nuevoCliente);
void cargarLista(fila cajas[5],nodo1*lista);
void mostrarFilas(fila cajas[5]);
cliente extraerFila(fila*caja,int*totalFacturas,int*cantidadDeClientes);
cliente verPrimero(nodo2* primero);
nodo2*borrarPrimero(nodo2*lista);
void persistenciaClientesAtendidos(cliente clienteAtendido);
nodo1*despercistenciaAtendidos();
#endif // FILAS_H_INCLUDED
