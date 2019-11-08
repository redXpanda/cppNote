#pragma once

#include "Animal.h"

class Tiger:public Animal
{
public:
	Tiger();
	Tiger(int damege);
	virtual ~Tiger()override;


	int getDamege() { return m_damege; };

protected:

	int m_damege;

private:
};
