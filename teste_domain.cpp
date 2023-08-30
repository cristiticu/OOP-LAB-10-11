#include "teste_domain.h"

void DomainTester::testAllDomain() {
	testConstructorsDomain();
	testGettersDomain();
	testSettersDomain();
	testOperators();
	std::cout << "Domain: OK!\n";
}

void DomainTester::testConstructorsDomain() {
	OfertaTuristica oferta1;
	OfertaTuristica oferta2{"Test 1", "Test d 1", "Test t 1", 1.1};
	assert(oferta1.getDenumire() == STANDARD_OFERTA_DENUMIRE);
	assert(oferta1.getDestinatie() == STANDARD_OFERTA_DESTINATIE);
	assert(oferta1.getTip() == STANDARD_OFERTA_TIP);
	assert(oferta1.getPret() == STANDARD_OFERTA_PRET);
	assert(oferta2.getDenumire() == "Test 1");
	assert(oferta2.getDestinatie() == "Test d 1");
	assert(oferta2.getTip() == "Test t 1");
	assert(oferta2.getPret() == 1.1);

	std::string first = "First string";
	std::string& reference = first;
	std::string second = reference;
	reference = "Changed!";
	assert(second == "First string");
	assert(first == "Changed!");
	std::cout << "Domain: Constructors OK!\n";
}

void DomainTester::testGettersDomain() {
	OfertaTuristica oferta1;
	OfertaTuristica oferta2{ "Test 1", "Test d 1", "Test t 1", 1.1 };
	assert(oferta1.getDenumire() == STANDARD_OFERTA_DENUMIRE);
	assert(oferta1.getDestinatie() == STANDARD_OFERTA_DESTINATIE);
	assert(oferta1.getTip() == STANDARD_OFERTA_TIP);
	assert(oferta1.getPret() == STANDARD_OFERTA_PRET);
	assert(oferta2.getDenumire() == "Test 1");
	assert(oferta2.getDestinatie() == "Test d 1");
	assert(oferta2.getTip() == "Test t 1");
	assert(oferta2.getPret() == 1.1);
	std::cout << "Domain: Getters OK!\n";
}

void DomainTester::testSettersDomain() {
	OfertaTuristica oferta1;
	oferta1.setDenumire("Setat Denumire");
	oferta1.setDestinatie("Setat Destinatie");
	oferta1.setTip("Setat Tip");
	oferta1.setPret(1111);
	assert(oferta1.getDenumire() == "Setat Denumire");
	assert(oferta1.getDestinatie() == "Setat Destinatie");
	assert(oferta1.getTip() == "Setat Tip");
	assert(oferta1.getPret() == 1111);
	std::cout << "Domain: Setters OK!\n";
}

void DomainTester::testOperators() {
	OfertaTuristica oferta1;
	OfertaTuristica oferta2;
	assert(oferta1 == oferta2);
	assert(!(oferta1 != oferta2));
	oferta1.setDenumire("Schimbat!");
	assert(oferta1 != oferta2);
	assert(!(oferta1 == oferta2));
	std::cout << "Domain: Operators OK!\n";
}
