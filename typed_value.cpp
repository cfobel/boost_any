#include <boost/program_options/value_semantic.hpp>
#include <boost/any.hpp>
#include <boost/foreach.hpp>
#include <boost/assign/list_of.hpp>       // for 'list_of()' and 'ref_list_of()'
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
using namespace boost::program_options;
using namespace boost::assign;
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
    double a3;
    typedef map<string, value_semantic*> attr_definition_t;
    typedef map<string, string> attr_list_t;

    attr_definition_t test = list_of< pair<string, value_semantic*> >
        ("my_int", new typed_value<int>(&a1))
        ("my_double", new typed_value<double>(&a3))
        ("my_string", new typed_value<string>(&a2));

    attr_list_t values = list_of< pair<string, string> >
        ("my_int", "1010")
        ("my_double", "10.1214")
        ("my_string", "hello world");

    BOOST_FOREACH(attr_list_t::value_type &item, values) {
        parse_value(*test[item.first], item.second);
    }

    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl;

    return 0;
}
