#include <iostream>  
#include <map>  
using namespace std; 

int main(void){
    map<string, double> map; 
    std::map<std::string, double>::iterator itr; 
    double sum = 0;

    map.insert(pair<string, double>("Brazil", 75.45));
    map.insert(pair<string, double>("Germany", 80.99));
    map.insert(pair<string, double>("Switzerland", 83.60));
    map.insert(pair<string, double>("Argentina", 76.37));
    map.insert(pair<string, double>("Italy", 83.24));

    if(map.empty())
        cout << "Empty map...";

    else{
        for(itr = map.begin(); itr != map.end(); ++itr) { 
            cout << itr->first << " - " << itr->second << endl;
            sum += itr->second;
        }

        cout << "Size of the map is " << map.size() << endl;
        cout << "Average life expectancy is " << sum / map.size() << endl;
    }

    cout << endl << "Removing South America countries..."  << endl;
    map.erase("Brazil");
    map.erase("Argentina");

    if(map.empty())
        cout << "Empty map...";

    else{
        sum = 0;
        for(itr = map.begin(); itr != map.end(); ++itr){
            cout << itr->first << " - " << itr->second << endl;
            sum += itr->second;
        }

        cout << "Size of the map is " << map.size() << endl;
        cout << "Europe average life expectancy is " << sum / map.size() << endl;
    }

    itr = map.find("Switzerland");
    if(itr != map.end())
        cout << endl << itr->first << " life expectancy is " << itr->second << endl;

    else
        cout << endl << "Key not found..." << endl;

    return 0;
}  
