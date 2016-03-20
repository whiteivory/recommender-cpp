#include "PredictedItemRating.h"
#include<algorithm>

PredictedItemRating::PredictedItemRating(int userId , int itemId , int rating )
{
	_userId = userId;
	_itemId = itemId;
	_rating = rating;
}


PredictedItemRating::~PredictedItemRating()
{
}
void PredictedItemRating::prsort(vector<PredictedItemRating>& v){
	sort(v.begin(), v.end());
}
vector<PredictedItemRating> PredictedItemRating::getTopNRecommendations( vector<PredictedItemRating>& v, int topN){
	prsort(v);
	vector<PredictedItemRating> rv;
		for (vector<PredictedItemRating>::const_reverse_iterator it = v.rbegin(); it != v.rend(); it++){
			if (topN-- <= 0) break;
			rv.push_back(*it);
		}
		if (topN > 0)
			throw invalid_argument("topN too big!");
		return rv;
}
bool  PredictedItemRating::operator<(const PredictedItemRating& rhs)const{ return _rating < rhs._rating; }
bool  PredictedItemRating::operator==(const PredictedItemRating& rhs)const { return _rating == rhs._rating; }
