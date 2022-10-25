#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lista2.h"
#include "listaSimple.h"
#include "filas.h"
#include <stdbool.h>
#define CANT_CAJAS 5
cliente cargaCliente();
int main()
{
    nodo1*listaSimple=inicListaSimple();
    cliente nuevoCliente;
    nodo1*nuevoNodoSimple;
    nodo1*listaAtendidos=inicListaSimple();
    cliente clienteAtendido;
    srand(time(NULL));
    char cajero1[100]="claudia";
    char cajero2[100]="juan";
    char cajero3[100]="jorge";
    char cajero4[100]="eduardo";
    char cajero5[100]="pepe";
    char tipo1[100]="regular";
    char tipo2[100]="jubilado";
    char tipo3[100]="persona gestante";
    char tipo4[100]="empresario";
    int cantidadPrimero[CANT_CAJAS];
    int cantidadUltimo[CANT_CAJAS];
    cliente primero;///para calcular los tiempos de espera
    int menorPromedio=0;
    nodo2*ultimo;
    int tiempoEspera[CANT_CAJAS];
    float esperaPromedio[CANT_CAJAS];
    fila cajas[CANT_CAJAS];
    inicFila(&cajas[0]);
    inicFila(&cajas[1]);
    inicFila(&cajas[2]);
    inicFila(&cajas[3]);
    inicFila(&cajas[4]);
    for(int i=0; i<CANT_CAJAS; i++)
    {

        cajas[i].numeroFila=i;
        switch(i)
        {
        case 1:
            strcpy(cajas[i].nombreCajero,cajero1);
            break;
        case 2:
            strcpy(cajas[i].nombreCajero,cajero2);
            break;
        case 3:
            strcpy(cajas[i].nombreCajero,cajero3);
            break;
        case 4:
            strcpy(cajas[i].nombreCajero,cajero4);
            break;
        case 5:
            strcpy(cajas[i].nombreCajero,cajero5);
            break;
        }
    }
    ///para estadisticas
    int cantidadClientes[CANT_CAJAS];///por cada fila/caja
    int cantidadFacturas[CANT_CAJAS];///por cada fila/caja


    for(int i=0;i<CANT_CAJAS;i++)
    {
        cantidadClientes[i]=0;
        cantidadFacturas[i]=0;
        tiempoEspera[i]=0;
        esperaPromedio[i]=0;
        cantidadPrimero[i]=0;
        cantidadUltimo[i]=0;

    }


    float promedio[CANT_CAJAS];

    int option=0;

    while(true)
    {
        printf("MENU\n");
        printf("1.entrar nuevos clientes \n");
        printf("2.acomodar en cajas\n");
        printf("3.ver cajas\n");
        printf("4.atender a los clientes\n");
        printf("5.ver archivo de clientes atendidos\n");
        printf("6.ver las estadisticas\n");
        scanf("%i",&option);

        switch (option)
        {
        case 1:
            for(int i=0; i<40; i++)
            {
                nuevoCliente=cargaCliente();
                nuevoNodoSimple=crearNodoSimple(nuevoCliente);
                listaSimple=agregarPrincipioSimple(listaSimple,nuevoNodoSimple);
            }
            system ("pause");
            system ("cls");
            break;
        case 2:

            cargarLista(cajas,listaSimple);
            system ("pause");
            system ("cls");
            break;
        case 3:
            mostrarFilas(cajas);
            system ("pause");
            system ("cls");
            break;
        case 4:
            for(int i=0;i<CANT_CAJAS;i++)
    {
        cantidadClientes[i]=0;
        cantidadFacturas[i]=0;
        tiempoEspera[i]=0;
        esperaPromedio[i]=0;
        cantidadPrimero[i]=0;
        cantidadUltimo[i]=0;

    }

            for(int i=0; i<CANT_CAJAS; i++)
            {
                primero=verPrimero(cajas[i].primero);
                cantidadPrimero[i]=primero.cantidadFacturas;
                ultimo=buscarUltimo(cajas[i].primero);
                cantidadUltimo[i]=ultimo->unCliente.cantidadFacturas;
                while(cajas[i].primero!=NULL)
                {
                    clienteAtendido=extraerFila(&cajas[i],&cantidadFacturas[i],&cantidadClientes[i]);
                    persistenciaClientesAtendidos(clienteAtendido);
                }
            }
            system ("pause");
            system ("cls");
            break;
        case 5:
            listaAtendidos=despercistenciaAtendidos();
            mostrarListaSimple(listaAtendidos);
            system ("pause");
            system ("cls");
            break;
        case 6:
            for(int i=0; i<CANT_CAJAS; i++)
            {
                promedio[i]=(float)cantidadFacturas[i]/(float)cantidadClientes[i];
                printf("promedio de facturas por cliente de caja %i es: %.4f\n",i+1,promedio[i]);
                tiempoEspera[i]=cantidadFacturas[i]-cantidadPrimero[i]-cantidadUltimo[i];

            }
            printf("\n\n");
            for(int i=0;i<CANT_CAJAS;i++)
            {
                esperaPromedio[i]=(float)tiempoEspera[i]/(float)cantidadClientes[i];
                printf("la espera promedio de la caja %i es de: %.4f\n",i+1,esperaPromedio[i]);
            }
            menorPromedio=buscarMenos(esperaPromedio);
            printf("el el de menor promedio de espera es la caja %i\n",menorPromedio+1);

            system ("pause");
            system ("cls");
            break;

        }

    }







    return 0;
}
cliente cargaCliente()///carga de clientes ramdom
{
    cliente nuevoCliente;

    int numero=rand()%4;
    int cantFacturas=rand()%20+1;
    char tipo1[100]="regular";
    char tipo2[100]="jubilado";
    char tipo3[100]="persona gestante";
    char tipo4[100]="empresario";
    nuevoCliente.cantidadFacturas=cantFacturas;

    switch(numero)
    {
    case 0:
        strcpy(nuevoCliente.tipo,tipo1);
        break;
    case 1:
        strcpy(nuevoCliente.tipo,tipo2);
        break;
    case 2:
        strcpy(nuevoCliente.tipo,tipo3);
        break;
    case 3:
        strcpy(nuevoCliente.tipo,tipo4);
        break;

    }

    return nuevoCliente;

}
int buscarMenos(float promedios[4])
{
    float menor=promedios[4];
    int posMenor=0;
    for(int i=0;i<4;i++)
    {
        if(promedios[i]<menor)
        {
            menor=promedios[i];
            posMenor=i;
        }
    }
    return posMenor;
}
