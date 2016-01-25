/************************************************************************
* Class: Rank
*
* Overview: This file holds the ENUM values for the colors and symbols
*	used in the game. Change the values here for them to change in 
*	the game!
*
*************************************************************************/
#ifndef RANK_H
#define RANK_H
enum symbol_ascii {
	THETA = 232,    // Φ			
	SIGMA = 228,    // Σ
	BETA = 225,     // ß
	INFINITY_S = 236, // ∞ 
	FORTE = 159,    // ƒ
	AE = 146,       // Æ
	EX = 88,        // X
	WILD = 168,     // ¿
	BLANK = 0
};

enum symbol_color {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	RED = 12,
	LIGHT_BLUE = 9,
	AQUA = 10,
	PURPLE = 5,
	GREY = 8,
	GOLD = 96
};
#endif