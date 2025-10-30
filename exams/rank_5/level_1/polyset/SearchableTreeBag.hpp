#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "SearchableBag.hpp"
#include "TreeBag.hpp"

class SearchableTreeBag : public SearchableBag, public TreeBag
{
	public:
		SearchableTreeBag();
		SearchableTreeBag(const SearchableTreeBag& other);
		~SearchableTreeBag();
		SearchableTreeBag&	operator=(const SearchableTreeBag& other);
		bool	has(int) const;
};

#endif
