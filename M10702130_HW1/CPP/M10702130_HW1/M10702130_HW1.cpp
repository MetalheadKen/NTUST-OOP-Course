#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int start, end, ans, guess;
	ifstream fileIn;

	fileIn.open("input.txt");
	fileIn >> start >> end >> ans;

	while (true) {
		cout << "Please guess an integer number between " << start << " and " << end << endl;
		
		cin >> guess;

		if (guess <= start || guess >= end) {
			cout << "The number you entered is not within the valid range." << endl;
			cout << "Please try again!" << endl << endl;
		} else if (guess < ans) {
			start = guess;
		} else if (guess > ans) {
			end = guess;
		} else {
			cout << "Bingo! You hit the bomb." << endl;
			break;
		}
	}

	fileIn.close();

	return 0;
}