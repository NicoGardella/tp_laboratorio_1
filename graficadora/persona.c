#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "persona.h"
#include "utn.h"



//Funciones privadas



//__________________



/** \brief
 * \param array Persona*
 * \param limite int
 * \return int
 *
 */
int persona_init(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int persona_mostrarDebug(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG]  -Nombre: %s -Dni: %d -Edad: %d -IsEmpty: %d\n", array[i].nombre, array[i].dni, array[i].edad, array[i].isEmpty);
        }
    }
    return retorno;
}
int persona_mostrar(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("Numero: %d -Nombre: %s -Dni: %d -Edad: %d \n",i, array[i].nombre, array[i].dni, array[i].edad);

        }
    }
    return retorno;
}

int persona_alta(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    int dni;
    int edad;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);

        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 50",nombre,50,2))
            {
                if(!getValidInt("\nEdad? ","\nEso no es edad",&edad,1,100,4))
                {
                    if(!getValidInt("\nDni? ","\nEso no es un dni",&dni,18000000,90000000,4))
                    {
                            retorno = 0;
                            strcpy(array[i].nombre,nombre);
                            array[i].dni=dni;
                            array[i].edad=edad;

                            //------------------------------
                            //------------------------------

                            array[i].isEmpty = 0;
                    }
                }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}

int persona_altaForzada(Persona* array,int limite, char nombre[50], int dni, int edad)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {

                            retorno = 0;
                            strcpy(array[i].nombre,nombre);
                            array[i].dni=dni;
                            array[i].edad=edad;

                            //------------------------------
                            //------------------------------

                            array[i].isEmpty = 0;


        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int persona_baja(Persona* array,int limite, int id)
{

    int retorno=-1;
    id = getInt("Ingrese numero de persona a borrar\n");

    if(id>=0 && array[id].isEmpty==0)
    {
        array[id].isEmpty=1;
        retorno=0;
    }
    return retorno;
}







int persona_ordenar(Persona* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Persona auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int buscarLugarLibre(Persona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int obtenerCantidad(Persona* array,int limite, int edadHasta, int edadDesde)
{
    int i;
    int contador = 0;
    for(i=0;i<limite;i++)
    {
        if(array[i].edad<=edadHasta && array[i].edad>=edadDesde)
        {
            contador++;
        }
    }
    return contador;
}

int persona_graficoEdades(Persona* array,int limite)
{
    int menores, medianos, grandes,maximo;
    menores = obtenerCantidad(array,limite,18,0);
    medianos = obtenerCantidad(array,limite,35,19);
    grandes = obtenerCantidad(array,limite,200,35);
    maximo = menores;
    char cMenor;
    char cMediano;
    char cGrandes;
    if (menores < medianos)
    {
        maximo = medianos;
    }

    if (maximo < grandes)
    {
        maximo = grandes;
    }
    while(maximo)
    {
        if(grandes>= maximo)
            cGrandes='*';
        else
            cGrandes=' ';
        if(medianos>= maximo)
            cMediano='*';
        else
            cMediano=' ';
        if(menores>= maximo)
            cMenor='*';
        else
            cMenor=' ';


        printf("%c \t %c \t %c \t\n",cMenor,cMediano,cGrandes);
        maximo--;
    }
    printf("<18 \t 19-35 \t >35 \t\n");
}
















