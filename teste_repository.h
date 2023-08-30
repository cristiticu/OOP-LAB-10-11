#pragma once
#include "oferta_repository.h"
#include <assert.h>
#include <iostream>

class RepositoryTester {
public:
	void testAllRepository();

	void testConstructor();

	void testGetSize();

	void testGetAllElements();

	void testGetOferta();

	void testInRepository();

	void testAddOferta();

	void testModifyOferta();

	void testDeleteOferta();
};


