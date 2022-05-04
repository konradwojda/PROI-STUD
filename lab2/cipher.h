#pragma once
#include <array>
#include <iostream>
#include <vector>

struct PolybiusSquare
{
	std::array<int, 5> verticalLabels;
	std::array<int, 5> horizontalLabels;
	std::array<char, 25> cells;
};

PolybiusSquare generateSquare(std::string codePhrase);

std::string removeDuplicate(const std::string& str);

std::string replaceJ(std::string str);

bool checkString(const int letter, const std::string str);

std::array<int, 5> getLabels(void);

std::array<char, 25> getCells(std::string& codePhrase);

std::ostream& operator<<(std::ostream& os, const PolybiusSquare& square);

std::istream& operator>> (std::istream& is, PolybiusSquare& square);

int findIndex(const std::array<char, 25> array, const char letter);

std::string cipherLetter(const char& letter, const PolybiusSquare& square);

//std::string cipherMessage(const std::string& word, const PolybiusSquare& square);

std::vector<int> cipherMessage(const std::string& word, const PolybiusSquare& square);

void validateKey(const std::string& key);

int findIndex(const std::array<int, 5>& array, const std::string& value);

char decryptLetter(const std::string& code, const PolybiusSquare& square);

std::string predecrypt(const PolybiusSquare& key1, const std::string& key2, const std::string& message);

std::string encrypt(
	PolybiusSquare const& key1,
	std::string const& key2,
	std::string const& message
);

std::string decrypt(
	PolybiusSquare const& key1,
	std::string const& key2,
	std::string const& message
);

