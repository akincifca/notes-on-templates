// templateVariadicTemplates.cpp

#include <iostream>

/*
 * n the example above, we have used the printSize function, which prints the number of elements (of any type) passed
 * as arguments. It detects the number of elements at compile-time using the sizeof operator, and in case of an empty
 * argument list, returns 0.

There is a struct defined as Mult which takes arguments of integer type and returns their product. If there is no argument
 passed, then it returns 1 which is the neutral element for multiplication. The result is stored in the value in the fully
 specialized template in lines 13 – 16. The partial specialization in lines 18 – 21 starts the recursion, which ends with t
 he aforementioned full specialization for 0. The primary template in line 10 is never used and must, therefore, never be defined.

To visualize the template instantiation for the above-mentioned example click here.
 https://cppinsights.io/lnk?code=I2luY2x1ZGUgPGlvc3RyZWFtPgoKdGVtcGxhdGUgPHR5cGVuYW1lLi4uIEFyZ3M+CmludCBwcmludFNpemUoQXJncy4uLiBhcmdzKXsKICByZXR1cm4gc2l6ZW9mIC4uLihhcmdzKTsKfQoKdGVtcGxhdGU8aW50IC4uLj4Kc3RydWN0IE11bHQ7Cgp0ZW1wbGF0ZTw+CnN0cnVjdCBNdWx0PD57CiAgc3RhdGljIGNvbnN0IGludCB2YWx1ZT0gMTsKfTsKCnRlbXBsYXRlPGludCBpLCBpbnQgLi4uIHRhaWw+CnN0cnVjdCBNdWx0PGksIHRhaWwgLi4uPnsKICBzdGF0aWMgY29uc3QgaW50IHZhbHVlPSBpICogTXVsdDx0YWlsIC4uLj46OnZhbHVlOwp9OwoKaW50IG1haW4oKXsKCiAgc3RkOjpjb3V0IDw8IHN0ZDo6ZW5kbDsKCiAgc3RkOjpjb3V0IDw8ICJwcmludFNpemUoKTogIiA8PCBwcmludFNpemUoKSA8PCBzdGQ6OmVuZGw7CiAgc3RkOjpjb3V0IDw8ICJwcmludFNpemUodGVtcGxhdGUsMjAxMSx0cnVlKTogIiA8PCBwcmludFNpemUoInRlbXBsYXRlIiwyMDExLHRydWUpIDw8IHN0ZDo6ZW5kbDsKICBzdGQ6OmNvdXQgPDwgInByaW50U2l6ZSgxLCAyLjUsIDQsIDUsIDEwKTogIiA8PCAgcHJpbnRTaXplKDEsIDIuNSwgNCwgNSwgMTApIDw8IHN0ZDo6ZW5kbDsKCiAgc3RkOjpjb3V0IDw8IHN0ZDo6ZW5kbDsKCiAgc3RkOjpjb3V0IDw8ICJNdWx0PDEwPjo6dmFsdWU6ICIgPDwgTXVsdDwxMD46OnZhbHVlIDw8IHN0ZDo6ZW5kbDsKICBzdGQ6OmNvdXQgPDwgIk11bHQ8MTAsMTAsMTA+Ojp2YWx1ZTogIiA8PCBNdWx0PDEwLDEwLDEwPjo6dmFsdWUgPDwgc3RkOjplbmRsOwogIHN0ZDo6Y291dCA8PCAiTXVsdDwxLDIsMyw0LDU+Ojp2YWx1ZTogIiA8PCBNdWx0PDEsMiwzLDQsNT46OnZhbHVlIDw8IHN0ZDo6ZW5kbDsKCiAgc3RkOjpjb3V0IDw8IHN0ZDo6ZW5kbDsKCn0K&insightsOptions=cpp17&std=cpp17&rev=1.0
 */

template <typename... Args>
int printSize(Args... args){
    return sizeof ...(args);
}

template<int ...>
struct Mult;

template<>
struct Mult<>{
    static const int value= 1;
};

template<int i, int ... tail>
struct Mult<i, tail ...>{
    static const int value= i * Mult<tail ...>::value;
};

int main(){

    std::cout << std::endl;

    std::cout << "printSize(): " << printSize() << std::endl;
    std::cout << "printSize(template,2011,true): " << printSize("template",2011,true) << std::endl;
    std::cout << "printSize(1, 2.5, 4, 5, 10): " <<  printSize(1, 2.5, 4, 5, 10) << std::endl;

    std::cout << std::endl;

    std::cout << "Mult<10>::value: " << Mult<10>::value << std::endl;
    std::cout << "Mult<10,10,10>::value: " << Mult<10,10,10>::value << std::endl;
    std::cout << "Mult<1,2,3,4,5>::value: " << Mult<1,2,3,4,5>::value << std::endl;

    std::cout << std::endl;

}
