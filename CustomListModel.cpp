#include "CustomListModel.h"

int CustomListModel::rowCount(const QModelIndex& parent) const {
	return this->service.getAllOferte().size();
}

void CustomListModel::somethingChanged(){
	emit dataChanged(index(0, 0), index(rowCount(), 0));
}

QVariant CustomListModel::data(const QModelIndex& index, int role) const {
	int row = index.row();
	int column = index.column();
	if (role == Qt::DisplayRole) {
		return QString::fromStdString(this->service.getAllOferte()[row].getDenumire());
	}
	if (role == Qt::FontRole) {
		QFont f;
		f.setItalic(row % 4 == 1);
		f.setBold(row % 2 == 1);
		return f;
	}
	if (role == Qt::BackgroundRole) {
		if (row % 5 == 0) {
			QBrush bg(Qt::red);
			return bg;
		}
	}
	return QVariant();
}
