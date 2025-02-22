#include <iostream>
#include <string>
#include <vector>
using namespace std;

void nameFinder(const vector<string>& array1, const vector<string>& array2) {
    string findName;

    cout << "Enter the name to find" << endl;
    cin >> findName;

    for (size_t x = 0; x < array1.size(); x++) {
        if (array1[x] == findName) {
            cout << "Name found on event1 index = " << x << endl;
        }
    }
    for (size_t x = 0; x < array2.size(); x++) {
        if (array2[x] == findName) {
            cout << "Name found on event2 index = " << x << endl;
        }
    }
}

void calculateTotal(int size1, int size2) {
    int total;
    total = size1 + size2;
    total = total * 10;

    cout << "Total dollars donated are = " << total << endl;
}

void reverseName(const vector<string>& array1, const vector<string>& array2) {
    
    vector<string> reverseEvent1(array1.size());
    vector<string> reverseEvent2(array2.size());

    for(int x = array1.size() - 1; x >= 0; x--) {
        reverseEvent1[array1.size() - x -1] = array1[x];
    }
    
    for(int x = array2.size() - 1; x >= 0; x--) {
        reverseEvent2[array2.size() - x -1] = array2[x];
    }

    cout << "Names in reverse order event1" << endl;
    for(int x = 0; x < reverseEvent1.size(); x++) {
        cout << reverseEvent1[x] << endl;
    }

    cout << "Names in reverse order event2" << endl;
    for(int x = 0; x < reverseEvent2.size(); x++) {
        cout << reverseEvent2[x] << endl;
    }

}
void barGraph(int size1, int size2) {
    cout << "Event 1";
    for(int x = 0; x < size1; x++) {
        cout << "*";    
    }
    cout << endl;
    cout << "Event 2";
    for(int x = 0; x < size2; x++) {
        cout << "*";
    }
    cout << endl;

}


int main() {

    int count1, count2;
    string userInput;

    cout << "Enter the number of participants in first event" << endl;
    cin >> count1;
    
    if(count1 > 5) {
        cout << "Maximum 5 participants are allowed" << endl;
        return 0;
    }
    vector<string> event1(count1);

    for(int x = 0; x < count1; x++) {
        
        cout << "Enter the name of the participants in first event" << endl;
        cin >> userInput;

        event1[x] = userInput;
    }
     
    cout << "Enter the number of participants in second event" << endl;
    cin >> count2;
    
    if(count2 > 5) {
        cout << "Maximum 5 participants are allowed" << endl;
        return 0;
    }
    vector<string> event2(count2);

    for(int x = 0; x < count2; x++) {
        
        cout << "Enter the name of the participants in second event" << endl;
        cin >> userInput;
        event2[x] = userInput;
    }
    nameFinder(event1, event2);
    calculateTotal(count1, count2);
    reverseName(event1, event2);
    barGraph(count1, count2);
}