#include "oferta_repository.h"

size_t Repository::getSize() const {
	return this->listaElemente.size();
}

std::vector<OfertaTuristica> Repository::getListaOferte() const {
	return this->listaElemente;
}

std::vector<OfertaTuristica>& Repository::getListaOferte() {
	return this->listaElemente;
}

OfertaTuristica Repository::getOferta(const unsigned int index) const {
	if (index >= this->listaElemente.size())
		throw customException("Error! Index invalid pentru repository\n");
	return this->listaElemente[index];
}

OfertaTuristica& Repository::getOferta(const unsigned int index) {
	if (index >= this->listaElemente.size())
		throw customException("Error! Index invalid pentru repository\n");
	return this->listaElemente[index];
}

OfertaTuristica Repository::getOferta(const OfertaTuristica& toGet) const {
	auto returned = std::find_if(this->listaElemente.begin(), this->listaElemente.end(), [toGet](OfertaTuristica oferta) {return oferta == toGet; });
	if (returned != this->listaElemente.end())
		return *returned;
	throw customException("Error! Oferta nu e in repository");
	/*
	for (unsigned int i = 0; i < this->listaElemente.size(); i++)
		if (this->listaElemente[i] == toGet)
			return this->listaElemente[i];
	throw std::invalid_argument("Error! Oferta nu e in repository");*/
}

bool Repository::inRepository(const OfertaTuristica& toCheck) const {
	for (auto& oferta : this->listaElemente)
		if (oferta == toCheck)
			return true;
	return false;
	/*
	for (unsigned int i = 0; i < this->listaElemente.size(); i++)
		if (this->listaElemente[i] == toCheck)
			return true;
	return false;*/
}

void Repository::addOferta(const OfertaTuristica toAdd) {
	if (this->inRepository(toAdd))
		throw customException("Error! Oferta este deja in repository!\n");
	this->listaElemente.push_back(toAdd);
}

void Repository::addActualOferta(OfertaTuristica& toAdd) {
	if (this->inRepository(toAdd))
		throw customException("Error! Oferta este deja in repository!\n");
	this->listaElemente.push_back(toAdd);
}

void Repository::deleteOferta(const OfertaTuristica& toDelete) {
	auto returned = std::find_if(this->listaElemente.begin(), this->listaElemente.end(), [toDelete](OfertaTuristica oferta) {return oferta == toDelete; });
	if (returned != this->listaElemente.end()) {
		this->listaElemente.erase(returned);
		return;
	}
	throw customException("Error! Oferta nu este in repository!\n");
	/*for (unsigned int i = 0; i < this->listaElemente.size(); i++)
		if (this->listaElemente[i] == toDelete) {
			this->listaElemente.erase(this->listaElemente.begin() + i);
			return;
		}
	throw std::invalid_argument("Error! Oferta nu este in repository!\n");*/
}

void Repository::deleteOferta(const unsigned int index) {
	if (index >= this->listaElemente.size())
		throw customException("Error! Index invalid pentru repository\n");
	this->listaElemente.erase(this->listaElemente.begin() + index);
}

void Repository::modifyOferta(const OfertaTuristica toModify) {
	auto returned = std::find_if(this->listaElemente.begin(), this->listaElemente.end(), [toModify](OfertaTuristica oferta) {return oferta == toModify; });
	if (returned != this->listaElemente.end()) {
		*returned = toModify;
		return;
	}
	throw customException("Error! Oferta nu este in repository!\n");
	/*for (unsigned int i = 0; i < this->listaElemente.size(); i++)
		if (this->listaElemente[i] == toModify) {
			this->listaElemente[i] = toModify;
			return;
		}
	throw std::invalid_argument("Error! Oferta nu este in repository!\n");*/
}

void Repository::modifyOferta(const unsigned int index, const OfertaTuristica toModify) {
	if (index >= this->listaElemente.size())
		throw customException("Error! Index invalid pentru repository\n");
	this->listaElemente[index] = toModify;
}

void Repository::eraseRepository() {
	this->listaElemente.clear();
}

void Repository::importOferte(const std::string& filename) {
	std::ifstream fin(filename);
	std::string denumire, destinatie, tip;
	double pret;
	if (!fin.is_open())
		throw customException("Fisier corupt!\n");
	while (!fin.eof()) {
		fin >> denumire >> destinatie >> tip >> pret;
		OfertaTuristica newOferta{ denumire, destinatie, tip, pret };
		this->addOferta(newOferta);
	}
	fin.close();
}

void Repository::exportOferte(const std::string& filename) const {
	std::ofstream fout(filename);
	if (!fout.is_open())
		throw customException("Fisier corupt!\n");
	int contor = 0;
	int numberOferte = this->listaElemente.size();
	for (auto& oferta : this->listaElemente) {
		contor++;
		fout << oferta.getDenumire() << "\n";
		fout << oferta.getDestinatie() << "\n";
		fout << oferta.getTip() << "\n";
		fout << oferta.getPret();
		if (contor != numberOferte)
			fout << "\n";
	}
	fout.close();
}
