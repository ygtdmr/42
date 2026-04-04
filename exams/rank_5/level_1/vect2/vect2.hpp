#include <utility>
#include <iostream>

class	vect2
{
	public:
		vect2( void );
		vect2( int n );
		vect2( int x, int y );
		vect2( const vect2 &other );

		vect2	&operator=( const vect2 &other );
		
		vect2	&operator+=( const vect2 &other );
		vect2	&operator-=( const vect2 &other );
		vect2	&operator*=( const vect2 &other );
		
		vect2	operator+( const vect2 &other ) const;
		vect2	operator-( const vect2 &other ) const;
		vect2	operator*( const vect2 &other ) const;

		vect2	&operator++( void );
		vect2	operator++( int );

		vect2	&operator--( void );
		vect2	operator--( int );
		
		bool	operator==( const vect2 &other );
		bool	operator!=( const vect2 &other );

		int		operator[]( int index ) const;
		int		&operator[]( int index );
	private:
		std::pair<int, int>	v;
};

std::ostream	&operator<<( std::ostream &os, const vect2 &other );
vect2			operator+( int i, const vect2 &other );
vect2			operator*( int i, const vect2 &other );
