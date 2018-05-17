#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "publicacion.h"
#define ACTIVA 1
#define PAUSADA 0
#define DEFINE_DEL_ARCHIVO  "hola"

//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Publicacion* arrayP,int limite);
//__________________

static int buscarLugarLibre(Publicacion* arrayP,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayP[i].isEmpty==1)
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

/** \brief inicializa la array pone un 1 en el isEmpy para declarar la array libre para carga de datos
 * \param arrayP Publicacion* array como parametro
 * \param limite int limite de la array
 * \return int -1 error de limite o array, 0 ok
 *
 */
int publicacion_init(Publicacion* arrayP,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayP[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief imprime array de publicaciones este isEmpy en 0 o en 1
 *
 * \param arrayP Publicacion* array como parametro
 * \param limite int limite de la array
 * \return int -1 error de limite o array, 0 ok
 *
 */
int publicacion_mostrarDebug(Publicacion* arrayP,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
                printf("[DEBUG] - %10d - %7d -%30s- %6d - %10d - %2d\n",arrayP[i].idPublicacion, arrayP[i].numeroRubro,
                   arrayP[i].textoAviso,arrayP[i].estado,arrayP[i].idCliente, arrayP[i].isEmpty);
        }
    }
    return retorno;
}

/** \brief imprime publicaciones que esten activas isEmpy 0
 *
 * \param arrayP Publicacion* array como parametro
 * \param limite int limite de la array
 * \return int -1 error de limite o array, 0 ok
 *
 */
int publicacion_mostrar(Publicacion* arrayP,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        retorno = 0;
        printf("[RELEASE] -ID Publicacion-Nro rubro-         Texto aviso        - Estado -ID cliente  - isEmpy \n");
        for(i=0;i<limite;i++)
        {
            if(!arrayP[i].isEmpty)
                printf("[RELEASE] - %10d - %7d -%30s- %6d - %10d - %2d\n",arrayP[i].idPublicacion, arrayP[i].numeroRubro,
                   arrayP[i].textoAviso,arrayP[i].estado,arrayP[i].idCliente, arrayP[i].isEmpty);
        }
    }
    return retorno;
}
/** \brief imprime publicaciones que esten activas isEmpy 0 por medio de in id
 *
 * \param arrayP Publicacion* array como parametro
 * \param limite int limite de la array
 * \param id int id como parametro de busqueda
 * \return int -1 error de limite o array, 0 ok
 *
 */
int publicacion_mostrarUno(Publicacion* arrayP,int limite, int id)
{
    int retorno = -1;
    int i=id;
    if(limite > 0 && arrayP != NULL)
    {
        retorno = 0;
        printf("[RELEASE] -ID Publicacion-Nro rubro-         Texto aviso        - Estado -ID cliente  - isEmpy \n");

        if(!arrayP[i].isEmpty)
        {
            printf("[RELEASE] - %10d - %7d -%30s- %6d - %10d - %2d\n",arrayP[i].idPublicacion, arrayP[i].numeroRubro,
               arrayP[i].textoAviso,arrayP[i].estado,arrayP[i].idCliente, arrayP[i].isEmpty);
        }
    }
    return retorno;
}

/** \brief imprime las publicaciones y le agrega el cuit cliente
 *
 * \param arrayP Publicacion* array como parametro
 * \param limiteP int limite de la array
 * \param arrayC Cliente* array como parametro
 * \param limiteC int limite de la array
 * \return int -1 error de limite o array, 0 ok
 *
 */
int publicacion_imprimirPublicacionesCuit(Publicacion* arrayP, int limiteP, Cliente* arrayC, int limiteC)
{
    int retorno = -1;
    int i;
    int indexC;
    char auxCuit[1024];
    if(limiteP > 0 && arrayP != NULL && limiteC > 0 && arrayC != NULL)
    {
         retorno = 0;
         printf("[RELEASE] -ID Publicacion-Nro rubro-         Texto aviso        - Estado -ID cliente  - isEmpy \n");
        for(i=0; i<limiteC; i++)
        {
                if(!arrayP[i].isEmpty && arrayP[i].estado==ACTIVA)
                {
                        indexC=cliente_buscarPorId(arrayC,limiteC,arrayP[i].idCliente);
                        strcpy(auxCuit,arrayC[indexC].cuit);
                        printf("[RELEASE] - %10d - %7d -%30s- %6d - %10d - %2d ",arrayP[i].idPublicacion, arrayP[i].numeroRubro,
                                arrayP[i].textoAviso,arrayP[i].estado,arrayP[i].idCliente, arrayP[i].isEmpty);
                        printf("-Cuit: %s\n",auxCuit);
                    }
        }
    }
    return retorno;
}

