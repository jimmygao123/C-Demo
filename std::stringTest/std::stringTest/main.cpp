//
//  main.cpp
//  std::stringTest
//
//  Created by jimmygao on 3/11/16.
//  Copyright (c) 2016 jimmygao. All rights reserved.
//

#include <iostream>
#include <string>
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::string str ("There are two needles in this haystack with needles.");
    std::string str2 ("needle");
    
    // different member versions of find in the same order as above:
    std::size_t found = str.find(str2);
    if (found!=std::string::npos)
        std::cout << "first 'needle' found at: " << found << '\n';
    
    found=str.find("needles are small",found+1,6);
    if (found!=std::string::npos)
        std::cout << "second 'needle' found at: " << found << '\n';

    
    str.replace(str.find(str2),str2.length(),"preposition");
    std::cout << str << '\n';
    
    return 0;
}
