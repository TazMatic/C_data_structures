CFLAGS += -Wall -Wextra -Wpedantic -Wwrite-strings -Wvla -Winline -Wfloat-equal -Wstack-usage=512

debug: CFLAGS += -g
debug: .DEFAULT

check: test/test_list_array
	./$^

TESTOBJS = $(subst .c,.o,$(wildcard test/test*.c))

test/test_list_array: src/list_array.o
test/test_list_array: $(TESTOBJS)
test/test_list_array: CFLAGS += -I src -g
test/test_list_array: LDFLAGS += -L src
test/test_list_array: LDLIBS += -lcunit


clean:
	$(RM) src/*.o test/*.o test/test_list_array