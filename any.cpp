#include <boost/lexical_cast.hpp>
#include <boost/any.hpp>
#include <boost/foreach.hpp>
#include <iostream>
#include <string>
#include <vector>

using boost::any_cast;
using namespace std;
typedef std::vector<boost::any> many;


int main() {
    many values;

    values.push_back(10);
    values.push_back(string("hello"));

    cout << any_cast<int>(values[0]) << endl;
    cout << any_cast<string>(values[1]) << endl;

    return 0;
}
