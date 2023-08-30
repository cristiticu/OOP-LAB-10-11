#include "MainQWidget.h"

MainQWidget::MainQWidget(Service& _service, QWidget *parent)
    : QWidget(parent), service(_service)
{
    ui.setupUi(this);
	this->setWindowTitle("OOP LAB 10-11: Manager Oferte Turistice");
	this->setWindowIcon(QIcon("repository.png"));

	this->observerListbox = new ObserverListboxGUI{ this->service };
	this->service.linkNewObserver(this->observerListbox);
	this->buildMainUIWindow();
	this->buildMainLeftSideUIWindow();
	this->buildMainRightSideUIWindow();

	QListView* testListModel = new QListView;
	this->customList= new CustomListModel{ this->service, this };
	testListModel->setModel(this->customList);
	testListModel->show();

	this->show();
}

MainQWidget::~MainQWidget(){
	this->close();
}





//_MAIN WINDOW
void MainQWidget::buildMainUIWindow() {
	QGridLayout* mainUIWindowGridLayout = new QGridLayout;
	this->setLayout(mainUIWindowGridLayout);
	this->setObjectName("MainUIWindow");
}




//_RIGHT SIDE WINDOW
void MainQWidget::buildMainRightSideUIWindow() {
	QLabel* rightSideTextLabel = new QLabel;
	rightSideTextLabel->setText("Introducere de date");


	//Right Side, introducere de date + butoane
	QWidget* rightSideMainUIWindow = new QWidget;
	rightSideMainUIWindow->setObjectName("RightSideMainUIWindow");
	QVBoxLayout* rightSideMainUIWindowBoxLayout = new QVBoxLayout;

	//QWidget* rightSideButtonAndFormHolder = new QWidget;
	//rightSideButtonAndFormHolder->setMaximumHeight(200);
	//QVBoxLayout* rightSideButtonAndFormHolderLayout = new QVBoxLayout;
	//rightSideButtonAndFormHolder->setLayout(rightSideButtonAndFormHolderLayout);

	rightSideMainUIWindow->setLayout(rightSideMainUIWindowBoxLayout);
	//rightSideMainUIWindow->setMaximumHeight(200);
	//rightSideMainUIWindow->setMinimumHeight(500);
	rightSideMainUIWindow->setMinimumWidth(300);

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
	denumireLabel->setObjectName("DenumireLineEdit");
	destinatieLabel->setObjectName("DestinatieLineEdit");
	tipLabel->setObjectName("TipLineEdit");
	pretLabel->setObjectName("PretLineEdit");

	rightSideMainUIWindowFormLayout->addRow("Denumire", denumireLabel);
	rightSideMainUIWindowFormLayout->addRow("Destinatie", destinatieLabel);
	rightSideMainUIWindowFormLayout->addRow("Tip", tipLabel);
	rightSideMainUIWindowFormLayout->addRow("Pret", pretLabel);

	//Construirea efectiva rightSide-> introducere peste butoane
	rightSideMainUIWindowBoxLayout->addWidget(rightSideDataWindow);
	//rightSideButtonAndFormHolderLayout->addWidget(rightSideDataWindow);


	// Construirea bucata butoane
	QWidget* rightButtonHolder = new QWidget;
	//rightButtonHolder->setMaximumHeight(100);
	QHBoxLayout* rightButtonHolderLayout = new QHBoxLayout;
	rightButtonHolder->setLayout(rightButtonHolderLayout);
	rightButtonHolder->setMaximumWidth(40 * 6 + 40);

	QPushButton* addOfertaButton = new QPushButton;
	QPushButton* stergeOfertaButton = new QPushButton;
	QPushButton* undoButton = new QPushButton;
	QPushButton* modifyButton = new QPushButton;
	QPushButton* sortButton = new QPushButton;
	QPushButton* filterButton = new QPushButton;
	//addOfertaButton->setText("Adauga Oferta");
	//stergeOfertaButton->setText("Sterge oferta selectata");
	addOfertaButton->setIcon(QIcon("plus.png"));
	stergeOfertaButton->setIcon(QIcon("minus.png"));
	undoButton->setIcon(QIcon("undo.png"));
	modifyButton->setIcon(QIcon("modify.png"));
	sortButton->setIcon(QIcon("sort.png"));
	filterButton->setIcon(QIcon("filter.png"));
	addOfertaButton->setMaximumWidth(40);
	stergeOfertaButton->setMaximumWidth(40);
	undoButton->setMaximumWidth(40);
	modifyButton->setMaximumWidth(40);
	sortButton->setMaximumWidth(40);
	filterButton->setMaximumWidth(40);
	addOfertaButton->setToolTip("Adauga datele");
	stergeOfertaButton->setToolTip("Sterge selectia");
	undoButton->setToolTip("Undo actiune");
	modifyButton->setToolTip("Modifica selectia");
	sortButton->setToolTip("Sorteaza dupa criterii");
	filterButton->setToolTip("Filtreaza dupa destinatie");
	QObject::connect(addOfertaButton, &QPushButton::clicked, this, &MainQWidget::adaugaOfertaButtonClicked);
	QObject::connect(stergeOfertaButton, &QPushButton::clicked, this, &MainQWidget::stergeOfertaButtonClicked);
	QObject::connect(undoButton, &QPushButton::clicked, this, &MainQWidget::undoButtonClicked);
	QObject::connect(modifyButton, &QPushButton::clicked, this, &MainQWidget::modifyButtonClicked);
	QObject::connect(sortButton, &QPushButton::clicked, this, &MainQWidget::sortButtonClicked);
	QObject::connect(filterButton, &QPushButton::clicked, this, &MainQWidget::filterButtonClicked);

	rightButtonHolderLayout->addWidget(undoButton);
	rightButtonHolderLayout->addWidget(addOfertaButton);
	rightButtonHolderLayout->addWidget(stergeOfertaButton);
	rightButtonHolderLayout->addWidget(modifyButton);
	rightButtonHolderLayout->addWidget(sortButton);
	rightButtonHolderLayout->addWidget(filterButton);

	rightSideMainUIWindowBoxLayout->addWidget(rightButtonHolder);
	//rightSideButtonAndFormHolderLayout->addWidget(rightButtonHolder);

	//rightSideMainUIWindowBoxLayout->addWidget(rightSideButtonAndFormHolder);



	//Wishlist Controls buttons
	QLabel* wishlistButtonsLabel = new QLabel;
	wishlistButtonsLabel->setText("Control Wishlist");

	QWidget* rightSideWishlistButtonsHolder = new QWidget;
	rightSideWishlistButtonsHolder->setMaximumWidth(40 * 4 + 40);
	QHBoxLayout* rightSideWishlistButtonsHolderLayout = new QHBoxLayout;
	rightSideWishlistButtonsHolder->setLayout(rightSideWishlistButtonsHolderLayout);


	QPushButton* addOfertaWishlistButton = new QPushButton;
	QPushButton* genereazaWishlistButton = new QPushButton;
	QPushButton* deleteWishlistButton = new QPushButton;
	QPushButton* exportWishlistButton = new QPushButton;
	addOfertaWishlistButton->setMaximumWidth(40);
	genereazaWishlistButton->setMaximumWidth(40);
	deleteWishlistButton->setMaximumWidth(40);
	exportWishlistButton->setMaximumWidth(40);
	addOfertaWishlistButton->setToolTip("Adauga selectia in wishlist");
	genereazaWishlistButton->setToolTip("Genereaza wishlist aleator");
	deleteWishlistButton->setToolTip("Sterge wishlist");
	exportWishlistButton->setToolTip("Export wishlist");
	addOfertaWishlistButton->setIcon(QIcon("plus.png"));
	genereazaWishlistButton->setIcon(QIcon("random.png"));
	deleteWishlistButton->setIcon(QIcon("minus.png"));
	exportWishlistButton->setIcon(QIcon("export.png"));

	QObject::connect(addOfertaWishlistButton, &QPushButton::clicked, this, &MainQWidget::adaugaOfertaWishlistButtonClicked);
	QObject::connect(genereazaWishlistButton, &QPushButton::clicked, this, &MainQWidget::genereazaOfertaWishlistButtonClicked);
	QObject::connect(deleteWishlistButton, &QPushButton::clicked, this, &MainQWidget::deleteOfertaWishlistButtonClicked);
	QObject::connect(exportWishlistButton, &QPushButton::clicked, this, &MainQWidget::exportOfertaWishlistButtonClicked);

	rightSideWishlistButtonsHolderLayout->addWidget(addOfertaWishlistButton);
	rightSideWishlistButtonsHolderLayout->addWidget(genereazaWishlistButton);
	rightSideWishlistButtonsHolderLayout->addWidget(deleteWishlistButton);
	rightSideWishlistButtonsHolderLayout->addWidget(exportWishlistButton);


	rightSideMainUIWindowBoxLayout->addWidget(wishlistButtonsLabel);
	rightSideMainUIWindowBoxLayout->addWidget(rightSideWishlistButtonsHolder);


	//Sorting group buttons
	QGroupBox* sortButtonsGroupBox = new QGroupBox;
	QVBoxLayout* sortButtonsGroupLayout = new QVBoxLayout;
	sortButtonsGroupBox->setLayout(sortButtonsGroupLayout);
	sortButtonsGroupBox->setTitle("Optiuni Sortare");
	sortButtonsGroupBox->setMaximumHeight(100);

	QRadioButton* sortbByDenumireButton = new QRadioButton;
	QRadioButton* sortbByDestinatieButton = new QRadioButton;
	QRadioButton* sortbByTipPretButton = new QRadioButton;
	sortbByDenumireButton->setText("Dupa denumire");
	sortbByDestinatieButton->setText("Dupa destinatie");
	sortbByTipPretButton->setText("Dupa tip si pret");
	sortbByDenumireButton->setChecked(true);
	
	sortButtonsGroupLayout->addWidget(sortbByDenumireButton);
	sortButtonsGroupLayout->addWidget(sortbByDestinatieButton);
	sortButtonsGroupLayout->addWidget(sortbByTipPretButton);

	QButtonGroup* sortButtonsGroupManager = new QButtonGroup;
	sortButtonsGroupManager->setObjectName("SortButtonsGroupManager");
	sortButtonsGroupManager->addButton(sortbByDenumireButton);
	sortButtonsGroupManager->addButton(sortbByDestinatieButton);
	sortButtonsGroupManager->addButton(sortbByTipPretButton);
	sortButtonsGroupManager->setId(sortbByDenumireButton, 1);
	sortButtonsGroupManager->setId(sortbByDestinatieButton, 2);
	sortButtonsGroupManager->setId(sortbByTipPretButton, 3);
	sortButtonsGroupManager->setParent(this);


	//Order group buttons
	QGroupBox* orderButtonsGroupBox = new QGroupBox;
	QVBoxLayout* orderButtonsGroupBoxLayout = new QVBoxLayout;
	orderButtonsGroupBox->setLayout(orderButtonsGroupBoxLayout);
	orderButtonsGroupBox->setTitle("Ordine Sortare");
	orderButtonsGroupBox->setMaximumHeight(70);

	QRadioButton* crescatorButton = new QRadioButton;
	QRadioButton* descrescatorButton = new QRadioButton;
	crescatorButton->setText("Crescator");
	descrescatorButton->setText("Descrescator");
	crescatorButton->setChecked(true);

	orderButtonsGroupBoxLayout->addWidget(crescatorButton);
	orderButtonsGroupBoxLayout->addWidget(descrescatorButton);

	QButtonGroup* orderButtonsGroupManager = new QButtonGroup;
	orderButtonsGroupManager->setObjectName("OrderButtonsGroupManager");
	orderButtonsGroupManager->addButton(crescatorButton);
	orderButtonsGroupManager->addButton(descrescatorButton);
	orderButtonsGroupManager->setId(crescatorButton, 1);
	orderButtonsGroupManager->setId(descrescatorButton, 2);
	orderButtonsGroupManager->setParent(this);



	auto mainLayout = dynamic_cast<QGridLayout*>(this->layout());
	mainLayout->addWidget(rightSideTextLabel, 1, 2);
	mainLayout->addWidget(rightSideMainUIWindow, 2, 2);
	mainLayout->addWidget(sortButtonsGroupBox, 2, 3);
	mainLayout->addWidget(orderButtonsGroupBox, 3, 3);
	this->setMaximumHeight(200);
}




