#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "publicacion.h"
#define OCUPADO 0
#define LIBRE 1


//Funciones privadas
static int buscarLugarLibre(Cliente* arrayC,int limite);
static int proximoId(void);
static int buscarLugarLibre(Cliente* arrayC,int limite);
//__________________
static int buscarLugarLibre(Cliente* arrayC, int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayC[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


static int buscarPorId(Cliente* arrayC,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty && arrayC[i].idCliente==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


/** \brief
 * \param arrayC Publicacion*
 * \param limite int
 * \return int
 *
 */
int cliente_init(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayC[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief muestra array de clientes sea isEmpy 0 o 1
 *
 * \param arrayC Cliente* array como parametro
 * \param limite int limite de la array
 * \return int -1 error limite o array, 0 ok
 *
 */
int cliente_mostrarDebug(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty)
                printf("[DEBUG] - %10d - %12s - %10s - %15s - %5d\n",arrayC[i].idCliente, arrayC[i].cuit, arrayC[i].nombre,arrayC[i].apellido, arrayC[i].isEmpty);
        }
    }
    return retorno;
}

/** \brief muestra array
 *
 * \param arrayC Cliente* es la array como parametro
 * \param limite int es el limite de la array
 * \return int -1 error en limite o en array 0 ok
 *
 */
int cliente_mostrar(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        printf("[RELEASE] - ID Cliente -   Nro Cuit   -   Nombre   -     Apellido    - isEmpy \n");
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty)
                printf("[RELEASE] - %10d - %12s - %10s - %15s - %5d\n",arrayC[i].idCliente, arrayC[i].cuit, arrayC[i].nombre,arrayC[i].apellido, arrayC[i].isEmpty);
        }
    }
    return retorno;
}

/** \brief muestra un cliente segun su id
 *
 * \param arrayC Cliente* es la array como parametro
 * \param limite int es el limite de la array
 * \param id int es el id como parametro
 * \return int -1 error en limite o en la array 0 ok
 *
 */
int cliente_mostrarUno(Cliente* arrayC,int limite, int id)
{
    int retorno = -1;
    int i=id;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        printf("[RELEASE] - ID Cliente -   Nro Cuit   -   Nombre   -     Apellido    - isEmpy \n");
        if(!arrayC[i].isEmpty)
        {
            printf("[RELEASE] - %10d - %12s - %10s - %15s - %5d\n",arrayC[i].idCliente, arrayC[i].cuit, arrayC[i].nombre,arrayC[i].apellido, arrayC[i].isEmpty);
        }
    }
    return retorno;
}

/** \brief imprime cantidad de publicaciones activas por cliente
 *
 * \param arrayC Cliente* es la array como parametro
 * \param limiteC int es el limite de la array
 * \param arrayP Publicacion* array como parametro
 * \param limiteP int es el limite de la array
 * \return int -1 error en las array o en los limites de las mismas 0 ok
 *
 */
