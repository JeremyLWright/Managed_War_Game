// ManagedCasino.h

#pragma once

#include <msclr/marshal_cppstd.h>
#include <Casino/Card.h>

using namespace System;

namespace ManagedCasino {

public ref class ManagedCard
{
	//Reference https://msdn.microsoft.com/en-us/library/ms235281.aspx
	//Explicit Interop overhead = 30 instructions (https://msdn.microsoft.com/en-us/library/ms235282.aspx)
public:
	ManagedCard()
		:
		m_Impl(new Casino::Card(Casino::Suite::CLUBS, 1))
	{
	}

	ManagedCard(Casino::Card another_card)
		:
		m_Impl(&another_card)
	{

	}

	ManagedCard(const ManagedCard% rhs)
		:
		m_Impl(rhs.m_Impl)
	{

	}
	
	ManagedCard(Casino::Card* rhs)
		:
		m_Impl(rhs)
	{

	}

	//Reference https://msdn.microsoft.com/en-us/library/ds533389.aspx
	//Only static member operators are available from other .NET languages
	static bool operator<(ManagedCard^ lhs, ManagedCard^ rhs)
	{
		return lhs->m_Impl->operator<(*(rhs->m_Impl));
	}

	~ManagedCard()
	{
		delete m_Impl;
	}
	// Reference (http://stackoverflow.com/questions/946813/c-cli-converting-from-systemstring-to-stdstring)
	virtual String^ ToString() override
	{
		auto s = m_Impl->ToString();
		return gcnew System::String(s.c_str());
	}

protected:
	//Reference https://msdn.microsoft.com/en-us/library/ms235281.aspx
	//Depending on how the garbage collector collects this class, either the 
	//destructor or this, the finalizer will run. 
	//The garbage collector will assure only one is ever executed.
	!ManagedCard()
	{
		delete m_Impl;
	}
private:
	Casino::Card* m_Impl;

};
}
