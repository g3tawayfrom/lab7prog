#ifndef LABA7PROG_RINGEDBUFFER_H
#define LABA7PROG_RINGEDBUFFER_H

#include <cmath>
#include "iterator.h"

namespace laba {
    template<class T>
    class RingBuffer {
    private:
        OwnIterator<T> currentIterator = generateIterator();
        int capacity = 5;
        T* head;
        T* tail;
        T* array;
        T* anchor_tail, * anchor_head;
        OwnIterator<T> generateIterator() {
            OwnIterator<T> iterator(this->array);
            return iterator;
        }

    public:
        explicit RingBuffer(int capacity) {
            setCapacity(capacity);
            OwnIterator<T> iterator(this->array);
            this->currentIterator = iterator;
        }

        OwnIterator<T> getIterator() {
            return this->currentIterator;
        }

        int insert_head(T element) {
            *head = element;
            head--;
            if (head == anchor_head)
                head = anchor_tail;
            return 0;
        }

        int insert_tail(T element) {
            *tail = element;
            tail++;
            if (tail == anchor_tail)
                tail = anchor_head;
            return 0;
        }

        int insert(T element) {
            *currentIterator = element;
            return 0;
        }

        T get_head() {
            T returnValue = *(head);
            return returnValue;
        }

        T get_tail() {
            T returnValue = *(tail);
            return returnValue;
        }

        T get() {
            return *(currentIterator);
        }

        int setCapacity(int newCapacity) {
            T* newArray = new T[newCapacity];
            for (int i = 0; i < capacity; i++) {
                *(newArray + i) = *(this->array);
            }
            for (int i = capacity; i < newCapacity; i++) {
                *(newArray + i) = static_cast<int>(NAN);
            }
            array = newArray;
            capacity = newCapacity;
            OwnIterator<T> iIterator(newArray);
            tail = array;
            head = array;
            anchor_head = array;
            anchor_tail = array + capacity;
            return 0;
        }

        int remove_head() {
            if (head == anchor_tail)
                head = anchor_head;
            else
                head++;
            *head = static_cast<int>(NAN);
            return 0;
        }

        int remove_tail() {
            if (tail == anchor_head)
                tail = anchor_tail;
            else
                tail--;
            *tail = static_cast<int>(NAN);
            return 0;
        }

        int remove() {
            *(this->currentIterator) = static_cast<int>(NAN);
            return 0;
        }

        void print() {
            T* iter = this->array;
            for (int i = 0; i < this->capacity; i++) {
                std::cout << *iter << " ";
                iter++;
            }
            cout << endl;
        }
    };
}
#endif
