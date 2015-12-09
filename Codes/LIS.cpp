// TODO print path must be added

vector<int> v;
v.push_back(inf);
for(int i=0 ; i<n ; i++) {
	int x  = dolls[i].w; // array element
	int id = lower_bound(v.begin(), v.end(), x + 1) - v.begin();

	if (id == v.size() - 1) v.push_back(inf); v[id] = x;
}
cout << v.size()-1 << endl;