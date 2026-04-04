#include "SearchableArrayBag.hpp"

SearchableArrayBag::SearchableArrayBag( void )
: ArrayBag()
{}

SearchableArrayBag::SearchableArrayBag( const SearchableArrayBag &other )
: ArrayBag( other )
{}

SearchableArrayBag	&SearchableArrayBag::operator=( const SearchableArrayBag &other )
{
	if ( this != &other )
		ArrayBag::operator=( other );
	return( *this );
}

SearchableArrayBag::~SearchableArrayBag()
{}

bool	SearchableArrayBag::has( int e ) const
{
	for ( int i = 0; i < this->_size; i++ )
	{
		if ( this->_data[i] == e )
			return ( true );
	}
	return ( false );
}
