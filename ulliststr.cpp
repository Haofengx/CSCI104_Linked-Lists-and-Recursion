#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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

// WRITE YOUR CODE HERE

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

void ULListStr::push_back(const std::string& val){
  // if the ULList is empty, we need to create a new ULList
  if(empty()){
    // create a new ULList
    Item* LList = new Item();
    head_ = LList;
    tail_ = LList;
    // put the value into the ULList
    LList->val[0] = val;
    LList->last++;
    size_++;
  }
  // if the tail ULList is full, we need to create a new ULList
  else if(tail_->last == ARRSIZE){
    // create a new ULList
    Item* LList = new Item();
    // connect them together
    tail_->next = LList;
    LList->prev = tail_;
    // put the val into the new created ULList
    LList->val[0] = val;
    LList->last++;
    // change the tail_ to the last one
    tail_ = LList;
    size_++;
  }
  // if there is any space in the last ULList, we can add the val directly
  else{
    // put the value into the val[]
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
  }
}

void ULListStr::push_front(const std::string& val){
  // if the ULList is empty, we need to create a new ULList
  if(empty()){
    // create a new ULList
    Item* LList = new Item();
    head_ = LList;
    tail_ = LList;
    // put the value into the ULList
    LList->val[9] = val;
    LList->last = 10;
    LList->first = 9;
    size_++;
  }
  // if the head_ ULList is full, we need to create a new ULList
  else if(head_->last == ARRSIZE){
    // create a new ULList
    Item* LList = new Item();
    // connect them together
    LList->next = head_;
    head_->prev = LList;
    head_ = LList;
    // put the val into the new created ULList
    LList->val[9] = val;
    LList->last = 10;
    LList->first = 9;
    size_++;
  }
  // if there is any space in the head ULList, we can add the val directly
  else{
    // put the value into the val[]
    head_->val[head_->first-1] = val;
    head_->first--;
    size_++;
  }

}

void ULListStr::pop_back(){
  // test special case
  if(size_ == 0) return;
  // delete the last one value
  tail_->last--;
  size_--;
  // test whether there have any empty ULList
  if(tail_->first == tail_->last){
    // if the head_ and tail_ both are same and empty
    if(head_ == tail_){
      delete head_;
      head_ = NULL;
      tail_ = NULL;
    }
    // if only the tail_ is empty
    else{
      tail_->prev->next = NULL;
      Item* temp = tail_;
      tail_ = tail_->prev;
      delete temp;
    }
  }
}

void ULListStr::pop_front(){
  // test special case
  if(size_ == 0) return;
  // delete the last one value
  head_->first++;
  size_--;
  // test whether there have any empty ULList
  if(head_->first == head_->last){
    // if the head_ and tail_ both are same and empty
    if(head_ == tail_){
      delete head_;
      head_ = NULL;
      tail_ = NULL;
    }
    // if only the head_ is empty
    else{
      head_->next->prev = NULL;
      Item* temp = head_;
      head_ = head_->next;
      delete temp;
    }
  }

}

// return the last value in the tail_
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

// return the first value in the head_
std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}


std::string* ULListStr::getValAtLoc(size_t loc) const{
  // test special case
  if(loc >= size_ || loc < 0) return NULL;
  // find where the loc is
  Item* temp = head_;
  while(loc >= 10){
    loc -= temp->last - temp->first;
    temp = temp->next;
  }
  return temp->val+temp->first+loc;
}
