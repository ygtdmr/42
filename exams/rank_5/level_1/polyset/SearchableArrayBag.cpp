#include "SearchableArrayBag.hpp"

SearchableArrayBag::SearchableArrayBag()
: ArrayBag()
{}
SearchableArrayBag::SearchableArrayBag(const SearchableArrayBag& other)
: ArrayBag(other)
{
	*this = other;
}
SearchableArrayBag::~SearchableArrayBag()
{}

SearchableArrayBag&	SearchableArrayBag::operator=(const SearchableArrayBag& other)
{
	if (this != &other)
		ArrayBag::operator=(other);
	return (*this);
}

bool	SearchableArrayBag::has(int num) const
{
	for (size_t i = 0; i < _size; i++)
	{
		if (_data[i] == num)
			return (true);
	}
	return (false);
}
