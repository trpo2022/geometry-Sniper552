#include <ctest.h>
#include <libmain/check.h>

CTEST(suite, test1_true)
{
    char filename[] = "test/testfile/test1.txt";
    int result = circles(filename);

    ASSERT_FALSE(result);
}

CTEST(suite, test2_true)
{
    int result = circles("test/testfile/test2.txt");

    ASSERT_FALSE(result);
}

CTEST(suite, test3_true)
{
    int result = circles("test/testfile/test3.txt");

    ASSERT_FALSE(result);
}

CTEST(suite, test4_true)
{
    int result = circles("test/testfile/test4.txt");

    ASSERT_FALSE(result);
}