//_LEFT SIDE WINDOW
void MainQWidget::buildMainLeftSideUIWindow() {
	QWidget* leftSideMainUIWindow = new QWidget;
	leftSideMainUIWindow->setObjectName("LeftSideMainUIWindow");

	QVBoxLayout* leftSideMainUIWindowBoxLayout = new QVBoxLayout;
	leftSideMainUIWindow->setLayout(leftSideMainUIWindowBoxLayout);

	leftSideMainUIWindow->setMinimumWidth(100);
	leftSideMainUIWindow->setMinimumHeight(240);

	//OLD LISTWIDGET REPLACED BY OBSERVER LISTBOX
	/*
	QListWidget* leftSideListBox = new QListWidget;
	leftSideListBox->setObjectName("ListBoxOferteTuristice");*/

	QObject::connect(this->observerListbox->ofertaListBox, &QListWidget::itemClicked, this, &MainQWidget::updateOfertaDetails);

	QListWidget* wishlistListBox = new QListWidget;
	wishlistListBox->setObjectName("ListBoxWishlist");

	QObject::connect(wishlistListBox, &QListWidget::itemClicked, this, &MainQWidget::updateWishlistOfertaDetails);

	QLabel* wishlistLabel = new QLabel;
	wishlistLabel->setText("Wishlist");
	wishlistLabel->setMaximumHeight(50);




	//Construirea efectiva leftSide, lista peste butoane
	leftSideMainUIWindowBoxLayout->addWidget(this->observerListbox->ofertaListBox);
	leftSideMainUIWindowBoxLayout->addWidget(wishlistLabel);
	leftSideMainUIWindowBoxLayout->addWidget(wishlistListBox);
	




	//Left side text
	QLabel* leftSideTextLabel = new QLabel;
	leftSideTextLabel->setText("Oferte Turistice");




	//Details screen under listBox!!
	QLineEdit* denumireDetailsLine = new QLineEdit;
	QLineEdit* destinatieDetailsLine = new QLineEdit;
	QLineEdit* tipDetailsLine = new QLineEdit;
	QLineEdit* pretDetailsLine = new QLineEdit;
	denumireDetailsLine->setReadOnly(true);
	destinatieDetailsLine->setReadOnly(true);
	tipDetailsLine->setReadOnly(true);
	pretDetailsLine->setReadOnly(true);
	denumireDetailsLine->setObjectName("DenumireDetailsLine");
	destinatieDetailsLine->setObjectName("DestinatieDetailsLine");
	tipDetailsLine->setObjectName("TipDetailsLine");
	pretDetailsLine->setObjectName("PretDetailsLine");

	QLabel* denumireDetailsLineLabel = new QLabel;
	QLabel* destinatieDetailsLineLabel = new QLabel;
	QLabel* tipDetailsLineLabel = new QLabel;
	QLabel* pretDetailsLineLabel = new QLabel;
	denumireDetailsLineLabel->setText("Denumire");
	destinatieDetailsLineLabel->setText("Destinatie");
	tipDetailsLineLabel->setText("Tip");
	pretDetailsLineLabel->setText("Pret");

	QWidget* ofertaDetails = new QWidget;
	QGridLayout* ofertaDetailsLayout = new QGridLayout;
	ofertaDetails->setLayout(ofertaDetailsLayout);
	ofertaDetails->setMinimumWidth(400);
	ofertaDetails->setMaximumHeight(100);

	ofertaDetailsLayout->addWidget(denumireDetailsLineLabel, 0, 0);
	ofertaDetailsLayout->addWidget(destinatieDetailsLineLabel, 0, 1);
	ofertaDetailsLayout->addWidget(tipDetailsLineLabel, 0, 2);
	ofertaDetailsLayout->addWidget(pretDetailsLineLabel, 0, 3);
	ofertaDetailsLayout->addWidget(denumireDetailsLine, 1, 0);
	ofertaDetailsLayout->addWidget(destinatieDetailsLine, 1, 1);
	ofertaDetailsLayout->addWidget(tipDetailsLine, 1, 2);
	ofertaDetailsLayout->addWidget(pretDetailsLine, 1, 3);

	QLabel* ofertaDetailsLabelUp = new QLabel;
	ofertaDetailsLabelUp->setText("Detalii oferta selectata");

	
	
	//Up toolbar
	QWidget* toolbarButtons = new QWidget;
	QHBoxLayout* toolbarButtonsLayout = new QHBoxLayout;
	toolbarButtons->setLayout(toolbarButtonsLayout);
	toolbarButtons->setMaximumWidth(40 * 5);

	QPushButton* saveRepositoryButton = new QPushButton;
	saveRepositoryButton->setMaximumWidth(40);
	saveRepositoryButton->setIcon(QIcon("save.png"));
	saveRepositoryButton->setToolTip("Salveaza in fisier");

	QPushButton* loadRepositoryButton = new QPushButton;
	loadRepositoryButton->setMaximumWidth(40);
	loadRepositoryButton->setIcon(QIcon("load.png"));
	loadRepositoryButton->setToolTip("Incarca din fisier");

	QPushButton* openCRUDObserverButton = new QPushButton;
	openCRUDObserverButton->setMaximumWidth(40);
	openCRUDObserverButton->setIcon(QIcon("newwindow.png"));
	openCRUDObserverButton->setToolTip("Deschide o fereastra CRUD");

	QPushButton* openROObserverButton = new QPushButton;
	openROObserverButton->setMaximumWidth(40);
	openROObserverButton->setIcon(QIcon("newwindow.png"));
	openROObserverButton->setToolTip("Deschide o fereastra Read-Only");

	QPushButton* openPainterObserverButton = new QPushButton;
	openPainterObserverButton->setMaximumWidth(40);
	openPainterObserverButton->setIcon(QIcon("newwindow.png"));
	openPainterObserverButton->setToolTip("Deschide o fereastra Painter");

	QObject::connect(saveRepositoryButton, &QPushButton::clicked, this, &MainQWidget::saveButtonClicked);
	QObject::connect(loadRepositoryButton, &QPushButton::clicked, this, &MainQWidget::loadButtonClicked);
	QObject::connect(openCRUDObserverButton, &QPushButton::clicked, this, &MainQWidget::openNewCRUDWindow);
	QObject::connect(openROObserverButton, &QPushButton::clicked, this, &MainQWidget::openNewROWindow);
	QObject::connect(openPainterObserverButton, &QPushButton::clicked, this, &MainQWidget::openNewPainterWindow);

	toolbarButtonsLayout->addWidget(saveRepositoryButton);
	toolbarButtonsLayout->addWidget(loadRepositoryButton);
	toolbarButtonsLayout->addWidget(openCRUDObserverButton);
	toolbarButtonsLayout->addWidget(openROObserverButton);
	toolbarButtonsLayout->addWidget(openPainterObserverButton);





	//Getting the layout of the mainUIWindow
	auto mainLayout = dynamic_cast<QGridLayout*>(this->layout());
	mainLayout->addWidget(toolbarButtons, 0, 0);
	mainLayout->addWidget(leftSideTextLabel, 1, 0);
	mainLayout->addWidget(leftSideMainUIWindow, 2, 0);
	mainLayout->addWidget(ofertaDetailsLabelUp, 3, 0);
	mainLayout->addWidget(ofertaDetails, 4, 0);
	//this->setMaximumHeight(300);
}




