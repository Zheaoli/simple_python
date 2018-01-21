#ifndef Py_ENGINE_H
#define Py_ENGINE_H

class ExcuteEngine
{
public:
	void Excute();

private:
	void ExecuteCommand(string& command);
	void ExcutePrint(string symbol);
	void ExcuteAdd(string& target, string& source);
	bool IsSourceAllDigit(string& source);
	PyObject* GetObjectFromSymbol(string& symbol);
	string Trim(string symbol);
private:
	string m_Command;
	PyObject* m_LocalEnvironment=PyDict_Create();
};

#endif
