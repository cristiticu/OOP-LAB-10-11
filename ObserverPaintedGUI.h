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
#include <qpainter.h>
#include <qpaintdevice.h>
#include <random>

struct ofertaDrawingData {
	short type;
	Qt::GlobalColor brushColor;
	Qt::GlobalColor penColor;
	Qt::BrushStyle style;
};

class ObserverPaintedGUI : public ObserverGUIBase, public Observer{
private:
	Service& observableReff;
	std::vector<ofertaDrawingData> drawingData;

	void loadExistingData();
public:
	ObserverPaintedGUI(Service& _observableReff, QWidget* parent = nullptr);
	~ObserverPaintedGUI();

	virtual void updateSelfOfertaAdded(OfertaTuristica ofertaAdded) override;
	virtual void updateSelfOfertaRemoved(const unsigned int index) override;
	virtual void updateSelfOfertaModified(const unsigned int index, OfertaTuristica ofertaModified) override;

	virtual void paintEvent(QPaintEvent* e) override;
};

