#include <boost/program_options.hpp>
#include <boost/any.hpp>
#include <boost/shared_ptr.hpp>
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
using namespace boost::program_options;

namespace boost { namespace program_options {
    template<class charT>
    basic_parsed_options<charT>
    parse_xml(const options_description& desc) {
        using boost::shared_ptr;
        set<string> allowed_options;

        const vector<shared_ptr<option_description> >& options = desc.options();
        for (unsigned i = 0; i < options.size(); ++i) {
            const option_description& d = *options[i];

            if (d.long_name().empty())
                boost::throw_exception(
                    error("long name required for config file"));

            allowed_options.insert(d.long_name());
        }

        // Parser return char strings
        parsed_options result(&desc);
        result.options.push_back(basic_option<charT>("my_double", vector<string>(1, "10.1214")));
        //result.options.push_back(basic_option<charT>("my_string", vector<string>(1, "hello world")));
        return basic_parsed_options<charT>(result);
    }

}}


int main() {
    int a1;
    string a2;
    double a3;
    typedef map<string, value_semantic*> attr_definition_t;
    typedef map<string, string> attr_list_t;

    options_description test;
    test.add_options()
        ("my_int", value<int>(&a1)->default_value(100))
        ("my_double", value<double>(&a3)->default_value(10.5))
        ("my_string", value<string>(&a2)->default_value("Goodbye cruel world!"));
    variables_map vm;
    store(parse_xml<char>(test), vm);
    notify(vm);

    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl;

    return 0;
}
