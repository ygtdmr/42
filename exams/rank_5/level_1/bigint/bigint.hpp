#include <string>

class bigint
{
	public:
		bigint( void );
		bigint( const std::string &nbr );
		bigint( int nbr );
	private:
		void *num;
};
