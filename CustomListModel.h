#pragma once
#include "oferta_service.h"
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
class CustomListModel : public QAbstractListModel{
private:
	Service& service;
public:
	CustomListModel(Service& srv, QObject* parent = nullptr) : service(srv), QAbstractListModel(parent) {};

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	void somethingChanged();

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
};

