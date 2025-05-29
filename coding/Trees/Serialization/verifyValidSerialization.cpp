// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/?envType=problem-list-v2&envId=tree

// Time Complexity: O(n)
// Space Complexity: O(n)

 bool isValidSerialization(string preorder) {
	int countSlots = 1;
	
	stringstream ss(preorder);
	string str;

	vector<string>vec;

	while(getline(ss, str, ',')) {
		vec.push_back(str);
	}

	int n = vec.size();

	for(int i = 0; i<n;i++){
		// curr elem consumed one slot 
		countSlots--;

		if(countSlots < 0) {
			return false;
		}

		// if it is not null then it means it will have 2 more slots for its left and right child
		if(vec[i] != "#") {
			countSlots += 2;
		}
	}

	if(countSlots != 0) {
		return false;
	}

	return true;

	}