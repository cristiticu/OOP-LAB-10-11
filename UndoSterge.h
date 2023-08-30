#pragma once
#include "ActiuneUndo.h"

class UndoSterge : public ActiuneUndo{
public:
	UndoSterge(OfertaTuristica ofertaAfectata) : ActiuneUndo{ ofertaAfectata } {};
	void doUndo(Repository& repositoryAfectat) override;
};

