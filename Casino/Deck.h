#pragma once

#include <vector>

#include "Card.h"
#include "Casino.h"

namespace Casino
{

class Deck
{
public:
	CASINO_API Deck();
	~Deck() = default;

	CASINO_API Card Draw();

	std::vector<Card> m_cards;
	std::vector<Card>::iterator m_draw_pos;
};


}
