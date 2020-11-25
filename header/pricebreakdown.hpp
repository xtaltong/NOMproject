#ifndef __PRICEBREAKDOWN_HPP__
#define __PRICEBREAKDOWN_HPP__

#include <iostream>
using namespace std;

class PriceBreakdown {
	public:
		PriceBreakdown();
		virtual void collectPriceMetadata() = 0;
};
#endif
