/*!	
	\file  Provincia.cpp
	\brief Definición de la clase Provincia
	\author Daniel Ranchal Parrado
	\date  
	\version 1.0
*/
//Para los flujos de entrada/salida en ficheros.
#include <fstream>  
#include <iostream>
// Para comprobar las pre y post condiciones
#include <cassert>
#include "Provincia.hpp"
// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE Provincia
// OBSERVADORES
bool ed::Provincia::hayMunicipios() const{
	return _listaMunicipios.isEmpty();
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
	
	existeMunicipio(nombre);
	return _listaMunicipios.getCurrentItem();
}
int ed::Provincia::getTotalHombres(){
	int hombres=0;
	_listaMunicipios.gotoHead();	
	while(_listaMunicipios.getCurrent()->getNext()!=NULL){
		hombres+=_listaMunicipios.getCurrent()->getItem().getHombres();
		_listaMunicipios.gotoNext();
	}
	return hombres;
}
int ed::Provincia::getTotalMujeres(){
	int mujeres=0;
	_listaMunicipios.gotoHead();
	while(_listaMunicipios.getCurrent()->getNext()!=NULL){
		mujeres+=_listaMunicipios.getCurrent()->getItem().getMujeres();
		_listaMunicipios.gotoNext();
	}
	return mujeres;
}
int ed::Provincia::getTotalHabitantes(){
	return _listaMunicipios.getTotalHombres() + _listaMunicipios.getTotalMujeres();
}

// MODIFICADORES
void ed::Provincia::setNombre(std::string nombre){
	_nombre=nombre;

	#ifndef NDEBUG
	assert(getNombre()==nombre);
	#endif
}
///////////////////////////////////////////////////////////////////////////////////

// FUNCIÓN DE ESCRITURA



/////////////////////////////////////////////////////////////////////////////////////////

// OPERACIONES CON FICHEROS


