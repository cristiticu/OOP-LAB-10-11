#include "teste_service.h"

void ServiceTester::testAllService() {
	testGetAllOferte();
	testAddOferta();
	testDeleteOferta();
	testModifyOferta();
	testSearchOferta();
	testFiltrareOferte();
	testSorteazaOferte();
	testGenereazaWishlist();
	testUndo();
	std::cout << "Service: OK!\n";
}

void ServiceTester::testGenereazaWishlist() {
	Repository repo;
	Repository wishlist;
	Service service(repo, wishlist);
	OfertaTuristica oferta1("Test", "Test", "Test", 2);
	OfertaTuristica oferta2("Test22", "Test22", "Test22", 40);
	OfertaTuristica oferta3("Test", "Test22", "Test22", 40);
	service.addOferta("Test", "Test", "Test", 2);
	service.addOferta("Test22", "Test22", "Test22", 40);
	service.addOferta("Test", "Test22", "Test22", 40);
	service.genereazaWishlist(3);
	assert(service.getWishlist().size() == 3);
	try {
		service.addOfertaWishlist(0);
		assert(false);
	}
	catch (customException&) {
		assert(true);
	}
	try {
		service.addOfertaWishlist(1);
		assert(false);
	}
	catch (customException&) {
		assert(true);
	}
	try {
		service.addOfertaWishlist(2);
		assert(false);
	}
	catch (customException&) {
		assert(true);
	}

	std::cout << "Service: genereazaWishlist OK!\n";
}

void ServiceTester::testGetAllOferte() {
	Repository repo;
	Service service(repo, repo);
	OfertaTuristica oferta1("Test", "Test", "Test", 2);
	service.addOferta("Test", "Test", "Test", 1);
	assert(service.getAllOferte()[0] == oferta1);
	std::cout << "Service: getAllOferte OK!\n";
}

void ServiceTester::testAddOferta() {
	Repository repo;
	Service service(repo, repo);
	OfertaTuristica oferta1("Test", "Test", "Test", 2);
	OfertaTuristica oferta2("Test22", "Test22", "Test22", 222);
	service.addOferta("Test", "Test", "Test", 1);
	assert(service.getAllOferte()[0] == oferta1);
	service.addOferta("Test22", "Test22", "Test22", 1);
	assert(service.getAllOferte()[0] == oferta1);
	assert(service.getAllOferte()[1] == oferta2);
	std::cout << "Service: addOferta OK!\n";
}

void ServiceTester::testDeleteOferta() {
	Repository repo;
	Service service(repo, repo);
	OfertaTuristica oferta1("Test", "Test", "Test", 2);
	OfertaTuristica oferta2("Test22", "Test22", "Test22", 222);
	service.addOferta("Test", "Test", "Test", 1);
	assert(service.getAllOferte()[0] == oferta1);
	service.addOferta("Test22", "Test22", "Test22", 1);
	assert(service.getAllOferte()[0] == oferta1);
	assert(service.getAllOferte()[1] == oferta2);
	service.deleteOferta(0);
	assert(service.getAllOferte()[0] == oferta2);
	assert(service.getAllOferte().size() == 1);
	service.deleteOferta(0);
	assert(service.getAllOferte().size() == 0);
	std::cout << "Service: deleteOferta OK!\n";
}

void ServiceTester::testModifyOferta() {
	Repository repo;
	Service service(repo, repo);
	OfertaTuristica oferta1("Test", "Test", "Test", 2);
	OfertaTuristica oferta2("Test22", "Test22", "Test22", 222);
	service.addOferta("Test", "Test", "Test", 1);
	assert(service.getAllOferte()[0] == oferta1);
	service.modifyOferta(0, "Test22", "Test22", "Test22", 1);
	assert(service.getAllOferte()[0] == oferta2);
	std::cout << "Service: modifyOferta OK!\n";
}

