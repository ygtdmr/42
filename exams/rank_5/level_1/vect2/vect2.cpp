#include "vect2.hpp"

vect2::vect2( void )
{}

vect2::vect2( int n )
{
	*this = vect2(n, n);
}

vect2::vect2( int x, int y )
{
	this->v.first = x;
	this->v.second = y;
}

vect2::vect2( const vect2 &other )
{
	*this = other;
}

vect2	&vect2::operator=( const vect2 &other )
{
	if (this != &other)
		this->v = other.v;
	return ( *this );
}

vect2	&vect2::operator+=( const vect2 &other )
{
	return ( *this = ( *this + other ) );
}

vect2	&vect2::operator-=( const vect2 &other )
{
	return ( *this = ( *this - other ) );
}

vect2	&vect2::operator*=( const vect2 &other )
{
	return ( *this = ( *this * other ) );
}

vect2	vect2::operator+( const vect2 &other ) const
{
	return ( vect2( ( *this )[0] + other[0], ( *this )[1] + other[1] ) );
}

vect2	vect2::operator-( const vect2 &other ) const
{
	return ( vect2( ( *this )[0] - other[0], ( *this )[1] - other[1] ) );
}

vect2	vect2::operator*( const vect2 &other ) const
{
	return ( vect2( ( *this )[0] * other[0], ( *this )[1] * other[1] ) );
}

vect2	&vect2::operator++( void )
{
	return ( *this += 1 );
}

vect2	vect2::operator++( int )
{
	vect2	tmp( *this );

	++*this;
	return ( tmp );
}

vect2	&vect2::operator--( void )
{
	return ( *this -= 1 );
}

vect2	vect2::operator--( int )
{
	vect2	tmp( *this );

	--*this;
	return ( tmp );
}


int		vect2::operator[]( int index ) const
{
	if ( index % 2 == 0 )
		return ( this->v.first );
	else
		return ( this->v.second );
}

int		&vect2::operator[]( int index )
{
	if ( index % 2 == 0 )
		return ( this->v.first );
	else
		return ( this->v.second );
}

bool	vect2::operator==( const vect2 &other )
{
	return ( ( ( *this )[0] == other[0] ) && ( ( *this )[1] == other[1] ) );
}

bool	vect2::operator!=( const vect2 &other )
{
	return ( !(*this == other) );
}


std::ostream	&operator<<( std::ostream &os, const vect2 &v )
{
	os << "{" << v[0] << ", " << v[1] << "}" << std::endl;
	return ( os );
}

vect2	operator+( int i, const vect2 &other )
{
	return ( other + i );
}

vect2	operator*( int i, const vect2 &other )
{
	return ( other * i );
}
