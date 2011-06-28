#include <boost/program_options/value_semantic.hpp>
#include <boost/any.hpp>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
using namespace boost::program_options;
using boost::any_cast;


void parse_value(value_semantic &vs, string value) {
    vector<string> v;
    v.push_back(value);

    boost::any temp;
    vs.parse(temp, v, true);
    vs.notify(temp);
}

int main() {
    int a1;
    string a2;
    value_semantic *v1 = new typed_value<int>(&a1);
    value_semantic *v2 = new typed_value<string>(&a2);

    parse_value(*v1, "1010");
    parse_value(*v2, "hello");

    cout << a1 << endl;
    cout << a2 << endl;

    return 0;
}
