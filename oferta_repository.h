#pragma once
#include <vector>
#include "exception.h"
#include "fstream"
#include "oferta_domain.h"
#include "VectorDinamic.h"

/*Clasa pentru a implementa un TAD Repository pentru stocarea de oferte imobiliare
*/
class Repository {
private:

	std::vector<OfertaTuristica> listaElemente;

public:

	/*Constructor pentru un obiect Repository;
	*/
	Repository(){}

	/*Metoda pentru a returna numarul de elemente din repository
	* :return: numarul de elemente din repository
	*/
	size_t getSize() const;

	/*Metoda pentru a returna o copie a listei de elemente din repository
	* :return: o copie a listei de elemente
	*/
	std::vector<OfertaTuristica> getListaOferte() const;

	std::vector<OfertaTuristica>& getListaOferte();

	/*Metoda pentru a returna o copie a unei oferte date de un index.
	* :return: oferta de la indexul respectiv
	* :raises: exception daca indexul este invalid
	*/
	OfertaTuristica getOferta(const unsigned int index) const;

	/*Metoda pentru a returna o copie a unei oferte date de o oferta template.
	* :return: oferta respectiva
	* :raises: exception daca indexul este invalid
	*/
	OfertaTuristica getOferta(const OfertaTuristica& toGet) const;

	/*Metoda pentru a returna oferta efectiva data de un index.
	* :return: oferta de la indexul respectiv
	* :raises: exception daca indexul este invalid
	*/
	OfertaTuristica& getOferta(const unsigned int index);

	/*Metoda ce verifica daca o oferta este sau nu in repository
	* :param toCheck: oferta ce trebuie verificata
	* :return: true / false daca este in repository / nu este in repository
	*/
	bool inRepository(const OfertaTuristica& toCheck) const;

	/*Metoda pentru a adauga o oferta in repository
	* :param toAdd: oferta ce trebuie adaugata
	* :raises: exception daca oferta este deja in repository
	*/
	void addOferta(const OfertaTuristica toAdd);

	/*Metoda pentru a adauga o oferta in repository
	* :param toAdd: oferta ce trebuie adaugata
	* :raises: exception daca oferta este deja in repository
	*/
	void addActualOferta(OfertaTuristica& toAdd);

	/*Metoda pentru a sterge o oferta din repository
	* :param toAdd: oferta ce trebuie stearsa
	* :raises: exception daca oferta nu este in repository
	*/
	void deleteOferta(const OfertaTuristica& toDelete);

	/*Metoda pentru a sterge o oferta din repository
	* :param index: indexul ofertei ce trebuie stearsa
	* :raises: exception daca oferta nu este in repository
	*/
	void deleteOferta(const unsigned int index);

	/*Metoda pentru a modifica o oferta din repository
	* :param toAdd: oferta ce trebuie modificata
	* :raises: exception daca oferta nu este in repository
	*/
	void modifyOferta(const OfertaTuristica toModify);

	/*Metoda pentru a modifica o oferta din repository
	* :param toAdd: indexul ofertei ce trebuie modificata
	* :raises: exception daca indexul este invalid
	*/
	void modifyOferta(const unsigned int index, const OfertaTuristica toModify);

	/*Metoda ce va sterge continutul vectorului
	*/
	void eraseRepository();

	/*Metoda ce va importa oferte dintr-un fisier
	* :param filename: numele fisierului
	*/
	void importOferte(const std::string& filename);

	/*Metoda ce va exporta oferte intr-un fisier
	* :param filename: numele fisierului
	*/
	void exportOferte(const std::string& filename) const;
};
