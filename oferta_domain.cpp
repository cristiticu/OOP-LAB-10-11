#include "oferta_domain.h"

OfertaTuristica::OfertaTuristica() noexcept {
	this->denumire = STANDARD_OFERTA_DENUMIRE;
	this->destinatie = STANDARD_OFERTA_DESTINATIE;
	this->tip = STANDARD_OFERTA_TIP;
	this->pret = STANDARD_OFERTA_PRET;
}

OfertaTuristica::OfertaTuristica(const std::string& denumire, const std::string& destinatie, const std::string& tip, const double pret) noexcept {
	this->denumire = denumire;
	this->destinatie = destinatie;
	this->tip = tip;
	this->pret = pret;
}

std::string OfertaTuristica::getDenumire() const noexcept {
	return this->denumire;
}

std::string OfertaTuristica::getDestinatie() const noexcept {
	return this->destinatie;
}

std::string OfertaTuristica::getTip() const noexcept {
	return this->tip;
}

double OfertaTuristica::getPret() const noexcept {
	return this->pret;
}

void OfertaTuristica::setDenumire(const std::string& newDenumire) {
	this->denumire = newDenumire;
}

void OfertaTuristica::setDestinatie(const std::string& newDestinatie) {
	this->destinatie = newDestinatie;
}

void OfertaTuristica::setTip(const std::string& newTip) {
	this->tip = newTip;
}

void OfertaTuristica::setPret(const double newPret) {
	this->pret = newPret;
}

bool OfertaTuristica::operator==(const OfertaTuristica& other) const {
	if (other.denumire == this->denumire && other.destinatie == this->destinatie && other.tip == this->tip)
		return true;
	return false;
}

bool OfertaTuristica::operator!=(const OfertaTuristica& other) const {
	if (other.denumire != this->denumire || other.destinatie != this->destinatie || other.tip != this->tip)
		return true;
	return false;
}

bool OfertaTuristica::operator<(const OfertaTuristica& other) const {
	if (other.denumire < this->denumire)
		return false;
	return true;
}
