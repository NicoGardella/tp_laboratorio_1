#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "publicacion.h"

/** \brief informa el mayor cantidad publicaciones activas por cliente
 *
 * \param arrayP Publicacion* es la array como parametro
 * \param limiteP int limite de la array
 * \param arrayC Cliente* array como parametro
 * \param limiteC int limite array
 * \return int -1 error en limite o en la array, 0 ok
 *
 */
int informar_clientesMaxPublicacionesActivas(Publicacion* arrayP,int limiteP, Cliente* arrayC, int limiteC)
{
    int retorno = -1;
    int i;
    int cantPublicaciones=0;
    int max=0;
    if(limiteP > 0 && arrayP != NULL && limiteC > 0 && arrayC != NULL)
    {
        printf("[RELEASE] - ID Cliente -   Nro Cuit   -   Nombre   -     Apellido    - isEmpy \n");
        for(i=0; i<limiteC; i++)
        {
                if(!arrayC[i].isEmpty)
                {
                        cantPublicaciones=publicacion_cantidadPublicacionesPorClienteActivas(arrayP,limiteP,i);
                        if(cantPublicaciones>max)
                        {
                            max=cantPublicaciones;
                        }
                }
        }
        if(max)
        {
            for(i=0; i<limiteC; i++)
            {
                if(!arrayC[i].isEmpty)
                {
                    cantPublicaciones=publicacion_cantidadPublicacionesPorClienteActivas(arrayP,limiteP,i);
                    if(cantPublicaciones==max)
                    {
                        printf("[RELEASE] - %10d - %12s - %10s - %15s - %5d ",arrayC[i].idCliente, arrayC[i].cuit, arrayC[i].nombre,arrayC[i].apellido, arrayC[i].isEmpty);
                        printf("-Publicaciones Activas:%d\n",max);
                    }
                }
            }
            retorno = 0;
        }
        else
        {
            printf("No hay publicaciones Activas...\n");
        }
    }
    return retorno;
}

/** \brief informa la mayor cantidad de publicaciones pausadas
 *
 * \param arrayP Publicacion* es la array como parametro
 * \param limiteP int limite de la array
 * \param arrayC Cliente* array como parametro
 * \param limiteC int limite de la array
 * \return int -1 error en el limite o en la array, 0 ok
 *
 */
int informar_clientesMaxPublicacionesPausadas(Publicacion* arrayP,int limiteP, Cliente* arrayC, int limiteC)
{
    int retorno = -1;
    int i;
    int cantPublicaciones=0;
    int max=0;
    if(limiteP > 0 && arrayP != NULL && limiteC > 0 && arrayC != NULL)
    {
        for(i=0; i<limiteC; i++)
        {
                if(!arrayC[i].isEmpty)
                {
                        cantPublicaciones=publicacion_cantidadPublicacionesPorClientePausadas(arrayP,limiteP,i);
                        if(cantPublicaciones>max)
                        {
                            max=cantPublicaciones;
                        }
                }
        }
        if(max)
        {
            printf("[RELEASE] - ID Cliente -   Nro Cuit   -   Nombre   -     Apellido    - isEmpy \n");
            for(i=0; i<limiteC; i++)
            {
                if(!arrayC[i].isEmpty)
                {
                    cantPublicaciones=publicacion_cantidadPublicacionesPorClientePausadas(arrayP,limiteP,i);
                    if(cantPublicaciones==max)
                    {
                        printf("[RELEASE] - %10d - %12s - %10s - %15s - %5d ",arrayC[i].idCliente, arrayC[i].cuit, arrayC[i].nombre,arrayC[i].apellido, arrayC[i].isEmpty);
                        printf("-Publicaciones pausadas:%d\n",max);
                    }
                }
            }
            retorno = 0;
        }
        else
        {
            printf("No hay publicaciones pausadas...\n");
        }
    }
    return retorno;
}

/** \brief informa maxima publicaciones por clientes
 *
 * \param arrayP Publicacion* array como parametro
 * \param limiteP int limite de la array
 * \param arrayC Cliente* array como parametro
 * \param limiteC int limite de la array
 * \return int -1 error de array o limite, 0 ok
 *
 */
int informar_clientesMaxPublicaciones(Publicacion* arrayP,int limiteP, Cliente* arrayC, int limiteC)
{
    int retorno = -1;
    int i;
    int cantPublicaciones=0;
    int max=0;
    if(limiteP > 0 && arrayP != NULL && limiteC > 0 && arrayC != NULL)
    {
        for(i=0; i<limiteC; i++)
        {
                if(!arrayC[i].isEmpty)
                {
                        cantPublicaciones=publicacion_cantidadPublicacionesPorCliente(arrayP,limiteP,i);
                        if(cantPublicaciones>max)
                        {
                            max=cantPublicaciones;
                        }
                }
        }
        if(max)
        {
            printf("[RELEASE] - ID Cliente -   Nro Cuit   -   Nombre   -     Apellido    - isEmpy \n");
            for(i=0; i<limiteC; i++)
            {
                if(!arrayC[i].isEmpty)
                {
                    cantPublicaciones=publicacion_cantidadPublicacionesPorCliente(arrayP,limiteP,i);
                    if(cantPublicaciones==max)
                    {
                        printf("[RELEASE] - %10d - %12s - %10s - %15s - %5d ",arrayC[i].idCliente, arrayC[i].cuit, arrayC[i].nombre,arrayC[i].apellido, arrayC[i].isEmpty);
                        printf("-Publicaciones:%d\n",max);
                    }
                }
            }
            retorno = 0;
        }
        else
        {
            printf("No hay publicaciones...\n");
        }
    }
    return retorno;
}