void MainQWidget::saveButtonClicked() {
	//Create dialog window to enter save file name
	QFileDialog saveDialog(this);
	saveDialog.setFileMode(QFileDialog::AnyFile);
	saveDialog.setNameFilter(tr("Data Files (*.data)"));
	saveDialog.setViewMode(QFileDialog::Detail);
	saveDialog.setWindowIcon(QIcon("save.png"));
	saveDialog.setWindowTitle("Salveaza in fisier");
	QStringList filename;
	if (saveDialog.exec())
		filename = saveDialog.selectedFiles();
	if (filename.size() != 0) {
		try {
			this->service.exportOferte((filename[0].toStdString()));
		}
		catch(customException&){}
	}
}




void MainQWidget::loadButtonClicked() {
	//Create dialog same way as save
	QFileDialog loadDialog(this);
	loadDialog.setFileMode(QFileDialog::ExistingFile);
	loadDialog.setNameFilter(tr("Data Files (*.data)"));
	loadDialog.setViewMode(QFileDialog::Detail);
	loadDialog.setWindowIcon(QIcon("load.png"));
	loadDialog.setWindowTitle("Incarca din fisier");
	QStringList filename;
	if (loadDialog.exec())
		filename = loadDialog.selectedFiles();
	if (filename.size() != 0) {
		try {
			this->service.importOferte(filename[0].toStdString());
			this->fillQListWithRepository();
			this->customList->somethingChanged();
		}
		catch (customException&) {}
	}
}




