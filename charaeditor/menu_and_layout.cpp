#include <QtWidgets>
#include "menu_and_layout.h"

Menu_and_layout::Menu_and_layout(QWidget *parent)
    : QWidget(parent) {
        name_edit_label_ = new QLabel("Name:");
        name_edit_ = new QLineEdit();

        filename_label_ = new QLabel("Filename:");
        filename_edit_ = new QLineEdit();

        map_name_label_ = new QLabel("On map…");
        map_name_edit_ = new QLineEdit();
        coordinates_label_ = new QLabel("at…");
        coor_x_ = new QSpinBox();
        coor_y_ = new QSpinBox();

        save_button_ = new QPushButton(tr("Save"));

        QGridLayout *main_layout = new QGridLayout;
        main_layout->setVerticalSpacing(15);
        main_layout->setHorizontalSpacing(10);

        // Character’s Name
        main_layout->addWidget(name_edit_label_, 0, 0, 1, 1);
        name_edit_label_->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        main_layout->addWidget(name_edit_, 0, 1, 1, 1);

        // Filename
        main_layout->addWidget(filename_label_, 0, 3, 1, 1);
        filename_label_->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        main_layout->addWidget(filename_edit_, 0, 4, 1, 2);

        // Map
        main_layout->addWidget(map_name_label_, 1, 0, 1, 1);
        map_name_label_->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        main_layout->addWidget(map_name_edit_, 1, 1, 1, 1);
        main_layout->addWidget(coordinates_label_, 1, 3, 1, 1);
        coordinates_label_->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        main_layout->addWidget(coor_x_, 1, 4, 1, 1);
        coor_x_->setMinimum(1);
        coor_x_->setMaximum(65535);
        main_layout->addWidget(coor_y_, 1, 5, 1, 1);
        coor_y_->setMinimum(1);
        coor_y_->setMaximum(65535);

        main_layout->addWidget(save_button_, 4, 5, 2, 1);

        setLayout(main_layout);
        setWindowTitle(tr("Saving…"));
    }

// Destructor
Menu_and_layout::~Menu_and_layout(){
    delete name_edit_label_;
    delete name_edit_;
    delete filename_label_;
    delete filename_edit_;
    delete map_name_label_;
    delete map_name_edit_;
    delete coordinates_label_;
    delete coor_x_;
    delete coor_y_;
    delete save_button_;
}