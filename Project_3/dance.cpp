//
//  main.cpp
//  project_3
//
//  Created by Adil Sultan on 4/25/16.
//  Copyright © 2016 Adil Sultan. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;


bool hasCorrectSyntax(string dance){
    
   if (dance.size() == 0)
       return true;
    //here for any case that is not acceptable return false.
    for (int k = 0; k != dance.size(); k ++){
        
        //if any letters other than the acceptable kind are use then return false
        if (dance[k] != 'L' || dance[k] != 'l' || dance[k] != 'R' || dance[k] != 'r' || dance[k] != 'U' || dance[k] != 'u' || dance[k] != 'D' || dance[k] != 'd')
            return false;
        // if a letter is not followed by a slash then return false
        if (isalpha(dance[k]) && dance[k+1] != '/')
            return false;
        //if a digit in the string is not followed by either a digit or a letter then return false
        if (isdigit(dance[k])){
            if(!isdigit(dance[k+1]) || (!isalpha(dance[k+1] && !isupper(dance[k+1]))))
                return false;
        }
        //if the last character in the string is not a slash then return false
        if (dance[dance.size()-1] != '/')
            return false;
    }
    
    //if none of the preceding cases occur then the string has correct syntax so return true
    return true;
}

/*int enoughBeats (string dance) {
    int beatCounter = 0;
    char longBeat = '0';
    for ( int i = 0; i != dance.size(); i++){
    if (isdigit(dance[i]) && isalpha(dance[i+1]))
        
    }
    return 0;
}*/

int convertDance (string dance, string& instructions, string& badBeat){
    int beatDuration;
    char longBeat = '0';
    int beatCount = 1;
    
    // if the string doesn't have correct syntax then don't convert and return false;
    if (!hasCorrectSyntax(dance))
        return 1;
    if (hasCorrectSyntax(dance)){
        int i;
        //traverse the string
        for (i = 0; i != dance.size(); i++){
            //if you come across a slash that indicates the end of a beat, increment beat counter.
            if (dance[i] == '/')
                beatCount++;
          
            //if the index of dance string is a lower case letter append it to the instructions string
            if (islower(dance[i]))
                instructions += dance[i];
            
            // if the index is a slash and it followed by anything other than a slash then continue
            if (dance[i] =='/' && dance[i+1] != '/')
                continue;
            
            // if the slash is followed by a slash then what we have is an empty beat append a '.' to represent this
            if (dance[i] =='/' && dance[i+1] =='/')
                instructions += '.';
           
            // if the index is an uppercase letter then convert it to lower case and append
            if (isupper(dance[i]))
                instructions += tolower(dance[i]);
          
            //if the beat number is not greater than 2 then bad beat is equal to the number of that beat and return 3
            if (isdigit(dance[i]) && isalpha(dance[i+1])){
                if (dance[i] < '2'){
                    badBeat = beatCount;
                    return 3;
                }
            }

            // if a freeze is in effect and ends prematurely then return 4 and set badBeat to that beat
            if ( isdigit(dance[i]) && isalpha(dance[i+1])){
                int freezeCount = 0;
                longBeat = dance[i];
                beatDuration = longBeat - '1';
                beatDuration++;
                for (int x= dance[i+2]; x <= dance[i+(2+beatDuration)]; x++){
                    if (dance[x]=='/')
                        freezeCount++;
                    
                }
                if (beatDuration != freezeCount){
                    badBeat = beatCount;
                    return 4;
                }
                
            }
            
            // if the index is a digit and it followed by a letter then append that letter the number equal to the number of the digit
            if (isdigit(dance[i]) && isalpha(dance[i+1])){
                longBeat = dance[i];
                beatDuration = longBeat - '1';
                beatDuration++;
                for ( int x = 0; x < beatDuration; x++){
                    instructions += tolower(dance[i+1]);
                }
            }
            
        }
    }
    
    
    
    return 0;
}

int main() {
    
    string beat;
    cout << "Enter a beat" << endl;
    getline (cin, beat);
    hasCorrectSyntax(beat);
    

}
