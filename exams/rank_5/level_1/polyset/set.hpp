#include "SearchableBag.hpp"

class set  {
	public:
		set( void );
		set(SearchableBag* bag);
		set(const set &other);
		~set();
		set		&operator=( const set &other );
		void	insert( int num );
		void	insert(int *arr, int size);
		void	clear( void );
		void	print( void );
		bool	has( int num );
	private:
		SearchableBag *bag_;
};