void MainQWidget::adaugaOfertaButtonClicked() {
	std::string denumire, destinatie, tip;
	double pret = 0;
	QLineEdit* lineParser = this->findChild<QLineEdit*>("DenumireLineEdit");
	denumire = lineParser->text().toStdString();
	lineParser->clear();
	lineParser = this->findChild<QLineEdit*>("DestinatieLineEdit");
	destinatie = lineParser->text().toStdString();
	lineParser->clear();
	lineParser = this->findChild<QLineEdit*>("TipLineEdit");
	tip = lineParser->text().toStdString();
	lineParser->clear();
	lineParser = this->findChild<QLineEdit*>("PretLineEdit");
	try {
		pret = std::stod(lineParser->text().toStdString());
		lineParser->clear();
		this->service.addOferta(denumire, destinatie, tip, pret);
		this->fillQListWithRepository();
		this->customList->somethingChanged();
	}
	catch(std::invalid_argument&){}
	catch (customException&) {}
}





void MainQWidget::stergeOfertaButtonClicked() {
	QList<QListWidgetItem*> items = this->observerListbox->ofertaListBox->selectedItems();
	if (items.size() != 0) {
		auto itemRow = this->observerListbox->ofertaListBox->row(items[0]);
		try {
			this->service.deleteOferta(itemRow);
			this->fillQListWithRepository();
			this->clearOfertaDetails();
			this->customList->somethingChanged();
		}
		catch (customException&) {}
	}
}




