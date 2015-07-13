#include "stdafx.h"

#include <random>
#include <algorithm>
#include <numeric>
#include <cassert>

#include "Deck.h"

namespace Casino
{ 
Deck::Deck()
{
	std::vector<std::uint8_t> values(13);
	std::iota(std::begin(values), std::end(values), 1);
	std::vector<Suite> suites{
		Suite::CLUBS,
		Suite::DIAMONDS,
		Suite::HEARTS,
		Suite::SPADES
	};

	m_cards.reserve(52);
	for (const auto suite : suites)
	{
		for (const auto value : values)
		{
			Card c(suite, value);
			m_cards.push_back(c);
		}
	}
	
	assert(m_cards.size() == 52 && "Deck is incorrect.");

	std::random_device rd;
	std::mt19937 entropy(rd());

	std::shuffle(
		std::begin(m_cards),
		std::end(m_cards),
		entropy);

	m_draw_pos = std::begin(m_cards);
}

Card Deck::Draw()
{
	if (m_draw_pos == std::end(m_cards))
		m_draw_pos = std::begin(m_cards);
	return *(++m_draw_pos);
}

}

