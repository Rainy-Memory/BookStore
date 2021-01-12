#include <iostream>
#include "BookStore.h"

using namespace std;

#define mainProgramme
#ifdef mainProgramme
int main(){
    Administrator Libro;
    Libro.runProgramme();
}
#endif //mainProgramme

//#define testUnrolledLinkedList
#ifdef testUnrolledLinkedList
#include "UnrolledLinkedList.h"
#include <cstdlib>
#include <map>

#define TEST_SIZE 10000

fstream fs;

void initialize() {
    fs.open("test.dat", ios::out | ios::binary);
    if (!fs)cerr << "[Error] File open failed in \"initialize()\"." << endl;
    Block temp;
    fs.write(reinterpret_cast<const char *>(&temp), sizeof(Block));
    fs.close();
}

int main() {
    initialize();
    map<string, vector<int>> save;
    UnrolledLinkedList ull("test.dat");
    vector<string> test_vec;
    srand(2333);
    for (int i = 0; i < TEST_SIZE; i++) {
        int temp = rand();
        string str = to_string(temp);
        test_vec.push_back(str);
        Element temp_ele(i, test_vec[i]);
        ull.addElement(temp_ele);
        if (i % (TEST_SIZE/100) == 0) cout << i << " " << test_vec[i] << endl;
    }
    
    for (int i = 0; i < TEST_SIZE; i += 2) {
        save[test_vec[i]].push_back(i);
        if (i % (TEST_SIZE/100) == 0)cout << i << endl;
    }
    
    //ull.printList();
    
    for (int i = 1; i < TEST_SIZE; i += 2) {
        Element temp_ele(i, test_vec[i]);
        ull.deleteElement(temp_ele);
        //ull.printList();
        if (i % (TEST_SIZE/100) == 1)cout << i << endl;
    }
    
    for (int i = 0; i < TEST_SIZE; i++) {
        vector<int> res, answer = save[test_vec[i]];
        ull.findElement(test_vec[i], res);
        for (int j = 0; j < res.size(); j++) {
            if (res[j] != answer[j]) {
                cerr << "key: " << test_vec[i] << " offset: " << answer[j] << endl;
                cerr << "your offset: " << res[j] << endl;
            }
        }
        if (i % (TEST_SIZE/100) == 0)cout << i << endl;
    }
    
    return 0;
}
#endif //testUnrolledLinkedList