/** \brief informa la maxima cantidad de publicaciones por rubro
 *
 * \param arrayP Publicacion* array como parametro
 * \param limiteP int limite de la array
 * \param limiteRubro int limite de rubros
 * \return int -1 error array o limite, 0 ok
 *
 */
int informar_MaxPublicacionesPorRubro(Publicacion* arrayP,int limiteP,int limiteRubro)
{
    int retorno = -1;
    int i;
    int cantPublicacionesRubro=0;
    int max=0;
    if(limiteP > 0 && arrayP != NULL && limiteRubro > 0)
    {
        for(i=0; i<limiteRubro; i++)
        {
                if(!arrayP[i].isEmpty)
                {
                        cantPublicacionesRubro=publicacion_cantidadPublicacionesPorRubroActivas(arrayP,limiteP,i);
                        if(cantPublicacionesRubro>max)
                        {
                            max=cantPublicacionesRubro;
                        }
                }
        }
        if(max)
        {
            for(i=0; i<limiteP; i++)
            {
                if(!arrayP[i].isEmpty)
                {
                    cantPublicacionesRubro=publicacion_cantidadPublicacionesPorRubroActivas(arrayP,limiteP,i);
                    if(cantPublicacionesRubro==max)
                    {
                        printf("Rubro: %d ",arrayP[i].numeroRubro);
                        printf("- Publicaciones activas: %d\n",max);
                    }
                }
            }
            retorno = 0;
        }
        else
        {
            printf("No hay publicaciones en ese rubro...\n");
        }
    }
    return retorno;
}

/** \brief informa la minima cantidad de publicaciones por rubro
 *
 * \param arrayP Publicacion* array como parametro
 * \param limiteP int limite de la array
 * \param limiteRubro int limite de rubros
 * \return int -1 error array o limite, 0 ok
 *
 */
int informar_MinPublicacionesPorRubro(Publicacion* arrayP,int limiteP,int limiteRubro)
{
    int retorno = -1;
    int i;
    int cantPublicacionesRubro=0;
    int max=0;
    int min=32767;
    if(limiteP > 0 && arrayP != NULL && limiteRubro > 0)
    {
        for(i=0; i<limiteRubro; i++)
        {
                if(!arrayP[i].isEmpty)
                {
                        cantPublicacionesRubro=publicacion_cantidadPublicacionesPorRubroActivas(arrayP,limiteP,i);
                        if(cantPublicacionesRubro>max)
                        {
                            max=cantPublicacionesRubro;
                        }
                        if(cantPublicacionesRubro<min && cantPublicacionesRubro>0)
                        {
                            min=cantPublicacionesRubro;
                        }
                }
        }
        if(min>0 && max!=min)
        {
            for(i=0; i<limiteP; i++)
            {
                if(!arrayP[i].isEmpty)
                {
                    cantPublicacionesRubro=publicacion_cantidadPublicacionesPorRubroActivas(arrayP,limiteP,i);
                    if(cantPublicacionesRubro==min)
                    {
                        printf("Rubro: %d ",arrayP[i].numeroRubro);
                        printf("- Publicaciones activas: %d\n",min);
                    }
                }
            }
            retorno = 0;
        }
        else
        {
            printf("No hay publicaciones por rubro...\n");
        }
    }
    return retorno;
}

/** \brief informa las publicaciones por ingreso de rubro
 *
 * \param arrayP Publicacion* array como parametro
 * \param limiteP int limite de la array
 * \param rubro int es el numero del rubro
 * \return int -1 error limite o array, 0 ok
 *
 */
int informar_PublicacionesPorRubro(Publicacion* arrayP,int limiteP,int rubro)
{
    int retorno = -1;
    int cantPublicacionesRubro=0;
    if(limiteP > 0 && arrayP != NULL)
    {
        cantPublicacionesRubro=publicacion_cantidadPublicacionesPorRubroActivas(arrayP,limiteP,rubro);
        if(cantPublicacionesRubro>0)
        {
            printf("Rubro: %d ",arrayP[rubro].numeroRubro);
            printf("- Publicaciones activas: %d\n",cantPublicacionesRubro);
            retorno = 0;
        }
        else
        {
            printf("Este rubro no tiene publicaciones...\n");
        }
        retorno=0;
    }
    return retorno;
}
