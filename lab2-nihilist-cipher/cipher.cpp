#include <iostream>
#include <array>
#include <string>
#include <sstream>
#include "cipher.h"
#include <vector>
#include <algorithm>

using namespace std;

string removeDuplicate(const string& str)
{
	int id = 0;
	string result;
	for (int i = 0; i < str.length(); i++)
	{
		int j;
		for (j = 0; j < i; j++)
		{
			if (str[i] == str[j])
				break;
		}
		if (j == i)
			result += str[i];
	}
	return result;
}


string replaceJ(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 106)
		{
			str[i] = 105;
		}
	}
	return str;
}

bool checkString(const int letter, const string str)
{
	if (str.find(char(letter)) == -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}


array<int, 5> getLabels(void)
{
	array<int, 5> labels;
	for (int i = 0; i < 5; i++)
	{
		int label = rand() % 1000 + 1;
		labels[i] = label;
	}
	return labels;
}


array<char, 25> getCells(string& codePhrase)
{
	validateKey(codePhrase);
	codePhrase = removeDuplicate(codePhrase);
	array<char, 25> cells;
	for (int i = 0; i < codePhrase.length(); i++)
	{
		cells[i] = codePhrase[i];
	}
	int j = 97;
	for (int i = 0; i < 25 - codePhrase.length(); i++)
	{
		for (j; j <= 122; j++)
		{
			if (checkString(j, codePhrase))
				continue;
			else if (j == 106)
			{
				continue;
			}
			else
			{

				cells[i + codePhrase.length()] = char(j);
				j++;
				break;
			}
		}
	}
	return cells;
}


PolybiusSquare generateSquare(string codePhrase)
{
	PolybiusSquare square;
	square.verticalLabels = getLabels();
	square.horizontalLabels = getLabels();
	square.cells = getCells(codePhrase);
	return square;
}


ostream& operator<<(ostream& os, const PolybiusSquare& square)
{
	os << "   ";
	for (int i = 0; i < 5; i++)
	{
		os << square.horizontalLabels[i] << " ";
	}
	os << "\n";
	int k = 0;
	for (int i = 0; i < 5; i++)
	{
		os << square.verticalLabels[i] << " ";
		if (square.verticalLabels[i] < 100)
			os << " ";
		else if (square.verticalLabels[i] < 10)
			os << "  ";
		for (int j = 0; j < 5; j++)
		{
			os << square.cells[k] << "   ";
			k++;
		}
		os << "\n";
	}
	return os;
}


istream& operator>> (istream& is, PolybiusSquare& square)
{
	string codePhrase;
	is >> codePhrase;
	square = generateSquare(codePhrase);
	return is;
}


int findIndex(const array<char, 25> array, const char letter)
{
	for (int i = 0; i < 25; i++)
	{
		if (array[i] == letter)
		{
			return i;
		}
	}
	return 0;
}


string cipherLetter(const char& letter, const PolybiusSquare& square)
{
	int arrayIndex = findIndex(square.cells, letter);
	int horizontalIndex = arrayIndex % 5;
	int verticalIndex = arrayIndex / 5;
	string ciphered = to_string(square.horizontalLabels[horizontalIndex]);
	ciphered += to_string(square.verticalLabels[verticalIndex]);
	return ciphered;
}


//string cipherMessage(const string& msg, const PolybiusSquare& square)
//{
//	string cipheredMsg;
//	for (int i = 0; i < msg.length(); i++)
//	{
//		if (msg[i] >= 97 && msg[i] <= 122)
//			cipheredMsg += cipherLetter(msg[i], square) + " ";
//	}
//	return cipheredMsg;
//}


vector<int> cipherMessage(const string& msg, const PolybiusSquare& square)
{
	vector<int> cipheredMsg;
	for (auto& letter : msg)
	{
		if (letter >= 97 && letter <= 122)
			cipheredMsg.push_back(stoi(cipherLetter(letter, square)));
	}
	return cipheredMsg;
}

void validateKey(const string& key)
{
	for (int i = 0; i < key.length(); i++)
	{
		if (key[i] < 97 || key[i] > 122)
		{
			throw invalid_argument("Key can contain only lower case letters");
		}
	}
}


string encrypt(
	PolybiusSquare const& key1,
	string const& key2,
	string const& message
)
{
	validateKey(key2);
	vector<int> encryptedKey = cipherMessage(replaceJ(key2), key1);
	vector<int> encryptedMsg = cipherMessage(replaceJ(message), key1);
	string result;
	int j = 0;
	for (auto& i : encryptedMsg)
	{
		result += to_string(i + encryptedKey[j]) + " ";
		j++;
		if (j == encryptedKey.size())
		{
			j = 0;
		}
	}
	result.pop_back();
	return result;
}


//string encrypt(
//	PolybiusSquare const& key1,
//	string const& key2,
//	string const& message
//)
//{
//	validateKey(key2);
//	string encryptedKey = cipherMessage(replaceJ(key2), key1);
//	string encryptedMsg = cipherMessage(replaceJ(message), key1);
//	istringstream msgStream(encryptedMsg);
//	istringstream keyStream(encryptedKey);
//	string result;
//	string msgLetter;
//	string keyLetter;
//	while(!msgStream.eof())
//	{
//		keyStream >> keyLetter;
//		if (keyStream.eof())
//		{
//			keyStream.clear();
//			keyStream.str("");
//			keyStream.str(encryptedKey);
//		}
//		else
//		{
//			msgStream >> msgLetter;
//			if (msgStream.eof())
//				break;
//			result += to_string(stoi(msgLetter) + stoi(keyLetter)) + " ";
//		}
//		
//	}
//	result.pop_back();
//	return result;
//}


int findIndex(const array<int, 5>& array, const string& value)
{
	for (int i = 0; i < 5; i++)
	{
		if (array[i] == stoi(value))
		{
			return i;
		}
	}
	return -1;
}


char decryptLetter(const string& code, const PolybiusSquare& square)
{
	vector<int> possibleVariations;
	for (int i = 0; i < 25; i++)
	{
		possibleVariations.push_back(stoi(cipherLetter(square.cells[i], square)));
	}
	auto iterator =  find(begin(possibleVariations), end(possibleVariations), stoi(code));
	int index = iterator - possibleVariations.begin();
	return square.cells[index];
}

//char decryptLetter(const string& code, const PolybiusSquare& square)
//{
//	string horVal;
//	string verVal;
//	switch (code.length())
//	{
//	case 6:
//	{
//		horVal += code.substr(0, 3);
//		verVal += code.substr(3, 3);
//		int horId = findIndex(square.horizontalLabels, horVal);
//		int verId = findIndex(square.verticalLabels, verVal);
//		int cellId = verId * 5 + horId;
//		return square.cells[cellId];
//	}
//	case 5:
//	{
//		horVal = code.substr(0, 2);
//		verVal = code.substr(2, 3);
//		int horId = findIndex(square.horizontalLabels, horVal);
//		int verId = findIndex(square.verticalLabels, verVal);
//		if (horId == -1 || verId == -1)
//		{
//			horVal = code.substr(0, 3);
//			verVal = code.substr(3, 2);
//		}
//		horId = findIndex(square.horizontalLabels, horVal);
//		verId = findIndex(square.verticalLabels, verVal);
//		int cellId = verId * 5 + horId;
//		return square.cells[cellId];
//	}
//	case 4:
//	{
//		horVal = code.substr(0, 1);
//		verVal = code.substr(1, 3);
//		int horId = findIndex(square.horizontalLabels, horVal);
//		int verId = findIndex(square.verticalLabels, verVal);
//		if (horId == -1 || verId == -1)
//		{
//			horVal = code.substr(0, 3);
//			verVal = code.substr(3, 1);
//		}
//		horId = findIndex(square.horizontalLabels, horVal);
//		verId = findIndex(square.verticalLabels, verVal);
//		if (horId == -1 || verId == -1)
//		{
//			horVal = code.substr(0, 2);
//			verVal = code.substr(2, 2);
//		}
//		horId = findIndex(square.horizontalLabels, horVal);
//		verId = findIndex(square.verticalLabels, verVal);
//		int cellId = verId * 5 + horId;
//		return square.cells[cellId];
//	}
//	case 3:
//	{
//		horVal = code.substr(0, 1);
//		verVal = code.substr(1, 2);
//		int horId = findIndex(square.horizontalLabels, horVal);
//		int verId = findIndex(square.verticalLabels, verVal);
//		if (horId == -1 || verId == -1)
//		{
//			horVal = code.substr(0, 2);
//			verVal = code.substr(2, 1);
//		}
//		horId = findIndex(square.horizontalLabels, horVal);
//		verId = findIndex(square.verticalLabels, verVal);
//		int cellId = verId * 5 + horId;
//		return square.cells[cellId];
//	}
//	case 2:
//	{
//		horVal = code.substr(0, 1);
//		verVal = code.substr(1, 1);
//		int horId = findIndex(square.horizontalLabels, horVal);
//		int verId = findIndex(square.verticalLabels, verVal);
//		int cellId = verId * 5 + horId;
//		return square.cells[cellId];
//	}
//	}
//}


//string predecrypt(const PolybiusSquare& key1, const string& key2, const string& message)
//{	
//	validateKey(key2);
//	string result;
//	string encryptedKey = cipherMessage(replaceJ(key2), key1);
//	istringstream keyStream(encryptedKey);
//	istringstream msgStream(message);
//	string msgLetter;
//	string keyLetter;
//	while (!msgStream.eof())
//	{
//		keyStream >> keyLetter;
//		if (keyStream.eof())
//		{
//			keyStream.clear();
//			keyStream.str("");
//			keyStream.str(encryptedKey);
//		}
//		else
//		{
//			msgStream >> msgLetter;
//			result += to_string(stoi(msgLetter) - stoi(keyLetter)) + " ";
//		}
//
//	}
//	result.pop_back();
//	return result;
//}

string predecrypt(const PolybiusSquare& key1, const string& key2, const string& message)
{	
	validateKey(key2);
	string result;
	vector<int> encryptedKey = cipherMessage(replaceJ(key2), key1);
	istringstream msgStream(message);
	string msgLetter;
	int i = 0;
	while (!msgStream.eof())
	{
		if (i >= encryptedKey.size())
		{
			i = 0;
		}
		msgStream >> msgLetter;
		result += to_string(stoi(msgLetter) - encryptedKey[i]) + " ";
		i++;
	}
	result.pop_back();
	return result;
}



string decrypt(
	PolybiusSquare const& key1,
	std::string const& key2,
	std::string const& message
)
{
	string predecryptedMsg = predecrypt(key1, key2, message);
	istringstream msgStream(predecryptedMsg);
	string msgLetter;
	string result;
	while (!msgStream.eof())
	{
		msgStream >> msgLetter;
		result += decryptLetter(msgLetter, key1);
	}
	return result;
}