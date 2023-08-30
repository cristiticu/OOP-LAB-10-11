#include "UndoAdauga.h"

void UndoAdauga::doUndo(Repository& repositoryAfectat) {
	repositoryAfectat.deleteOferta(this->ofertaAfectata);
}
