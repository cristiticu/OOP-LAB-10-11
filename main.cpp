#include "MainQWidget.h"
#include <QtWidgets/QApplication>
#include "teste_master.h"

int main(int argc, char *argv[]){
    testEverything();

    QApplication a(argc, argv);

    Repository repository;
    Repository wishlist;
    Service service(repository, wishlist);
    MainQWidget mainUI(service);
    return a.exec();
}
