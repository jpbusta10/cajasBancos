#include "listaSimple.h"


nodo1*inicListaSimple()
{
    return NULL;
}
nodo1*crearNodoSimple(cliente nuevoCliente)
{
    nodo1*nuevoNodo=(nodo1*)malloc(sizeof(nodo1));
    nuevoNodo->siguiente=NULL;

    nuevoNodo->unCliente=nuevoCliente;

    return nuevoNodo;
}
nodo1*agregarPrincipioSimple(nodo1*lista,nodo1*nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente=lista;
        lista=nuevoNodo;
    }
    return lista;
}
nodo1*buscarUltimoSimple(nodo1*lista)
{
    nodo1*seguidora=lista;
    if(seguidora!=NULL)
    {
        while(seguidora->siguiente!=NULL)
        {
            seguidora=seguidora->siguiente;
        }
    }
    return seguidora;
}
nodo1*agregarFinalSimple(nodo1*lista,nodo1*nuevoNodo)
{
    nodo1*ultimo;
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        ultimo=buscarUltimo(lista);
        ultimo->siguiente=nuevoNodo;
    }
    return lista;
}
void mostrarNodoSimple(nodo1*aMostrar)
{
    printf("TIPO DE CLIENTE: %s\n",aMostrar->unCliente.tipo);
    printf("CANTIDAD DE FACTURAS: %i\n",aMostrar->unCliente.cantidadFacturas);
}
void mostrarListaSimple(nodo1*lista)
{
    nodo1*seguidora=lista;
    while(seguidora!=NULL)
    {
        mostrarNodoSimple(seguidora);
        printf("\n");
        seguidora=seguidora->siguiente;
    }
}

