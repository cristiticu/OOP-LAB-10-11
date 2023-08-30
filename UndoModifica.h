#pragma once
#include "ActiuneUndo.h"

class UndoModifica : public ActiuneUndo {
private:
	unsigned int indexOferta;
public:
	UndoModifica(OfertaTuristica ofertaAfectata, unsigned int _index) : ActiuneUndo{ ofertaAfectata }, indexOferta(_index) {};
	void doUndo(Repository& repositoryAfectat) override;
};

