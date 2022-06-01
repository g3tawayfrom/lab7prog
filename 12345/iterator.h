#ifndef UNTITLED_ITERATOR_H
#define UNTITLED_ITERATOR_H


#include <iterator>

using namespace std;
namespace laba {
    template<typename T>
    class OwnIterator : public iterator<input_iterator_tag, T> {
    private:
        T* p;
    public:
        explicit OwnIterator(T* p) {
            p = this->p;
        }

        OwnIterator(const OwnIterator& it) {
            p = it.p;
        }

        bool operator!=(OwnIterator const& other) const {
            return p != other.p;
        }

        bool operator==(OwnIterator const& other) const {
            return p == other.p;
        }

        T operator*() const {
            return *p;
        }

        OwnIterator& operator++() {
            ++p;
            return *this;
        }

        OwnIterator& operator--() {
            --p;
            return *this;
        }
    };
}

#endif
