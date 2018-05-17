#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "utn.h"
#include "Cliente.h"
#include "informar.h"
#define QTY_CLIENTE 100
#define LEN_PUBLICACION 1000
#define CANT_RUBROS 10
#define ACTIVA 1
#define PAUSADA 0


int main()
{
    Publicacion arrayP[LEN_PUBLICACION];
    Cliente arrayC[QTY_CLIENTE];
    int menu;
    int auxiliarId;
    int indice;
    int indiceC;
    char seguir='n';
    publicacion_init(arrayP,LEN_PUBLICACION);
    cliente_init(arrayC,QTY_CLIENTE);

    cliente_altaForzada(arrayC,QTY_CLIENTE,"Cacho","Perez","20345677891");
    cliente_altaForzada(arrayC,QTY_CLIENTE,"Alfredo","Carlone","20345677892");
    cliente_altaForzada(arrayC,QTY_CLIENTE,"Oscar","Sidero","20345677893");
    cliente_altaForzada(arrayC,QTY_CLIENTE,"Zafira","Aguilar","20345677895");

    publicacion_altaForzada(arrayP,LEN_PUBLICACION,0,0,"colchon de 1 plaza");
    publicacion_altaForzada(arrayP,LEN_PUBLICACION,0,1,"colchon de 2 plazas");
    publicacion_altaForzada(arrayP,LEN_PUBLICACION,1,2,"cama de 1 plaza");
    publicacion_altaForzada(arrayP,LEN_PUBLICACION,1,0,"cama de 2 plazas");
    publicacion_altaForzada(arrayP,LEN_PUBLICACION,1,1,"sabanas de 1 plaza");
    publicacion_altaForzada(arrayP,LEN_PUBLICACION,2,2,"sabanas de 2 plazas");

    do
    {
        getValidInt("\n\n1.Alta\n2.Modificar\n3.Baja\n4.Publicar\n5.Pausar publicacion\n6.Reanudar publicacion\n7.Imprimir clientes\n8.Imprimir publicaciones\n9.Informar clientes\n10.Informar publicaciones\n11.Salir\n","\nNo valida\n",&menu,1,11,1);
        switch(menu)
        {
            case 1:
                printf("Alta Cliente:\n");
                cliente_alta(arrayC,QTY_CLIENTE);
                break;
            case 2:
                printf("Modificar Cliente:\n");
                cliente_mostrar(arrayC,QTY_CLIENTE);
                getValidInt("ID Cliente?","\nNumero valida\n",&auxiliarId,0,QTY_CLIENTE,2);
                cliente_modificacion(arrayC,QTY_CLIENTE,auxiliarId);
                cliente_mostrarUno(arrayC,QTY_CLIENTE, auxiliarId);
                break;
            case 3:
                printf("Baja Cliente:\n");
                cliente_mostrar(arrayC,QTY_CLIENTE);
                getValidInt("ID Cliente?","\nNumero valida\n",&auxiliarId,0,QTY_CLIENTE,2);
                indice=cliente_buscarPorId(arrayC,QTY_CLIENTE,auxiliarId);
                if(indice>=0)
                {
                    publicacion_buscarPorIdCliente(arrayP,LEN_PUBLICACION,indice);
                    seguir=getChar("Confirma dar de baja presione s:");
                   if(seguir=='s')
                    {
                      cliente_baja(arrayC,QTY_CLIENTE,indice);
                      publicacion_baja(arrayP,LEN_PUBLICACION,indice);
                      seguir='n';
                    }
                }
                break;
            case 4:
                printf("Alta publicacion:\n");
                cliente_mostrar(arrayC,QTY_CLIENTE);
                getValidInt("ID Cliente?","\nNumero valida\n",&auxiliarId,0,QTY_CLIENTE,2);
                indice=cliente_buscarPorId(arrayC,QTY_CLIENTE,auxiliarId);
                if(indice>=0)
                {
                    publicacion_alta(arrayP,LEN_PUBLICACION,indice);
                }
                break;
            case 5:
                printf("Pausar publicacion:\n");
                publicacion_mostrar(arrayP,LEN_PUBLICACION);
                getValidInt("ID Publicacion?","\nNumero valida\n",&auxiliarId,0,LEN_PUBLICACION,2);
                indice=publicacion_buscarPorId(arrayP,LEN_PUBLICACION,auxiliarId);
                if(indice>=0)
                {
                    auxiliarId=arrayP[indice].idCliente;
                    indiceC=cliente_buscarPorId(arrayC,QTY_CLIENTE,auxiliarId);
                    cliente_mostrarUno(arrayC,QTY_CLIENTE, indiceC);
                    seguir=getChar("Confirma pausar publicacion presione s:");
                   if(seguir=='s')
                    {
                      arrayP[indice].estado=PAUSADA;
                      publicacion_mostrarUno(arrayP,LEN_PUBLICACION,indice);
                      seguir='n';
                    }
                }
                else
                {
                    printf("Error! no existe ID publicacion\n");
                }
                break;
            case 6:
                printf("Activar publicacion:\n");
                publicacion_mostrar(arrayP,LEN_PUBLICACION);
                getValidInt("ID Publicacion?","\nNumero valida\n",&auxiliarId,0,LEN_PUBLICACION,2);
                indice=publicacion_buscarPorId(arrayP,LEN_PUBLICACION,auxiliarId);
                if(indice>=0)
                {
                    auxiliarId=arrayP[indice].idCliente;
                    indiceC=cliente_buscarPorId(arrayC,QTY_CLIENTE,auxiliarId);
                    cliente_mostrarUno(arrayC,QTY_CLIENTE, indiceC);
                    seguir=getChar("Confirma activar publicacion presione s:");
                   if(seguir=='s')
                    {
                      arrayP[indice].estado=ACTIVA;
                      publicacion_mostrarUno(arrayP,LEN_PUBLICACION,indice);
                      seguir='n';
                    }
                }
                break;
            case 7:
                printf("Impresion clientes:\n");
                cliente_ordenar(arrayC,QTY_CLIENTE,1);
                cliente_imprimirClienteCantidadPublicacionesActivas(arrayC,QTY_CLIENTE,arrayP,LEN_PUBLICACION);
                break;
            case 8:
                printf("Impresion publicaciones:\n");
                publicacion_ordenar(arrayP,LEN_PUBLICACION,1);
                publicacion_imprimirPublicacionesCuit(arrayP,LEN_PUBLICACION,arrayC,QTY_CLIENTE);
                break;
            case 9:
                printf("Informe Clientes:\n");
                printf("Clientes con mas publicaciones activas:\n");
                informar_clientesMaxPublicacionesActivas(arrayP,LEN_PUBLICACION,arrayC,QTY_CLIENTE);
                printf("Clientes con mas publicaciones pausadas:\n");
                informar_clientesMaxPublicacionesPausadas(arrayP,LEN_PUBLICACION,arrayC,QTY_CLIENTE);
                printf("Clientes con mas publicaciones:\n");
                informar_clientesMaxPublicaciones(arrayP,LEN_PUBLICACION,arrayC,QTY_CLIENTE);
                break;
            case 10:
                printf("Informe publicaciones:\n");
                printf("Cantidad de publicaciones de un rubro:\n");
                getValidInt("Rubro?","\nNumero valida\n",&auxiliarId,0,CANT_RUBROS,2);
                informar_PublicacionesPorRubro(arrayP,LEN_PUBLICACION,auxiliarId);
                printf("Rubro con mas publicaciones activas:\n");
                informar_MaxPublicacionesPorRubro(arrayP,LEN_PUBLICACION,CANT_RUBROS);
                printf("Rubro con menos publicaciones activas:\n");
                informar_MinPublicacionesPorRubro(arrayP,LEN_PUBLICACION,CANT_RUBROS);
                break;
        }

    }while(menu != 11);

    return 0;
}
