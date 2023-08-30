#pragma once
#include "oferta_repository.h"
#include "oferta_domain.h"
#include "VectorDinamic.h"
#include "UndoAdauga.h"
#include "UndoModifica.h"
#include "UndoSterge.h"
#include <algorithm>
#include <chrono>
#include <stack>
#include <random>
#include <iterator>
#include <stdexcept>
#include "Observable.h"

/*Clasa pentru management-ul unui repository cu oferte
*/
class Service : public Observable {
private:
	Repository& repository;
	Repository& wishlist;
	std::stack<ActiuneUndo*> undoStack;

public:
	Service(Repository& _repository, Repository& _wishlist);
	~Service();

	/*Metoda ce va returna toate ofertele din repository
	* :return: vector cu toate ofertele
	*/
	std::vector<OfertaTuristica> getAllOferte() const;

	/*Metoda ce va returna toate ofertele din wishlist
	* :return: vector cu toate ofertele din wishlist
	*/
	std::vector<OfertaTuristica> getWishlist() const;

	/*Metoda ce va adauga o oferta in repository
	* :param denumire: denumirea ofertei noi
	* :param destinatie: destinatia ofertei noi
	* :param tip: tipul ofertei noi
	* :param pret: pretul ofertei noi
	*/
	void addOferta(const std::string& denumire, const std::string& destinatie, const std::string& tip, const double pret);

	/*Metoda ce va adauga o oferta dupa index in wishlist
	* :param index: indexul ofertei
	*/
	void addOfertaWishlist(const unsigned int index);

	/*Metoda ce va sterge o oferta din repository
	* :param index: indexul ofertei ce trebuie stearsa
	*/
	void deleteOferta(const unsigned int index);

	/*Metoda ce va modifica o oferta din repository
	* :param index: indexul ofertei ce trebuie modificata
	* :param denumire: denumirea ofertei noi
	* :param destinatie: destinatia ofertei noi
	* :param tip: tipul ofertei noi
	* :param pret: pretul ofertei noi
	*/
	void modifyOferta(const unsigned int index, const std::string& denumire, const std::string& destinatie, const std::string& tip, const double pret);

	/*Metoda ce va cauta in repository o oferta anume
	* :params: datele ofertei
	* :return: o lista cu ofertele ce satisfac conditiile
	*/
	std::vector<OfertaTuristica> searchOferta(const std::string& denumire, const std::string& destinatie, const std::string& tip) const;

	/*Metoda ce va cauta in repository o oferta cu o destinatie anume
	* :param destinatie: destinatia ofertei
	* :return: o lista cu ofertele ce satisfac conditiile
	*/
	std::vector<OfertaTuristica> filtrareOferteDestinatie(const std::string& destinatie) const;

	/*Metoda ce va cauta in repository o oferta cu un pret anume
	* :param pret: pretul ofertei
	* :return: o lista cu ofertele ce satisfac conditiile
	*/
	std::vector<OfertaTuristica> filtrareOfertePret(const double pret) const;

	/*Metoda ce returneaza o lista cu oferte sortate dupa denumire
	*/
	std::vector<OfertaTuristica> sortareOferteDenumire() const;

	/*Metoda ce returneaza o lista cu oferte sortate dupa destinatie
	*/
	std::vector<OfertaTuristica> sortareOferteDestinatie() const;

	/*Metoda ce returneaza o lista cu oferte sortate dupa tip si pret
	*/
	std::vector<OfertaTuristica> sortareOferteTipPret() const;

	/*Metoda ce va genera un cos de oferte random
	* :param numarOferte: numarul ofertelor de adaugat
	*/
	void genereazaWishlist(const unsigned int numarOferte);

	/*Metoda ce va sterge toate ofertele din wishlist
	*/
	void deleteWishlist();

	/*Metoda ce va anula efectele ultimelor comenzi
	*/
	void undo();

	/*Metoda ce va importa oferte din fisier in repository
	* :param filename: numele fisierului
	*/
	void importOferte(const std::string& filename);

	/*Metoda ce va exporta oferte in fisier din repository
	* :param filename: numele fisierului
	*/
	void exportOferte(const std::string& filename) const;

	/*Metoda ce va inversa ofertele din repository
	*/
	void reverseRepository();
};
