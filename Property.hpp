// Copyright (c) 2020 Leevi Riitakangas
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef PROPERTY_H_
#define PROPERTY_H_

#include <functional>
#include <type_traits>

class PropertyDisable{};

template<class Get,class Set>
class Property
{
public:
    Property(std::function<Get(void)> r, std::function<void(Set)> s):rf(r),sf(s){}
    ~Property(){}

    /// Conversion operator for getting
    template<class T = Get, typename = typename std::enable_if<!std::is_same<T,PropertyDisable>::value, void>::type>
    operator Get()
    {
        return rf();
    }

    /// Parenthesis operator for getting
    template<class T = Get, typename = typename std::enable_if<!std::is_same<T,PropertyDisable>::value, void>::type>
    Get operator()()
    {
        return rf();
    }
    
    /// Getter function
    template<class T = Get, typename = typename std::enable_if<!std::is_same<T,PropertyDisable>::value, void>::type>
    Get get()
    {
        return rf();
    }

    /// Assignment operator for setting
    template<class T = Set, typename = typename std::enable_if<!std::is_same<T,PropertyDisable>::value, void>::type>
    void operator= (Set s)
    {
        sf(s);
    }

    /// Parenthesis operator for setting
    template<class T = Set, typename = typename std::enable_if<!std::is_same<T,PropertyDisable>::value, void>::type>
    void operator() (Set s)
    {
        sf(s);
    }

    /// Setter function
    template<class T = Set, typename = typename std::enable_if<!std::is_same<T,PropertyDisable>::value, void>::type>
    Set set(Set s)
    {
        sf(s);
    }

private:
    std::function<Get(void)> rf;
    std::function<void(Set)> sf;
    
};

#endif