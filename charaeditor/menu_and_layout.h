#ifndef MENU_AND_LAYOUT_H
#define MENU_AND_LAYOUT_H

#include <QWidget>
#include <QSpinBox>

class QLabel;
class QLineEdit;
class QSpinBox;
class QPushButton;
//class QTextBrowser;

class Menu_and_layout : public QWidget{
    Q_OBJECT

    public:
        // Constructor and destructor
        explicit Menu_and_layout(QWidget *parent = 0);
        ~Menu_and_layout();

    private:
        QLabel* name_edit_label_;
        QLineEdit* name_edit_;

        QLabel* filename_label_;
        QLineEdit* filename_edit_;

        QLabel* map_name_label_;
        QLineEdit* map_name_edit_;
        QLabel* coordinates_label_;
        QSpinBox* coor_x_;
        QSpinBox* coor_y_;

        QPushButton* save_button_;
};

#endif // MENU_AND_LAYOUT_H