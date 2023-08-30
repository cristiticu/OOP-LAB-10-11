#include "UndoSterge.h"

void UndoSterge::doUndo(Repository& repositoryAfectat) {
	repositoryAfectat.addOferta(this->ofertaAfectata);
}