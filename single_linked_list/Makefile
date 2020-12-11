CFLAGS += -Wall -Wextra -Wpedantic -Wwrite-strings -Wvla -Winline -Wfloat-equal -Wstack-usage=512

debug: CFLAGS += -g
debug: .DEFAULT

check: test/test_single_linked_list
	./$^

TESTOBJS = $(subst .c,.o,$(wildcard test/test*.c))

test/test_single_linked_list: src/single_linked_list.o
test/test_single_linked_list: $(TESTOBJS)
test/test_single_linked_list: CFLAGS += -I src -g
test/test_single_linked_list: LDFLAGS += -L src
test/test_single_linked_list: LDLIBS += -lcunit


clean:
	$(RM) src/*.o test/*.o test/test_single_linked_list