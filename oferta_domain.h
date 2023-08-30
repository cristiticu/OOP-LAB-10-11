#pragma once
#include <string>

#define STANDARD_OFERTA_DENUMIRE "Denumire"
#define STANDARD_OFERTA_DESTINATIE "Destinatie"
#define STANDARD_OFERTA_TIP "Tip"
#define STANDARD_OFERTA_PRET 0.0

/*
* Clasa pentru a defini un TAD care reprezinta o oferta turistica
* Contine denumire, destinatie, tip si pret
*  Utilizata cu metodele aferente
*/
class OfertaTuristica {
private:

	std::string denumire;
	std::string destinatie;
	std::string tip;
	double pret;

public:

	/*
	* Constructor pentru un obiect de tip oferta turistica. Initializeaza campurile cu valori predefinite
	*/
	OfertaTuristica() noexcept;

	/*
	* Constructor pentru un obiect de tip oferta turistica. Initializeaza campurile cu parametrii dati
	* :param denumire: denumirea ofertei
	* :param destinatie: destinatia ofertei
	* :param tip: tipul ofertei
	* :param pret: pretul ofertei
	*/
	OfertaTuristica(const std::string& denumire, const std::string& destinatie, const std::string& tip, const double pret) noexcept;

	/*
	* Functie getter pentru denumirea unei oferte
	* :return: denumirea ofertei
	*/
	std::string getDenumire() const noexcept;

	/*
	* Functie getter pentru destinatia unei oferte
	* :return: destinatia ofertei
	*/
	std::string getDestinatie() const noexcept;

	/*
	* Functie getter pentru tipul unei oferte
	* :return: tipul ofertei
	*/
	std::string getTip() const noexcept;

	/*
	* Functie getter pentru pretul unei oferte
	* :return: pretul ofertei
	*/
	double getPret() const noexcept;

	/*
	* Functie setter pentru denumirea unei oferte
	*/
	void setDenumire(const std::string& newDenumire);

	/*
	* Functie setter pentru destinatia unei oferte
	*/
	void setDestinatie(const std::string& newDestinatie);

	/*
	* Functie setter pentru tipul unei oferte
	*/
	void setTip(const std::string& newTip);

	/*
	* Functie setter pentru pretul unei oferte
	*/
	void setPret(const double newPret);

	/* Overload operator egalitate intre doua oferte turistice
	*/
	bool operator==(const OfertaTuristica& other) const;

	/* Overload operator inegalitate intre doua oferte turistice
	*/
	bool operator!=(const OfertaTuristica& other) const;

	bool operator<(const OfertaTuristica& other) const;
};
