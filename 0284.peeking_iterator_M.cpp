/**
 * https://leetcode.com/problems/peeking-iterator/description/
 * 2015/10
 * 4 ms
 */

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    bool has_next;
    int current_element;
    int next_element;
    void updateElements()
    {
        if(has_next = Iterator::hasNext())
        {
            current_element = next_element;
            next_element = Iterator::next();
        }
        else
            current_element = next_element;
    }
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    next_element = 42;
	    updateElements();
	}
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return next_element;
	}
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    updateElements();
	    return current_element;
	}
	bool hasNext() const {
	    return has_next;
	}
};
