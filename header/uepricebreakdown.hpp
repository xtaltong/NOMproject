#ifndef __UEPRICEBREAKDOWN_HPP__
#define __UEPRICEBREAKDOWN_HPP__

#include "pricebreakdown.hpp"

class UEPriceBreakdown : public PriceBreakdown {
	public:
		UEPriceBreakdown();
		virtual void collectPriceMetadata();
};
#endif 
