#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>
#include <QString>
#include <QDebug>

#define REACT_PROPERTY(type, name)\
    Q_PROPERTY(type name READ get_##name WRITE set_##name NOTIFY name##Changed)\
    private:\
    type name;\
    public:\
    type get_##name() const {return name;}\
    Q_SIGNAL void name##Changed(type name); \
    public slots:\
    void set_##name(type name) { if(this->name != name) {this->name=name; emit name##Changed(this->name);}}\



class DataModel : public QObject
{
    Q_OBJECT


public:
    DataModel(const DataModel&) = delete;
    DataModel& operator=(const DataModel&) = delete;
    
    static DataModel& instance() {
        static DataModel instance;
        return instance;
    }

    REACT_PROPERTY(int, value)
    REACT_PROPERTY(QString,name)



private:
    explicit DataModel(QObject *parent = nullptr):QObject(parent){};








};

#endif // DATAMODEL_H
