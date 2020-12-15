  
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "list_array.h"

static list_array *list;

void
listSetup(void)
{
    list = list_array_create();
}

void
listTeardown(void)
{
    list_array_destroy(list);
}

void
testSizeEmpty(void)
{
    CU_ASSERT_EQUAL(list_array_size(list), 0);
}
void
testAppendOne(void)
{
    list_array_append(list, 1);
    CU_ASSERT_EQUAL(list_array_size(list), 1);
}
void
testPrependOne(void)
{
    list_array_prepend(list, 1);
    CU_ASSERT_EQUAL(list_array_size(list), 1);
}
void
testAddAfterIndexOne(void)
{
    list_array_prepend(list, 1);
    list_array_append(list, 2);
    list_array_append(list, 3);
    list_array_insertAfterIndex(list, 4, 1);
    CU_ASSERT_EQUAL(list_array_size(list), 4);
}
void
testFetch(void)
{
    list_array_append(list, 1);
    list_array_append(list, 2);
    CU_ASSERT_EQUAL(*list_array_fetch(list, 0), 1);
    CU_ASSERT_EQUAL(*list_array_fetch(list, 1), 2);
}

static CU_TestInfo listTests[] = {
    // Name, functionThatRunsTest
    { "List.size([])", testSizeEmpty },
    { "test.append([])", testAppendOne},
    { "test.prepend([])", testPrependOne},
    { "test.insertAfterIndex([])", testAddAfterIndexOne},
    { "test.fetch([])", testFetch},
    CU_TEST_INFO_NULL
};

CU_SuiteInfo listSuite = {
    "List tests",
    NULL,
    NULL,
    listSetup,
    listTeardown,
    listTests
};

int
main(void)
{
    extern CU_SuiteInfo listSuite;

    CU_SuiteInfo suites[] = {
        // Name, suiteSetup, suiteTeardown, testSetup, testTeardown, arrayOfTests
        listSuite,
        CU_SUITE_INFO_NULL
    };

    CU_initialize_registry();

    // Add all suites listed to registry
    CU_register_suites(suites);

    CU_basic_run_tests();

    CU_cleanup_registry();
}
