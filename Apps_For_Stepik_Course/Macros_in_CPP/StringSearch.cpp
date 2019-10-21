#include <iostream>
using namespace std;

unsigned sLength(const char *s)
{
    unsigned length = 0;
    for (; *s != 0; s++, length++)
        ;
    return length;
}

int search(char *where, char *what)
{
    int foundPosition = -1;
    for (unsigned i = 0; where != where + sLength(where); where++, i++)
        if (*where == *what)
        {
            foundPosition = i;
            // cout << "found " << *what << " at position " << foundPosition << endl;
            for (; what != what + sLength(what); what++, where++)
                if (*what != *where)
                {
                    foundPosition = -1;
                    break;
                }
        }
    return foundPosition;
}

// unsigned findFirstOccurence(const char *where, const char *what)
// {
//     unsigned whereLength = sLength(where);
//     unsigned whatLength = sLength(what);
//     if (whereLength == 0 || whatLength == 0)
//         return -1;

//     for (unsigned foundPosition = 0, i = 0; where <= where + whereLength; where++, i++)
//         if (*where == *what)
//         {
//             foundPosition = i;
//             cout << "found " << *what << " at position " << foundPosition << endl;
//             for (; what <= what + whatLength; what++, where++) // we have to take every next char in where
//                 if (*what != *where)
//                 {
//                     foundPosition = 0;
//                     break;
//                 }
//             if (foundPosition > 0)
//                 return foundPosition;
//         }
//     return -1;
// }

// void launchTests()
// {
//     struct test
//     {
//         int ret_value;
//         const char *text;
//         const char *pattern;
//     };
//     test tests[] = {
//         {0, "", ""},           //0
//         {0, "a", ""},          //1
//         {0, "a", "a"},         //2
//         {-1, "a", "b"},        //3
//         {0, "aa", ""},         //4
//         {0, "aa", "a"},        //5
//         {0, "ab", "a"},        //6
//         {1, "ba", "a"},        //7
//         {-1, "bb", "a"},       //8
//         {0, "aaa", ""},        //9
//         {0, "aaa", "a"},       //10
//         {1, "abc", "b"},       //11
//         {2, "abc", "c"},       //12
//         {-1, "abc", "d"},      //13
//         {-1, "a", "aa"},       //14
//         {-1, "a", "ba"},       //15
//         {-1, "a", "ab"},       //16
//         {-1, "a", "bb"},       //17
//         {-1, "a", "aaa"},      //18
//         {-1, "aa", "aaa"},     //19
//         {0, "aaa", "aaa"},     //20
//         {0, "aaab", "aaa"},    //21
//         {1, "baaa", "aaa"},    //22
//         {1, "baaaa", "aaa"},   //23
//         {1, "baaab", "aaa"},   //24
//         {-1, "abd", "abc"},    //25
//         {2, "ababc", "abc"},   //26
//         {3, "abdabc", "abc"},  //27
//         {-1, "", "a"},         //28
//         {2, "asasaf", "asaf"}, //29
//         {2, "ababac", "abac"}  //30
//     };
//     for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i)
//     {
//         int ret = search(tests[i].text, tests[i].pattern);
//         (tests[i].ret_value == ret) ? cout << "OK" : cout << "Failed";
//         cout << " : " << i << " (" << tests[i].ret_value << " : " << ret << ")" << endl;
//     }
// }

int main()
{
    // cout << "enter a string:" << endl;
    // cin >> ???
    char s[] = "test string";
    char t[] = "st";
    int foundPosition = search(s, t);
    cout << "first occurence of \"" << t << "\" found is at position: " << foundPosition << endl;
    // launchTests();
    return 0;
}