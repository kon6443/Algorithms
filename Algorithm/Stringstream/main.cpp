#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int answer = 0;
    string my_string = "3 + 44 - 44 + 7";
    stringstream ss;

    /**
     * Initializing ss to my_string.
     */
    ss.str(my_string);
    cout<<"Before while loop:";
    cout<<ss.str()<<endl;

    // Initializing answer to the first segement of my_string.
    ss >> answer;
    
    /**
     * This while loop starts from second segement since answer took the first segement from above.
     */
    string ch;
    int cursor = 0;
    while(ss) {
        if(ch=="+") {
            answer += cursor;
        } else if(ch=="-") {
            answer -= cursor;
        }
        /**
         * Second segement of my_string goes to ch which is string type,
         * third segement of my_string goes to cursor which is int type.
         * And keep repeating it until end of the ss.
         */
        ss >> ch >> cursor;
    }

    /**
     * Above process does not change any to ss variable. 
     * ss.str() returns the entire string sentence. 
     */
    cout<<"After while loop: ";
    cout<<ss.str()<<endl;
    cout<<"Answer: "<<answer<<endl;
    return 0;
}
