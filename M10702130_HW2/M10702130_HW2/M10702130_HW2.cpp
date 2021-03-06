#include <iostream>
#include <string>

using namespace std;

void Put_String(string *str_arr, string str, int length)
{
	int i = 0;

	// Insertion Sort
	for (i = 0; i < length; i++) {
		if (str.compare(str_arr[i]) < 0) {
			for (int j = length - 1; j > i; j--) {
				str_arr[j] = str_arr[j - 1];
			}

			str_arr[i] = str;
			break;
		}
	}

	if (i == length) str_arr[i - 1] = str;
}

int main()
{
	int num, count = 0;

	cout << "Please input the max number of words to be stored." << endl;
	cin >> num;
	cin.ignore();

	string *str_arr = new string[num];

	while (true) {
		string str;

		cout << "Please input the word, or command(print/exit) : ";
		getline(cin, str);

		if (!str.compare("print")) {
			for (int i = 0; i < count; i++) {
				cout << str_arr[i] << " ";
			}
			cout << endl;
		} else if (!str.compare("exit")) {
			break;
		} else {
			if (count == num) {
				cout << "The array is full!" << endl;
			} else {
				Put_String(str_arr, str, ++count);
			}
		}
	}

	return 0;
}
