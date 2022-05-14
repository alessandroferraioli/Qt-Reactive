# Qt Reactive MACRO

Really simple example on how to use a _reactive_ approach using a basic _data model_ and automatically generating signal and slot for _change_ and _set_.
In this way as shows into [widget.cpp](widget.cpp) we can easly connect the view and the data model effortless:

```cpp
    connect(value, qOverload<int>(&QSpinBox::valueChanged),&DataModel::instance(), &DataModel::set_value);
    connect(&DataModel::instance(),&DataModel::nameChanged,name_label,&QLabel::setText);
```

In this way every time we need to update the data, automatically the _data model_ is going to update the view.

