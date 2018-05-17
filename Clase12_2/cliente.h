#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit[50];
    int idCliente;
    int isEmpty;
}Cliente;

#include "publicacion.h"

int cliente_init(Cliente* arrayC,int limite);
int cliente_mostrar(Cliente* arrayC,int limite);
int cliente_mostrarUno(Cliente* arrayC,int limite, int id);
int cliente_mostrarDebug(Cliente* arrayC,int limite);
int cliente_imprimir(Cliente* arrayC,int limite);
int cliente_alta(Cliente* arrayC,int limite);
int cliente_modificacion(Cliente* arrayC,int limite, int id);
int cliente_baja(Cliente* arrayC,int limite, int id);
int cliente_buscarPorId(Cliente* arrayC,int limite, int id);
int cliente_modificacion(Cliente* arrayC,int limite, int id);
int cliente_ordenar(Cliente* arrayC,int limite, int orden);
int cliente_ordenarCuit(Cliente* arrayC,int limite, int orden);
int cliente_imprimirClienteCantidadPublicacionesActivas(Cliente* arrayC,int limiteC ,Publicacion* arrayP, int limiteP);
int cliente_altaForzada(Cliente* arrayC,int limite,char* nombre, char* apellido,char* cuit);

#endif // PUBLICACION_H_INCLUDED
