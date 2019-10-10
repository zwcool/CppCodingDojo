#include <map>

#include "catch.hpp"
//#include "fromRomanNumerals.h"

/*
Beispiele
„I“ -> 1
„II“ -> 2
„IV“ -> 4
„V“ -> 5
„IX“ -> 9
„XLII“ -> 42
„XCIX“ -> 99
„MMXIII“ -> 2013

Wertigkeiten
I	V	X	L	C	D	M
1	5	10	50	100	500	1000

Aufgabenvariationen
Erkenne syntaktische (z.B. „I X“) und semantische (z.B. „IC“) Fehler in Römischen Zahlen.
*/

using namespace std;

class FromRomanNumerals {
	
	public:
		static int toInteger(string romanNumber) {
			if (isNumberValid(romanNumber)) {
				
			}
			return 0;
		}

	private:
		static bool isNumberValid(string romanNumber) {
			string validNumbers [] {"I","V","X","L","C","D","M"};
			for(int i=0; i <= romanNumber.size(); i++) {
				if (validNumbers->find(romanNumber)) {
					return true;
				}
			}
			return false;
		}
};

int fromRomanToInteger(string romanNumber) {

}

bool isRomanNumberValid(string romanNumber) {

}

TEST_CASE( "Converter can convert I to 1", "[fromRomanNumerals]" ) {
	// Arrange
	string romanNumber = "I";
	int expectedInteger = 1;
	FromRomanNumerals romanNumberConverter;
	// Act
	int result = romanNumberConverter.toInteger(romanNumber);
	// Assert
	REQUIRE(expectedInteger == result );
}

TEST_CASE("Converter can convert V to 5", "[fromRomanNumerals]") {
	// Arrange
	string romanNumber = "X";
	int expectedInteger = 10;
	FromRomanNumerals romanNumberConverter;
	// Act
	int result = romanNumberConverter.toInteger(romanNumber);
	// Assert
	REQUIRE(expectedInteger == result);
}

TEST_CASE("Converter can convert X to 10", "[fromRomanNumerals]") {
	// Arrange
	string romanNumber = "X";
	int expectedInteger = 10;
	FromRomanNumerals romanNumberConverter;
	// Act
	int result = romanNumberConverter.toInteger(romanNumber);
	// Assert
	REQUIRE(expectedInteger == result);
}

TEST_CASE("Converter can convert basic roman numbers-X", "[fromRomanNumerals]") {
	// Arrange
	string romanNumber = "X";
	int expectedInteger = 10;
	FromRomanNumerals romanNumberConverter;
	// Act
	int result = romanNumberConverter.toInteger(romanNumber);
	// Assert
	REQUIRE(expectedInteger == result);
}

TEST_CASE("Converter returns 0 if an invalid sign is in the number", "[fromRomanNumerals]") {
	// Arrange
	string invalidNumber = "B";
	int expectedInteger = 0;
	FromRomanNumerals romanNumberConverter;
	// Act
	int result = romanNumberConverter.toInteger(invalidNumber);
	// Assert
	REQUIRE(expectedInteger == result);
}

