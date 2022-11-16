#include "nvector.h"
#include <iostream>

namespace SK {
NVector::NVector(int capacity) {
  if (capacity < 1) {
    std::cout << "The capacity must be greater than 0" << std::endl;
  }
  this->capacity = capacity;
  arr = new int[capacity];
}

NVector::~NVector() { delete[] arr; }
int NVector::getSize() const { return size; }
bool NVector::isEmpty() const { return size == 0; }
int NVector::at(int index) const {
  if (index < 0 || index > size) {
    std::cout << "ERROR: Index Out Of Bound" << std::endl;
    return -1;
  }
  return arr[index];
}

int NVector::find(int item) const {
  int foundIndex = -1;
  for (int i = 0; i < size; i++) {
    if (arr[i] == item) {
      foundIndex = i;
      break;
    }
  }
  return foundIndex;
}

void NVector::push(int item) {
  resize(size+1);
  arr[size] = item;
  size++;
}

void NVector::insert(int item, int index) {
  if (index < 0 || index > size) {
    std::cout << "ERROR: Index Out Of Bound" << std::endl;
  }
  // Traverse to the item
  resize(size+1);
  for (int i = size; i > index; i--) {
    arr[i] = arr[i - 1];
  }
  arr[index] = item;
  size++;
}

void NVector::prepend(int item) { insert(0, item); }

int NVector::pop() {
  if (size == 0) {
    std::cout << "Nothing to pop!" << std::endl;
    return -1;
  }
  resize(size-1);
  int value = arr[size - 1];
  size--;
  return value;
}

void NVector::deleteItem(int index) {
  if (index == size - 1) {
    pop();
  } else {
    resize(size-1);
    for (int i = index; i < size; i++) {
      arr[i] = arr[i + 1];
    }
    size--;
  }
}

void NVector::remove(int item) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == item) {
      deleteItem(i);
      i--;
    }
  }
}

void NVector::resize(int candidateSize) {
  if (size < candidateSize) {
    if (size == capacity) {
      increase();
    }
  } else if (size > candidateSize) {
    if (size < capacity / KShrinkFactor) {
      decrease();
    }
  }
}

void NVector::increase() {
  int *newArr = new int[capacity * kGrowthFactor];
  capacity = capacity * kGrowthFactor;
  for (int i = 0; i < size; i++) {
    newArr[i] = arr[i];
  }
  delete[] arr;
  arr = newArr;
}

void NVector::decrease() {
  int *newArr = new int[capacity / 2];
  capacity = capacity / 2;
  for (int i = 0; i < size; i++) {
    newArr[i] = arr[i];
  }
  delete[] arr;
  arr = newArr;
}

} // namespace SK
