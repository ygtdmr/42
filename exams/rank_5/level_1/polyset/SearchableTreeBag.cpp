#include "SearchableTreeBag.hpp"

SearchableTreeBag::SearchableTreeBag()
: TreeBag()
{}
SearchableTreeBag::SearchableTreeBag(const SearchableTreeBag& other)
: TreeBag(other)
{
	*this = other;
}
SearchableTreeBag::~SearchableTreeBag()
{}

SearchableTreeBag&	SearchableTreeBag::operator=(const SearchableTreeBag& other)
{
	if (this != &other)
		TreeBag::operator=(other);
	return (*this);
}

bool	SearchableTreeBag::has(int num) const
{
	Node	*tmp;

	tmp = root;
	while (tmp)
	{
		if (tmp->value == num)
			return (true);
		tmp = tmp->right;
	}
	return (false);
}
