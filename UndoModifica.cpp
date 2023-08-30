#include "UndoModifica.h"

void UndoModifica::doUndo(Repository& repositoryAfectat) {
	repositoryAfectat.modifyOferta(this->indexOferta,this->ofertaAfectata);
}
