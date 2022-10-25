#include "lista2.h"

nodo2*inicListaDoble()
{
    return NULL;
}
nodo2*crearNodoDoble(cliente nuevoCliente)
{
    nodo2*nuevoNodo=(nodo2*)malloc(sizeof(nodo2));
    nuevoNodo->siguiente=NULL;
    nuevoNodo->anterior=NULL;
    nuevoNodo->unCliente=nuevoCliente;

    return nuevoNodo;
}

nodo2*agregarPrincipioDoble(nodo2*lista,nodo2*nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente=lista;
        lista->anterior=nuevoNodo;
        lista=nuevoNodo;
    }
    return lista;
}
nodo2*buscarUltimo(nodo2*lista)
{
    nodo2*seguidora=lista;
    if(seguidora!=NULL)
    {
        while(seguidora->siguiente!=NULL)
        {
            seguidora=seguidora->siguiente;
        }
    }
    return seguidora;

}
nodo2*agregarFinalDoble(nodo2*lista,nodo2*nuevoNodo)
{
    nodo2*ultimo;
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        ultimo=buscarUltimo(lista);
        ultimo->siguiente=nuevoNodo;
        nuevoNodo->anterior=ultimo;
    }
    return lista;
}
void mostrarNodoDoble(nodo2*aMostrar)
{
    printf("TIPO DE CLIENTE: %s\n",aMostrar->unCliente.tipo);
    printf("CANTIDAD DE FACTURAS: %i\n",aMostrar->unCliente.cantidadFacturas);
}
void mostrarListaDoble(nodo2*lista)
{
    nodo2*seguidora=lista;
    while(seguidora!=NULL)
    {
        mostrarNodoDoble(seguidora);
        printf("\n");
        seguidora=seguidora->siguiente;
    }
}
nodo2*agregarOrdenadoDoble(nodo2*lista,nodo2*nuevoNodo)
{

    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else if(lista->unCliente.cantidadFacturas>nuevoNodo->unCliente.cantidadFacturas)
    {
       lista=agregarPrincipioDoble(lista,nuevoNodo);
    }
    else
    {
        nodo2*seguidora=lista->siguiente;
        nodo2*anterior=lista;
        while((seguidora!=NULL)&&(seguidora->unCliente.cantidadFacturas<nuevoNodo->unCliente.cantidadFacturas))
        {
            anterior=seguidora;
            seguidora=seguidora->siguiente;
        }
        anterior->siguiente=nuevoNodo;
        nuevoNodo->siguiente=seguidora;
        nuevoNodo->anterior=anterior;
        if(seguidora!=NULL)
        {
            seguidora->anterior=nuevoNodo;
        }

    }
    return lista;
}
