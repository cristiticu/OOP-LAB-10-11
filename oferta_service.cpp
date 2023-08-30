#include "oferta_service.h"

bool denumireCmp(const OfertaTuristica& left, const OfertaTuristica& right) {
	std::string denumireLeft = left.getDenumire();
	std::string denumireRight = right.getDenumire();
	if (denumireLeft.compare(denumireRight) <= 0)
		return false;
	return true;
}

bool destinatieCmp(const OfertaTuristica& left, const OfertaTuristica& right) {
	std::string destinatieLeft = left.getDestinatie();
	std::string destinatieRight = right.getDestinatie();
	if (destinatieLeft.compare(destinatieRight) <= 0)
		return false;
	return true;
}

bool tipPretCmp(const OfertaTuristica& left, const OfertaTuristica& right) {
	std::string tipLeft = left.getTip();
	std::string tipRight = right.getTip();
	const double pretLeft = left.getPret();
	const double pretRight = right.getPret();
	if (tipLeft.compare(tipRight) < 0)
		return false;
	else if (tipLeft.compare(tipRight) == 0)
		if (pretLeft <= pretRight)
			return false;
	return true;

}

Service::Service(Repository& _repository, Repository& _wishlist) : repository(_repository), wishlist(_wishlist){

}
Service::~Service() {
	while (this->undoStack.size() != 0) {
		ActiuneUndo* actiune = undoStack.top();
		undoStack.pop();
		delete actiune;
	}
}

std::vector<OfertaTuristica> Service::getAllOferte() const {
	return this->repository.getListaOferte();
}

std::vector<OfertaTuristica> Service::getWishlist() const {
	return this->wishlist.getListaOferte();
}

void Service::addOferta(const std::string& denumire, const std::string& destinatie, const std::string& tip, const double pret) {
	OfertaTuristica newOferta{denumire, destinatie, tip, pret};
	this->repository.addOferta(newOferta);
	UndoAdauga* undo = new UndoAdauga{ newOferta };
	this->undoStack.push(undo);
	this->notifyObserversOfertaAdded(newOferta);
}

void Service::addOfertaWishlist(const unsigned int index) {
	this->wishlist.addOferta(this->repository.getListaOferte()[index]);
}

void Service::deleteOferta(const unsigned int index) {
	OfertaTuristica toDelete = this->repository.getOferta(index);
	this->repository.deleteOferta(index);
	UndoSterge* undo = new UndoSterge{ toDelete };
	this->undoStack.push(undo);
	this->notifyObserversOfertaRemoved(index);
}

void Service::modifyOferta(const unsigned int index, const std::string& denumire, const std::string& destinatie, const std::string& tip, const double pret) {
	OfertaTuristica toModify = this->repository.getOferta(index);
	OfertaTuristica modifiedOferta{denumire, destinatie, tip, pret};
	this->repository.modifyOferta(index, modifiedOferta);
	UndoModifica* undo = new UndoModifica{ toModify, index };
	this->undoStack.push(undo);
	this->notifyObserversOfertaModified(index, modifiedOferta);
}

std::vector<OfertaTuristica> Service::searchOferta(const std::string& denumire, const std::string& destinatie, const std::string& tip) const {
	OfertaTuristica toSearch(denumire, destinatie, tip, -1);
	std::vector<OfertaTuristica> oferte;
	std::vector<OfertaTuristica> listaInitiala;
	listaInitiala = this->repository.getListaOferte();
	std::copy_if(listaInitiala.begin(), listaInitiala.end(), std::back_inserter(oferte), [toSearch](OfertaTuristica oferta) {return oferta == toSearch; });
	return oferte;

	/*for (int i = 0; i < this->repository.getSize(); i++)
		if (this->repository.getListaOferte()[i] == toSearch)
			oferte.push_back(this->repository.getListaOferte()[i]);
	return oferte;*/
}

