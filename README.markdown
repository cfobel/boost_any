# Boost.Any #

Generic type (see [Boost docs](http://www.boost.org/doc/libs/1_46_1/doc/html/any.html))

## `any.cpp` ##

Basic example showing the use of a `vector` containing instances of 
`boost::any`, along with the use of `any_cast` to cast `any` instances to
source types.


## `typed_value.cpp` ##

Example using `boost::program_options::value_semantic` to store values which
can parse a string to the stored value type.
