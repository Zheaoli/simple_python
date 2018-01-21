#ifndef Py_STR_OBJECT_H
#define Py_STR_OBJECT_H
typedef struct tagPyStrObject {
	PyObject_HEAD;
	int length;
	long hashValue;
	char value[50];
}PyStrObject;
extern PyTypeObject PyStr_Type;
PyObject * PyStr_Create(const char* value);
#endif