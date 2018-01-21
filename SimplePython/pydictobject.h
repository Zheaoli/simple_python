#ifndef Py_DICT_OBJECT_H
#define Py_DICT_OBJECT_H
typedef struct tagPyDictObject {
	PyObject_HEAD;
	map<long, PyObject*>dict;
}PyDictObject;
extern PyTypeObject PyDict_Type;
PyObject* PyDict_Create();
PyObject* PyDict_GetItem(PyObject* target, PyObject* key);
int PyDict_SetItem(PyObject* target, PyObject* key, PyObject* value);
#endif