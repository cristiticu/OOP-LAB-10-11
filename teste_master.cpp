#include "teste_master.h"

void testEverything() {
	DomainTester domainTester;
	RepositoryTester repositoryTester;
	ServiceTester serviceTester;
	UndoTester undoTester;

	domainTester.testAllDomain();
	repositoryTester.testAllRepository();
	serviceTester.testAllService();
	undoTester.testAllUndo();

	testAllVectorDinamic();
}