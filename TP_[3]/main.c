/**********************************************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
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

	banderaInicio = 0;
	banderaModificaciones = 0;
	banderaGuardarTexto = 1;
	banderaGuardarBinario = 1;
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
			break;
		case 9:
			puts("\t  *************** Guardar lista en modo binario ***************");
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
					PedirEnteroP(&salir, "Solo se guardo la nueva lista en uno de los formatos. \n"
							"Aconsejamos que lo guardes en los 2 formatos, aun asi, quiere salir sin guardar en los 2 formatos? \n"
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

