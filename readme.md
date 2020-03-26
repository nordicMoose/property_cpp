Property system for c++
===

Simple system to achieve c# like property behaviour using lambdas.

### Info:
- For examples see test.cpp
- To make a property read-only or write-only, the corresponding template argument must be PropertyDisable
- Get and set types don't necessarily have to be the same.
- With a property you can get:
    - Conversion operator
    - Assignment operator
    - Overloaded parenthesis operator
    - Get function
    - Set function
- Requires c++11