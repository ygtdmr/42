#include "SearchableBag.hpp"

class Set
{
	public:
		Set( SearchableBag *bag );
		Set( const Set &other );
		~Set();
		Set	&operator=( const Set &other );
		virtual void insert(int);
		virtual void insert(int*, int);
		virtual void print(void) const;
		virtual void clear();
		virtual bool has(int) const;
	private:
		SearchableBag	*bag_;
};
