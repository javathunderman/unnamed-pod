#include "commands.h"
#include <assert.h>

#define SIZE 10

void test_init(CommandBuffer *cb, volatile int *buff, int size);
void test_empty_read(CommandBuffer *cb);
void test_write_read(CommandBuffer *cb);
void test_circular(CommandBuffer *cb);
void test_estop(CommandBuffer *cb);


int main(void) {
    volatile int buff[SIZE];
    CommandBuffer cb;
    
    test_init(&cb, buff, SIZE);
    test_empty_read(&cb);
    
    test_write_read(&cb);
    test_empty_read(&cb);
    
    test_circular(&cb);
    test_empty_read(&cb);
    
    test_estop(&cb);
    test_empty_read(&cb);
}

void test_init(CommandBuffer *cb, volatile int *buff, int size) {
    assert(init_cmd_buffer(cb, buff, size) == 0);
}

void test_empty_read(CommandBuffer *cb) {
    int cmd = 1;
    assert(read_cmd(cb, &cmd) == 0);
    assert(cmd == 0);
}

void test_write_read(CommandBuffer *cb) {
    int cmd = 5;
    assert(write_cmd(cb, cmd) == 0);
    
    cmd = 0;
    assert(read_cmd(cb, &cmd) == 0);
    assert(cmd == 5);
}

void test_circular(CommandBuffer *cb) {
    int i, j, cmd;
    
    /* Write 1, Read 1 */
    for (i = 1; i < 100; i++) {
        assert(write_cmd(cb, i) == 0);
        assert(read_cmd(cb, &cmd) == 0);
        assert(cmd == i);
    }
    
    /* Write 3, Read 3 */
    for (i = 1; i < 100; i++) {
        for (j = i; j < i+3; j++) {
            assert(write_cmd(cb, j) == 0);
        }
        for (j = i; j < i+3; j++) {
            assert(read_cmd(cb, &cmd) == 0);
            assert(cmd == j);
        }
    }
}

void test_estop(CommandBuffer *cb) {
    int cmd = 0;
    /* Write 5 then ESTOP */
    assert(write_cmd(cb, 5) == 0);
    assert(write_cmd(cb, ESTOP) == 0);
    
    /* Should read ESTOP until ack */
    assert(read_cmd(cb, &cmd) == 0);
    assert(cmd == ESTOP);
    
    cmd = 0;
    assert(read_cmd(cb, &cmd) == 0);
    assert(cmd == ESTOP);
    
    /* Should read 5 after ack */
    ack_estop(cb);
    assert(read_cmd(cb, &cmd) == 0);
    assert(cmd == 5);
}

