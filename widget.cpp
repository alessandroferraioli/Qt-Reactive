#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    setMinimumSize(200,50);
    QVBoxLayout* main_layout = new QVBoxLayout(this);

    QLabel*name_label = new QLabel("Current Value: 0",this); main_layout->addWidget(name_label);
    QSpinBox* value = new QSpinBox(this); main_layout->addWidget(value);

    connect(value, qOverload<int>(&QSpinBox::valueChanged),&DataModel::instance(), &DataModel::set_value);
    connect(&DataModel::instance(),&DataModel::nameChanged,name_label,&QLabel::setText);

    connect(&DataModel::instance(),&DataModel::valueChanged,[](int value){
        DataModel::instance().set_name(QString("Current Value: ")+QString::number(value));
    });


}

Widget::~Widget()
{
}

