#include "SimilarUser.h"
#include<algorithm>

SimilarUser::SimilarUser(const User& u ,double simi)
{
	_friend = new User(u);
	_similiraty = simi;
}


SimilarUser::~SimilarUser()
{
	delete _friend;
}
void SimilarUser::susort(vector<SimilarUser>& vu){
	sort(vu.begin(), vu.end());
}

vector<User> SimilarUser::getTopNFriends(vector<SimilarUser>& vu, int topN)const{
	vector<User> rv;
		for (vector<SimilarUser>::reverse_iterator it1 = vu.rbegin(); it1 != vu.rend(); it1++){
			if (topN-- <= 0)break;
			rv.push_back(it1->getUser());
		}
		if (topN > 0)
			throw invalid_argument("topN too big!");
	return rv;
}

void SimilarUser::print(const vector<SimilarUser>&vu,const string& header){
	cout << endl << header << endl;
	for each (auto var in vu)
	{
		cout << "name: " << var.getFriendName() << ", similarity: " << var.getSimilarity() << endl;
	}

}