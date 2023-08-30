#include "UI.h"


UI::UI(Service& _service) : service(_service) {
	this->buildMainUIWindow();
	this->buildMainLeftSideUIWindow();
	this->buildMainRightSideUIWindow();

	this->mainUIWindow->show();
}




//_MAIN WINDOW
void UI::buildMainUIWindow() {
	this->mainUIWindow = new QWidget;
	QGridLayout* mainUIWindowGridLayout = new QGridLayout;
	this->mainUIWindow->setLayout(mainUIWindowGridLayout);
	this->mainUIWindow->setObjectName("MainUIWindow");
}




//_RIGHT SIDE WINDOW
void UI::buildMainRightSideUIWindow() {
	QLabel* rightSideTextLabel = new QLabel;
	rightSideTextLabel->setText("Introducere de date");


	//Right Side, introducere de date + butoane
	QWidget* rightSideMainUIWindow = new QWidget;
	rightSideMainUIWindow->setObjectName("RightSideMainUIWindow");
	QVBoxLayout* rightSideMainUIWindowBoxLayout = new QVBoxLayout;

	rightSideMainUIWindow->setLayout(rightSideMainUIWindowBoxLayout);
	//rightSideMainUIWindow->setMinimumHeight(500);
	rightSideMainUIWindow->setMinimumWidth(200);

	//Right side, introducere de date
	QWidget* rightSideDataWindow = new QWidget;
	rightSideDataWindow->setObjectName("DataFormWindow");
	QFormLayout* rightSideMainUIWindowFormLayout = new QFormLayout;
	rightSideDataWindow->setLayout(rightSideMainUIWindowFormLayout);

	//Introducere de date right side
	QLineEdit* denumireLabel = new QLineEdit;
	QLineEdit* destinatieLabel = new QLineEdit;
	QLineEdit* tipLabel = new QLineEdit;
	QLineEdit* pretLabel = new QLineEdit;

	rightSideMainUIWindowFormLayout->addRow("Denumire", denumireLabel);
	rightSideMainUIWindowFormLayout->addRow("Destinatie", destinatieLabel);
	rightSideMainUIWindowFormLayout->addRow("Tip", tipLabel);
	rightSideMainUIWindowFormLayout->addRow("Pret", pretLabel);

	//Construirea efectiva rightSide-> introducere peste butoane
	rightSideMainUIWindowBoxLayout->addWidget(rightSideDataWindow);
	rightSideMainUIWindowBoxLayout->addStretch();


	// Construirea bucata butoane
	QWidget* rightButtonHolder = new QWidget;
	QHBoxLayout* rightButtonHolderLayout = new QHBoxLayout;
	rightButtonHolder->setLayout(rightButtonHolderLayout);

	QPushButton* addOfertaButton = new QPushButton;
	QPushButton* stergeOfertaButton = new QPushButton;
	addOfertaButton->setText("Adauga Oferta");
	stergeOfertaButton->setText("Sterge oferta selectata");
	//QObject::connect(addOfertaButton, &QPushButton::clicked, dependency, &UI::adaugaOfertaButtonClicked);

	rightButtonHolderLayout->addWidget(addOfertaButton);
	rightButtonHolderLayout->addWidget(stergeOfertaButton);

	rightSideMainUIWindowBoxLayout->addWidget(rightButtonHolder);

	auto mainLayout = dynamic_cast<QGridLayout*>(this->mainUIWindow->layout());
	mainLayout->addWidget(rightSideTextLabel, 0, 2);
	mainLayout->addWidget(rightSideMainUIWindow, 1, 2);
}




//_LEFT SIDE WINDOW
void UI::buildMainLeftSideUIWindow() {
	QWidget* leftSideMainUIWindow = new QWidget;
	leftSideMainUIWindow->setObjectName("LeftSideMainUIWindow");

	QVBoxLayout* leftSideMainUIWindowBoxLayout = new QVBoxLayout;
	leftSideMainUIWindow->setLayout(leftSideMainUIWindowBoxLayout);

	leftSideMainUIWindow->setMinimumWidth(500);
	//leftSideMainUIWindow->setMinimumHeight(500);

	QListWidget* leftSideListBox = new QListWidget;
	leftSideListBox->setObjectName("ListBoxOferteTuristice");

	//Test Values
	leftSideListBox->addItem("1312312");
	leftSideListBox->addItem("1312312");
	leftSideListBox->addItem("1312312");
	leftSideListBox->addItem("1312312");
	leftSideListBox->addItem("1312312");

	//Construirea efectiva leftSide, lista peste butoane
	leftSideMainUIWindowBoxLayout->addWidget(leftSideListBox);
	leftSideMainUIWindowBoxLayout->addStretch();

	//Left side text
	QLabel* leftSideTextLabel = new QLabel;
	leftSideTextLabel->setText("Oferte Turistice");
	
	//Getting the layout of the mainUIWindow
	auto mainLayout = dynamic_cast<QGridLayout*>(this->mainUIWindow->layout());
	mainLayout->addWidget(leftSideTextLabel, 0, 0);
	mainLayout->addWidget(leftSideMainUIWindow, 1, 0);
}

void UI::adaugaOfertaButtonClicked() {
	qDebug()<<"jejeje";
}