void MainQWidget::undoButtonClicked() {
	try {
		this->service.undo();
		this->fillQListWithRepository();
		this->clearOfertaDetails();
		this->customList->somethingChanged();
	}
	catch(customException&){}
}





void MainQWidget::modifyButtonClicked() {
	//QListWidget* listBox = this->findChild<QListWidget*>("ListBoxOferteTuristice");
	QList<QListWidgetItem*> items = this->observerListbox->ofertaListBox->selectedItems();
	std::string denumire, destinatie, tip;
	double pret = 0;
	QLineEdit* lineParser = this->findChild<QLineEdit*>("DenumireLineEdit");
	denumire = lineParser->text().toStdString();
	lineParser->clear();
	lineParser = this->findChild<QLineEdit*>("DestinatieLineEdit");
	destinatie = lineParser->text().toStdString();
	lineParser->clear();
	lineParser = this->findChild<QLineEdit*>("TipLineEdit");
	tip = lineParser->text().toStdString();
	lineParser->clear();
	lineParser = this->findChild<QLineEdit*>("PretLineEdit");
	if (items.size() != 0) {
		auto itemRow = this->observerListbox->ofertaListBox->row(items[0]);
		try {
			pret = std::stod(lineParser->text().toStdString());
			lineParser->clear();
			this->service.modifyOferta(itemRow, denumire, destinatie, tip, pret);
			this->fillQListWithRepository();
			this->clearOfertaDetails();
			this->customList->somethingChanged();
		}
		catch (customException&) {}
		catch (std::invalid_argument&) {}
	}
}




