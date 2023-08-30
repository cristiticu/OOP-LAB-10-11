#include "teste_undo.h"

void UndoTester::testAllUndo() {
	OfertaTuristica oferta1{ "Denumire1", "Destinatie1", "Tip1", 1 };
	OfertaTuristica oferta2{ "Denumire2", "Destinatie2", "Tip2", 2 };
	OfertaTuristica oferta3{ "Denumire3", "Destinatie3", "Tip3", 3 };
	OfertaTuristica oferta11{ "Denumire1", "Destinatie1", "Tip1", 232 };
	Repository repo{};
	repo.addOferta(oferta1);
	UndoAdauga undo1(oferta1);
	undo1.doUndo(repo);
	assert(repo.getSize() == 0);
	repo.addOferta(oferta2);
	repo.addOferta(oferta1);
	undo1.doUndo(repo);
	assert(repo.getSize() == 1);
	assert(repo.getListaOferte()[0] == oferta2);
	UndoAdauga undo2(oferta2);
	undo2.doUndo(repo);
	assert(repo.getSize() == 0);
	UndoSterge undo3(oferta2);
	undo3.doUndo(repo);
	assert(repo.getSize() == 1);
	assert(repo.getListaOferte()[0] == oferta2);
	repo.addOferta(oferta1);
	repo.modifyOferta(oferta11);
	UndoModifica undo4(oferta1, 1);
	undo4.doUndo(repo);
	assert(repo.getListaOferte()[1].getPret() == 1);

	std::cout << "Undo: OK!\n";
}
