/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author Daniel Ranchal Parrado
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
	/*if(isEmpty()){
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
	}*/
	return _nitems;
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

	if(getCurrent()->getNext()==NULL){
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
	if(isEmpty()){
		setCurrent(getHead());
		return false;
	}
	else{
		gotoHead();
		while(_current->getNext()!=NULL && _current->getItem() < item){
			if(getCurrentItem() == item){
				return true;
			}
			gotoNext();
		}
		if(getCurrentItem() == item){
				return true;
		}	
		#ifndef NDEBUG
		assert(item < _current->getItem() || isLastItem());
		#endif
		return false;
	}
}
void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::insert(ed::Municipio const & item){
	#ifndef NDEBUG
	int oldnitems=nItems();
	assert(find(item)==false);
	#endif
	
	if(!find(item)){
		if(isEmpty()){
			ed::NodoDoblementeEnlazadoMunicipio *aux = new ed::NodoDoblementeEnlazadoMunicipio(item, NULL, NULL);
			setHead(aux);
			setCurrent(getHead());
		}
		else{
			if(isFirstItem()){
				ed::NodoDoblementeEnlazadoMunicipio *aux = new ed::NodoDoblementeEnlazadoMunicipio(item, NULL, getCurrent());
				_current->setPrevious(aux);
				setHead(aux);
				setCurrent(getHead());
			}
			else{
				if(isLastItem() && !(item < getCurrentItem())){
					ed::NodoDoblementeEnlazadoMunicipio *aux = new ed::NodoDoblementeEnlazadoMunicipio(item, _current, NULL);
					_current->setNext(aux);
					setCurrent(_current->getNext());
				}
				else{
					ed::NodoDoblementeEnlazadoMunicipio *aux = new ed::NodoDoblementeEnlazadoMunicipio(item, _current->getPrevious(), _current);
					_current->getPrevious()->setNext(aux);
					_current->setPrevious(aux);
					setCurrent(aux);
				}
			}
		}
		_nitems++;
	}
	//std::cout<<getCurrentItem()<<"\n";

	#ifndef NDEBUG
	assert(getCurrentItem()==item && nItems()==(oldnitems + 1));
	#endif
}
void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::remove(){
	#ifndef NDEBUG
	assert(isEmpty()==false);
	#endif

	int oldnitems=nItems();
	if(oldnitems==1){
		setHead(NULL);

		#ifndef NDEBUG
		assert(isEmpty());
		#endif
	}
	else{
		if(oldnitems > 1 && isFirstItem()){
			NodoDoblementeEnlazadoMunicipio *aux=_current->getNext();
			setCurrent(NULL);
			aux->setPrevious(NULL);
			setCurrent(aux);
			
			#ifndef NDEBUG
			assert(aux->getItem()==getCurrentItem() && isFirstItem());
			#endif
		}
		else{
			if(isLastItem()){
				NodoDoblementeEnlazadoMunicipio *aux=_current->getPrevious();
				setCurrent(NULL);
				aux->setNext(NULL);
				setCurrent(aux);
				
				#ifndef NDEBUG
				assert(isEmpty() || (isLastItem() && aux->getItem()==getCurrentItem()));
				#endif
			}
			else{
				NodoDoblementeEnlazadoMunicipio *aux1=_current->getPrevious();
				NodoDoblementeEnlazadoMunicipio *aux2=_current->getNext();
				setCurrent(NULL);
				aux1->setNext(aux2);
				aux2->setPrevious(aux1);

				#ifndef NDEBUG
				assert(aux1->getItem()==getPreviousItem() && (aux2->getItem()==getCurrentItem()));
				#endif
			}
		}
	}
	
	_nitems--;
	
	#ifndef NEDEBUG
	assert(nItems()==oldnitems-1);
	#endif
}
void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::removeAll(){
	setCurrent(_head->getNext());
	while(_current->getNext()!=NULL){
		delete _current->getPrevious();
		setCurrent(_current->getNext());
	}
	setCurrent(getHead());
	
	#ifndef NDEBUG
	assert(isEmpty());
	#endif
}