void MainQWidget::sortButtonClicked() {
	auto sortButtonGroupManager = this->findChild<QButtonGroup*>("SortButtonsGroupManager");
	auto orderButtonGroupManager = this->findChild<QButtonGroup*>("OrderButtonsGroupManager");
	auto buttonId = sortButtonGroupManager->checkedId();
	auto orderId = orderButtonGroupManager->checkedId();
	try {
		switch (buttonId) {
		case 1:
			this->service.sortareOferteDenumire();
			break;
		case 2:
			this->service.sortareOferteDestinatie();
			break;
		case 3:
			this->service.sortareOferteTipPret();
			break;
		}
		if (orderId == 1)
			this->service.reverseRepository();
		this->fillQListWithRepository();
		this->clearOfertaDetails();
		this->customList->somethingChanged();
	}
	catch(customException&){}
}






void MainQWidget::filterButtonClicked() {
	QDialog* filterWindow = new QDialog;
	filterWindow->setWindowIcon(QIcon("filter.png"));
	filterWindow->setWindowTitle("Rezultate filtrare");
	QVBoxLayout* filterWindowLayout = new QVBoxLayout;
	filterWindow->setLayout(filterWindowLayout);

	QListWidget* filterList = new QListWidget;

	QLineEdit* destinatieParser = this->findChild<QLineEdit*>("DestinatieLineEdit");
	std::string destinatie = destinatieParser->text().toStdString();
	destinatieParser->clear();
	 
	std::vector<OfertaTuristica> oferteFiltrate = this->service.filtrareOferteDestinatie(destinatie);
	
	for (auto& oferta : oferteFiltrate)
		filterList->addItem(QString::fromStdString(oferta.getDenumire()));

	filterWindowLayout->addWidget(filterList);

	filterWindow->exec();

	filterWindow->close();
}







