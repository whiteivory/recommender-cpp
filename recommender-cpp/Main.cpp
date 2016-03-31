
#include "XMLDataSet.h"
#include "Delphi.h"
#include"PredictedItemRating.h"
using namespace std;
void main(){
	XMLDataSet xds;
	xds.loadData();

	Delphi delphi(xds, RecommendationType::USER_BASED);
	User u(1, "tom");
	vector<PredictedItemRating> p = delphi.recommend(u);
	vector<SimilarUser> su = delphi.findSimilarUsers(u);
	SimilarUser s = su[0];
	int i;
}