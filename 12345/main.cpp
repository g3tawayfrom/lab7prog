#include <iostream>
using namespace std;
#include "RingBuffer.h"

int main() {
    int capacity = 10;
    laba::RingBuffer<int> buffer(capacity);
    laba::OwnIterator<int> iterator = buffer.getIterator();
    int input = 0;
    while (input != -1) {
        cin >> input;
        buffer.insert_tail(input);
        buffer.print();
    }
    return 0;
}