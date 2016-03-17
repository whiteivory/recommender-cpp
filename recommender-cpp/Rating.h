
class Rating
{
public:
	Rating();
	~Rating();
	int getItemId();
	int getRating() { return _rating; }
private:
	int _rating;
	int _id;
};

int Rating::getItemId(){
	return _id;
}
Rating::Rating()
{
}

Rating::~Rating()
{
}