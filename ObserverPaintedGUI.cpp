#include "ObserverPaintedGUI.h"

ObserverPaintedGUI::ObserverPaintedGUI(Service& _observableReff, QWidget* parent) : observableReff(_observableReff), ObserverGUIBase{parent} {
	this->setMinimumHeight(100);
	this->setMinimumWidth(200);
	srand(time(NULL));
	this->loadExistingData();
}

ObserverPaintedGUI::~ObserverPaintedGUI(){
	this->observableReff.unlinkObserver(this);
}

void ObserverPaintedGUI::updateSelfOfertaAdded(OfertaTuristica ofertaAdded) {
	ofertaDrawingData data;
	switch ((ofertaAdded.getDenumire().size() + rand() % 10) % 5) {
	case 1:
		data.brushColor = Qt::cyan;
		break;
	case 2:
		data.brushColor = Qt::red;
		break;
	case 3:
		data.brushColor = Qt::green;
		break;
	case 4:
		data.brushColor = Qt::magenta;
		break;
	default:
		data.brushColor = Qt::yellow;
		break;
	}

	switch ((ofertaAdded.getDestinatie().size() + rand() % 10) % 5) {
	case 1:
		data.penColor = Qt::darkBlue;
		break;
	case 2:
		data.penColor = Qt::lightGray;
		break;
	case 3:
		data.penColor = Qt::darkYellow;
		break;
	case 4:
		data.penColor = Qt::black;
		break;
	default:
		data.penColor = Qt::darkRed;
		break;
	}

	switch ((ofertaAdded.getTip().size() + rand() % 10) % 5) {
	case 1:
		data.style = Qt::BDiagPattern;
		break;
	case 2:
		data.style = Qt::ConicalGradientPattern;
		break;
	case 3:
		data.style = Qt::RadialGradientPattern;
		break;
	case 4:
		data.style = Qt::CrossPattern;
		break;
	default:
		data.style = Qt::SolidPattern;
		break;
	}
	data.type = 0;
	this->drawingData.push_back(data);
	this->update();
}

void ObserverPaintedGUI::updateSelfOfertaRemoved(const unsigned int index) {
	this->drawingData.erase(this->drawingData.begin() + index);
	this->update();
}

void ObserverPaintedGUI::updateSelfOfertaModified(const unsigned int index, OfertaTuristica ofertaModified) {
	ofertaDrawingData data;
	switch ((ofertaModified.getDenumire().size() + rand() % 10) % 5) {
	case 1:
		data.brushColor = Qt::cyan;
		break;
	case 2:
		data.brushColor = Qt::red;
		break;
	case 3:
		data.brushColor = Qt::green;
		break;
	case 4:
		data.brushColor = Qt::magenta;
		break;
	default:
		data.brushColor = Qt::yellow;
		break;
	}

	switch ((ofertaModified.getDestinatie().size() + rand() % 10) % 5) {
	case 1:
		data.penColor = Qt::darkBlue;
		break;
	case 2:
		data.penColor = Qt::lightGray;
		break;
	case 3:
		data.penColor = Qt::darkYellow;
		break;
	case 4:
		data.penColor = Qt::black;
		break;
	default:
		data.penColor = Qt::darkRed;
		break;
	}

	switch ((ofertaModified.getTip().size() + rand() % 10) % 5) {
	case 1:
		data.style = Qt::BDiagPattern;
		break;
	case 2:
		data.style = Qt::ConicalGradientPattern;
		break;
	case 3:
		data.style = Qt::RadialGradientPattern;
		break;
	case 4:
		data.style = Qt::CrossPattern;
		break;
	default:
		data.style = Qt::SolidPattern;
		break;
	}
	data.type = 0;
	this->drawingData[index] = data;
	this->update();
}

void ObserverPaintedGUI::paintEvent(QPaintEvent* e) {
	QPainter p{this};

	QBrush painterBrush{};
	QPen painterPen{};

	for (int i = 0; i < this->drawingData.size(); i++) {
		auto& data = this->drawingData[i];
		int shapeSize = 30;
		int numberPerShape = 5;
		int xoff = 20;
		int xcoord = (i % numberPerShape) * shapeSize;
		int ycoord = (i / numberPerShape) * shapeSize;
		painterBrush.setColor(data.brushColor);
		painterBrush.setStyle(data.style);
		painterPen.setColor(data.penColor);
		p.setPen(painterPen);
		p.setBrush(painterBrush);

		QRect rectForm{ xoff + xcoord + (i % numberPerShape) * numberPerShape, ycoord + (i / numberPerShape) * numberPerShape, shapeSize, shapeSize};

		switch (data.type) {
		case 0:
			p.drawRect(rectForm);
			break;
		case 1:
			break;
		case 2:
			break;
		default:
			break;
		}
	}
}

void ObserverPaintedGUI::loadExistingData() {
	for (auto& oferta : this->observableReff.getAllOferte())
		this->updateSelfOfertaAdded(oferta);
}
