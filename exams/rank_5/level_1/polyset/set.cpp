#include "set.hpp"

set::set()
{
	bag_ = 0;
}

set::set(SearchableBag *bag)
: bag_(bag)
{}

set::set(const set &other)
: bag_(other.bag_)
{}

set::~set()
{}

set &set::operator=( const set &other )
{
	if (this != &other)
		bag_ = other.bag_;
	return ( *this );
}

void	set::print( void )
{
	if (bag_)
		bag_->print();
}

void	set::clear( void )
{
	if (bag_)
		bag_->clear();
}

void	set::insert( int num )
{
	if (!bag_->has( num ))
		bag_->insert( num );
}

void	set::insert(int *arr, int size)
{
	if (!arr || size <= 0)
		return ;
	for (size_t i = 0; i < size; i++)
		this->insert( arr[i] );
}

bool	set::has( int num )
{
	return ( bag_->has( num ) );
}
