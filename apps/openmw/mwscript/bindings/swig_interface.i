%module openmw
 %{
 /* Includes the header in the wrapper code */
 #include "extensionsbindings.hpp"
 #include "extensionsbindings0.hpp"
 %}

%ignore interpreter;
%ignore luaState;
%ignore pythonInitialized;
%ignore context;
%ignore Data;
%ignore getData;
%ignore stackReturn;
%ignore opcodesInstalled;

%include "std_string.i"


 /* Parse the header file to generate wrappers */
%include "extensionsbindings.hpp"
%include "extensionsbindings0.hpp"
%include "../../../../components/interpreter/types.hpp"

