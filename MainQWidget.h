#pragma once

// Qt Dependencies
#include <QtWidgets/QWidget>
#include "ui_MainQWidget.h"
#include <QtWidgets/QApplication>
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
#include <qgroupbox.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qinputdialog.h>
#include <qfiledialog.h>
#include <qdialog.h>
#include <qlistview.h>

// Custom Dependencies
#include "oferta_service.h"
#include "CustomListModel.h"

// STD Dependencies
#include <string.h>
#include <conio.h>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <vector>

// Observer Pattern Dependencies
#include "ObserverListboxGUI.h"
#include "ObservableGUI.h"
#include "ObserverPaintedGUI.h"



//   ::QT OBJECT CHILD NAMES::
//  Widget-ul principal:                           MainUIWindow
// 
//  Widget-ul din stanga ecranului principal:      LeftSideMainUIWindow
//  Lista cu oferte turistice din stanga:          ListBoxOferteTuristice
//
//  Widget-ul din dreapta ecranului principal:     RightSideMainUIWindow
//  Form-ul pentru introducere a datelor:          DataFormWindow
//
//
//

class MainQWidget : public QWidget
{
    Q_OBJECT

public:
    MainQWidget(Service& _service, QWidget *parent = nullptr);
    ~MainQWidget();

private:
    Service& service;
    Ui::MainQWidgetClass ui;
    ObserverListboxGUI* observerListbox;

    CustomListModel* customList;

    void buildMainUIWindow();
    void buildMainLeftSideUIWindow();
    void buildMainRightSideUIWindow();

private slots:
    void adaugaOfertaButtonClicked();
    void stergeOfertaButtonClicked();
    void undoButtonClicked();
    void modifyButtonClicked();
    void sortButtonClicked();
    void filterButtonClicked();

    void adaugaOfertaWishlistButtonClicked();
    void genereazaOfertaWishlistButtonClicked();
    void deleteOfertaWishlistButtonClicked();
    void exportOfertaWishlistButtonClicked();

    void saveButtonClicked();
    void loadButtonClicked();

    void fillQListWithRepository();
    void fillQListWithWishlist();

    void updateOfertaDetails();
    void updateWishlistOfertaDetails();
    void clearOfertaDetails();

    void openNewCRUDWindow();
    void openNewROWindow();
    void openNewPainterWindow();

    void __test__observer__();
};
