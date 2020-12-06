#ifndef __DDPRICEBREAKDOWN_HPP__
#define __DDPRICEBREAKDOWN_HPP__

#include "pricebreakdown.hpp"

class DDPriceBreakdown : public PriceBreakdown {
        public:
		DDPriceBreakdown();
                virtual void collectPriceMetadata(Restaurant *);
};
#endif
