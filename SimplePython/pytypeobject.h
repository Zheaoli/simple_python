#ifndef Py_TYPE_OBJECT_H
#define Py_TYPE_OBJECT_H

typedef void (*PrintFun) (PyObject *object);
typedef PyObject* (*AddFun) (PyObject * left, PyObject* right);
typedef long(*HashFun) (PyObject* object);
typedef struct tagPyTypeObject {
	PyObject_HEAD;
	char* name;
	PrintFun print;
	AddFun add;
	HashFun hash;
}PyTypeObject;
extern PyTypeObject PyType_Type;
#endif