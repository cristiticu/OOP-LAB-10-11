#pragma once
#include "ObserverGUIBase.h"
#include <vector>
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

class ObserverListboxGUI : public ObserverGUIBase, public Observer {
private:
	Service& observableRef;
	QHBoxLayout* mainHorizontalLayout;

	void loadExistingData();
public:
	QListWidget* ofertaListBox;
	ObserverListboxGUI(Service& _observableRef, QWidget* parent = nullptr);
	~ObserverListboxGUI();

	virtual void updateSelfOfertaAdded(OfertaTuristica ofertaAdded) override;
	virtual void updateSelfOfertaRemoved(const unsigned int index) override;
	virtual void updateSelfOfertaModified(const unsigned int index, OfertaTuristica ofertaModified) override;
};

