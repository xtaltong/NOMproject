#ifndef __PRICEBREAKDOWN_HPP__
#define __PRICEBREAKDOWN_HPP__

#include <iostream>
using namespace std;

struct Fee {
	string feeType;
	double price;
	Fee(string feeType, double price) : feeType(feeType), price(price) {};
}

class PriceBreakdown {
	protected:
		vector<Fee> feeBreakdown;
	public:
		PriceBreakdown();
		virtual void collectPriceMetadata(Restaurant *) = 0;
};
#endif

//{(pickup, 10), (delivery, 20)}
//cookTime x num Items

// DeliveryOptionFactory* delfact = new UEDeliveryFactory();
// PriceBreakdown* pb = delfact->createPriceBreakdown()
// get each item they want price

// DD: DisneyBakery {beignet - 1, cookie - 2}
// UE: DisneyBakery {beignet - 2, cookie - 1}

// Restaurant r= DisneyBakery {beignet, cookie}
// -1 default
// r->addItem("beignet");
// r->addItem("cookie")

// choose Restaurant : DisneyBakery
// print menu
// add items to restaurant object as they choose with default price -1
// make factory after they choose if they want pricce or __TIME__
// make product which will automatically do the one that matches the factory
// get hte price information and fill in for item objects
// add tags if they want
// make strategy to compare the options

