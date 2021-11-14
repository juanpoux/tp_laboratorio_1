/**********************************************************************************
	AUTOR: Juan Poux
	TRABAJO PRACTICO N°3
 ***********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#define ARCHIVOID "guardarId.csv"
#define ARCHIVOPRINCIPAL "data.csv"
#define ARCHIVOBINARIO "data.bin"

int main()
{
	setbuf(stdout, NULL);

	int salir;
	int bancoId;
	LinkedList *listaEmpleados = ll_newLinkedList();
	int banderaInicio;
	int banderaModificaciones;
	int banderaGuardarTexto;
	int banderaGuardarBinario;
	int banderaAlta;

	banderaInicio = 0;
	banderaModificaciones = 0;
	banderaGuardarTexto = 1;
	banderaGuardarBinario = 1;
	banderaAlta = 0;
	do
	{
		switch(controller_menuDeOpciones())
		{
		case 1:
			if(banderaInicio == 0)
			{
				puts("\t*************** Carga de empleados ***************");
				if(!controller_loadFromText(ARCHIVOPRINCIPAL, listaEmpleados))
				{
					controller_GuardarPrimerId(&bancoId);
					banderaInicio = 1;
					puts("\t  *************** Carga exitosa ***************");
				}
				else
				{
					puts("Error al realizar la carga!");
				}
			}
			else
			{
				puts("Carga de empleados ya realizada!");
			}
			break;
		case 2:
			if(banderaInicio == 0)
			{
				puts("\t*************** Carga de empleados ***************");
				if(!controller_loadFromBinary(ARCHIVOBINARIO, listaEmpleados))
				{
					controller_GuardarPrimerId(&bancoId);
					banderaInicio = 1;
					puts("\t  *************** Carga exitosa ***************");
				}
				else
				{
					puts("Error al realizar la carga!");
				}
			}
			else
			{
				puts("Carga de empleados ya realizada!");
			}
			break;
		case 3:
			puts("\t*************** Alta de empleado ***************");

			switch(controller_addEmployee(listaEmpleados))
			{
			case -1:
				puts("Error al realizar el alta!");
				break;
			case 0:
				puts("\t  *************** Alta exitosa ***************");
				banderaModificaciones = 1;
				banderaGuardarTexto = 0;
				banderaGuardarBinario = 0;
				banderaAlta = 1;
				break;
			case 1:
				puts("\t  *************** Alta cancelada ***************");
				break;
			}
			break;
		case 4:
			if(!ll_isEmpty(listaEmpleados))
			{
				puts("\t*************** Modificacion de empleado ***************");
				if(!controller_editEmployee(listaEmpleados))
				{
					puts("\t  *************** Modificacion exitosa ***************");
					banderaModificaciones = 1;
					banderaGuardarTexto = 0;
					banderaGuardarBinario = 0;
				}
				else
				{
					puts("Error al realizar la modificacion!");
				}
			}
			else
			{
				puts("Primero debe cargar el archivo o dar de alta un empleado!");
			}
			break;
		case 5:
			if(!ll_isEmpty(listaEmpleados))
			{
				if(!controller_removeEmployee(listaEmpleados))
				{
					puts("\t  *************** Baja de empleado exitosa ***************");
					banderaModificaciones = 1;
					banderaGuardarTexto = 0;
					banderaGuardarBinario = 0;
				}
				else
				{
					puts("Error al realizar la baja!");
				}
			}
			else
			{
				puts("Primero debe cargar el archivo o dar de alta un empleado!");
			}
			break;
		case 6:
			if(!ll_isEmpty(listaEmpleados))
			{
				puts("\t  *************** Listado de empleados ***************");
				if(controller_ListEmployee(listaEmpleados) == -1)
				{
					puts("Error al realizar el listado!");
				}
			}
			else
			{
				puts("Primero debe cargar el archivo o dar de alta un empleado!");
			}
			break;
		case 7:
			if(!ll_isEmpty(listaEmpleados))
			{
				puts("\t  *************** Ordenar Empleados ***************");
				if(!controller_sortEmployee(listaEmpleados))
				{
					puts("\t  *************** Lista ordenada por ID nuevamente ***************");
				}
				else
				{
					puts("Error al realizar el listado!");
				}
				banderaGuardarTexto = 0;
				banderaGuardarBinario = 0;
			}
			else
			{
				puts("Primero debe cargar el archivo o dar de alta un empleado!");
			}
			break;
		case 8:
			if(banderaInicio == 0 && banderaAlta == 1)
			{
				puts("Se dio de alta al menos un empleado nuevo sin haber cargado el archivo, si guarda asi se sobreescribiran todos los datos.\n"
						"Primero tiene que hacer la carga del archivo y luego va a poder guardar.");
			}
			else
			{
				if(banderaInicio == 1)
				{
					puts("\t  *************** Guardar lista en modo texto ***************");
					if(!controller_saveAsText(ARCHIVOPRINCIPAL, listaEmpleados))
					{
						banderaGuardarTexto = 1;
						banderaModificaciones = 0;
						puts("\t  *************** Lista guardada en modo texto! ***************");
					}
					else
					{
						puts("\t  *************** Error al guardar en modo texto! ***************");
					}
				}
				else
				{
					puts("Debe al menos cargar el archivo para poder guardar!");
				}
			}
			break;
		case 9:
			puts("\t  *************** Guardar lista en modo binario ***************");
			if(banderaInicio == 0 && banderaAlta == 1)
			{
				puts("Se dio de alta al menos un empleado nuevo sin haber cargado el archivo, si guarda asi se sobreescribiran todos los datos.\n"
						"Primero tiene que hacer la carga del archivo y luego va a poder guardar.");
			}
			else
			{
				if(banderaInicio == 1)
				{
					if(!controller_saveAsBinary(ARCHIVOBINARIO, listaEmpleados))
					{
						banderaGuardarBinario = 1;
						banderaModificaciones = 0;
						puts("\t  *************** Lista guardada en modo binario! ***************");
					}
					else
					{
						puts("\t  *************** Error al guardar en modo binario! ***************");
					}
				}
				else
				{
					puts("Debe al menos cargar el archivo para poder guardar!");
				}
			}
			break;
		case 10:
			puts("\t  *************** Salir ***************");
			if(banderaModificaciones == 1)
			{
				PedirEnteroP(&salir, "Se realizaron modificaciones en la lista de empleados, quiere salir sin guardar? \n"
						"1) Salir sin guardar \n2) Cancelar \nElija una opcion: \n", "Error, ingreso invalido \n", 1, 2);
				if(salir == 1)
				{
					controller_guardarId2(bancoId);
					ll_deleteLinkedList(listaEmpleados);
				}
			}
			else
			{
				if(banderaGuardarBinario != 1 || banderaGuardarTexto != 1)
				{
					PedirEnteroP(&salir, "Solo se guardo la nueva lista en uno de los modos. \n"
							"Aconsejamos que lo guardes en los 2 modos, aun asi, quiere salir sin guardar en los 2 modos? \n"
							"1) Salir sin guardar \n2) Cancelar \nElija una opcion: \n", "Error, ingreso invalido \n", 1, 2);
					if(salir == 1)
					{
						controller_guardarId2(bancoId);
						ll_deleteLinkedList(listaEmpleados);
					}
				}
				else
				{
					PedirEnteroP(&salir, "1) Salir \n2) Cancelar \nElija una opcion: \n", "Error, ingreso invalido \n", 1, 2);
					if(salir == 1)
					{
						ll_deleteLinkedList(listaEmpleados);
					}
				}
			}
			break;
		}
	} while(salir != 1);
	return 0;
}

