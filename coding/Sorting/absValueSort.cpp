// sort stl 

vector<int> absSort(const vector<int>& arr)
{
	// your code goes here
	vector<int> ans = arr;

	sort(ans.begin(), ans.end(), [](int a, int b){
		if(abs(a) == abs(b)){
			return a < b;
		}

		return abs(a) < abs(b);
	});

	return ans;
}