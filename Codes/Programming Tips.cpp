Lower bound and upper bound for binary Search
	- lower bound Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
	- upper bound Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.

map<string, int> dict;
class cmp{
public :
	bool operator()(const string& a, const string& b) const {
		return dict[a] < dict[b];
	}
};
typedef set<string,  cmp> sset;