void MainQWidget::fillQListWithRepository() {
	this->observerListbox->ofertaListBox->clear();
	for (auto& oferta : this->service.getAllOferte()) {
		std::string listString;
		listString += oferta.getDenumire();
		QString qstring = QString::fromStdString(listString);
		this->observerListbox->ofertaListBox->addItem(qstring);
	}
}



void MainQWidget::fillQListWithWishlist() {
	QListWidget* listBox = this->findChild<QListWidget*>("ListBoxWishlist");
	listBox->clear();
	for (auto& oferta : this->service.getWishlist()) {
		std::string listString;
		listString += oferta.getDenumire();
		QString qstring = QString::fromStdString(listString);
		listBox->addItem(qstring);
	}
}



void MainQWidget::updateOfertaDetails() {
	QList<QListWidgetItem*> items = this->observerListbox->ofertaListBox->selectedItems();
	if (items.size() != 0) {
		auto itemRow = this->observerListbox->ofertaListBox->row(items[0]);
		OfertaTuristica ofertaSelectata = this->service.getAllOferte()[itemRow];
		QLineEdit* lineParser = this->findChild<QLineEdit*>("DenumireDetailsLine");
		lineParser->setText(QString::fromStdString(ofertaSelectata.getDenumire()));
		lineParser = this->findChild<QLineEdit*>("DestinatieDetailsLine");
		lineParser->setText(QString::fromStdString(ofertaSelectata.getDestinatie()));
		lineParser = this->findChild<QLineEdit*>("TipDetailsLine");
		lineParser->setText(QString::fromStdString(ofertaSelectata.getTip()));
		lineParser = this->findChild<QLineEdit*>("PretDetailsLine");
		lineParser->setText(QString::fromStdString(std::to_string(ofertaSelectata.getPret())));
	}
}



void MainQWidget::updateWishlistOfertaDetails() {
	QListWidget* listBox = this->findChild<QListWidget*>("ListBoxWishlist");
	QList<QListWidgetItem*> items = listBox->selectedItems();
	if (items.size() != 0) {
		auto itemRow = listBox->row(items[0]);
		OfertaTuristica ofertaSelectata = this->service.getWishlist()[itemRow];
		QLineEdit* lineParser = this->findChild<QLineEdit*>("DenumireDetailsLine");
		lineParser->setText(QString::fromStdString(ofertaSelectata.getDenumire()));
		lineParser = this->findChild<QLineEdit*>("DestinatieDetailsLine");
		lineParser->setText(QString::fromStdString(ofertaSelectata.getDestinatie()));
		lineParser = this->findChild<QLineEdit*>("TipDetailsLine");
		lineParser->setText(QString::fromStdString(ofertaSelectata.getTip()));
		lineParser = this->findChild<QLineEdit*>("PretDetailsLine");
		lineParser->setText(QString::fromStdString(std::to_string(ofertaSelectata.getPret())));
	}
}




