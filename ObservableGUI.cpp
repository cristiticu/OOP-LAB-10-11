#include "ObservableGUI.h"

void ObservableGUI::adaugaOfertaButtonClicked() {
	std::string denumire, destinatie, tip;
	double pret = 0;
	denumire = this->denumireLabel->text().toStdString();
	destinatie = this->destinatieLabel->text().toStdString();
	tip = this->tipLabel->text().toStdString();
	try {
		pret = std::stod(this->pretLabel->text().toStdString());
		this->effectiveService.addOferta(denumire, destinatie, tip, pret);
	}
	catch (std::invalid_argument&) {}
	catch (customException&) {}
}

void ObservableGUI::stergeOfertaButtonClicked() {
	QList<QListWidgetItem*> items = this->observerListBox->ofertaListBox->selectedItems();
	if (items.size() != 0) {
		auto itemRow = this->observerListBox->ofertaListBox->row(items[0]);
		try {
			this->effectiveService.deleteOferta(itemRow);
		}
		catch (customException&) {}
	}
}
