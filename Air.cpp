#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

struct range{
	int lower = 0;
	int upper = 0;
	int weight = 0;
//	vector<range> overlap;
};

bool Comparator(const range a, const range b) {
	//	cout << a.weight << " < " << b.weight << "? ";
	return a.weight < b.weight;
}



void optimizeMinions(){
	int numOfMinions = 0;
	cin >> numOfMinions;

	vector<range> listOfRanges;


	int lower = 0, upper = 0;
	for (int i = 0 ; i < numOfMinions ; i++){
		cin >> lower >> upper;
		listOfRanges.push_back(range{lower, upper, upper-lower});
	}

	sort(listOfRanges.begin(), listOfRanges.end(), Comparator);

	

//	sort(listOfRanges.begin(), listOfRanges.end(), Comparator_overlap);

/*
for (int index = 0; index < listOfRanges.size(); index++){
		lower = listOfRanges[index].lower;
		upper = listOfRanges[index].upper;
		//listOfRanges.pop_back();
		for(int i = 0; i < listOfRanges.size(); i++){
//			cout << "Other's range: " << listOfRanges[i].lower << " , " << listOfRanges[i].upper << " Our range: " << lower << " , " << upper << "\n";
			if (listOfRanges[i].upper >= lower && listOfRanges[i].lower <= upper){
				listOfRanges[index].overlap.push_back(listOfRanges[i]);

//				cout << "Deleted the other range!\n";
				//listOfRanges.erase(listOfRanges.begin() + i);
			}
		}

	}

	20
1 5
2 6
2 4
3 9
5 6
6 8
7 8
7 8
7 13
6 9
10 13
9 11
9 13
9 11
10 13
13 14
13 15
14 17
14 16
2 4

	*/


	int numOfRooms = 0;
	for(int k = 0; k < listOfRanges.size(); k++){
//		cout << "\n" << listOfRanges[k].lower << "-->" << listOfRanges[k].upper << "\n";
		lower = listOfRanges[k].lower;
		upper = listOfRanges[k].upper;

		
		if (upper == -1){
			//listOfRanges.erase(listOfRanges.begin()+j);
			continue;
		}
		vector<int> overLap[(upper - lower + 1)];

		for(int i = 0; i < listOfRanges.size(); i++){
			for (int j = lower; j <= upper; j++){
//				cout << listOfRanges[i].upper << " > " << j << " > " << listOfRanges[i].lower << "\n";
				if ( i != k && listOfRanges[i].upper >= j && listOfRanges[i].lower <= j){
//					cout << "Pushed back the edge to " << j-lower << " ! \n";
					overLap[j-lower].push_back(i);
				}
			}				
		}
		
		int index = 0;
		int max = 0;

		for (int i = 0; i < upper - (lower); i++){
//			cout << "size: " << overLap[i].size();
			if (overLap[i].size() > max){
				max = overLap[i].size();
				index = i;
			}
		}

//		cout << "Deleting edges: \n";

		for(int e : overLap[index]){
//			cout << listOfRanges[e].lower << " " << listOfRanges[e].upper << "\n";
			listOfRanges[e] = range{-1,-1,-1};
		}
	//	cout << "\n";
		// for(range e: listOfRanges){
		// 	cout << e.lower << "-->" << e.upper << "\n";
		// }

	}
	//	cout << "\n\n";
		for(range e: listOfRanges){

		//	cout << e.lower << "-->" << e.upper << "\n";
			if (e.upper != -1 && e.lower != -1){
				numOfRooms++;
			}

		}
	


	

//listOfRanges.erase(listOfRanges.begin()+i);
	cout << numOfRooms;


}


int main(){
	optimizeMinions();
}