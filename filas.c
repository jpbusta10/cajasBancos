#include "filas.h"

void inicFila(fila*Filin)
{
    Filin->primero=inicListaDoble();
    Filin->ultimo=inicListaDoble();
}

void agregarFila(fila*filin,cliente nuevoCliente)
{
    nodo2*nuevo =crearNodoDoble(nuevoCliente);
    if(filin->primero==NULL)
    {
        filin->primero=nuevo;
        filin->ultimo=nuevo;
    }
    else
    {
        filin->primero=agregarFinalDoble(filin->primero,nuevo);
        filin->ultimo=nuevo;
    }
}
void cargarLista(fila cajas[5],nodo1*lista)
{
    char tipo1[100]="regular";
    char tipo2[100]="jubilado";
    char tipo3[100]="persona gestante";
    char tipo4[100]="empresario";
    nodo1*aBorrar;
    int contFila1=0;
    int contFila3=0;
    int i=0;
    while((lista!=NULL))
    {
        if((strcmp(lista->unCliente.tipo,tipo1)==0)&&contFila1<6)
        {
            agregarFila(&cajas[0],lista->unCliente);
            contFila1++;
        }
        else if(strcmp(lista->unCliente.tipo,tipo2)==0)
        {
            agregarFila(&cajas[1],lista->unCliente);

        }
        else if((strcmp(lista->unCliente.tipo,tipo3)==0)||((strcmp(lista->unCliente.tipo,tipo1)==0)&&(contFila3<7)))
        {
            if ((strcmp(lista->unCliente.tipo,tipo3)==0))
                {
                    nodo2* auxi =crearNodoDoble(lista->unCliente);//paso el nodo a nodo doble
                    cajas[2].primero=agregarPrincipioDoble(cajas[2].primero,auxi);
                }
                else
                {
                    agregarFila(&cajas[2],lista->unCliente);
                }
            contFila3++;

        }
        else if(strcmp(lista->unCliente.tipo,tipo1)==0)
        {
            nodo2* nuevoNodo=crearNodoDoble(lista->unCliente);
            cajas[3].primero=agregarOrdenadoDoble(cajas[3].primero,nuevoNodo);
            cajas[3].ultimo=buscarUltimo(cajas[3].primero);
            nodo2*aux=cajas[3].primero;




        }
        else if(strcmp(lista->unCliente.tipo,tipo4)==0)
        {
            if(lista->unCliente.cantidadFacturas<=10)
            {
                agregarFila(&cajas[4],lista->unCliente);

            }
            if(lista->unCliente.cantidadFacturas>=11)
            {
                cliente auxiliar;
                auxiliar.cantidadFacturas=lista->unCliente.cantidadFacturas-10;
                strcpy(auxiliar.tipo,lista->unCliente.tipo);
                lista->unCliente.cantidadFacturas=10;
                agregarFila(&cajas[4],lista->unCliente);
                agregarFila(&cajas[4],auxiliar);

            }

        }

        aBorrar=lista;
        lista=lista->siguiente;
        free(aBorrar);

    }
}
void mostrarFilas(fila cajas[5])
{
    for(int i=0; i<5; i++)
    {
        printf("CAJA %i\n",i+1);
        mostrarListaDoble(cajas[i].primero);
        printf("\n\n");
    }
}
cliente extraerFila(fila*caja,int*totalFacturas,int*cantidadDeClientes)
{
    cliente respuesta;
    respuesta.cantidadFacturas=-1;
    if(caja->primero!=NULL)
    {
        respuesta=verPrimero(caja->primero);
        nodo2* prim;///nodo auxiliar para poder agarrar al cliente
        prim=caja->primero;
        (*totalFacturas)=(*totalFacturas)+(prim->unCliente.cantidadFacturas);
        (*cantidadDeClientes)++;
        caja->primero=borrarPrimero(caja->primero);
        if(caja->primero==NULL)
        {
            caja->ultimo=inicListaDoble();
        }
    }
    return respuesta;
}
cliente verPrimero(nodo2* primero)
{
    cliente respuesta;
    respuesta.cantidadFacturas=-1;
    if(primero!=NULL)
    {
        respuesta=primero->unCliente;
    }
    return respuesta;
}
nodo2*borrarPrimero(nodo2*lista)
{
    nodo2*aBorrar=lista;
    if(lista!=NULL)
    {
        lista=lista->siguiente;
        if(lista!=NULL)
        {
            lista->anterior=NULL;
        }
        free(aBorrar);
    }
    return lista;
}
void persistenciaClientesAtendidos(cliente clienteAtendido)
{
    FILE*fp;
    fp=fopen("clientesAtendidos.bin","ab");
    if(fp!=NULL)
    {
        fwrite(&clienteAtendido,sizeof(cliente),1,fp);
    }
    fclose(fp);
}

nodo1*despercistenciaAtendidos()
{
    nodo1*lista=inicListaSimple();
    cliente clienteAtendido;
    nodo1* nuevoNodo;
    FILE* fp;
    fp=fopen("clientesAtendidos.bin","rb");
    if(fp!=NULL)
    {
        while(fread(&clienteAtendido,sizeof(clienteAtendido),1,fp)>0)
        {
            nuevoNodo=crearNodoSimple(clienteAtendido);
            lista=agregarPrincipioSimple(lista,nuevoNodo);
        }
        fclose(fp);
    }
    return lista;
}







