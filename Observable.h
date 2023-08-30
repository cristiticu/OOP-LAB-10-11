#pragma once
#include <vector>
#include "Observer.h"

class Observable{
private:
	std::vector<Observer*> linkedObservers;
public:
	void linkNewObserver(Observer* observerToLink);
	void unlinkObserver(Observer* observerToErase);
protected:
	void notifyObserversOfertaAdded(OfertaTuristica ofertaAdded);
	void notifyObserversOfertaRemoved(const unsigned int index);
	void notifyObserversOfertaModified(const unsigned int index, OfertaTuristica ofertaModified);
};