std::vector<OfertaTuristica> Service::filtrareOferteDestinatie(const std::string& destinatie) const {
	std::vector<OfertaTuristica> oferte;
	std::vector<OfertaTuristica> listaInitiala;
	listaInitiala = this->repository.getListaOferte();
	std::copy_if(listaInitiala.begin(), listaInitiala.end(), std::back_inserter(oferte), [destinatie](OfertaTuristica oferta) {return oferta.getDestinatie() == destinatie; });
	return oferte;

	/*for(int i = 0; i < this->repository.getSize(); i++)
		if (this->repository.getListaOferte()[i].getDestinatie() == destinatie)
			oferte.push_back(this->repository.getListaOferte()[i]);
	return oferte;*/
}

std::vector<OfertaTuristica> Service::filtrareOfertePret(const double pret) const {
	std::vector<OfertaTuristica> oferte;
	std::vector<OfertaTuristica> listaInitiala;
	listaInitiala = this->repository.getListaOferte();
	std::copy_if(listaInitiala.begin(), listaInitiala.end(), std::back_inserter(oferte), [pret](OfertaTuristica oferta) {return oferta.getPret() == pret; });
	return oferte;

	/*for (int i = 0; i < this->repository.getSize(); i++)
		if (this->repository.getListaOferte()[i].getPret() == pret)
			oferte.push_back(this->repository.getListaOferte()[i]);
	return oferte;*/
}

std::vector<OfertaTuristica> Service::sortareOferteDenumire() const {
	std::vector<OfertaTuristica>& oferte = this->repository.getListaOferte();
	std::sort(oferte.begin(), oferte.end(), denumireCmp);
	return oferte;
}

std::vector<OfertaTuristica> Service::sortareOferteDestinatie() const {
	std::vector<OfertaTuristica>& oferte = this->repository.getListaOferte();
	std::sort(oferte.begin(), oferte.end(), destinatieCmp);
	return oferte;
}

std::vector<OfertaTuristica> Service::sortareOferteTipPret() const {
	std::vector<OfertaTuristica>& oferte = this->repository.getListaOferte();
	std::sort(oferte.begin(), oferte.end(), tipPretCmp);
	return oferte;
}

void Service::genereazaWishlist(const unsigned int numarOferte) {
	if (numarOferte + this->wishlist.getSize() > this->repository.getSize() || numarOferte == 0)
		throw customException("Numar invalid de oferte!\n");
	unsigned int totalAdaugat = 0;
	unsigned int randomIndex;
	std::mt19937 twister{ std::random_device{}() };
	std::uniform_int_distribution<> distribution(0, this->repository.getSize() - 1);
	while (totalAdaugat < numarOferte) {
		randomIndex = distribution(twister);
		OfertaTuristica chosenOferta = this->repository.getOferta(randomIndex);
		if (!this->wishlist.inRepository(chosenOferta)) {
			this->wishlist.addOferta(chosenOferta);
			totalAdaugat++;
		}
	}
}

void Service::deleteWishlist() {
	this->wishlist.eraseRepository();
}

void Service::undo() {
	if (this->undoStack.size() != 0) {
		ActiuneUndo* toUndo = this->undoStack.top();
		toUndo->doUndo(this->repository);
		delete toUndo;
		this->undoStack.pop();
	}
	else {
		throw customException("Nu exista undo posibil!\n");
	}
}

void Service::importOferte(const std::string& filename) {
	std::ifstream fin(filename);
	std::string denumire, destinatie, tip;
	double pret;
	if (!fin.is_open())
		throw customException("Fisier corupt!\n");
	while (!fin.eof()) {
		fin >> denumire >> destinatie >> tip >> pret;
		//OfertaTuristica newOferta{ denumire, destinatie, tip, pret };
		this->addOferta(denumire, destinatie, tip, pret);
	}
	fin.close();
	//this->repository.importOferte(filename);
}

void Service::exportOferte(const std::string& filename) const {
	this->repository.exportOferte(filename);
}

void Service::reverseRepository() {
	std::vector<OfertaTuristica>& oferte = this->repository.getListaOferte();
	std::reverse(oferte.begin(), oferte.end());
}