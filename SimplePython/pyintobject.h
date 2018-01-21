#pragma once
#ifndef Py_INT_OBJECT_H
#define Py_INT_OBJECT_H
typedef struct tagPyIntObject {
	PyObject_HEAD;
	int value;
}PyIntObject;
extern PyTypeObject PyInt_Type;
PyObject * PyInt_Create(int value);
#endif