#pragma once
#include <vector>
#include "ObserverListboxGUI.h"
#include "oferta_domain.h"
#include <qlistwidget.h>
#include <string.h>
#include <conio.h>
#include "time.h"
#include <fstream>
#include "stdlib.h"
#include "math.h"
#include <vector>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qformlayout.h>
#include <qboxlayout.h>
#include <qbitmap.h>
#include <qscrollarea.h>
#include <qscrollbar.h>
#include <qgridlayout.h>
#include <qlistwidget.h>
#include <qtextformat.h>
#include "oferta_service.h"

class ObservableGUI : public ObserverGUIBase{
private:
	Service& effectiveService;

	QHBoxLayout* mainHLayout;
	QVBoxLayout* leftVLayout;
	QWidget* leftSide;
	QLineEdit* denumireLabel;
	QLineEdit* destinatieLabel;
	QLineEdit* tipLabel;
	QLineEdit* pretLabel;
	QWidget* dataWindow;
	QFormLayout* dataWindowFormLayout;
	QWidget* buttonHolder;
	QHBoxLayout* buttonHolderLayout;
	QPushButton* addOfertaButton;
	QPushButton* stergeOfertaButton;

	ObserverListboxGUI* observerListBox;

	void adaugaOfertaButtonClicked();
	void stergeOfertaButtonClicked();

public:
	ObservableGUI(Service& _effectiveRef, QWidget* parent = nullptr) : effectiveService(_effectiveRef), ObserverGUIBase{ parent } {
		observerListBox = new ObserverListboxGUI(this->effectiveService);
		this->effectiveService.linkNewObserver(this->observerListBox);

		this->mainHLayout = new QHBoxLayout;
		this->setLayout(this->mainHLayout);

		this->leftSide = new QWidget;
		this->leftVLayout = new QVBoxLayout;
		this->leftSide->setLayout(this->leftVLayout);

		this->dataWindow = new QWidget;
		this->dataWindowFormLayout = new QFormLayout;
		this->dataWindow->setLayout(this->dataWindowFormLayout);

		this->denumireLabel = new QLineEdit;
		this->destinatieLabel = new QLineEdit;
		this->tipLabel = new QLineEdit;
		this->pretLabel = new QLineEdit;

		this->dataWindowFormLayout->addRow("Denumire", this->denumireLabel);
		this->dataWindowFormLayout->addRow("Destinatie", this->destinatieLabel);
		this->dataWindowFormLayout->addRow("Tip", this->tipLabel);
		this->dataWindowFormLayout->addRow("Pret", this->pretLabel);

		this->buttonHolder = new QWidget;
		this->buttonHolderLayout = new QHBoxLayout;
		this->buttonHolder->setLayout(this->buttonHolderLayout);
		this->buttonHolder->setMaximumWidth(40 * 2 + 40);

		this->addOfertaButton = new QPushButton;
		this->stergeOfertaButton = new QPushButton;
		this->addOfertaButton->setIcon(QIcon("plus.png"));
		this->stergeOfertaButton->setIcon(QIcon("minus.png"));
		this->addOfertaButton->setMaximumWidth(40);
		this->stergeOfertaButton->setMaximumWidth(40);
		this->addOfertaButton->setToolTip("Adauga datele");
		this->stergeOfertaButton->setToolTip("Sterge selectia");

		QObject::connect(addOfertaButton, &QPushButton::clicked, this, &ObservableGUI::adaugaOfertaButtonClicked);
		QObject::connect(stergeOfertaButton, &QPushButton::clicked, this, &ObservableGUI::stergeOfertaButtonClicked);

		this->buttonHolderLayout->addWidget(this->addOfertaButton);
		this->buttonHolderLayout->addWidget(this->stergeOfertaButton);

		this->leftVLayout->addWidget(this->dataWindow);
		this->leftVLayout->addWidget(this->buttonHolder);

		this->mainHLayout->addWidget(this->observerListBox);
		this->mainHLayout->addWidget(this->leftSide);
	};
};

