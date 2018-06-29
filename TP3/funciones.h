#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];
    int id;
}EMovie;

#endif // FUNCIONES_H_INCLUDED

#include "ArrayList.h"

/** \brief retorna los parametros cargados en un elemento
 *
 * \param titulo char* pide un titulo como parametro
 * \param genero char* pide un genero como parametro
 * \param descripcion char* pide una descripcion como parametro
 * \param linkImagen char* pide un link como parametro
 * \param duracion int pide la duracion como parametro
 * \param puntaje int pide un puntaje como parametro
 * \return EMovie* retorna el elemento con sus parametros cargados
 *
 */
EMovie* funciones_newPar(char* titulo,char* genero,char* descripcion,char* linkImagen,int duracion,int puntaje);

/** \brief carga una pelicula al arrayList y al archivo .txt
 *
 * \param lista EMovie* pide la lista EMovie
 * \param arrayList ArrayList* pide la lista del arrayList
 * \return int retorna 1 o 0 si funciono
 *
 */
int funciones_cargarPelicula(EMovie* lista,ArrayList* arrayList);

/** \brief muestra una pelicula y sus datos
 *
 * \param this EMovie* pide el elemento
 * \return int retorna 1 o 0 si funciono
 *
 */
int funciones_mostrarPelicula(EMovie* this);

/** \brief carga un dato al archivo .txt sin borrar los datos ya cargados
 *
 * \param this EMovie* pide el elemento
 * \return void
 *
 */
void funciones_cargarAlArchivo(EMovie* this);

/** \brief Toma los datos del archivo .txt y los carga al arrayList
 *
 * \param this ArrayList* Pide el arrayList donde guardar los datos
 * \return void
 *
 */
void funciones_cargarDeArchivo(ArrayList* this);

/** \brief Lista por consola los titulos cargados en el arrayList
 *
 * \param this ArrayList* pide el arrayList
 * \return int retorna 1 o 0 si funciona
 *
 */
int funciones_listarPeliculas(ArrayList* this);

/** \brief Carga todos los datos al archivo .txt eliminando lo que ya tenia
 *
 * \param this ArrayList* pide el arrayList
 * \return void
 *
 */
void funciones_cargarTodoAlArchivo(ArrayList* this);

/** \brief Elimina una pelicula del arrayList
 *
 * \param this ArrayList* pide el arrayList
 * \return int retorna 1 o 0 si funciona
 *
 */
int funciones_borrarPelicula(ArrayList* this);

/** \brief Modifica los datos de un elemento del arrayList
 *
 * \param this ArrayList* pide el arrayList
 * \return int retona 1 o 0 si funciona
 *
 */
int funciones_modificarPelicula(ArrayList* this);

/** \brief Crea el archivo .html y le carga todos los datos del ArrayList
 *
 * \param this EMovie* Pide el arrayList
 * \return void
 *
 */
void funciones_crearHTML(ArrayList* this);

int funciones_mostrarPeliculaConIndice(EMovie* this, int indice);


int funciones_setTitulo(EMovie* this, char* titulo);

int funciones_getTitulo(EMovie* this, char* titulo);

int funciones_setGenero(EMovie* this, char* genero);

int funciones_getGenero(EMovie* this, char* genero);

int funciones_setDescripcion(EMovie* this, char* descripcion);

int funciones_getDescripcion(EMovie* this, char* descripcion);

int funciones_setLinkImagen(EMovie* this, char* linkImagen);

int funciones_getLinkImagen(EMovie* this, char* linkImagen);

int funciones_setDuracion(EMovie* this, int duracion);

int funciones_getDuracion(EMovie* this, int* duracion);

int funciones_setPuntaje(EMovie* this, int puntaje);

int funciones_getPuntaje(EMovie* this, int* puntaje);
