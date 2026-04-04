#include "SearchableBag.hpp"
#include "ArrayBag.hpp"

class	SearchableArrayBag : public SearchableBag, public ArrayBag
{
	public:
		SearchableArrayBag( void );
		SearchableArrayBag( const SearchableArrayBag &other );
		SearchableArrayBag	&operator=( const SearchableArrayBag &other );
		bool	has(int) const;
		~SearchableArrayBag();
};
