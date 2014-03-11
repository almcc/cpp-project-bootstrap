%module Library
%{
    #define SWIG_FILE_WITH_INIT
    #include "../common/App/Python/Interface.h"

%}

%include <typemaps.i>
%include <std_deque.i>
%include <std_list.i>
%include <std_map.i>
%include <std_pair.i>
%include <std_set.i>
%include <std_string.i>
%include <std_vector.i>

// Instantiate templates used by example
namespace std {
   %template(IntVector) vector<int>;
   %template(StringVector) vector<string>;
   %template(DoubleVector) vector<double>;
}

%include "../common/App/Python/Interface.h"