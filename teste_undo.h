#pragma once
#include <iostream>
#include "oferta_domain.h"
#include "oferta_repository.h"
#include "UndoAdauga.h"
#include "UndoSterge.h"
#include "UndoModifica.h"
#include <assert.h>

class UndoTester{
public:
	void testAllUndo();
};

