  
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "single_linked_list.h"

static single_linked_list *list;

void
listSetup(void)
{
    list = single_linked_list_create();
}

void
listTeardown(void)
{
    single_linked_list_destroy(list);
}

void
testSizeEmpty(void)
{
    CU_ASSERT_EQUAL(single_linked_list_size(list), 0);
}
void
testAppendOne(void)
{
    single_linked_list_append(list, 1);
    CU_ASSERT_EQUAL(single_linked_list_size(list), 1);
}
void
testPrependOne(void)
{
    single_linked_list_prepend(list, 1);
    CU_ASSERT_EQUAL(single_linked_list_size(list), 1);
}
void
testAddAfterIndexOne(void)
{
    single_linked_list_prepend(list, 1);
    single_linked_list_append(list, 2);
    single_linked_list_append(list, 3);
    single_linked_list_insertAfterIndex(list, 4, 1);
    CU_ASSERT_EQUAL(single_linked_list_size(list), 4);
}
void
testFetch(void)
{
    single_linked_list_append(list, 1);
    single_linked_list_append(list, 2);
    CU_ASSERT_EQUAL(*single_linked_list_fetch(list, 0), 1);
    CU_ASSERT_EQUAL(*single_linked_list_fetch(list, 1), 2);
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
