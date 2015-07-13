#pragma once

#include <cstdint>
#include <ostream>

#include <sstream>

namespace Casino
{

enum class Suite
{
	CLUBS,
	SPADES,
	HEARTS,
	DIAMONDS
};

class Card
{
public:
	Card(Suite suite,
		std::uint8_t value)
		:
		m_suite(suite),
		m_value(value)
	{

	}

	~Card() = default;

	bool operator<(const Card& rhs) const
	{
		return m_value < rhs.m_value;
	}

	std::string ToString() const
	{
		std::stringstream ss;
		ss << *this;
		return ss.str();
	}

private:
	friend std::ostream& operator<<(std::ostream& os, const Card& card);
	Suite m_suite;
	std::uint8_t m_value;
};

inline std::ostream& operator<<(std::ostream& os, const Card& card)
{
	os << static_cast<int>(card.m_value) << " of ";

	switch (card.m_suite)
	{
		case Suite::CLUBS:
			os << "Clubs.\n";
			break;

		case Suite::SPADES:
			os << "Spades.\n";
			break;
		case Suite::HEARTS:
			os << "Hearts.\n";
			break;
		case Suite::DIAMONDS:
			os << "Diamonds.\n";
			break;
	}
	return os;
}



}