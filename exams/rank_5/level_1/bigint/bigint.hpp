#include <iostream>
#include <string>

class bigint
{
	public:
		bigint( const std::string &other );
		bigint( unsigned int other );
		bigint( void );
		bigint( const bigint &other );
		
		bigint	&operator=( const bigint &other );
		bigint	&operator+=( const bigint &other );
		bigint	&operator<<=( const bigint &other );
		bigint	&operator>>=( const bigint &other );
		
		bigint	operator+( const bigint &other ) const;
		bigint	operator<<( const bigint &other ) const;
		bigint	operator>>( const bigint &other ) const;

		bigint	&operator++( void );
		bigint	operator++( int );

		bool	operator==( const bigint &other ) const;
		bool	operator!=( const bigint &other ) const;
		bool	operator>( const bigint &other ) const;
		bool	operator<( const bigint &other ) const;
		bool	operator>=( const bigint &other ) const;
		bool	operator<=( const bigint &other ) const;

		const std::string	&getNum( void ) const;
	private:
		std::string	num_;
};

std::ostream	&operator<<( std::ostream &os, const bigint &other );
