#include "simplepython.h"
PyObject* PyStr_Create(const char* value) {
	PyStrObject* object = new PyStrObject;
	object->refCount = 1;
	object->type = &PyStr_Type;
	object->length = (value == NULL) ? 0 : strlen(value);
	object->hashValue = -1;
	memset(object->value, 0, 50);
	if (value != NULL) {
		strcpy(object->value, value);
	}
	return (PyObject*)object;
}
static void string_print(PyObject* object) {
	PyStrObject* strObject = (PyStrObject*)object;
	printf("%s\n", strObject->value);
}
static long string_hash(PyObject* object) {
	PyStrObject* strObject = (PyStrObject*)object;
	register int len;
	register unsigned char *p;
	register long x;
	if (strObject->hashValue != -1) {
		return strObject->hashValue;
	}
	len = strObject->length;
	p = (unsigned char *)strObject->value;
	x = *p << 7;
	while (--len >= 0)
		x = (1000003 * x) ^ *p++;
	x ^= strObject->length;
	if (x == -1)
		x = -2;
	strObject->hashValue = x;
	return x;
}
static PyObject* string_add(PyObject* left, PyObject* right) {
	PyStrObject *leftStr = (PyStrObject*)left;
	PyStrObject *rightStr = (PyStrObject*)right;
	PyStrObject *result = (PyStrObject*)PyStr_Create(NULL);
	if (result == NULL) {
		printf("We do not have enough memory");
	}
	else {
		strcpy(result->value, leftStr->value);
		strcat(result->value, rightStr->value);
	}
	return (PyObject*)result;
}
PyTypeObject PyStr_Type = {
	PyObject_HEAD_INIT(&PyType_Type),
	"str",
	string_print,
	string_add,
	string_hash
};
