#include "PredictedItemRating.h"
#include<algorithm>

PredictedItemRating::PredictedItemRating(int userId = 0, int itemId = 0, int rating = 0)
{
	_userId = userId;
	_itemId = itemId;
	_rating = rating;
}


PredictedItemRating::~PredictedItemRating()
{
}
void PredictedItemRating::prsort(const vector<PredictedItemRating>& v){
	sort(v.begin(), v.end());
}
vector<PredictedItemRating> PredictedItemRating::getTopNRecommendations(const vector<PredictedItemRating>& v, int topN){
	prsort(v);
	vector<PredictedItemRating> rv;
		for (vector<PredictedItemRating>::reverse_iterator it = v.rbegin(); it != v.rend(); it++){
			if (topN-- <= 0) break;
			rv.push_back(*it);
		}
		if (topN > 0)
			throw invalid_argument("topN too big!");
		return rv;
}