int cliente_imprimirClienteCantidadPublicacionesActivas(Cliente* arrayC,int limiteC,Publicacion* arrayP, int limiteP)
{
    int retorno = -1;
    int i;
    int indexC;
    int cantPublicaciones=0;
    if(limiteP > 0 && arrayP != NULL && limiteC > 0 && arrayC != NULL)
    {
        printf("[RELEASE] - ID Cliente -   Nro Cuit   -   Nombre   -     Apellido    - isEmpy \n");
        for(i=0; i<limiteC; i++)
        {
            indexC=i;
                if(!arrayC[i].isEmpty)
                {
                        cantPublicaciones=publicacion_cantidadPublicacionesPorClienteActivas(arrayP,limiteP,indexC);
                        printf("[RELEASE] - %10d - %12s - %10s - %15s - %5d ",arrayC[i].idCliente, arrayC[i].cuit, arrayC[i].nombre,arrayC[i].apellido, arrayC[i].isEmpty);
                        printf("-Publicaciones Activas: %d\n",cantPublicaciones);
                    }
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief da de alta un cliente
 *
 * \param arrayC Cliente* es la array como parametro
 * \param limite int es el limite de la array
 * \return int -1 error en la array o en el limite de la misma, -2 si no hay lugar libre, 0 ok
 *
 */
int cliente_alta(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    char cuit[50];
      if(limite > 0 && arrayC != NULL)
        {
            i = buscarLugarLibre(arrayC,limite);
            if(i >= 0)
            {
                if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 50",nombre,50,2))
                {
                    if(!getValidString("\nApellido? ","\nEso no es un apellido","El maximo es 40",apellido,50,2))
                    {
                            if(!getValidStringCuit("\nCuit? ","\nEso no es un cuit","El maximo es 40",cuit,99999999999,2))
                            {
                                retorno = 0;
                                strcpy(arrayC[i].nombre,nombre);
                                strcpy(arrayC[i].apellido,apellido);
                                strcpy(arrayC[i].cuit,cuit);
                                arrayC[i].idCliente = proximoId();
                                arrayC[i].isEmpty = 0;
                                printf("[RELEASE] - ID Cliente -   Nro Cuit   -   Nombre   -     Apellido    - isEmpy \n");
                                printf("[RELEASE] - %10d - %12s - %10s - %15s - %5d\n",arrayC[i].idCliente, arrayC[i].cuit,
                                       arrayC[i].nombre,arrayC[i].apellido, arrayC[i].isEmpty);
                            }
                        }
                    }
            }
            else
            {
                retorno = -2;
            }
        }
    return retorno;
}

/** \brief modificas datos de un cliente
 *
 * \param arrayC Cliente* es la array como parametro
 * \param limite int es el limite de la array
 * \param id int es el indice como parametro para buscar datos a modificar
 * \return int -1 error limite o array, -2 no encuentra id, 0 ok
 *
 */
int cliente_modificacion(Cliente* arrayC,int limite, int id)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    char cuit[50];

    i = buscarPorId(arrayC,limite,id);
    if(i>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 50",nombre,50,2))
            {
                if(!getValidString("\nApellido? ","\nEso no es un apellido","El maximo es 40",apellido,50,2))
                {
                    if(!getValidStringCuit("\nCuit? ","\nEso no es un cuit","El maximo es 40",cuit,99999999999,2))
                    {
                        retorno = 0;
                        strcpy(arrayC[i].nombre,nombre);
                        strcpy(arrayC[i].apellido,apellido);
                        strcpy(arrayC[i].cuit,cuit);
                    }
                }
            }
    }
    else
    {
        printf("No esta ID cliente...");
        retorno = -2;
    }
    return retorno;
}

/** \brief realiza la baja de un cliente
 *
 * \param arrayC Cliente* es la array como parametro
 * \param limite int es el limite de la array
 * \param id int es el id como parametro para la baja
 * \return int -1 error de limite o de la array, 0 ok
 *
 */
int cliente_baja(Cliente* arrayC,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = buscarPorId(arrayC,limite,id);
    if(indiceAEliminar>=0)
    {
        arrayC[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

/** \brief busca en la array por id
 *
 * \param arrayC Cliente* es la array como parametro
 * \param limite int es el limite de la array
 * \param id int es el id como parametro para la busqueda
 * \return int -1 error en el indice, -2 error en la array o en el limite, 0 ok
 *
 */
int cliente_buscarPorId(Cliente* arrayC,int limite, int id)
{
    int retorno = -1;
    int i;
    int indice;
    indice= buscarPorId(arrayC,limite,id);
    if(indice>=0)
    {
        retorno=-2;
        if(limite > 0 && arrayC != NULL)
        {
            retorno = -3;
            for(i=0;i<limite;i++)
            {
                if(arrayC[i].isEmpty == OCUPADO && arrayC[i].idCliente == id)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    else
    {
        printf("Error! no existe id\n");
    }
    return retorno;
}

/** \brief fuerza el alta de un clientes con datos harcodeados
 *
 * \param arrayC Cliente* es la array como parametro
 * \param limite int limite de la array como parametro
 * \param nombre char* variable de entrada nombre
 * \param apellido char* variable de entrada apellido
 * \param cuit char* variable cuit de entrada
 * \return int -1 error de limite o array, -2 no hay lugar libre, 0 ok
 *
 */
int cliente_altaForzada(Cliente* arrayC,int limite,char* nombre, char* apellido,char* cuit)
{
    int retorno = -1;
    int i;
   // int posPant;
    if(limite > 0 && arrayC != NULL)
    {
        retorno=-2;
        i = buscarLugarLibre(arrayC,limite);
        if(i >= 0)
        {
            strcpy(arrayC[i].nombre,nombre);
            strcpy(arrayC[i].apellido,apellido);
            strcpy(arrayC[i].cuit,cuit);
            //------------------------------
            arrayC[i].idCliente = proximoId();
            arrayC[i].isEmpty = OCUPADO;
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief ordena clientes por cuit
 *
 * \param arrayC Cliente* array como parametro
 * \param limite int limite de la array
 * \param orden int 0 ascendente, 1 descendente
 * \return int -1 error array o de limite, 0 ok
 *
 */
int cliente_ordenarCuit(Cliente* arrayC,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Cliente auxiliarEstructura;
    if(limite > 0 && arrayC != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!arrayC[i].isEmpty && !arrayC[i+1].isEmpty)
                {
                    if((strcmp(arrayC[i].cuit,arrayC[i+1].cuit) > 0 && orden) || (strcmp(arrayC[i].cuit,arrayC[i+1].cuit) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = arrayC[i];
                        arrayC[i] = arrayC[i+1];
                        arrayC[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

/** \brief ordena clientes por id
 *
 * \param arrayC Cliente* array como parametro
 * \param limite int limite de la array
 * \param orden int 0 ascendente, 1 descendente
 * \return int -1 error array o de limite, 0 ok
 *
 */
int cliente_ordenar(Cliente* arrayC,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Cliente auxiliarEstructura;

    if(limite > 0 && arrayC != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!arrayC[i].isEmpty && !arrayC[i+1].isEmpty)
                {
                    if(((arrayC[i].idCliente > arrayC[i+1].idCliente) && orden) || ((arrayC[i].idCliente < arrayC[i+1].idCliente) && !orden)) //******
                    {
                        auxiliarEstructura = arrayC[i];
                        arrayC[i] = arrayC[i+1];
                        arrayC[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

