#include "Observable.h"

void Observable::linkNewObserver(Observer* observerToLink) {
	this->linkedObservers.push_back(observerToLink);
}

void Observable::unlinkObserver(Observer* observerToUnlink) {
	this->linkedObservers.erase(std::remove(this->linkedObservers.begin(), this->linkedObservers.end(), observerToUnlink), this->linkedObservers.end());
}

void Observable::notifyObserversOfertaAdded(OfertaTuristica ofertaAdded) {
	for (auto& observer : this->linkedObservers)
		observer->updateSelfOfertaAdded(ofertaAdded);
}

void Observable::notifyObserversOfertaRemoved(const unsigned int index) {
	for (auto& observer : this->linkedObservers)
		observer->updateSelfOfertaRemoved(index);
}

void Observable::notifyObserversOfertaModified(const unsigned int index, OfertaTuristica ofertaModified) {
	for (auto& observer : this->linkedObservers)
		observer->updateSelfOfertaModified(index, ofertaModified);
}
