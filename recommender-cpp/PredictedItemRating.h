#pragma once
#include<vector>
#include"User.h"
#include"DataSet.h"
using namespace std;
class PredictedItemRating
{
private:
	int _userId;
	int	_itemId;
	double _rating;
public:
	PredictedItemRating(int userId = 0, int itemId = 0, int rating = 0);
	~PredictedItemRating();
	bool operator<(const PredictedItemRating& rhs){ return _rating < rhs._rating; }
	int getUserId()const{ return _userId; }
	int getItemId() const{ return _itemId; }
	double getRating() const{ return _rating; }
	void setRating(double rating){ _rating = rating; }
	static void prsort(const vector<PredictedItemRating>& v);
	static vector<PredictedItemRating> getTopNRecommendations(const vector<PredictedItemRating>& v, int topN);
	static void printUserRecommendations(
		const User& user, const DataSet& ds, vector<PredictedItemRating> recommendedItems);
};

