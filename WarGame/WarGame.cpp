// WarGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <Casino/Deck.h>


int main(int argc, char* argv[])
{

	Casino::Deck deck;

	const auto player_card = deck.Draw();
	const auto computer_card = deck.Draw();

	
	std::cout << "You got a: " << player_card << '\n';
	std::cout << "I got a: "  << computer_card << '\n';

	if (computer_card < player_card)
		std::cout << "You won!\n";
	else
		std::cout << "You lost!\n";
	
	return 0;
}

