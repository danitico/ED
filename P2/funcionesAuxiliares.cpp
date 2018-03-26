/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal de la provincia
  \author Daniel Ranchal Parrado
  \date 26/03/2018
*/
#include <iostream>
#include <string>
// Para usar atoi
#include <stdlib.h>
#include <unistd.h>
#include "Provincia.hpp"
#include "Municipio.hpp"
#include "funcionesAuxiliares.hpp"
#include "macros.hpp"
int ed::menu(){
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Comprobar si la provincia tiene municipios";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Cargar la provincia desde un fichero";

	PLACE(posicion++,10);
	std::cout << "[3] Grabar la provincia en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[4] Consultar datos de la provincia";

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar municipios de la provincia";

	PLACE(posicion++,10);
	std::cout << "[6] Modificar datos de la provincia: código, nombre o datos de un municipio";

	PLACE(posicion++,10);
	std::cout << "[7] Borrar todos los municipios de una provincia";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[8] Consultar un municipio";

	PLACE(posicion++,10);
	std::cout << "[9] Insertar un municipio";

	PLACE(posicion++,10);
	std::cout << "[10] Borrar un municipio";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}

//////////////////////////////////////////////////////////////////////////////

void ed::comprobarProvinciaVacia(ed::Provincia &provincia){
	if(provincia.hayMunicipios()){
		std::cout<<IBLUE<<"La provincia "<<RESET<<IRED<<ITALIC<<UNDERLINE<<provincia.getNombre()<<RESET<<IBLUE<<" tiene "<<RESET<<IRED<<ITALIC<<UNDERLINE<<provincia.getNumeroMunicipios()<<RESET<<IBLUE<<" municipios."<<RESET<<std::endl;
	}
	else{
		std::cout<<BIRED<<"La provincia '"<<provincia.getNombre()<<"' está vacia"<<RESET<<std::endl;
	}

	return;
}

//////////////////////////////////////////////////////////////////////////////

void ed::cargarProvincia(ed::Provincia &provincia){
	std::string nombre_fichero;
	std::cout<<IPURPLE<<"Introduzca el nombre del fichero que quiere cargar: "<<RESET;
	std::cin>>nombre_fichero;
	std::cin.ignore();

	bool res=provincia.cargarFichero(nombre_fichero);

	std::cout << CLEAR_SCREEN;
	PLACE(3,1);
	std::cout <<  "[1] Comprobar si la provincia tiene municipios"<<std::endl;

	if(res){
		std::cout<<BIGREEN<<"Fichero cargado correctamente"<<RESET<<std::endl;
	}
	else{
		std::cout<<BIRED<<"Error al cargar el fichero "<<nombre_fichero<<", ya que no existe o no se puede abrir"<<RESET<<std::endl;
	}

	return;
}
void ed::grabarProvincia(ed::Provincia  &provincia){
	std::string nombre_fichero;
	std::cout<<IPURPLE<<"Introduzca el nombre del fichero en donde quiere grabar datos: "<<RESET;
	std::cin>>nombre_fichero;
	std::cin.ignore();

	bool res=provincia.grabarFichero(nombre_fichero);

	std::cout << CLEAR_SCREEN;
	PLACE(3,1);
	std::cout << "[2] Cargar la provincia desde un fichero"<<std::endl;

	if(res){
		std::cout<<BIGREEN<<"Fichero grabado correctamente"<<RESET<<std::endl;
	}
	else{
		std::cout<<BIRED<<"Error al abrir el fichero "<<nombre_fichero<<", ya que no se poseen los suficientes permisos"<<RESET<<std::endl;
	}

	return;
}

//////////////////////////////////////////////////////////////////////

void ed::consultarDatosDeProvincia(ed::Provincia &provincia){
	std::cout<<IBLUE<<"El nombre de la provincia es "<<RESET<<IRED<<ITALIC<<UNDERLINE<<provincia.getNombre()<<RESET<<std::endl;
	std::cout<<IBLUE<<"El código de la provincia de "<<RESET<<IRED<<ITALIC<<UNDERLINE<<provincia.getNombre()<<RESET<<IBLUE<<" es "<<RESET<<IRED<<ITALIC<<UNDERLINE<<provincia.getCodigo()<<RESET<<std::endl;

	if(provincia.hayMunicipios()){
		std::cout<<IBLUE<<"La provincia de "<<RESET<<IRED<<ITALIC<<UNDERLINE<<provincia.getNombre()<<RESET<<IBLUE<<" tiene "<<RESET<<IRED<<ITALIC<<UNDERLINE<<provincia.getNumeroMunicipios()<<RESET<<IBLUE<<" municipios."<<RESET<<std::endl;
		std::cout<<IBLUE<<"El número total de habitantes de la provincia de "<<RESET<<IRED<<ITALIC<<UNDERLINE<<provincia.getNombre()<<RESET<<IBLUE<<" es "<<RESET<<IRED<<ITALIC<<UNDERLINE<<provincia.getTotalHabitantes()<<RESET<<IBLUE<<", donde "<<RESET<<IRED<<ITALIC<<UNDERLINE<<provincia.getTotalHombres()<<RESET<<IBLUE<<" son hombres y "<<RESET<<IRED<<ITALIC<<UNDERLINE<<provincia.getTotalMujeres()<<RESET<<IBLUE<<" son mujeres."<<RESET<<std::endl;
	}
	else{
		std::cout<<BIRED<<"No se pueden consultar los datos relativos a los municipios ya que la lista de municipios está vacia."<<RESET<<std::endl;
	}
	return;
}

