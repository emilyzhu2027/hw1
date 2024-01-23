#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val){
  // If linked list has no elements
  if (head_ == NULL){
    Item* newItem = new Item();
    (newItem->val)[0] = val;
    newItem->last += 1;
    head_ = newItem;
    tail_ = newItem;
    size_ += 1;
  }
  // If last item is already filled, allocates new item
  else if (tail_->last == ARRSIZE){
    Item* newItem = new Item();
    (newItem->val)[0] = val;
    newItem->last += 1;
    newItem->prev = tail_;
    tail_->next = newItem;
    tail_ = newItem;
    size_+=1;
  } 
  // If last item isn't filled
  else{
    (tail_->val)[tail_->last] = val;
    tail_->last += 1;
    size_+=1;
  }
}

void ULListStr::pop_back(){
  // If list is empty, nothing to pop
  if (tail_ == NULL) {
    return;
  }

  // If tail node has more than one item 
  if ((tail_->last - tail_->first) > 1) {
    tail_->last -= 1;
  } 
  // If tail node has only one item, deallocate entire node bc empty otherwise
  else {
    Item* temp = tail_;

    // If tail node is the only node in list
    if (tail_->prev == NULL){
      tail_ = NULL;
      head_ = NULL;
    }
    // If more than one node in list
    else{
      tail_ = tail_->prev;
      tail_->next = NULL;
    }

    delete temp;
  }
  size_ -= 1;
}

void ULListStr::push_front(const std::string& val){
  // If linked list is empty
  if (head_ == NULL){
    Item* newItem = new Item();
    (newItem->val)[ARRSIZE - 1] = val;
    newItem->last = ARRSIZE;
    newItem->first = ARRSIZE - 1;
    head_ = newItem;
    tail_ = newItem;
    size_ += 1;
  }
  // If head node is full, allocate new node at head
  else if (head_->first == 0){
    Item* newItem = new Item();
    (newItem->val)[ARRSIZE - 1] = val;
    newItem->last = ARRSIZE;
    newItem->first = ARRSIZE - 1;
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;
    size_+=1;
  } 
  // If space available in head node
  else{
    (head_->val)[head_->first - 1] = val;
    head_->first -= 1;
    size_+=1;
  }
}

void ULListStr::pop_front(){
  // If list is empty, nothing to pop
  if (head_ == NULL) {
    return;
  }
  // If head node has more than one item
  if ((head_->last - head_->first) > 1) {
    head_->first += 1;
  } 
  // If head node has only one item, remove the entire node
  else {
    Item* temp = head_;

    // If head node is only node in linked list
    if (head_->next == NULL){
      tail_ = NULL;
      head_ = NULL;
    }
    // If more than one node in linked list
    else{
      head_ = head_->next;
      head_->prev = NULL;
    }

    delete temp;
  }
  size_ -= 1;
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* curr = head_;

  while (curr != nullptr) {
    if (loc < (curr->last - curr->first)) {
        // The value is in the current node
        return &(curr->val[(curr->first) + loc]);
    } 
    else {
        // Move to the next node
        loc -= (curr->last - curr->first);
        curr = curr->next;
    }
  }
  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
