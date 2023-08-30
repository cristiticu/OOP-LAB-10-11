#pragma once
#include "Observer.h"
#include <QtWidgets/QWidget>

class ObserverGUIBase : public QWidget{
	Q_OBJECT
public:
    ObserverGUIBase(QWidget* parent = nullptr) : QWidget{ parent, Qt::Window } { QWidget::setWindowFlags(Qt::Window); this->setWindowFlags(Qt::Window); };
    ~ObserverGUIBase() = default;
};

