#include <QtWidgets>
#include "menu_and_layout.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    Menu_and_layout window;

    window.setWindowTitle("Character Editor");
    window.show();

    return app.exec();
}