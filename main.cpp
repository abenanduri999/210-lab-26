//COMSC 210 | LAB 26 | Abhishek Nanduri
#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;
using namespace std::chrono; 

const int CODES_SIZE = 20000; 

int main() {
    
    //READINGS
    int vrtotal = 0, lrtotal = 0, srtotal = 0, 
        vstotal = 0, lstotal = 0,
        vitotal = 0, litotal = 0, sitotal = 0,
        vdtotal = 0, ldtotal = 0, sdtotal = 0;


     for(int i = 0; i < 15; i++) 
     {

    auto startvr = high_resolution_clock::now(); 
    vector<string> v1; 
    ifstream input("codes.txt");
    string linev; 
    int cv = 0; 
    while(getline(input, linev))
    {
        v1.push_back(linev);
        cv++; 
    }
    input.close(); 
    auto endvr = high_resolution_clock::now(); 
    auto durationvr = duration_cast<microseconds>(endvr - startvr); 
    vrtotal = vrtotal + durationvr.count();

    auto startlr = high_resolution_clock::now(); 
    list<string> l1;
    ifstream inputl("codes.txt"); 
    string linel;
    int count = 0;
    while(getline(inputl, linel))
    {
        l1.push_back(linel);
        count++;
    }
    inputl.close();
    auto endlr = high_resolution_clock::now(); 
    auto durationlr = duration_cast<microseconds>(endlr - startlr);
    lrtotal = lrtotal + durationlr.count();
     
    auto startsr = high_resolution_clock::now(); 
    set<string> s1; 
    ifstream inputs("codes.txt");
    string lines;
    int cs= 0; 
    while(getline(inputs, lines))
    {
        s1.insert(lines);
        cs++;
    }
    inputs.close(); 
    auto endsr = high_resolution_clock::now();
    auto durationsr = duration_cast<microseconds>(endsr - startsr); 
    srtotal = srtotal + durationsr.count();

    
    
    // SORTINGS

    auto startvs = high_resolution_clock::now(); 
    sort(v1.begin(), v1.end()); 
    auto endvs = high_resolution_clock::now(); 
    auto durationvs = duration_cast<milliseconds>(endvs - startvs); 
    vstotal = vstotal + durationvs.count();

    auto startls = high_resolution_clock::now(); 
    l1.sort();
    auto endls = high_resolution_clock::now(); 
    auto durationls = duration_cast<microseconds>(endls - startls); 
    lstotal = lstotal + durationls.count();
    
    
    //INSERTIONS
    
    auto startvi = high_resolution_clock::now(); 
    int middle = v1.size() / 2; 
    v1.insert(v1.begin(), middle, "TESTCODE"); 
    auto endvi = high_resolution_clock::now(); 
    auto durationvi = duration_cast<microseconds>(endvi - startvi); 
    vitotal = vitotal + durationvi.count();

    auto startli = high_resolution_clock::now();  
    int mid_of_list = l1.size() / 2; 
    auto it = l1.begin(); 
    advance(it, mid_of_list);
    l1.insert(it, "TESTCODE");
    auto endli = high_resolution_clock::now(); 
    auto durationli = duration_cast<microseconds>(endli - startli); 
    litotal = litotal + durationli.count();

    auto startsi = high_resolution_clock::now(); 
    int mid_of_set = s1.size() / 2; 
    auto it_s = s1.begin();
    advance(it_s, mid_of_set);
    s1.insert (it_s, "TESTCODE"); // assignment just said insert into the set 
    auto endsi = high_resolution_clock::now(); 
    auto durationsi = duration_cast<microseconds>(endsi - startsi); 
    sitotal = sitotal + durationsi.count();


    
    // DELETIONS

     auto startvd = high_resolution_clock::now(); 
     v1.erase(v1.begin() + 10000); 
     auto endvd = high_resolution_clock::now();
     auto durationvd = duration_cast<microseconds>(endvd - startvd); 
     vdtotal = vdtotal + durationvd.count();

     auto startld = high_resolution_clock::now();
     auto l_it = l1.begin();
     advance(l_it, mid_of_list); 
     l1.erase(l_it);
     auto endld = high_resolution_clock::now();
     auto durationld = duration_cast<microseconds>(endld - startld);
     ldtotal = ldtotal + durationld.count();

     auto startsd = high_resolution_clock::now();
     auto s_it = s1.begin();
     advance(s_it, mid_of_set); 
     s1.erase(s_it);
     auto endsd = high_resolution_clock::now();
     auto durationsd = duration_cast<microseconds>(endsd - startsd);  
     sdtotal = sdtotal + durationsd.count();
    
     }
    
    cout<<setw(10)<<right<<"Operation"<<setw(10)<<right<<"Vector"<<setw(10)<<right<<"List"<<
    setw(10)<<right<<"Delete"<<endl; 
    
    cout<<setw(10)<<right<<"Read"<<setw(10)<<right<<vrtotal/15<<setw(10)<<right<<lrtotal/15
    <<setw(10)<<right<<srtotal/15<<endl; 
    
    cout<<setw(10)<<right<<"Sort"<<setw(10)<<right<<vstotal/15<<setw(10)<<right<<lstotal/15
    <<setw(10)<<right<<"-1"<<endl;
    
    cout<<setw(10)<<right<<"Insert"<<setw(10)<<right<<vitotal/15<<setw(10)<<right<<litotal/15
    <<setw(10)<<right<<sitotal/15<<endl; 

    cout<<setw(10)<<right<<"Set"<<setw(10)<<right<<vdtotal/15<<setw(10)<<right<<setw(10)
    <<right<<ldtotal/15<<setw(10)<<right<<sdtotal/15<<endl;



    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/