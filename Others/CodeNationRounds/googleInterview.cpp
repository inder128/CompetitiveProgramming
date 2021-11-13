Given a sorted string array (alphabetical order), and a prefix string, please find the number of strings have the prefix given in this array.


// n

// m


l -  r

r - l + 1;

arr[i], prefix





arr[i] < prefix + "zzzzzzzzzzzzzinfinote", i is maximum

arr[i] >= prefix, i is minimum


abcd > abc

rp = 0;
lp = 1;
// 0

// prefix = ab; [a, b, c]

int matchihgPrefix(string prefix, vector <string> arr){
	int n = arr.size();
	int m = prefix.size();

	// lp
	//  arr[i] >= prefix, i is minimum
	int l = -1, r = n;
	while(l + 1 < r){
		int mid = (l + r) / 2;
		bool check;
		if(arr[i] >= prefix){
			check = true;
		}
		else{
		 	check = false;
		}

		if(check == true){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	int lp = r;


	// rp
	// arr[i] < prefix + "zzzzzzzzzzzzzinfinote", i is maximum
	l = -1, r = n;
	while(l + 1 < r){
		int mid = (l + r) / 2;
		bool check ;
		if(arr[i] <= prefix){
			check = true;
		}
		else{
			check = false;
		}

		if(check == true){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	int rp = l;
  
	return rp - lp + 1;
}