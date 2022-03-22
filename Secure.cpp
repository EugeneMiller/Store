#include <iostream>

char alphabet[] = { "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPKQRSTUVWXYZ0123456789" };

char cezar(char l) {
	for (size_t i = 0; i < strlen(alphabet); i++)
	{
		if (alphabet[i] == l)
		{
			size_t new_ind = (i + 3) % strlen(alphabet);
			return alphabet[new_ind];
		}
	}
	return l;
}

char* code_str(char* str, size_t size) {
	char* code_str = new char[size];//выделили num симв под строку
	if (strlen(str) >= size) {
		strncpy_s(str,size, str, (size - 1));
	}
	for (size_t i = 0; i < strlen(str); i++)
	{
		if (str[i]=='\0')
			code_str[i] = str[i];
		else
			code_str[i] = cezar(str[i]);
	}
	return code_str;
}