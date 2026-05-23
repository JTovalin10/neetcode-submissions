class DynamicArray {
public:

    DynamicArray(int capacity = 1) : capacity(capacity), size(0), arr(new int[capacity]) {
        
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (this->size == this->capacity) {
            resize();
        }
        this->arr[size++] = n;
    }

    int popback() {
        int res = this->arr[this->size - 1];
        this->size--;
        return res;
    }

    void resize() {
        int newCap = capacity * 2;
        int* newArr = new int[newCap];
        // copy
        for (int i = 0; i < this->size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        this->arr = newArr;
        this->capacity = newCap;
        // free memoryalignas
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }
private:
// 24 bytes
int* arr;
size_t capacity;
size_t size;
};
