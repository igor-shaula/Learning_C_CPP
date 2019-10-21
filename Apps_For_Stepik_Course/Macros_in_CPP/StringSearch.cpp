#include <iostream>
using namespace std;

unsigned sLength(const char *s)
{
    unsigned length = 0;
    for (; *(s + length) != 0; length++) // *(s + length) is more safer because we change length but s remains the same
        ;
    return length;
}

//   if (pattern == "" || *pattern == '\0'){
//     return 0;
//   }

// int search(const char *text, const char *pattern)
// {
//     unsigned textLength = sLength(pattern);
//     if (textLength == 0)
//         return 0;
//     unsigned patternLength = sLength(text);
//     if (textLength > patternLength)
//         return -1;

//     int foundPosition = -1;
//     for (unsigned i = 0; text != text + sLength(text); text++, i++)
//         if (*text == *pattern)
//         {
//             foundPosition = i;
//             // cout << "found " << *pattern << " at position " << foundPosition << endl;
//             for (; pattern != pattern + sLength(pattern); pattern++, text++)
//                 if (*pattern != *text)
//                 {
//                     foundPosition = -1;
//                     break;
//                 }
//         }
//     return foundPosition;
// }

int search(const char *text, const char *pattern)
{
    if (pattern == "")
        return 0;
    if (sLength(pattern) == 0)
        return 0;
    if (sLength(pattern) > sLength(text))
        return -1;

    bool found = false;

    for (int count = 0; *text != '\0'; text++, count++)
        if (*text == *pattern)
        {
            for (int i = 0; pattern[i] != '\0'; i++)
            {
                if (text[i] == pattern[i])
                    found = true;
                else
                    found = false;
            }
            if (found == true)
                return count;
        }
    return -1;
}

// unsigned findFirstOccurence(const char *text, const char *pattern)
// {
//     unsigned patternLength = sLength(text);
//     unsigned textLength = sLength(pattern);
//     if (patternLength == 0 || textLength == 0)
//         return -1;

//     for (unsigned foundPosition = 0, i = 0; text <= text + patternLength; text++, i++)
//         if (*text == *pattern)
//         {
//             foundPosition = i;
//             cout << "found " << *pattern << " at position " << foundPosition << endl;
//             for (; pattern <= pattern + textLength; pattern++, text++) // we have to take every next char in text
//                 if (*pattern != *text)
//                 {
//                     foundPosition = 0;
//                     break;
//                 }
//             if (foundPosition > 0)
//                 return foundPosition;
//         }
//     return -1;
// }

