#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    int idCliente;
    int numeroRubro;
    char textoAviso[64];
    int estado;

    //------------
    int idPublicacion;
    int isEmpty;
}Publicacion;
#endif // PANTALLA_H_INCLUDED
#include "cliente.h"
int publicacion_init(Publicacion* arrayP,int limite);
int publicacion_mostrar(Publicacion* arrayP,int limite);
int publicacion_mostrarUno(Publicacion* arrayP,int limite, int id);
int publicacion_mostrarDebug(Publicacion* arrayP,int limite);
int publicacion_alta(Publicacion* arrayP,int limite,int id);
int publicacion_baja(Publicacion* arrayP,int limite, int id);
int publicacion_ordenar(Publicacion* arrayP,int limite, int orden);
int publicacion_buscarPorId(Publicacion* arrayP,int limite, int id);
int publicacion_buscarPorIdCliente(Publicacion* arrayP,int limite, int id);
int publicacion_altaForzada(Publicacion* arrayP,int limite, int idCliente, int rubro, char* textoAviso);
int publicacion_cantidadPublicacionesPorClienteActivas(Publicacion* arrayP, int limite, int idCliente);
int publicacion_cantidadPublicacionesPorClientePausadas(Publicacion* arrayP, int limite, int idCliente);
int publicacion_cantidadPublicacionesPorCliente(Publicacion* arrayP, int limite, int idCliente);
int publicacion_cantidadPublicacionesPorRubroActivas(Publicacion* arrayP, int limite, int rubro);
int publicacion_imprimirPublicacionesCuit(Publicacion* arrayP, int limiteP, Cliente* arrayC, int limiteC);
//int publicacion_modificacion(Publicacion* arrayP,int limite, int id);
//int buscarLugarLibre(Publicacion* arrayP,int limite);
//int proximoId();
//int publicacion_buscarPorId(Publicacion* arrayP,int limite, int id);
