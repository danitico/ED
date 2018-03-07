/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author  
	\date  
	\version 1.0
*/
// Para comprobar las pre y post-condiciones
#include <cassert>
#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "NodoMunicipioInterfaz.hpp"
#include "Municipio.hpp"
// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE ListaDoblementeEnlazadaOrdenadaMunicipios
int ed::ListaDoblementeEnlazadaOrdenadaMunicipios::nItems() const{
	if(isEmpty()){
		return 0;
	}
	else{
		if(_head->getNext()==NULL && getHead()!=NULL){
			return 1;
		}
		else{
			NodoDoblementeEnlazadoMunicipio *aux=getHead();
			int n=0;
			while(aux->getNext()!=NULL){
				aux=aux->getNext();
				n++;
			}
			return n;
		}
	}
}
bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::isFirstItem() const{
	#ifndef NDEBUG
	assert(isEmpty()==false);
	#endif	
	
	if(getHead()==getCurrent()){
		return true;
	}
	else{
		return false;
	}
}
bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::isLastItem() const{
	#ifndef NDEBUG
	assert(isEmpty()==false);
	#endif

	NodoDoblementeEnlazadoMunicipio *aux=getHead();
	while(aux->getNext()!=NULL){
		aux=aux->getNext();
	}

	if(aux==getCurrent()){
		return true;
	}
	else{
		return false;
	}
}
ed::Municipio const & ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getCurrentItem() const{
	#ifndef NDEBUG
	assert(isEmpty()==false);
	#endif

	return _current->getItem();
}
ed::Municipio const & ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getPreviousItem() const{
	#ifndef NDEBUG
	assert(isEmpty()==false && isLastItem()==false);
	#endif

	return (_current->getPrevious())->getItem();
}
ed::Municipio const & ed::ListaDoblementeEnlazadaOrdenadaMunicipios::getNextItem() const{
	#ifndef NDEBUG
	assert(isEmpty()==false && isLastItem()==false);
	#endif

	return (_current->getNext())->getItem();
}
void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoHead(){
	#ifndef NDEBUG
	assert(isEmpty()==false);
	#endif

	setCurrent(getHead());

	#ifndef NDEBUG
	assert(isFirstItem());
	#endif
}
void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoLast(){
	#ifndef NDEBUG
	assert(isEmpty()==false);
	#endif

	if(!isLastItem()){
		setCurrent(getHead());
		while(_current->getNext()!=NULL){
			setCurrent(_current->getNext());
		}
	}

	#ifndef NDEBUG
	assert(isLastItem());
	#endif
}
void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoPrevious(){
	#ifndef NDEBUG
	assert(isEmpty()==false && isFirstItem()==false);
	#endif

	setCurrent(_current->getPrevious());
}
void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoNext(){
	#ifndef NDEBUG
	assert(isEmpty()==false && isLastItem()==false);
	#endif

	setCurrent(_current->getNext());
}
bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::find(ed::Municipio const & item){
	bool res=false;
	gotoHead();
	while(_current->getNext()!=NULL){
		if(_current->getItem()==item){
			 res=true;
		}
		gotoNext();
	}		
	
	if(res){	
		#ifndef NDEBUG
		assert(_current->getItem()==item);
		#endif
		return res;
	}

	gotoHead();
	while(_current->getNext()!=NULL && _current->getItem()<item){
		gotoNext();
	}
	
	#ifndef NDEBUG
	assert(item < _current->getItem() || isLastItem()==true);
	#endif

	return res;
}
void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::insert(ed::Municipio const & item){
	#ifndef NDEBUG
	assert(find(item)==false);
	#endif
	int oldnitems=nItems();
	gotoHead();
	
	if(oldnitems==0){
		NodoDoblementeEnlazadoMunicipio aux(item, NULL, NULL);
		setHead(&aux);
	}
	else{
		while(_current->getNext()!=NULL && _current->getItem()<item){
			gotoNext();
		}
		NodoDoblementeEnlazadoMunicipio aux(item, _current->getPrevious(), _current);

		gotoPrevious();
		_current->setNext(&aux);//*(_current->getNext())=aux;
		gotoNext(); gotoNext();
		_current->setPrevious(&aux);//*(_current->getPrevious())=aux;
		gotoPrevious();
	}

	#ifndef NDEBUG
	assert(_current->getItem()==item	&& nItems()==(oldnitems + 1));
	#endif
}
void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::remove(){
	#ifndef NDEBUG
	assert(isEmpty()==false);
	#endif

	int oldnitems=nItems();
	if(oldnitems==1){
		setCurrent(NULL);
	}
	else{
		if(oldnitems > 1 && isFirstItem()){
			NodoDoblementeEnlazadoMunicipio *aux=_current->getNext();
			setCurrent(NULL);
			aux->setPrevious(NULL);
			setCurrent(aux);
		}
		else{
			if(isLastItem()){
				NodoDoblementeEnlazadoMunicipio *aux=_current->getPrevious();
				setCurrent(NULL);
				aux->setNext(NULL);
				setCurrent(aux);
				
				#ifndef NDEBUG
				assert(isEmpty() || (isLastItem() && 
			}
			else{
				NodoDoblementeEnlazadoMunicipio *aux1=_current->getPrevious();
				NodoDoblementeEnlazadoMunicipio *aux2=_current->getNext();
				setCurrent(NULL);
				aux1->setNext(aux2);
				aux2->setPrevious(aux1);
			}
		}
	}
}
