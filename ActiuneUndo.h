#pragma once
#include "oferta_domain.h"
#include "oferta_repository.h"

class ActiuneUndo{
protected:
	OfertaTuristica ofertaAfectata;
public:
	ActiuneUndo(OfertaTuristica _ofertaAfectata): ofertaAfectata(_ofertaAfectata) {}
	virtual void doUndo(Repository& repositoryAfectat) = 0;

};

