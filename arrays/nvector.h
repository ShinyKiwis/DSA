#ifndef N_VECTOR_H
#define N_VECTOR_H

// SK: Shiny Kiwis
namespace SK {
class NVector {
   public:
    NVector(int capacity);
    NVector(const NVector& other) = default;
    ~NVector();
    int getSize() const;
    bool isEmpty() const;
    int at(int index) const;
    void push(int item);
    void insert(int item, int index);
    void prepend(int item);
    int pop();
    void deleteItem(int index);
    void remove(int item);
    int find(int item) const;

   private:
    int capacity = 2;
    const int kGrowthFactor = 2;
    const int KShrinkFactor = 4;
    int size = 0;
    int* arr;
    void resize(int candidateSize);
    void decrease();
    void increase();
};
}  // namespace SK

#endif  // !N_VECTOR_H
