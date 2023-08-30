#pragma once
#include "oferta_domain.h"
#include "oferta_repository.h"
#include "oferta_service.h"
#include <iostream>
#include <assert.h>
#include <stdexcept>

class ServiceTester {
public:
	void testAllService();

	void testGenereazaWishlist();

	void testGetAllOferte();

	void testAddOferta();

	void testDeleteOferta();

	void testModifyOferta();

	void testSearchOferta();

	void testFiltrareOferte();

	void testSorteazaOferte();

	void testUndo();
};