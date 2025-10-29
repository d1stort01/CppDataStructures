#include <stack>
#include <string>
using namespace std;

class Express
{
public:
    Express(string str) {
        exp = str;
        post_exp = "";
    }
    string get_post_exp() {
        return post_exp;
    }
    void Trans();
    double GetValue();
    bool isValid();

private:
    string exp;
    string post_exp;
};
