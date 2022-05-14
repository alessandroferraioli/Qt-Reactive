# Qt Reactive MACRO

Really simple example on how to use a _reactive_ approach using a basic _data model_ and automatically generating signal and slot for _change_ and _set_.
In this way as shows into [widget.cpp](widget.cpp) we can easly connect the view and the data model effortless:

```cpp
    connect(value, qOverload<int>(&QSpinBox::valueChanged),&DataModel::instance(), &DataModel::set_value);
    connect(&DataModel::instance(),&DataModel::nameChanged,name_label,&QLabel::setText);
```

In this way every time we need to update the data, automatically the _data model_ is going to update the view.

Most of the work is done by the following _MACRO_ : 

```cpp

#define REACT_PROPERTY(type, name)\
    Q_PROPERTY(type name READ get_##name WRITE set_##name NOTIFY name##Changed)\
    private:\
    type name;\
    public:\
    type get_##name() const {return name;}\
    Q_SIGNAL void name##Changed(type name); \
    public slots:\
    void set_##name(type name) { if(this->name != name) {this->name=name; emit name##Changed(this->name);}}\
```

where we create, for the given _type_ and _name_ a signal named _nameChanged(type name)_ and a slot named set_name(type name)
