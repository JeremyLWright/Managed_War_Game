#include "stdafx.h"
#include "ManagedDeck.h"

namespace ManagedCasino
{
	ManagedCard^ ManagedDeck::Draw()
	{
		//auto c = m_Impl->Draw();
		auto pc = new Casino::Card(m_Impl->Draw());
		auto mc = gcnew ManagedCard(pc);
		return mc;
	}
}