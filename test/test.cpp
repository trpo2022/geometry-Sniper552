#include <ctest.h>
#include <libmain/check.h>

CTEST(suite, test1_true)
{
    int result = ProcessGeomFile("test/testfile/test1.txt");

    ASSERT_FALSE(result);
}

CTEST(suite, test2_true)
{
    int result = ProcessGeomFile("test/testfile/test2.txt");

    ASSERT_FALSE(result);
}

CTEST(suite, test3_true)
{
    int result = ProcessGeomFile("test/testfile/test3.txt");

    ASSERT_FALSE(result);
}

CTEST(suite, test4_true)
{
    int result = ProcessGeomFile("test/testfile/test4.txt");

    ASSERT_FALSE(result);
}
