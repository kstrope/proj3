#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

void print(vector<int> numbers[], int input) {
    for(int i = 0; i < input; i++) {
        cout << numbers[input].at(i) << ";";
        if (i == 9)
        {
                cout << endl;
        }
	}
}

void transfer(vector<int> numbers[], vector<int> numbers2[], int a, int b, int input){
	int x;
	for (int i = 0; i < 10; i++){
		x = numbers[a].at(i);
		numbers2[b].push_back(x);
	}
}

void MyFunc (vector<int> numbers[], int input, int checks) {
	vector<int> numbers2[input];
	int limit = 10;
	int a = 0, b = 0;
	int count[limit];
	for (int i = 0; i < limit; i++){
		count[i] = 0;
	}
	for (int j = 0; j < input; j++){
		count[numbers[j].at(checks)] = count[numbers[j].at(checks)] + 1;
	}
	for (int k = 0; k < limit; k++){
		a = 0;
		while (count[k] > 0 && b < input){
			if (numbers[a].at(checks) == k){
				transfer(numbers, numbers2, a, b, input);
				b++;
				count[k]--;
			}
			if (count[k] == 0)
				break;
			a++;
			if (a == input)
				a = 0;
		}
	}
	checks--;
	if (checks < 0)
		print(numbers2, checks);
	else
		MyFunc(numbers2, input, checks);
}


int main(int argc,char **argv) {
	int input;
	cin >> input;
	vector<int> numbers[input];
	for ( int i=0; i<input; i++ )
	{
		for(int j=0; j<10; j++)
		{
			int num;
			cin >> num;
			numbers[i].push_back(num);
		}
	}
  // Run your algorithms to manipulate the elements in Sequence
	MyFunc(numbers,input,9);
}