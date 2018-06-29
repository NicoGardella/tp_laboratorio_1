#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"
#include "ArrayList.h"


EMovie* funciones_new()
{
    return malloc(sizeof(EMovie));
}

void funciones_delete(EMovie* this)
{
    if(this != NULL)
        free(this);
}

EMovie* funciones_newPar(char* titulo,char* genero,char* descripcion,char* linkImagen,int duracion,int puntaje)
{
    EMovie* this;
    this = funciones_new();

    if( !funciones_setTitulo(this,titulo) &&
        !funciones_setGenero(this,genero) &&
        !funciones_setDescripcion(this,descripcion) &&
        !funciones_setLinkImagen(this,linkImagen)&&
        !funciones_setDuracion(this,duracion)&&
        !funciones_setPuntaje(this,puntaje))
    {

        return this;
    }
    funciones_delete(this);
    return NULL;
}


int funciones_cargarPelicula(EMovie* lista,ArrayList* arrayList)
{
    EMovie* auxListaP;

    int retorno = -1;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];

    if(lista!=NULL && arrayList!=NULL)
    {
        if(!getValidString("\nTitulo? ","\nEso no es un Titulo","El maximo es 40",titulo,40,2))
        {
            if(!getValidString("\nGenero? ","\nEso no es un Genero","El maximo es 40",genero,40,2))
            {
                if(!getValidInt("\nDuracion? ","\nEso no es una duracion valido",&duracion,0,500,2))
                {
                    if(!getValidString("\nDescripcion? ","\nEso no es una descripcion","El maximo es 40",descripcion,40,2))
                    {
                        if(!getValidInt("\nPuntaje? ","\nEso no es un puntaje valido",&puntaje,0,10,2))
                        {
                            if(!getValidString("\nLink Imagen? ","\nEso no es un link","El maximo es 40",linkImagen, 200,2))
                            {
                                retorno = 0;
                                auxListaP=funciones_newPar(titulo,genero,descripcion,linkImagen,duracion,puntaje);
                                al_add(arrayList,auxListaP);
                                funciones_cargarAlArchivo(auxListaP);
                                printf("ok");
                                retorno =0;
                            }
                        }
                    }
                }

            }
        }
    }
    return retorno;
}


int funciones_mostrarPelicula(EMovie* this)
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];

    funciones_getTitulo(this,titulo);
    funciones_getGenero(this,genero);
    funciones_getDuracion(this,&duracion);
    funciones_getDescripcion(this,descripcion);
    funciones_getPuntaje(this,&puntaje);
    funciones_getLinkImagen(this,linkImagen);

    printf("Tit:%s - Gen:%s - Dur:%d - Des:%s - Punt:%d - Link:%s\n",titulo,genero,duracion,descripcion,puntaje,linkImagen);
    return 0;
}
int funciones_mostrarPeliculaConIndice(EMovie* this, int indice)
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];

    funciones_getTitulo(this,titulo);
    funciones_getGenero(this,genero);
    funciones_getDuracion(this,&duracion);
    funciones_getDescripcion(this,descripcion);
    funciones_getPuntaje(this,&puntaje);
    funciones_getLinkImagen(this,linkImagen);

    printf("ID:%d - Tit:%s - Gen:%s - Dur:%d - Des:%s - Punt:%d - Link:%s\n",indice,titulo,genero,duracion,descripcion,puntaje,linkImagen);
    return 0;
}


void funciones_cargarAlArchivo(EMovie* this)
{

    FILE *pFile;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];
    pFile = fopen("data.csv","a");

    if(pFile!=NULL)
    {
        funciones_getTitulo(this, titulo);
        funciones_getGenero(this, genero);
        funciones_getDuracion(this, &duracion);
        funciones_getDescripcion(this, descripcion);
        funciones_getPuntaje(this, &puntaje);
        funciones_getLinkImagen(this, linkImagen);
        fprintf(pFile,"%s,%s,%d,%s,%d,%s\n",titulo,genero,duracion,descripcion,puntaje,linkImagen);

    }
    fclose(pFile);
}

//------------------------------------------BORRAR------------------------------------------------

