#include "publicacion.h"
#include "cliente.h"
#include "utn.h"

int informar_clientesMaxPublicacionesActivas(Publicacion* arrayP,int limiteP, Cliente* arrayC, int limiteC);
int informar_clientesMaxPublicacionesPausadas(Publicacion* arrayP,int limiteP, Cliente* arrayC, int limiteC);
int informar_MaxPublicacionesPorRubro(Publicacion* arrayP,int limiteP,int limiteRubro);
int informar_MinPublicacionesPorRubro(Publicacion* arrayP,int limiteP,int limiteRubro);
int informar_PublicacionesPorRubro(Publicacion* arrayP,int limiteP,int rubro);

//int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas, char* cuit);
//int informar_ListarContrataciones(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas);
//int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas);
//int informar_ListarCantidadContratacionesPorClienteImporte(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas);
//int informar_ListarCantMaxContrataciones(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas);
