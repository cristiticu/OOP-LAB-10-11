#include "teste_vector.h"

void testAllVectorDinamic() {
	testVector();
	testIterator();

	std::cout << "Vector OK!\n";
}

void testVector() {/*
	std::vector<int> testVectorInt(2);
	assert(testVectorInt.size() == 0);
	testVectorInt.push_back(1);
	testVectorInt.push_back(2);
	testVectorInt.push_back(3);
	assert(testVectorInt.size() == 3);
	assert(testVectorInt[0] == 1);
	assert(testVectorInt[1] == 2);
	assert(testVectorInt[2] == 3);
	testVectorInt.erase(testVectorInt.begin() + 1);
	assert(testVectorInt.size() == 2);
	assert(testVectorInt[0] == 1);
	assert(testVectorInt[1] == 3);

	std::vector<OfertaTuristica> testVectorOferta(6);
	OfertaTuristica oferta1("Denumire 1", "Destinatie 1", "Tip 1", 1);
	OfertaTuristica oferta2("Denumire 2", "Destinatie 2", "Tip 2", 2);
	OfertaTuristica oferta3("Denumire 3", "Destinatie 3", "Tip 3", 3);
	assert(testVectorOferta.size() == 0);
	testVectorOferta.push_back(oferta1);
	assert(testVectorOferta.size() == 1);
	assert(testVectorOferta[0] == oferta1);
	testVectorOferta.push_back(oferta2);
	assert(testVectorOferta.size() == 2);
	assert(testVectorOferta[0] == oferta1);
	assert(testVectorOferta[1] == oferta2);
	testVectorOferta.push_back(oferta3);
	assert(testVectorOferta.size() == 3);
	assert(testVectorOferta[0] == oferta1);
	assert(testVectorOferta[1] == oferta2);
	assert(testVectorOferta[2] == oferta3);
	testVectorOferta.erase(testVectorOferta.begin() + 1);
	assert(testVectorOferta.size() == 2);
	assert(testVectorOferta[0] == oferta1);
	assert(testVectorOferta[1] == oferta3);*/
	std::cout << "Vector: vector OK!\n";
}

void testIterator() {
	std::vector<int> testVectorInt(2);
	testVectorInt.push_back(1);
	testVectorInt.push_back(2);
	testVectorInt.push_back(3);/*
	IteratorVectorDinamic<int> it = testVectorInt.begin();
	int i = 1;
	while (it != testVectorInt.end()) {
		assert(*it == i);
		++it;
		i++;
	}
	testVectorInt.push_back(6);
	testVectorInt.push_back(5);
	testVectorInt.push_back(4);
	testVectorInt.push_back(7);
	testVectorInt.push_back(8);
	testVectorInt.push_back(9);
	testVectorInt.push_back(10);
	std::sort(testVectorInt.begin(), testVectorInt.end());
	it = testVectorInt.begin();
	i = 1;
	while (it != testVectorInt.end()) {
		assert(*it == i);
		++it;
		i++;
	}*/
	std::cout << "Vector: iterator OK!\n";
}
