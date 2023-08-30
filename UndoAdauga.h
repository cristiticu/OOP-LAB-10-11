#pragma once
#include "ActiuneUndo.h"
class UndoAdauga : public ActiuneUndo {
public:
	UndoAdauga(OfertaTuristica ofertaAfectata) : ActiuneUndo{ ofertaAfectata } {}
	void doUndo(Repository& repositoryAfectat) override;
};