void funciones_cargarDeArchivo(ArrayList* this)
{
    FILE *pFile;
    EMovie* auxListaP;
    char titulo[20];
    char genero[20];
    char auxDuracion[20];
    int duracion;
    char descripcion[50];
    char auxPuntaje[20];
    int puntaje;
    char linkImagen[200];
    pFile = fopen("data.csv","r");

    if(pFile!=NULL)
    {
        do
        {
            int parts = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",titulo,genero,auxDuracion,descripcion,auxPuntaje,linkImagen);
            if(parts==6)
            {
                duracion=atoi(auxDuracion);
                puntaje=atoi(auxPuntaje);
                auxListaP=funciones_newPar(titulo,genero,descripcion,linkImagen,duracion,puntaje);
                al_add(this, auxListaP);
            }
        }while(!feof(pFile));
        fclose(pFile);
    }
}

int funciones_listarPeliculas(ArrayList* this)
{
    int retorno=-1;
    int i;
    if(this!=NULL)
    {
        for(i = 0; i < al_len(this); i++)
        {
            funciones_mostrarPeliculaConIndice(al_get(this,i),i);
        }
    }
    return retorno;
}

void funciones_cargarTodoAlArchivo(ArrayList* this)
{

    FILE *pFile;
    int i;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];
    EMovie* auxListaP;
    pFile = fopen("data.csv","w");

    for(i=0;i<al_len(this);i++)
    {
        if(pFile!=NULL)
        {
            auxListaP=al_get(this,i);
            funciones_getTitulo(auxListaP, titulo);
            funciones_getGenero(auxListaP, genero);
            funciones_getDuracion(auxListaP, &duracion);
            funciones_getDescripcion(auxListaP, descripcion);
            funciones_getPuntaje(auxListaP, &puntaje);
            funciones_getLinkImagen(auxListaP, linkImagen);
            fprintf(pFile,"%s,%s,%d,%s,%d,%s\n",titulo,genero,duracion,descripcion,puntaje,linkImagen);
        }
    }
    printf("\nHa cargado la lista modificada\n");
    fclose(pFile);
}

int funciones_borrarPelicula(ArrayList* this)
{
    int retorno=-1;
    int idx;
    if(this!=NULL)
    {

        funciones_listarPeliculas(this);
        printf("Numero de Pelicula?\n");

        scanf("%d",&idx);
        if(idx>=0 && idx-1<al_len(this))
        {
            al_remove(this,idx-1);
            funciones_cargarTodoAlArchivo(this);
        }
        retorno=0;
    }
    return retorno;
}
//----------------MODIFICAR-----------------------------------



