#include "Express.hpp"
#include <iostream>
using namespace std;

int main() {
    string str = "(56-20)/(4+2)";
    Express obj(str);
    cout << "in: " << str << endl;
    cout << (obj.isValid() ? "valid" : "invalid") << endl;
    obj.Trans();
    cout << "post: " << obj.get_post_exp() << endl;
    cout << "value: " << obj.GetValue() << endl;
    cout << endl;
    string str2 = "(56-20/(4+2)";
    Express obj2(str2);
    cout << "in: " << str2 << endl;
    cout << (obj2.isValid() ? "valid" : "invalid") << endl;
    obj2.Trans();
    cout << "post: " << obj2.get_post_exp() << endl;
    cout << "value: " << obj2.GetValue() << endl;
    return 0;
}