/*
#[[

this is a template to generate a c config file
note the output has proper \#define statement  as well as these comment
 documentating how to use cmakedefine commands in i any file template
all lines cmakedefine VAR ...

will be replaced with either:

#define VAR ...

or:

#undef VAR within comments

depending on whether VAR is set in CMake to any value not considered a false constant by the if() command. The “…” content on the line after the variable name, if any, is processed as above. Input file lines of the form #cmakedefine01 VAR will be replaced with either #define VAR 1 or #define VAR 0 similarly. The result lines (with the exception of the #undef comments) can be indented using spaces and/or tabs between the # character and the cmakedefine or cmakedefine01 words. This whitespace indentation will be preserved in the output lines:

  cmakedefine VAR
  cmakedefine01 VAR

//will be replaced, if VAR is defined, with:

#  define VAR
#  define VAR 1
//end of ducomentation
]]
*/
#ifndef CONFIG_H__
#define CONFIG_H__ 1

#cmakedefine WITH_GUI 1
#cmakedefine DATA_DIR "${DATA_DIR}"
#cmakedefine X11_FOUND 1

#endif