int funciones_modificarPelicula(ArrayList* this)
{
    int retorno=-1;
    char titulo[20];
    char genero[20];
    char descripcion[50];
    char linkImagen[50];
    int duracion;
    int puntaje;
    int idx;

    EMovie* auxListaP;
    if(this!=NULL)
    {
        funciones_listarPeliculas(this);
        printf("Numero de Pelicula?\n");

        scanf("%d",&idx);
        if((idx-1 >=0) && (idx-1 <al_len(this)))
        {
            if(!getValidString("\nTitulo? ","\nEso no es un Titulo","El maximo es 40",titulo,40,2))
            {
                if(!getValidString("\nGenero? ","\nEso no es un Genero","El maximo es 40",genero,40,2))
                {
                    if(!getValidInt("\nDuracion? ","\nEso no es una duracion valido",&duracion,0,500,2))
                    {
                        if(!getValidString("\nDescripcion? ","\nEso no es una descripcion","El maximo es 40",descripcion,40,2))
                        {
                            if(!getValidInt("\nPuntaje? ","\nEso no es un puntaje valido",&puntaje,0,10,2))
                            {
                                if(!getValidString("\nLink Imagen? ","\nEso no es un link","El maximo es 40",linkImagen, 200,2))
                                {
                                    auxListaP=funciones_newPar(titulo,genero,descripcion,linkImagen,duracion,puntaje);
                                    al_set(this,idx-1,auxListaP);
                                    funciones_cargarTodoAlArchivo(this);
                                    printf("\nHa cargado la lista modificada\n");
                                    retorno=0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return retorno;
}

//-------------------------------------------HTML-------------------------------------------------

void funciones_crearHTML(ArrayList* this)
{

    FILE *pFile;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int i;
    EMovie* auxListaP;
    pFile = fopen("index.html","w");

    if(pFile!=NULL && this!=NULL)
    {
        fprintf(pFile,"<!DOCTYPE html>\n");
        fprintf(pFile,"<html lang='en'>\n");
        fprintf(pFile,"<head>\n");
        fprintf(pFile,"    <meta charset='utf-8'>\n");
        fprintf(pFile,"    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(pFile,"    <meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(pFile,"    <title>Lista peliculas</title>\n");
        fprintf(pFile,"    <link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(pFile,"    <link href='css/custom.css' rel='stylesheet'>\n");
        fprintf(pFile,"</head>\n");
        fprintf(pFile,"<body>\n");
        fprintf(pFile,"    <div class='container'>\n");

        for(i=0;i<al_len(this);i++)
        {
            auxListaP=al_get(this,i);
            funciones_getTitulo(auxListaP, titulo);
            funciones_getGenero(auxListaP, genero);
            funciones_getDuracion(auxListaP, &duracion);
            funciones_getDescripcion(auxListaP, descripcion);
            funciones_getPuntaje(auxListaP, &puntaje);
            funciones_getLinkImagen(auxListaP, linkImagen);
            fprintf(pFile,"\n");
            fprintf(pFile,"            <article class='col-md-4 article-intro'>\n");
            fprintf(pFile,"                <a href='#'>\n");
            fprintf(pFile,"                    <img class='img-responsive img-rounded' src=' %s ' alt=''>\n",linkImagen);
            fprintf(pFile,"                </a>\n");
            fprintf(pFile,"                <h3>\n");
            fprintf(pFile,"                    <a href='#'> %s </a>\n",titulo);
            fprintf(pFile,"                </h3>\n");
            fprintf(pFile,"				<ul>\n");
            fprintf(pFile,"					<li>Género: %s </li>\n",genero);
            fprintf(pFile,"					<li>Puntaje: %d </li>\n",puntaje);
            fprintf(pFile,"					<li>Duración: %d </li>		\n",duracion);
            fprintf(pFile,"				</ul>\n");
            fprintf(pFile,"                <p> %s </p>\n",descripcion);
            fprintf(pFile,"            </article>\n");
            fprintf(pFile,"\n");
        }
        fprintf(pFile,"        </div>\n");
        fprintf(pFile,"    </div>\n");
        fprintf(pFile,"    <script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(pFile,"    <script src='js/bootstrap.min.js'></script>\n");
        fprintf(pFile,"	<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(pFile,"	<script src='js/holder.min.js'></script>\n");
        fprintf(pFile,"</body>\n");
        fprintf(pFile,"</html>\n");
        printf("\n\nArchivo creado con exito!!\n\n");
    }
    fclose(pFile);

}


int funciones_setTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(this->titulo,titulo);
        retorno = 0;
    }
    return retorno;
}
int funciones_getTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo , this->titulo);
        retorno = 0;
    }
    return retorno;
}

int funciones_setGenero(EMovie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(this->genero,genero);
        retorno = 0;
    }
    return retorno;
}
int funciones_getGenero(EMovie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero , this->genero);
        retorno = 0;
    }
    return retorno;
}

int funciones_setDescripcion(EMovie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno = 0;
    }
    return retorno;
}
int funciones_getDescripcion(EMovie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(descripcion , this->descripcion);
        retorno = 0;
    }
    return retorno;
}

int funciones_setLinkImagen(EMovie* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL)
    {
        strcpy(this->linkImagen,linkImagen);
        retorno = 0;
    }
    return retorno;
}
int funciones_getLinkImagen(EMovie* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL)
    {
        strcpy(linkImagen , this->linkImagen);
        retorno = 0;
    }
    return retorno;
}

int funciones_setDuracion(EMovie* this, int duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        this->duracion = duracion;
        retorno = 0;
    }
    return retorno;
}
int funciones_getDuracion(EMovie* this, int* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;
        retorno = 0;
    }
    return retorno;
}

int funciones_setPuntaje(EMovie* this, int puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        this->puntaje = puntaje;
        retorno = 0;
    }
    return retorno;
}
int funciones_getPuntaje(EMovie* this, int* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        *puntaje = this->puntaje;
        retorno = 0;
    }
    return retorno;
}

int funciones_setId(EMovie* this)
{
    static int ultimoId = 0;
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        ultimoId++;
        this->id = ultimoId;
    }
    return retorno;
}

int funciones_getId(EMovie* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}