void ServiceTester::testSearchOferta() {
	Repository repo;
	Service service(repo, repo);
	OfertaTuristica oferta1("Test", "Test", "Test", 2);
	OfertaTuristica oferta2("Test22", "Test22", "Test22", 222);
	std::vector<OfertaTuristica> result;
	service.addOferta("Test", "Test", "Test", 2);
	result = service.searchOferta("Test", "Test", "Test");
	assert(result.size() == 1);
	assert(result[0] == oferta1);
	result = service.searchOferta("Test22", "Test2323", "Test");
	assert(result.size() == 0);
	std::cout << "Service: searchOferta OK!\n";
}

void ServiceTester::testFiltrareOferte() {
	Repository repo;
	Service service(repo, repo);
	OfertaTuristica oferta1("Test", "Test", "Test", 2);
	OfertaTuristica oferta2("Test22", "Test22", "Test22", 40);
	OfertaTuristica oferta3("Test", "Test22", "Test22", 40);
	service.addOferta("Test", "Test", "Test", 2);
	service.addOferta("Test22", "Test22", "Test22", 40);
	service.addOferta("Test", "Test22", "Test22", 40);
	std::vector<OfertaTuristica> result;
	result = service.filtrareOferteDestinatie("Test");
	assert(result.size() == 1);
	assert(result[0] == oferta1);
	result = service.filtrareOferteDestinatie("Test22");
	assert(result.size() == 2);
	assert(result[0] == oferta2);
	assert(result[1] == oferta3);
	result = service.filtrareOfertePret(2);
	assert(result.size() == 1);
	assert(result[0] == oferta1);
	result = service.filtrareOfertePret(40);
	assert(result.size() == 2);
	assert(result[0] == oferta2);
	assert(result[1] == oferta3);

	std::cout << "Service: filtrare OK!\n";
}

void ServiceTester::testSorteazaOferte() {
	Repository repo;
	Service service(repo, repo);
	OfertaTuristica oferta1("A", "1", "A", 2);
	OfertaTuristica oferta2("B", "0", "A", 3);
	OfertaTuristica oferta3("C", "3", "B", 1);
	service.addOferta("A", "1", "A", 2);
	service.addOferta("B", "0", "A", 3);
	service.addOferta("C", "3", "B", 1);
	std::vector<OfertaTuristica> result;
	result = service.sortareOferteDenumire();
	assert(result.size() == 3);
	assert(result[2] == oferta1);
	assert(result[1] == oferta2);
	assert(result[0] == oferta3);
	result = service.sortareOferteDestinatie();
	assert(result.size() == 3);
	assert(result[0] == oferta3);
	assert(result[1] == oferta1);
	assert(result[2] == oferta2);
	result = service.sortareOferteTipPret();
	assert(result.size() == 3);
	assert(result[0] == oferta3);
	assert(result[1] == oferta2);
	assert(result[2] == oferta1);
	std::cout << "Service: sortare OK!\n";
}

void ServiceTester::testUndo() {
	Repository repo;
	Repository wishlist;
	Service service(repo, wishlist);
	OfertaTuristica oferta1("A", "1", "A", 2);
	OfertaTuristica oferta2("B", "0", "A", 3);
	OfertaTuristica oferta3("C", "3", "B", 1);
	OfertaTuristica oferta11{ "A", "1", "A", 2000 };
	try {
		service.undo();
		assert(false);
	}
	catch (customException&) {
		assert(true);
	}
	service.addOferta("A", "1", "A", 2);
	assert(service.getAllOferte()[0] == oferta1);
	service.undo();
	assert(service.getAllOferte().size() == 0);
	service.addOferta("A", "1", "A", 2);
	service.addOferta("C", "3", "B", 1);
	service.deleteOferta(1);
	service.undo();
	assert(service.getAllOferte()[1] == oferta3);
	service.undo();
	service.undo();
	assert(service.getAllOferte().size() == 0);
	service.addOferta("A", "1", "A", 2);
	service.modifyOferta(0, "A", "1", "A", 2000);
	service.undo();
	assert(service.getAllOferte()[0].getPret() == 2);
	std::cout << "Service: undo OK!\n";
}
