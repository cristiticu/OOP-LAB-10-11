#pragma once
#include "oferta_domain.h"

class Observer{
public:
	virtual void updateSelfOfertaAdded(OfertaTuristica ofertaAdded) = 0;
	virtual void updateSelfOfertaRemoved(const unsigned int index) = 0;
	virtual void updateSelfOfertaModified(const unsigned int index, OfertaTuristica ofertaModified) = 0;
};

