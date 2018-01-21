#include"simplepython.h"
char* info = "********** Python Research **********\nInput 'exit' to exit\n";
char* prompt = ">>> ";
void ExcuteEngine::Excute() {
	cout << info;
	cout << prompt;
	while (getline(cin, m_Command))
	{
		if (m_Command.size() == 0)
		{
			cout << prompt;
			continue;
		}
		else if (m_Command == "exit")
		{
			return;
		}
		else
		{
			ExecuteCommand(m_Command);
		}
		cout << prompt;
	}
}
void ExcuteEngine::ExecuteCommand(string& command) {
	string::size_type pos = 0;
	if ((pos = command.find("print ")) != string::npos) {
		ExcutePrint(command.substr(6));
	}
	else if ((pos = command.find(" = ")) != string::npos) {
		string target = command.substr(0, pos);
		string source = command.substr(pos + 3);
		ExcuteAdd(target, source);
	}
}
void ExcuteEngine::ExcuteAdd(string& target, string& source) {
	string::size_type pos;
	PyObject* strValue = NULL;
	PyObject* resultValue = NULL;
	if (IsSourceAllDigit(source)) {
		PyObject* intValue = PyInt_Create(atoi(source.c_str()));
		PyObject* key = PyStr_Create(target.c_str());
		PyDict_SetItem(m_LocalEnvironment, key, intValue);
	}
	else if (source.find("\"") != string::npos) {
		strValue = PyStr_Create(source.substr(1, source.size() - 2).c_str());
		PyObject* key = PyStr_Create(target.c_str());
		PyDict_SetItem(m_LocalEnvironment, key, strValue);
	}
	else if ((pos = source.find("+")) != string::npos) {
		PyObject* leftObject = GetObjectFromSymbol(source.substr(0, pos));
		PyObject* rightObject = GetObjectFromSymbol(source.substr(pos + 1));
		if (leftObject != NULL&&right != NULL&&leftObject->type == rightObject->type) {
			resultValue = (leftObject->type)->add(leftObject, rightObject);
			PyObject* key = PyStr_Create(target.c_str());
			PyDict_SetItem(m_LocalEnvironment, key, resultValue);
		}
		(m_LocalEnvironment->type)->print(m_LocalEnvironment);
	}
}
bool ExcuteEngine::IsSourceAllDigit(string& source)
{
	string::size_type len = source.size();
	for (string::size_type i = 0; i < len; ++i)
	{
		if (!isdigit(source[i]))
		{
			return false;
		}
	}
	return true;
}
PyObject* ExcuteEngine::GetObjectFromSymbol(string& symbol) {
	PyObject* key = PyStr_Create(symbol.c_str());
	PyObject* value = PyDict_GetItem(m_LocalEnvironment, key);
	if (value == NULL) {
		cout << "[Error] : " << symbol << "is not defined" << endl;
		return NULL;
	}
	return value;
}
void ExcuteEngine::ExcutePrint(string symbol) {
	PyObject* object = GetObjectFromSymbol(symbol);
	if (object != NULL) {
		PyTypeObject* type = object->type;
		type->print(object);
	}
}