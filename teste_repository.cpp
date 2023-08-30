#include "teste_repository.h"

void RepositoryTester::testAllRepository() {
	testConstructor();
	testGetSize();
	testGetAllElements();
	testGetOferta();
	testInRepository();
	testAddOferta();
	testDeleteOferta();
	testModifyOferta();

	std::cout << "Repository: OK!\n";
}
void RepositoryTester::testConstructor() {
	Repository repo;
	assert(repo.getSize() == 0);
	std::cout << "Repository: Constructor OK!\n";
}

void RepositoryTester::testGetSize() {
	Repository repo;
	assert(repo.getSize() == 0);
	std::cout << "Repository: getSize OK!\n";
}

void RepositoryTester::testGetAllElements() {
	Repository repo;
	OfertaTuristica oferta1;
	OfertaTuristica oferta2;
	assert(repo.getListaOferte().size() == 0);
	repo.addOferta(oferta1);
	assert(repo.getListaOferte().size() == 1);
	repo.deleteOferta(oferta1);
	assert(repo.getListaOferte().size() == 0);
	std::cout << "Repository: getAllElements OK!\n";
}

void RepositoryTester::testGetOferta() {
	Repository repo;
	OfertaTuristica oferta1;
	OfertaTuristica oferta2;
	OfertaTuristica oferta3{ "123123" , "123213", "213213", 2323};
	repo.addOferta(oferta1);
	assert(repo.getOferta(0) == oferta1);
	assert(repo.getOferta(oferta2) == oferta1);
	try {
		repo.getOferta(1);
		assert(false);
	}
	catch(customException&){
		assert(true);
	}
	try {
		repo.getOferta(oferta3);
		assert(false);
	}
	catch (customException&) {
		assert(true);
	}
	std::cout << "Repository: getOferta OK!\n";
}

void RepositoryTester::testInRepository() {
	Repository repo;
	OfertaTuristica oferta1;
	OfertaTuristica oferta2;
	OfertaTuristica oferta3{ "123123" , "123213", "213213", 2323 };
	repo.addOferta(oferta1);
	assert(repo.inRepository(oferta1));
	assert(repo.inRepository(oferta2));
	assert(!repo.inRepository(oferta3));
	std::cout << "Repository: inRepository OK!\n";
}

void RepositoryTester::testAddOferta() {
	Repository repo;
	OfertaTuristica oferta1;
	OfertaTuristica oferta2;
	OfertaTuristica oferta3{ "123123" , "123213", "213213", 2323 };
	repo.addOferta(oferta1);
	assert(repo.inRepository(oferta1));
	assert(repo.inRepository(oferta2));
	assert(!repo.inRepository(oferta3));
	try {
		repo.addOferta(oferta2);
		assert(false);
	}
	catch (customException&) {
		assert(true);
	}
	std::cout << "Repository: addOferta OK!\n";
}

void RepositoryTester::testModifyOferta() {
	Repository repo;
	OfertaTuristica oferta1;
	OfertaTuristica oferta2;
	OfertaTuristica oferta3{ "123123" , "123213", "213213", 2323 };
	OfertaTuristica oferta4{ "123123" , "123213", "213213", 65656 };
	repo.addOferta(oferta1);
	repo.modifyOferta(0, oferta3);
	assert(repo.getOferta(0) == oferta3);
	repo.modifyOferta(oferta4);
	assert(repo.getOferta(0) == oferta4);
	repo.deleteOferta(0);
	try {
		repo.modifyOferta(43534, oferta2);
		assert(false);
	}
	catch (customException&) {
		assert(true);
	}
	try {
		repo.modifyOferta(oferta3);
		assert(false);
	}
	catch (customException&) {
		assert(true);
	}
	std::cout << "Repository: modifyOferta OK!\n";
}

void RepositoryTester::testDeleteOferta() {
	Repository repo;
	OfertaTuristica oferta1;
	OfertaTuristica oferta2;
	OfertaTuristica oferta3{ "123123" , "123213", "213213", 2323 };
	repo.addOferta(oferta1);
	assert(repo.inRepository(oferta1));
	assert(repo.inRepository(oferta2));
	assert(!repo.inRepository(oferta3));
	repo.deleteOferta(oferta2);
	assert(!repo.inRepository(oferta1));
	repo.addOferta(oferta3);
	assert(repo.inRepository(oferta3));
	repo.deleteOferta(0);
	assert(!repo.inRepository(oferta3));
	try {
		repo.deleteOferta(0);
		assert(false);
	}
	catch (customException&) {
		assert(true);
	}
	try {
		repo.deleteOferta(oferta2);
		assert(false);
	}
	catch (customException&) {
		assert(true);
	}
	std::cout << "Repository: deleteOferta OK!\n";
}
