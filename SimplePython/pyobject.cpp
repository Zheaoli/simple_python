#include "simplepython.h"
PyTypeObject PyType_Type = {
	PyObject_HEAD_INIT(&PyType_Type),
	"type",
	0,
	0,
	0
};