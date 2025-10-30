#ifndef SEARCHABLE_ARRAY_BAG_HPP
#define SEARCHABLE_ARRAY_BAG_HPP

#include "SearchableBag.hpp"
#include "ArrayBag.hpp"

class SearchableArrayBag : public SearchableBag, public ArrayBag
{
	public:
		SearchableArrayBag();
		SearchableArrayBag(const SearchableArrayBag& other);
		~SearchableArrayBag();
		SearchableArrayBag&	operator=(const SearchableArrayBag& other);
		bool	has(int) const;
};

#endif
