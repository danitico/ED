/*!
	\file  Provincia.cpp
	\brief Definición de la clase Provincia
	\author Daniel Ranchal Parrado
	\date
	\version 2.0
*/
//Para los flujos de entrada/salida en ficheros.
#include <fstream>
#include <iostream>
#include <cstdlib>
// Para comprobar las pre y post condiciones
#include <cassert>
#include "Provincia.hpp"
// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE Provincia
// OBSERVADORES
bool ed::Provincia::hayMunicipios() const{
	return !(_listaMunicipios.isEmpty());
}
int ed::Provincia::getNumeroMunicipios() const{
	return _listaMunicipios.nItems();
}
bool ed::Provincia::existeMunicipio(std::string nombre){
	Municipio buscado(nombre);
	return _listaMunicipios.find(buscado);
}
ed::Municipio ed::Provincia::getMunicipio(std::string nombre){
	#ifndef NDEBUG
	assert(existeMunicipio(nombre));
	#endif

	return _listaMunicipios.getCurrentItem();
}
int ed::Provincia::getTotalHombres(){
	int hombres=0;
	_listaMunicipios.gotoHead();
	while(!_listaMunicipios.isLastItem()){
		hombres+=_listaMunicipios.getCurrentItem().getHombres();
		_listaMunicipios.gotoNext();
	}
	hombres+=_listaMunicipios.getCurrentItem().getHombres();
	return hombres;
}
int ed::Provincia::getTotalMujeres(){
	int mujeres=0;
	_listaMunicipios.gotoHead();
	while(!_listaMunicipios.isLastItem()){
		mujeres+=_listaMunicipios.getCurrentItem().getMujeres();
		_listaMunicipios.gotoNext();
	}
	mujeres+=_listaMunicipios.getCurrentItem().getMujeres();
	return mujeres;
}
int ed::Provincia::getTotalHabitantes(){
	return getTotalHombres() + getTotalMujeres();
}

// MODIFICADORES
void ed::Provincia::setNombre(std::string nombre){
	_nombre=nombre;

	#ifndef NDEBUG
	assert(getNombre()==nombre);
	#endif
}
void ed::Provincia::setCodigo(int codigo){
	_codigo=codigo;

	#ifndef NDEBUG
	assert(getCodigo()==codigo);
	#endif
}
void ed::Provincia::insertarMunicipio(ed::Municipio municipio){
	#ifndef NDEBUG
	int oldmunicipios=getNumeroMunicipios();
	assert(!existeMunicipio(municipio.getNombre()));
	#endif

	_listaMunicipios.insert(municipio);

	#ifndef NDEBUG
	assert(existeMunicipio(municipio.getNombre()));
	assert(getNumeroMunicipios()==oldmunicipios+1);
	#endif
}
void ed::Provincia::borrarMunicipio(std::string cadena){
	#ifndef NDEBUG
	int oldmunicipios=getNumeroMunicipios();
	assert(existeMunicipio(cadena));
	#endif

	Municipio municipio(cadena);
	_listaMunicipios.find(municipio);
	_listaMunicipios.remove();

	#ifndef NDEBUG
	assert(!existeMunicipio(cadena) && getNumeroMunicipios()==oldmunicipios-1);
	#endif
}
void ed::Provincia::borrarTodosLosMunicipios(){
	_listaMunicipios.removeAll();

	#ifndef NDEBUG
	assert(!hayMunicipios());
	#endif
}
///////////////////////////////////////////////////////////////////////////////////

// FUNCIÓN DE ESCRITURA
void ed::Provincia::escribirMunicipios(){
	std::cout<<getCodigo()<<"\t"<<getNombre()<<std::endl;
	std::cout<<std::endl;
	std::cout<<"#######################################################################"<<std::endl<<std::endl;
	std::cout<<"|"<<BGREEN<<" Código Postal "<<RESET<<"|"<<BYELLOW<<" Municipio "<<RESET<<"|"<<BBLUE<<" Nº Hombres "<<RESET<<"|"<<BPURPLE<<" Nº Mujeres "<<RESET<<"|"<<BCYAN<<" Nº Habitantes "<<RESET<<"|"<<std::endl;
	if(!_listaMunicipios.isEmpty()){
		_listaMunicipios.gotoHead();
		while(!_listaMunicipios.isLastItem()){
			_listaMunicipios.getCurrentItem().escribirMunicipio();
			_listaMunicipios.gotoNext();
		}
		_listaMunicipios.getCurrentItem().escribirMunicipio();
	}
}
///////////////////////////////////////////////////////////////////////////////////

// OPERACIONES CON FICHEROS
bool ed::Provincia::cargarFichero(std::string archivo){
	std::ifstream file(archivo.c_str());
	std::string stream;
	Municipio a;

	if(file.is_open()){
		getline(file, stream, ' ');
		setCodigo(atoi(stream.c_str()));
		getline(file, stream, '\n');
		setNombre(stream);

		while(getline(file, stream, ' ')){
			a.setCodigoPostal(atoi(stream.c_str()));

			getline(file, stream, ';');
			a.setNombre(stream);

			getline(file, stream, ';');
			a.setHombres(atoi(stream.c_str()));

			getline(file, stream, ';');
			a.setMujeres(atoi(stream.c_str()));

			getline(file, stream, '\n');

			insertarMunicipio(a);
		}
		file.close();
		return true;
	}
	else{
		return false;
	}
}
bool ed::Provincia::grabarFichero(std::string archivo){
	std::ofstream file(archivo.c_str());

	if(file.is_open()){
		file<<getCodigo()<<" "<<getNombre()<<"\n";
		_listaMunicipios.gotoHead();
		while(!_listaMunicipios.isLastItem()){
			file<<_listaMunicipios.getCurrentItem().getCodigoPostal()<<" ";
			file<<_listaMunicipios.getCurrentItem().getNombre()<<";";
			file<<_listaMunicipios.getCurrentItem().getHombres()<<";";
			file<<_listaMunicipios.getCurrentItem().getMujeres()<<";";
			file<<"\n";

			_listaMunicipios.gotoNext();
		}

		return true;
	}
	else{
		return false;
	}
}