void MainQWidget::clearOfertaDetails() {
	QLineEdit* lineParser = this->findChild<QLineEdit*>("DenumireDetailsLine");
	lineParser->clear();
	lineParser = this->findChild<QLineEdit*>("DestinatieDetailsLine");
	lineParser->clear();
	lineParser = this->findChild<QLineEdit*>("TipDetailsLine");
	lineParser->clear();
	lineParser = this->findChild<QLineEdit*>("PretDetailsLine");
	lineParser->clear();
}





void MainQWidget::adaugaOfertaWishlistButtonClicked() {
	QList<QListWidgetItem*> items = this->observerListbox->ofertaListBox->selectedItems();
	if (items.size() != 0) {
		auto itemRow = this->observerListbox->ofertaListBox->row(items[0]);
		try {
			this->service.addOfertaWishlist(itemRow);
			this->fillQListWithWishlist();
		}
		catch (customException&){}
	}
}





void MainQWidget::genereazaOfertaWishlistButtonClicked() {
	try {
		bool okayDialog = false;
		int userInput = QInputDialog::getInt(this, tr("Introduceti numarul de oferte"), tr("Numar de oferte"), 0, 1, this->service.getAllOferte().size() - this->service.getWishlist().size(), 1, &okayDialog);
		if (okayDialog) {
			this->service.genereazaWishlist(userInput);
			this->fillQListWithWishlist();
		}
	}
	catch (customException&) {}
}





void MainQWidget::deleteOfertaWishlistButtonClicked() {
	try {
		this->service.deleteWishlist();
		this->fillQListWithWishlist();
		this->clearOfertaDetails();
	}
	catch(customException&){}
}





void MainQWidget::exportOfertaWishlistButtonClicked() {
	bool okayDialog = false;
	QString filename = QInputDialog::getText(this, tr("Introduceti numele fisierului"), tr("Nume fisier"), QLineEdit::Normal, "export.html", &okayDialog);
	if (okayDialog && !filename.isEmpty()) {
		std::ofstream file(filename.toStdString());
		if (file.is_open()) {
			file << "<!DOCTYPE html><html><head></head><body>";
			std::vector<OfertaTuristica> wishlist = this->service.getWishlist();
			for (unsigned int index = 0; index < wishlist.size(); index++) {
				file << "&nbsp;&nbsp;&nbsp;";
				file << index + 1;
				file << "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
				file << wishlist[index].getDenumire();
				file << "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
				file << wishlist[index].getDestinatie();
				file << "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
				file << wishlist[index].getTip();
				file << "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
				file << wishlist[index].getPret();
				file << "<br>";
			}
			file << "</body></html>";
			file.close();
		}
	}

}




void MainQWidget::openNewCRUDWindow() {
	ObservableGUI* newCRUDWindow = new ObservableGUI{ this->service, this };
	newCRUDWindow->setWindowTitle("OOP LAB 10-11: CRUD Window");
	newCRUDWindow->show();
}







void MainQWidget::openNewROWindow() {
	ObserverListboxGUI* newROWindow = new ObserverListboxGUI{ this->service, this };
	newROWindow->setWindowTitle("OOP LAB 10-11: Read-Only Window");
	this->service.linkNewObserver(newROWindow);
	newROWindow->show();
}






void MainQWidget::openNewPainterWindow() {
	ObserverPaintedGUI* newPainterWindow = new ObserverPaintedGUI{ this->service, this };
	newPainterWindow->setWindowTitle("OOP LAB 10-11: Painter Window");
	this->service.linkNewObserver(newPainterWindow);
	newPainterWindow->show();
}




void MainQWidget::__test__observer__() {
	ObserverListboxGUI* test = new ObserverListboxGUI(this->service, this);
	ObserverListboxGUI* test2 = new ObserverListboxGUI(this->service, this);
	ObservableGUI* testerCRUD = new ObservableGUI(this->service, this);
	ObservableGUI* testerCRUD2 = new ObservableGUI{ this->service, this };
	ObserverPaintedGUI* testPaint = new ObserverPaintedGUI{ this->service, this };

	test->show();
	test2->show();
	testerCRUD->show();
	testerCRUD2->show();
	testPaint->show();

	this->service.linkNewObserver(test);
	this->service.linkNewObserver(test2);
	this->service.linkNewObserver(testPaint);
}

