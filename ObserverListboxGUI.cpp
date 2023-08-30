#include "ObserverListboxGUI.h"

ObserverListboxGUI::ObserverListboxGUI(Service& _observableRef, QWidget* parent) : observableRef(_observableRef), ObserverGUIBase{parent} {
	this->mainHorizontalLayout = new QHBoxLayout;
	this->setLayout(mainHorizontalLayout);
	this->ofertaListBox = new QListWidget;
	this->mainHorizontalLayout->addWidget(this->ofertaListBox);
	this->loadExistingData();
}

ObserverListboxGUI::~ObserverListboxGUI(){
	this->observableRef.unlinkObserver(this);
}


void ObserverListboxGUI::updateSelfOfertaAdded(OfertaTuristica ofertaAdded) {
	std::string listString;
	listString += ofertaAdded.getDenumire();
	QString qstring = QString::fromStdString(listString);
	this->ofertaListBox->addItem(qstring);
}

void ObserverListboxGUI::updateSelfOfertaRemoved(const unsigned int index) {
	this->ofertaListBox->takeItem(index);
}

void ObserverListboxGUI::updateSelfOfertaModified(const unsigned int index, OfertaTuristica ofertaModified) {
	std::string listString;
	listString += ofertaModified.getDenumire();
	QString qstring = QString::fromStdString(listString);
	this->ofertaListBox->takeItem(index);
	this->ofertaListBox->insertItem(index, qstring);
}

void ObserverListboxGUI::loadExistingData() {
	for (auto& oferta : this->observableRef.getAllOferte())
		this->updateSelfOfertaAdded(oferta);
}
