#include "Set.hpp"

Set::Set( SearchableBag *bag )
: bag_( bag )
{}

Set::Set( const Set &other )
{
	*this = other;
}

Set	&Set::operator=( const Set &other )
{
	if ( this != &other )
		this->bag_ = other.bag_;
	return ( *this );
}

bool Set::has(int i) const
{
	return ( this->bag_->has( i ) );
}

void Set::insert( int value )
{
    if ( !this->bag_->has( value ) )
		this->bag_->insert( value );
}

void Set::insert( int* array, int arraySize )
{
	for ( int i = 0; i < arraySize; i++ )
		this->insert( array[i] );
}

void Set::print(void) const
{
	this->bag_->print();
}

void Set::clear()
{
	this->bag_->clear();
}


Set::~Set()
{}
