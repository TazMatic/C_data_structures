CFLAGS += -Wall -Wextra -Wpedantic -Wwrite-strings -Wvla -Winline -Wfloat-equal -Wstack-usage=512

debug: CFLAGS += -g
debug: .DEFAULT

check: test/test_single_linked_list_threaded
	./$^

TESTOBJS = $(subst .c,.o,$(wildcard test/test*.c))

test/test_single_linked_list_threaded: src/single_linked_list_threaded.o
test/test_single_linked_list_threaded: $(TESTOBJS)
test/test_single_linked_list_threaded: CFLAGS += -I src -g
test/test_single_linked_list_threaded: LDFLAGS += -L src
test/test_single_linked_list_threaded: LDLIBS += -lcunit


clean:
	$(RM) src/*.o test/*.o test/test_single_linked_list_threaded