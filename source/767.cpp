//
//  main.cpp
//  CardShuffle767
//
//  Created by Chyanna Tsang on 30/11/2021.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {

    int testCase;
    cin >> testCase;
    for (int i=0; i<testCase;i++){
        int numOfInstructions;
        cin >> numOfInstructions;
        vector<int>pile;
        for (int i =0; i < numOfInstructions; i++){
            string i1,i2;
            int num;
            cin >> i1;
            if (i1=="I"){
                cin >> i2;
                if (i2=="H"){
                    cin >> num;
                    pile.insert(pile.begin(), num);
                } else{
                    cin >> num;
                    pile.insert(pile.end(), num);
                }
            } else if (i1=="R"){
                cin >> i2;
                if (i2=="H"){
                    pile.erase(pile.begin());
                }else{
                    pile.pop_back();
                }
            }else{
                cin >> num;
                cout << pile.at(num-1)<<endl;
                    }
                }
            }
    return 0;
        }
       

        
    
    