/** \brief da de alta una publicacion
 *
 * \param arrayP Publicacion* array como parametro
 * \param limite int limite de la array
 * \param id int id para buscar cliente
 * \return int -1 error de limite o array, -2 no hay lugar libre, -3 0 ok
 *
 */
int publicacion_alta(Publicacion* arrayP,int limite, int id)
{
    int retorno = -1;
    int i;
    int numeroRubro;
    char textoAviso[64];
    if(limite > 0 && arrayP != NULL)
    {
        i = buscarLugarLibre(arrayP,limite);
        if(i >= 0)
        {
            if(!getValidInt("\nNumero rubro? ","\nEso no es un numero",&numeroRubro,0,100,2))
            {
                if(!getValidString("\nTexto del aviso? ","\nError","El maximo es 63 caracteres",textoAviso,63,2))
                {
                            retorno = 0;
                            arrayP[i].numeroRubro=numeroRubro;
                            strcpy(arrayP[i].textoAviso,textoAviso);
                            arrayP[i].estado = ACTIVA;
                            arrayP[i].idCliente = id;
                            //------------------------------
                            //------------------------------
                            arrayP[i].idPublicacion = proximoId();
                            arrayP[i].isEmpty = 0;
                            printf("[RELEASE] -ID Publicacion-Nro rubro-           Texto aviso        - Estado -ID cliente  - isEmpy \n");
                             printf("[RELEASE] - %12d - %7d -%30s- %6d - %10d - %2d\n",arrayP[i].idPublicacion, arrayP[i].numeroRubro,
                                    arrayP[i].textoAviso,arrayP[i].estado,arrayP[i].idCliente, arrayP[i].isEmpty);

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

/** \brief da de baja una publicacion con id cliente
 *
 * \param arrayP Publicacion* array como dato
 * \param limite int limite array
 * \param id int id del cliente a dar de baja
 * \return int -1 error limite o array, 0 ok
 *
 */
int publicacion_baja(Publicacion* arrayP,int limite, int id)
{
    int retorno=-1;
    int i;
    if(id>=0)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            if(arrayP[i].idCliente==id)
            {
                arrayP[i].isEmpty=1;
            }
        }
    }
    return retorno;
}

/** \brief ordena publicaciones
 *
 * \param arrayP Publicacion* array como parametro
 * \param limite int limite de la array
 * \param orden int 0 ascendente, 1 descendente
 * \return int -1 error de array o limite, 0 ok
 *
 */
int publicacion_ordenar(Publicacion* arrayP,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicacion auxiliarEstructura;
    if(limite > 0 && arrayP != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!arrayP[i].isEmpty && !arrayP[i+1].isEmpty)
                {
                    if(((arrayP[i].idCliente > arrayP[i+1].idCliente) && orden) || ((arrayP[i].idCliente < arrayP[i+1].idCliente) && !orden)) //******
                    {
                        auxiliarEstructura = arrayP[i];
                        arrayP[i] = arrayP[i+1];
                        arrayP[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

/** \brief busca una publicacion por id
 *
 * \param arrayP Publicacion* array como parametro
 * \param limite int limite de la array
 * \param id int id donde busca publicacion
 * \return int -1 error de array o limite, i= id de la publicacion Ok
 *
 */
int publicacion_buscarPorId(Publicacion* arrayP,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayP[i].isEmpty && arrayP[i].idPublicacion==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief busca id publicacion por id cliente
 *
 * \param arrayP Publicacion* array como parametro
 * \param limite int limite de la array
 * \param id int cliente a pasar
 * \return int -1 error de array o limite, -2 id de cliente no existe, 0 ok
 *
 */
int publicacion_buscarPorIdCliente(Publicacion* arrayP,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        retorno=0;
        printf("[RELEASE] -ID Publicacion-Nro rubro-         Texto aviso        - Estado -ID cliente  - isEmpy \n");
        for(i=0;i<limite;i++)
        {
            if(!arrayP[i].isEmpty && arrayP[i].idCliente==id)
            {
                printf("[RELEASE] - %10d - %7d -%30s- %6d - %10d - %2d\n",arrayP[i].idPublicacion, arrayP[i].numeroRubro,
                   arrayP[i].textoAviso,arrayP[i].estado,arrayP[i].idCliente, arrayP[i].isEmpty);
            }
            else
            {
                retorno=-2;
            }
        }
    }
    return retorno;
}

/** \brief fuerza alta de publicaciones por harcodeado
 *
 * \param arrayP Publicacion* array como parametro
 * \param limite int limite de array
 * \param idCliente int id cliente pertenece publicacion
 * \param rubro int numero de rubro
 * \param textoAviso char* texto del aviso
 * \return int -1 error de array o limite, 0 ok
 *
 */
int publicacion_altaForzada(Publicacion* arrayP,int limite, int idCliente, int rubro, char* textoAviso)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        i = buscarLugarLibre(arrayP,limite);
        if(i >= 0)
        {
            retorno = 0;
            arrayP[i].idCliente=idCliente;
            strcpy(arrayP[i].textoAviso,textoAviso);
            arrayP[i].numeroRubro = rubro;
            arrayP[i].estado = ACTIVA;
            arrayP[i].idPublicacion = proximoId();
            arrayP[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief muestra la cantidad de publicaciones por clientes activas
 *
 * \param arrayP Publicacion* array como parametro
 * \param limite int limite de la array
 * \param idCliente int id del cliente
 * \return int -1 error limite o array, >0 devuelve cantidad de publicaciones
 *
 */
int publicacion_cantidadPublicacionesPorClienteActivas(Publicacion* arrayP, int limite, int idCliente)
{
    int retorno = -1;
    int i;
    int cantPublicaciones=0;
    if(limite > 0 && arrayP != NULL )
    {
        for(i=0; i<limite; i++)
        {
                if(!arrayP[i].isEmpty)
                {
                    if(!arrayP[i].isEmpty && arrayP[i].idCliente==idCliente && arrayP[i].estado==ACTIVA)
                    {
                       cantPublicaciones++;
                    }
                }
        }
        retorno = cantPublicaciones;
    }
    return retorno;
}

/** \brief muestra la cantidad de publicaciones por clientes pausadas
 *
 * \param arrayP Publicacion* array como parametro
 * \param limite int limite de la array
 * \param idCliente int id del cliente
 * \return int -1 error limite o array, >0 devuelve cantidad de publicaciones
 *
 */
int publicacion_cantidadPublicacionesPorClientePausadas(Publicacion* arrayP, int limite, int idCliente)
{
    int retorno = -1;
    int i;
    int cantPublicaciones=0;
    if(limite > 0 && arrayP != NULL )
    {
        for(i=0; i<limite; i++)
        {
                if(!arrayP[i].isEmpty)
                {
                    if(!arrayP[i].isEmpty && arrayP[i].idCliente==idCliente && arrayP[i].estado==PAUSADA)
                    {
                       cantPublicaciones++;
                    }
                }
        }
        retorno = cantPublicaciones;
    }
    return retorno;
}
/** \brief muestra la cantidad de publicaciones por cliente
 *
 * \param arrayP Publicacion* array como parametro
 * \param limite int limite de la array
 * \param idCliente int id del cliente
 * \return int -1 error limite o array, >0 devuelve cantidad de publicaciones
 *
 */
int publicacion_cantidadPublicacionesPorCliente(Publicacion* arrayP, int limite, int idCliente)
{
    int retorno = -1;
    int i;
    int cantPublicaciones=0;
    if(limite > 0 && arrayP != NULL )
    {
        for(i=0; i<limite; i++)
        {
                if(!arrayP[i].isEmpty)
                {
                    if(!arrayP[i].isEmpty && arrayP[i].idCliente==idCliente)
                    {
                       cantPublicaciones++;
                    }
                }
        }
        retorno = cantPublicaciones;
    }
    return retorno;
}
/** \brief muestra la cantidad de publicaciones por rubro que estan activas
 *
 * \param arrayP Publicacion* array como parametro
 * \param limite int limite de la array
 * \param rubro int rubro como indice
 * \return int -1 error limite o array, >0 devuelve cantidad de publicaciones
 *
 */
int publicacion_cantidadPublicacionesPorRubroActivas(Publicacion* arrayP, int limite, int rubro)
{
    int retorno = -1;
    int i;
    int cantPublicaciones=0;

    if(limite > 0 && arrayP != NULL )
    {
        for(i=0; i<limite; i++)
        {
                if(!arrayP[i].isEmpty)
                {
                    if(!arrayP[i].isEmpty && arrayP[i].numeroRubro==rubro && arrayP[i].estado==ACTIVA)
                    {
                       cantPublicaciones++;
                    }
                }
        }
        retorno = cantPublicaciones;
    }
    return retorno;
}

