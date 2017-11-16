#include "stdafx.h"
#include "LeetCode_12_IntegerToRoman.h"


string LeetCode_12_IntegerToRoman::intToRoman(int num)
{
	string romanPieces[35] = { "","I","II","III","IV","V","VI","VII","VIII","IX",
		"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
		"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
		"","M","MM","MMM","MMMM" };

	return romanPieces[num / 1000 + 30] + romanPieces[(num / 100) % 10 + 20]
		+ romanPieces[(num / 10) % 10 + 10] + romanPieces[num % 10];


}