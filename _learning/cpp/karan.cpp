#include <iostream>
#include <cstring>
unsing namespace std;

struct karan_list {
    char* name;
    int price;
    karan_list* pointer_to_itself;
} banana;

class karan_class {
    karan_list*;
    public:
}

//karan_list banana; //same thing as line 9 "banana"

int main(int argc, char *argv[]) {
    //karan_list banana; //same thing as line 9 "banana" BUT scoped on main
    cout << "Hello, World!";
    return 0;
}