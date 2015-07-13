#pragma once

#include "ManagedCard.h"
#include "Casino/Deck.h"

namespace ManagedCasino
{

public ref class ManagedDeck
{
public:
	ManagedDeck()
		:
		m_Impl(new Casino::Deck())
	{

	}

	~ManagedDeck()
	{
		delete m_Impl;
	}

	//You cannot return value types to C#!
	//you'll get a compiler error about "Languge does not support (method name)
	//Reference http://stackoverflow.com/questions/8661645/my-own-managed-type-as-arg-in-c-cli-class-library-cs0570-is-not-supported-b
	ManagedCasino::ManagedCard^ Draw();

protected:
	!ManagedDeck()
	{
		delete m_Impl;
	}

private:
	Casino::Deck* m_Impl;

};


}