void test1()
{
    (0 == search("", "")) ? cout << "OK : 1"
                                 << " (" << 0 << " : " << (0 == search("", "")) << " )" << endl
                          : cout << "Failed : 1"
                                 << " (" << 0 << " : " << (0 == search("", "")) << " )" << endl;
    (0 == search("a", "")) ? cout << "OK : 2"
                                  << " (" << 0 << " : " << (0 == search("a", "")) << " )" << endl
                           : cout << "Failed : 2"
                                  << " (" << 0 << " : " << (0 == search("a", "")) << " )" << endl;
    (0 == search("a", "a")) ? cout << "OK : 3"
                                   << " (" << 0 << " : " << (0 == search("a", "a")) << " )" << endl
                            : cout << "Failed : 3"
                                   << " (" << 0 << " : " << (0 == search("a", "a")) << " )" << endl;
    (-1 == search("a", "b")) ? cout << "OK : 4"
                                    << " (" << -1 << " : " << (-1 == search("a", "b")) << " )" << endl
                             : cout << "Failed : 4"
                                    << " (" << -1 << " : " << (-1 == search("a", "b")) << " )" << endl;
    (0 == search("aa", "")) ? cout << "OK : 5"
                                   << " (" << 0 << " : " << (0 == search("aa", "")) << " )" << endl
                            : cout << "Failed : 5"
                                   << " (" << 0 << " : " << (0 == search("aa", "")) << " )" << endl;
    (0 == search("aa", "a")) ? cout << "OK : 6"
                                    << " (" << 0 << " : " << (0 == search("aa", "a")) << " )" << endl
                             : cout << "Failed : 6"
                                    << " (" << 0 << " : " << (0 == search("aa", "a")) << " )" << endl;
    (0 == search("ab", "a")) ? cout << "OK : 7"
                                    << " (" << 0 << " : " << (0 == search("ab", "a")) << " )" << endl
                             : cout << "Failed : 7"
                                    << " (" << 0 << " : " << (0 == search("ab", "a")) << " )" << endl;
    (1 == search("ba", "a")) ? cout << "OK : 8"
                                    << " (" << 1 << " : " << (1 == search("ba", "a")) << " )" << endl
                             : cout << "Failed : 8"
                                    << " (" << 1 << " : " << (1 == search("ba", "a")) << " )" << endl;
    (-1 == search("bb", "a")) ? cout << "OK : 9"
                                     << " (" << -1 << " : " << (-1 == search("bb", "a")) << " )" << endl
                              : cout << "Failed : 9"
                                     << " (" << -1 << " : " << (-1 == search("bb", "a")) << " )" << endl;
    (0 == search("aaa", "")) ? cout << "OK : 10"
                                    << " (" << 0 << " : " << (0 == search("aaa", "")) << " )" << endl
                             : cout << "Failed : 10"
                                    << " (" << 0 << " : " << (0 == search("aaa", "")) << " )" << endl;
    (0 == search("aaa", "a")) ? cout << "OK : 11"
                                     << " (" << 0 << " : " << (0 == search("aaa", "a")) << " )" << endl
                              : cout << "Failed : 11"
                                     << " (" << 0 << " : " << (0 == search("aaa", "a")) << " )" << endl;
    (1 == search("abc", "b")) ? cout << "OK : 12"
                                     << " (" << 1 << " : " << (1 == search("abc", "b")) << " )" << endl
                              : cout << "Failed : 12"
                                     << " (" << 1 << " : " << (1 == search("abc", "b")) << " )" << endl;
    (2 == search("abc", "c")) ? cout << "OK : 13"
                                     << " (" << 2 << " : " << (2 == search("abc", "c")) << " )" << endl
                              : cout << "Failed : 13"
                                     << " (" << 2 << " : " << (2 == search("abc", "c")) << " )" << endl;
    (-1 == search("abc", "d")) ? cout << "OK : 14"
                                      << " (" << -1 << " : " << (-1 == search("abc", "d")) << " )" << endl
                               : cout << "Failed : 14"
                                      << " (" << -1 << " : " << (-1 == search("abc", "d")) << " )" << endl;
    (-1 == search("a", "aa")) ? cout << "OK : 15"
                                     << " (" << -1 << " : " << (-1 == search("a", "aa")) << " )" << endl
                              : cout << "Failed : 15"
                                     << " (" << -1 << " : " << (-1 == search("a", "aa")) << " )" << endl;
    (-1 == search("a", "ba")) ? cout << "OK : 16"
                                     << " (" << -1 << " : " << (-1 == search("a", "ba")) << " )" << endl
                              : cout << "Failed : 16"
                                     << " (" << -1 << " : " << (-1 == search("a", "ba")) << " )" << endl;
    (-1 == search("a", "ab")) ? cout << "OK : 17"
                                     << " (" << -1 << " : " << (-1 == search("a", "ab")) << " )" << endl
                              : cout << "Failed : 17"
                                     << " (" << -1 << " : " << (-1 == search("a", "ab")) << " )" << endl;
    (-1 == search("a", "bb")) ? cout << "OK : 18"
                                     << " (" << -1 << " : " << (-1 == search("a", "bb")) << " )" << endl
                              : cout << "Failed : 18"
                                     << " (" << -1 << " : " << (-1 == search("a", "bb")) << " )" << endl;
    (-1 == search("a", "aaa")) ? cout << "OK : 19"
                                      << " (" << -1 << " : " << (-1 == search("a", "aaa")) << " )" << endl
                               : cout << "Failed : 19"
                                      << " (" << -1 << " : " << (-1 == search("a", "aaa")) << " )" << endl;
    (-1 == search("aa", "aaa")) ? cout << "OK : 20"
                                       << " (" << -1 << " : " << (-1 == search("aa", "aaa")) << " )" << endl
                                : cout << "Failed : 20"
                                       << " (" << -1 << " : " << (-1 == search("aa", "aaa")) << " )" << endl;
    (0 == search("aaa", "aaa")) ? cout << "OK : 21"
                                       << " (" << 0 << " : " << (0 == search("aaa", "aaa")) << " )" << endl
                                : cout << "Failed : 21"
                                       << " (" << 0 << " : " << (0 == search("aaa", "aaa")) << " )" << endl;
    (0 == search("aaab", "aaa")) ? cout << "OK : 22"
                                        << " (" << 0 << " : " << (0 == search("aaab", "aaa")) << " )" << endl
                                 : cout << "Failed : 22"
                                        << " (" << 0 << " : " << (0 == search("aaab", "aaa")) << " )" << endl;
    (1 == search("baaa", "aaa")) ? cout << "OK : 23"
                                        << " (" << 1 << " : " << (1 == search("baaa", "aaa")) << " )" << endl
                                 : cout << "Failed : 23"
                                        << " (" << 1 << " : " << (1 == search("baaa", "aaa")) << " )" << endl;
    (1 == search("baaaa", "aaa")) ? cout << "OK : 24"
                                         << " (" << 1 << " : " << (1 == search("baaaa", "aaa")) << " )" << endl
                                  : cout << "Failed : 24"
                                         << " (" << 1 << " : " << (1 == search("baaaa", "aaa")) << " )" << endl;
    (1 == search("baaab", "aaa")) ? cout << "OK : 25"
                                         << " (" << 1 << " : " << (1 == search("baaab", "aaa")) << " )" << endl
                                  : cout << "Failed : 25"
                                         << " (" << 1 << " : " << (1 == search("baaab", "aaa")) << " )" << endl;
    (-1 == search("abd", "abc")) ? cout << "OK : 26"
                                        << " (" << -1 << " : " << (-1 == search("abd", "abc")) << " )" << endl
                                 : cout << "Failed : 26"
                                        << " (" << -1 << " : " << (-1 == search("abd", "abc")) << " )" << endl;
    (2 == search("ababc", "abc")) ? cout << "OK : 27"
                                         << " (" << 2 << " : " << (2 == search("ababc", "abc")) << " )" << endl
                                  : cout << "Failed : 27"
                                         << " (" << 2 << " : " << (2 == search("ababc", "abc")) << " )" << endl;
    (3 == search("abdabc", "abc")) ? cout << "OK : 28"
                                          << " (" << 3 << " : " << (3 == search("abdabc", "abc")) << " )" << endl
                                   : cout << "Failed : 28"
                                          << " (" << 3 << " : " << (3 == search("abdabc", "abc")) << " )" << endl;
}

