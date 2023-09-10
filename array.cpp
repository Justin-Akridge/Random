#include <iostream>
#include <vector>

template <class elemType>
class listType {
public:
  bool isEmpty() const; 
  bool isFull() const;
  bool search(const elemType& searchItem) const;
  void fill(std::vector<elemType>& list);
  void insert(const elemType& newElement);
  void remove(const elemType& removeElement);
  void destroyList();
  void printList();
  std::vector<elemType> get_list();
protected: 
  std::vector<elemType> list;
  int size = 50;
};

template <class elemType>
std::vector<elemType> listType<elemType>::get_list() {
  return list;
}

template <class elemType>
void listType<elemType>::fill(std::vector<elemType>& list) {
  for (int i = 0; i < list.size(); i++) {
    list[i] = i;
  }
}

template <class elemType>
bool listType<elemType>::isEmpty() const {
  if (list.empty()) {
    return true;
  } else {
    return false;
  }
}
  
template <class elemType>
bool listType<elemType>::isFull() const {
  if (list.size() == 100) {
    return true;
  } else {
    return false;
  }
}

template <class elemType>
bool listType<elemType>::search(const elemType& searchItem) const {
  for (int i = 0; i < list.size(); i++) {
    if (searchItem == list[i]) {
      return true;
    }
  }
  return false;
}

template <class elemType>
void listType<elemType>::insert(const elemType& newElement) {
  list.push_back(newElement);
}

template <class elemType>
void listType<elemType>::remove(const elemType& removeElement) {
  for (int i = 0; i < list.size(); i++) {
    if (removeElement == list[i]) {
      list.erase(list.begin() + i);
    }
  }
}

template <class elemType>
void listType<elemType>::destroyList() {
  list.clear();
}

template <class elemType>
void listType<elemType>::printList() {
  for (int i = 0; i < 100; i++) {
    std::cout << list[i] << std::endl;
  }
}

int main() {
  listType<int> list_1;
  for (int i = 0; i < 100; i++) {
    list_1.insert(i);
  }

  std::vector<int> list = list_1.get_list();

  list_1.fill(list);
  list_1.printList();
}