void ed::mostrarMunicipiosDeProvincia(ed::Provincia & provincia){
	if(provincia.hayMunicipios()){
		provincia.escribirMunicipios();
	}
	else{
		std::cout<<BIRED<<"No se pueden mostrar los municipios ya que la lista de municipios está vacia."<<RESET<<std::endl;
	}
	return;
}

void ed::modificarDatosDeProvincia(ed::Provincia &provincia){
	int opcion, codigo;
	std::string nombre;

	do{
		PLACE(3,1);
		std::cout << "[6] Modificar datos de la provincia: código, nombre o datos de un municipio"
							  << std::endl;
		std::cout << BIYELLOW  << "Nombre de la provincia: "  << RESET
				  << provincia.getNombre() << std::endl;
		std::cout << BIYELLOW << "Código de la provincia: " << RESET
				  << provincia.getCodigo() << std::endl  << std::endl;

		std::cout << "Indique qué dato desea modificar: " << std::endl;
		std::cout << BIBLUE << "(1) Nombre " << std::endl;
		std::cout << BIBLUE << "(2) Código" << std::endl;
		std::cout << BIBLUE << "(3) Modificar datos de un municipio" << std::endl  << std::endl;
		std::cout << BIRED << "(0) Salir" << std::endl << std::endl  << std::endl;
		std::cout << IPURPLE;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
	    std::cin.ignore();

		std::cout << std::endl;

		switch(opcion)
		{
			case 0:
					// Fin de las modificaciones
					break;
			case 1:
					std::cout << IPURPLE;
					std::cout << "Nuevo nombre de la provincia: ";
					std::cout << RESET;
					std::getline(std::cin,nombre);
					provincia.setNombre(nombre);
					break;

			case 2:
					std::cout << IPURPLE;
					std::cout << "Nuevo código de la provincia: ";
					std::cout << RESET;
					std::cin >> codigo;
					provincia.setCodigo(codigo);
					break;

			case 3:
					std::cout << IPURPLE;
					std::cout << "Introduzca el nombre del municipio: ";
					std::cout << RESET;
					std::cin>>nombre;
					std::cin.ignore();

					if(provincia.existeMunicipio(nombre)){
						modificarDatosDeMunicipio(provincia, nombre);
					}
					else{
						std::cout << BIRED << "El municipio no se puede modificar ya que no existe" << RESET <<std::endl<<std::endl;
						std::cout << "Pulse "<< BIGREEN << "ENTER" << RESET << "para continuar" << std::endl;
						std::cin.ignore();
					}

					break;

			default:
					std::cout << BIRED << "Opción incorrecta:" << RESET
							  << opcion << std::endl;
		}

		std::cout << CLEAR_SCREEN;
	}while (opcion != 0);

	return;
}
void ed::borrarTodosLosMunicipiosDeProvincia(ed::Provincia &provincia){
	if(provincia.hayMunicipios()){
		provincia.borrarTodosLosMunicipios();
		std::cout << BIGREEN <<"Se han borrado todos los municipios de la provincia de la lista."<<RESET<<std::endl;
	}
	else{
		std::cout << BIRED <<"La lista ya esta vacía, por lo que ya están borrados los municipios"<<RESET<<std::endl;
	}

	return;
}
void ed::consultarMunicipioDeProvincia(ed::Provincia &provincia){
	std::string nombre_municipio;
	std::cout<<IPURPLE<<"Introduzca el nombre del municipio de la provincia a consultar: "<<RESET;
	std::getline(std::cin,nombre_municipio);

	if(provincia.existeMunicipio(nombre_municipio)){
		std::cout<<BIGREEN<<"Se ha obtenido la información del municipio correctamente. Se procede a mostrarla."<<RESET<<std::endl;
		std::cout<<"|"<<BGREEN<<" Código Postal "<<RESET<<"|"<<BYELLOW<<" Municipio "<<RESET<<"|"<<BBLUE<<" Nº Hombres "<<RESET<<"|"<<BPURPLE<<" Nº Mujeres "<<RESET<<"|"<<BCYAN<<" Nº Habitantes "<<RESET<<"|"<<std::endl;
		provincia.getMunicipio(nombre_municipio).escribirMunicipio();
	}
	else{
		std::cout<<BIRED<<"El municipio consultado no existe"<<RESET<<std::endl;
	}

	return;
}
void ed::insertarMunicipioEnProvincia(ed::Provincia &provincia){
	Municipio a;
	std::cout<<BIRED<<"¡CUIDADO! Los datos se leen teniendo en cuenta el formato: CP Nombre; hombres; mujeres;"<<RESET<<std::endl;
	std::cin>>a;
	std::cin.ignore();

	if(provincia.existeMunicipio(a.getNombre())){
		std::cout<<BIRED<<"Un municipio con ese nombre ya existe, por lo que se procede al aborto de esta operación"<<RESET<<std::endl;
	}
	else{
		provincia.insertarMunicipio(a);
		std::cout<<BIGREEN<<"El municipio se ha insertado con éxito"<<RESET<<std::endl;
	}

	return;
}
void ed::borrarMunicipioDeProvincia(ed::Provincia &provincia){
	std::string nombre_municipio_a_borrar;
	std::cout<<IPURPLE<<"Introduzca el nombre del municipio de la provincia para borrarlo de la lista: "<<RESET;
	std::getline(std::cin,nombre_municipio_a_borrar);//si no se pone eso, no admite municipios con espacios

	if(provincia.existeMunicipio(nombre_municipio_a_borrar)){
		provincia.borrarMunicipio(nombre_municipio_a_borrar);
		std::cout<<BIGREEN<<"El municipio se ha borrado con éxito"<<RESET<<std::endl;
	}
	else{
		std::cout<<BIRED<<"El municipio no estaba en la lista, por lo que se procede al aborto de esta operación"<<RESET<<std::endl;
	}

	return;
}
void ed::modificarDatosDeMunicipio(ed::Provincia & provincia, std::string & nombre_municipio){
	int codigo_postal, hombres, mujeres, opcion;
	std::string nombre;
	Municipio aux;

	std::cout << CLEAR_SCREEN;
	do{
		PLACE(3,1);
		std::cout << "(3) Modificar datos de un municipio"
							  << std::endl;
		std::cout<<"|"<<BGREEN<<" Código Postal "<<RESET<<"|"<<BYELLOW<<" Municipio "<<RESET<<"|"<<BBLUE<<" Nº Hombres "<<RESET<<"|"<<BPURPLE<<" Nº Mujeres "<<RESET<<"|"<<BCYAN<<" Nº Habitantes "<<RESET<<"|"<<std::endl;
		provincia.getMunicipio(nombre_municipio).escribirMunicipio();

		std::cout << "Indique qué dato desea modificar: " << std::endl;
		std::cout << BIBLUE << "{1} Nombre del municipio" << std::endl;
		std::cout << BIBLUE << "{2} Código postal" << std::endl;
		std::cout << BIBLUE << "{3} Nº Hombres" << std::endl;
		std::cout << BIBLUE << "{4} Nº Mujeres" << std::endl;
		std::cout << BIRED << "{0} Salir" << std::endl << std::endl << std::endl;
		std::cout << IPURPLE;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
	    std::cin.ignore();

		std::cout << std::endl;

		switch(opcion)
		{
			case 0:
					// Fin de las modificaciones
					break;
			case 1:
					std::cout << IPURPLE;
					std::cout << "Nuevo nombre del municipio: ";
					std::cout << RESET;
					std::getline(std::cin,nombre); /*se supone que el nombre introducido no se encuentra en la lista, es decir
					que no hay dos pueblos con el mismo nombre en la provincia*/

					if(provincia.existeMunicipio(nombre)){
						std::cout << BIRED << "Ese nombre de municipio ya existe, por lo que se aborta esta operación" << RESET << std::endl << std::endl;
						std::cout << "Pulse "<< BIGREEN << "ENTER" << RESET << " para continuar";
						std::cin.ignore();
						break;
					}

					aux=provincia.getMunicipio(nombre_municipio);
					aux.setNombre(nombre);
					provincia.borrarMunicipio(nombre_municipio);
					provincia.insertarMunicipio(aux);

					nombre_municipio=nombre;
					break;

			case 2:
					std::cout << IPURPLE;
					std::cout << "Nuevo código postal del municipio: ";
					std::cout << RESET;
					std::cin >> codigo_postal;

					aux=provincia.getMunicipio(nombre_municipio);
					aux.setCodigoPostal(codigo_postal);
					provincia.setNuevoMunicipio(aux);

					break;

			case 3:
					std::cout << IPURPLE;
					std::cout << "Nuevo número de habitantes hombres: ";
					std::cout << RESET;
					std::cin >> hombres;

					aux=provincia.getMunicipio(nombre_municipio);
					aux.setHombres(hombres);
					provincia.setNuevoMunicipio(aux);

					break;

			case 4:
					std::cout << IPURPLE;
					std::cout << "Nuevo número de habitantes mujeres: ";
					std::cout << RESET;
					std::cin >> mujeres;

					aux=provincia.getMunicipio(nombre_municipio);
					aux.setMujeres(mujeres);
					provincia.setNuevoMunicipio(aux);

					break;

			default:
					std::cout << BIRED << "Opción incorrecta:" << RESET
							  << opcion << std::endl;
		}

		std::cout << CLEAR_SCREEN;
	}while (opcion != 0);

	return;
}
