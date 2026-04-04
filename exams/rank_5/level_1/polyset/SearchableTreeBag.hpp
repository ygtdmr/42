#include "SearchableBag.hpp"
#include "TreeBag.hpp"

class	SearchableTreeBag : public SearchableBag, public TreeBag
{
	public:
		SearchableTreeBag( void );
		SearchableTreeBag( const SearchableTreeBag &other );
		SearchableTreeBag	&operator=( const SearchableTreeBag &other );
		bool	has(int) const;
		~SearchableTreeBag();
};
