#include <sstream>
#include <cctype>
#include "bigint.hpp"

bigint::bigint( const std::string &other )
{
	std::stringstream	ss;
	bool				filterZero( true );

	for ( size_t i = 0; i < other.size(); i++ )
	{
		if ( other[i] == '0' && filterZero )
			continue;
		if ( std::isdigit( other[i] ) )
		{
			filterZero = false;
			ss << other[i];
		}
	}
	this->num_ = ss.str();
	if ( this->num_.empty() )
		this->num_ = "0";
}

bigint::bigint( unsigned int other )
{
	std::stringstream	ss;

	ss << other;
	this->num_ = ss.str();
}

bigint::bigint( void )
: num_("0")
{}

bigint::bigint( const bigint &other )
{
	*this = other;
}

bool	bigint::operator==( const bigint &other ) const
{
	return ( this->num_ == other.num_ );
}

bool	bigint::operator!=( const bigint &other ) const
{
	return ( this->num_ != other.num_ );
}

bool	bigint::operator>( const bigint &other ) const
{
	if ( this->num_.size() > other.num_.size() )
		return ( true );
	if ( this->num_.size() < other.num_.size() )
		return ( false );

	std::string::const_iterator	it_self = this->num_.begin();
	std::string::const_iterator	it_other = other.num_.begin();

	while ( it_self != this->num_.end() )
	{
		if ( ( *it_self - '0' ) > ( *it_other - '0' ) )
			return ( true );
		it_self++;
		it_other++;
	}
	return ( false );
}

bool	bigint::operator<( const bigint &other ) const
{
	if ( this->num_.size() < other.num_.size() )
		return ( true );
	if ( this->num_.size() > other.num_.size() )
		return ( false );

	std::string::const_iterator	it_self = this->num_.begin();
	std::string::const_iterator	it_other = other.num_.begin();

	while ( it_self != this->num_.end() )
	{
		if ( ( *it_self - '0' ) < ( *it_other - '0' ) )
			return ( true );
		it_self++;
		it_other++;
	}
	return ( false );
}

bool	bigint::operator>=( const bigint &other ) const
{
	return ( ( *this == other ) || ( *this > other ) );
}

bool	bigint::operator<=( const bigint &other ) const
{
	return ( ( *this == other ) || ( *this < other ) );
}

bigint	&bigint::operator=( const bigint &other )
{
	if ( this != &other )
		this->num_ = other.num_;
	return ( *this );
}

bigint	&bigint::operator+=( const bigint &other )
{
	return ( *this = ( *this + other ) );
}

bigint	&bigint::operator<<=( const bigint &other )
{
	return ( *this = ( *this << other ) );
}

bigint	&bigint::operator>>=( const bigint &other )
{
	return ( *this = ( *this >> other ) );
}

bigint	bigint::operator<<( const bigint &other ) const
{
	std::stringstream	ss;
	bigint				tmp;

	if ( other == bigint( 0 ) )
		return ( *this );
	while( tmp++ < other )
		ss << '0';
	return ( bigint( this->num_ + ss.str() ) );
}

bigint	bigint::operator>>( const bigint &other ) const
{
	std::stringstream	ss;
	bigint				tmp(1);
	std::string::const_iterator	it_self( this->num_.begin() );

	if ( other == bigint( 0 ) )
		return ( *this );
	tmp <<= other;
	while( tmp < *this )
	{
		tmp <<= 1;
		ss << *it_self++;
	}
	return ( bigint( ss.str() ) );
}

bigint	&bigint::operator++( void )
{
	return ( *this += bigint( 1 ) );
}

bigint	bigint::operator++( int )
{
	bigint	tmp( *this );
	++( *this );
	return ( tmp );
}

bigint	bigint::operator+( const bigint &other ) const
{
	std::string						num_self( this->num_ );
	std::string						num_other( other.num_ );
	std::string::reverse_iterator	it_self( num_self.rbegin() );
	std::string::reverse_iterator	it_other( num_other.rbegin() );
	int								carry(0);

	if ( num_self.size() < num_other.size() )
		num_self.swap( num_other );

	while( it_other != num_other.rend() )
	{
		int	total( ( *it_self - '0' ) + ( *it_other - '0' ) + carry );
		*it_self = (total % 10) + '0';
		carry = total / 10;
		it_self++;
		it_other++;
	}

	while( it_self != num_self.rend() && carry )
	{
		int	total( ( *it_self - '0' ) + carry );
		*it_self = (total % 10) + '0';
		carry = total / 10;
		it_self++;
	}

	if ( carry )
		num_self.insert( num_self.begin(), '1' );

	return ( bigint( num_self ) );
}

const std::string	&bigint::getNum( void ) const
{
	return ( this->num_ );
}

std::ostream	&operator<<( std::ostream &os, const bigint &other )
{
	os << other.getNum();
	return ( os );
}
