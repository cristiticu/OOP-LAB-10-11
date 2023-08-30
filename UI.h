#pragma once
#include "oferta_service.h"
#include <conio.h>
#include "time.h"
#include <fstream>
#include "stdlib.h"
#include "math.h"
#include <vector>
#include "MainQWidget.h"
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
#include "MainQWidget.h"



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

class UI{
private:
	Service& service;
	QWidget* mainUIWindow;

	void buildMainUIWindow();
	void buildMainLeftSideUIWindow();
	void buildMainRightSideUIWindow();

	void adaugaOfertaButtonClicked();
public:
	UI(Service& _service);
};