void test2()
{
    struct test
    {
        int ret_value;
        const char *text;
        const char *pattern;
    };
    test tests[] = {
        {0, "", ""},           //0
        {0, "a", ""},          //1
        {0, "a", "a"},         //2
        {-1, "a", "b"},        //3
        {0, "aa", ""},         //4
        {0, "aa", "a"},        //5
        {0, "ab", "a"},        //6
        {1, "ba", "a"},        //7
        {-1, "bb", "a"},       //8
        {0, "aaa", ""},        //9
        {0, "aaa", "a"},       //10
        {1, "abc", "b"},       //11
        {2, "abc", "c"},       //12
        {-1, "abc", "d"},      //13
        {-1, "a", "aa"},       //14
        {-1, "a", "ba"},       //15
        {-1, "a", "ab"},       //16
        {-1, "a", "bb"},       //17
        {-1, "a", "aaa"},      //18
        {-1, "aa", "aaa"},     //19
        {0, "aaa", "aaa"},     //20
        {0, "aaab", "aaa"},    //21
        {1, "baaa", "aaa"},    //22
        {1, "baaaa", "aaa"},   //23
        {1, "baaab", "aaa"},   //24
        {-1, "abd", "abc"},    //25
        {2, "ababc", "abc"},   //26
        {3, "abdabc", "abc"},  //27
        {-1, "", "a"},         //28
        {2, "asasaf", "asaf"}, //29
        {2, "ababac", "abac"}  //30
    };
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i)
    {
        int ret = search(tests[i].text, tests[i].pattern);
        (tests[i].ret_value == ret) ? cout << "OK" : cout << "Failed";
        cout << " : " << i << " (" << tests[i].ret_value << " : " << ret << ")" << endl;
    }
}

struct test3struct
{
    int ret_value;
    const char *text;
    const char *pattern;
};
test3struct tests[] = {
    {0, "", ""},           //0
    {0, "a", ""},          //1
    {0, "a", "a"},         //2
    {-1, "a", "b"},        //3
    {0, "aa", ""},         //4
    {0, "aa", "a"},        //5
    {0, "ab", "a"},        //6
    {1, "ba", "a"},        //7
    {-1, "bb", "a"},       //8
    {0, "aaa", ""},        //9
    {0, "aaa", "a"},       //10
    {1, "abc", "b"},       //11
    {2, "abc", "c"},       //12
    {-1, "abc", "d"},      //13
    {-1, "a", "aa"},       //14
    {-1, "a", "ba"},       //15
    {-1, "a", "ab"},       //16
    {-1, "a", "bb"},       //17
    {-1, "a", "aaa"},      //18
    {-1, "aa", "aaa"},     //19
    {0, "aaa", "aaa"},     //20
    {0, "aaab", "aaa"},    //21
    {1, "baaa", "aaa"},    //22
    {1, "baaaa", "aaa"},   //23
    {1, "baaab", "aaa"},   //24
    {-1, "abd", "abc"},    //25
    {2, "ababc", "abc"},   //26
    {3, "abdabc", "abc"},  //27
    {-1, "", "a"},         //28
    {2, "asasaf", "asaf"}, //29
    {2, "ababac", "abac"}  //30
};
void test3()
{
    for (unsigned i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i)
    {
        int ret = search(tests[i].text, tests[i].pattern);
        (tests[i].ret_value == ret) ? cout << "OK" : cout << "Failed";
        cout << " : " << i << " (" << tests[i].ret_value << " : " << ret << ")" << endl;
    }
}

int main()
{
    // char s[] = "test string";
    char s[] = "\0";
    char t[] = "";
    // char t[] = "st";
    int foundPosition = search(s, t);
    cout << "first occurence of \"" << t << "\" found is at position: " << foundPosition << endl;
    test1();
    test2();
    test3();
    return 0;
}