#include "SearchableTreeBag.hpp"

SearchableTreeBag::SearchableTreeBag( void )
: TreeBag()
{}

SearchableTreeBag::SearchableTreeBag( const SearchableTreeBag &other )
: TreeBag( other )
{}

SearchableTreeBag	&SearchableTreeBag::operator=( const SearchableTreeBag &other )
{
	if ( this != &other )
		TreeBag::operator=( other );
	return( *this );
}

SearchableTreeBag::~SearchableTreeBag()
{}

bool	SearchableTreeBag::has( int e ) const
{
	Node	*current( root );

	while( current )
	{
		if ( current->value == e )
			return ( true );
		current = current->right;
	}
	return ( false );
}
