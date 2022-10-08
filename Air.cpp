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
};

bool Comparator(const range a, const range b) {
	//	cout << a.weight << " < " << b.weight << "? ";
	return a.weight > b.weight;
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

	int numOfRooms = 0;

	while(listOfRanges.size() != 0){
		lower = listOfRanges.back().lower;
		upper = listOfRanges.back().upper;
		listOfRanges.pop_back();
		numOfRooms++;
		for(int i = 0; i < listOfRanges.size(); i++){
//			cout << "Other's range: " << listOfRanges[i].lower << " , " << listOfRanges[i].upper << " Our range: " << lower << " , " << upper << "\n";
			if (listOfRanges[i].upper >= lower && listOfRanges[i].lower <= upper){
//				cout << "Deleted the other range!\n";
				listOfRanges.erase(listOfRanges.begin() + i);
			}
		}

	}


	cout << numOfRooms;


}


int main(){
	optimizeMinions();
}