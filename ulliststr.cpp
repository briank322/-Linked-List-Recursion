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

void ULListStr::set(size_t loc, const std::string& val)
{
    std::string* ptr = getValAtLoc(loc);
    if(NULL == ptr){
      throw std::invalid_argument("Bad location");
    }
    *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
    std::string* ptr = getValAtLoc(loc);
    if(NULL == ptr){
      throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
    std::string* ptr = getValAtLoc(loc);
    if(NULL == ptr){
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



//Adds a new value to the back of the list
void ULListStr::push_back(const std::string& val)
{
    //if head is NULL, create a head.
    //Put the element into head's front.
     if(head_== NULL)
     {
       //if empty, create a new head
       Item* newitem = new Item();
       head_ = newitem;
       //Add a number at newitem's array
       newitem->val[head_->last] = val;
       //Now, this newitem is both head and tail.
       tail_ = newitem;
       //Increment the last to one because I just add a new number.
       (tail_->last)++;
       size_++;
     }

    //if tail's last isn't an arraysize, then put it
    //at tail's end, then increment tail's last. 
     else if(tail_->last != 10)
     {
       tail_->val[(tail_->last)]=val;
       (tail_->last) ++;
       size_++;
     }

     //Else, create a new tail and put the element 
     //at tail's head.
     else
     {
       //if all nodes(arrays) are full, create a new node(tail).
       Item* newitem= new Item();
       //update next and prev pointer for the new tail.
       tail_->next = newitem;
       newitem->prev = tail_;
       tail_ = newitem;
       //newtail->next should be null.
       newitem->next = NULL;
       tail_->val[(tail_->last)]=val;
       (tail_->last) ++;
       size_++;
     }

}


  //  Removes a value from the back of the list
  //   - MUST RUN in O(1)

void ULListStr::pop_back()
{
      //if head is NULL. Do nothing
      if(head_ == NULL)
      {
         return;
      }
      //if tail has more than one item, tail's last--;
      else if((tail_->last)-(tail_->first) >= 1)
      {
         size_ --;
         tail_->last--;
      }
      //Else((only one item left in tail) delete tail_.
      else
      {
         size_--;
         //dset oldtail->prev to new tail.
         tail_= tail_->prev;
         //elete the old tail.
         delete tail_->next;
         tail_->next = NULL;
         tail_->last = 10;
      }
  
}


   


void ULListStr::push_front(const std::string& val)

{
 	  //if head is null, create a head, and put the element
    //at the very end of head string.
     if(head_ == NULL)
     {
       Item* newitem = new Item();
       head_ = newitem;
       //Add a new number at the end of the "new" head string.
       head_->first = 9;
       head_->last = 10;
       head_->val[newitem->first] = val;
       //Tail is also pointing to head node.
       tail_ = newitem;
       size_ ++;
     } 

    //if head's first isn't 0, put the element at the head's front.
     else if(head_->first != 0)
     {
       (head_ -> first) --;
       head_->val[(head_->first)]=val;
       size_ ++;
     }
    //if head's first is 0, create a new head which points to the previous head. 
     else if(head_->first==0)
     {
       //Nodes(array) are full, then we need to create a new node.
       Item* newitem= new Item();
       //Update the old head prev to the "new" head.
       head_->prev = newitem;
       //link two nodes together 
       newitem->next = head_;
       //Now, this newitem is the new head.
       head_= newitem;
       //head->prev should points to NULL
       newitem->prev=NULL;

       size_ ++;
       //assign the new head's first to the last index
       newitem->first = 9;
       //Add a new number at the very end of the array
       head_->val[newitem->first]=val;
       //Update head because number is at the end of the array.
       newitem->last = 10;
     }

}




  //Removes a value from the front of the list
   //- MUST RUN in O(1)

void ULListStr::pop_front()
{
     //if head is null do nothing
     if(head_== NULL)
     {
       return;
     }
     //if head has more than 2 item head.first++
     else if(head_->first != 9)
     {
       size_ --;
       (head_->first)++;
     }
     //if head has only one item, remove the head.
     else
     {
       size_ --;
       //Update head nodes to the second node.
       head_=head_->next;
       //Delete the old head
       delete head_->prev;
       //Assign the new head's prev to null
       head_->prev = NULL;
       head_->first = 0;
     }

}

  
  // - MUST RUN in O(n) 
  // This function's runtime is O(n) because if(loc < onlyheadsize) then O(n),
  // else if(loc>onlyheadsize) then O(n). There is no loc value that can enter
  // both for loop and while loop.
std::string* ULListStr::getValAtLoc(size_t loc) const
{
       //Invalid location returns NULL.
    if(loc >= size_ || loc < 0)
    {
         return NULL;
    }

       //If the loc is valid, we have 2 cases.
    else if (loc >=0 || loc < size_ )
    {
           size_t onlyheadsize =
           ((head_->last)-(head_->first));

           size_t counter_head = 0;
           size_t counter_all = 0;
           Item* buff = NULL;
           buff = head_->next;
        
         if((head_->first) == 0 && (head_->last) == 0)
         {
            return NULL;
         }
         //First, the loc is inside the head's array.
         if(loc < onlyheadsize)
         {  
            size_t temp = head_->first;
            while(counter_head<loc)
            {
               counter_head++;
               temp++;
            }
          
            return &(head_->val[temp]);
            //return &(head_->val[loc + (head_->first)]);
         } 
           // Second, loc is in between head(exlcusive) and tail(inclusive)
         else if (loc >= onlyheadsize)
         {
           while(counter_all < (loc-onlyheadsize)/10 )
           {
             buff = buff->next;
             counter_all++;
           }
           return &(buff->val[(loc-onlyheadsize)%10]);
         }
          //Otherwise, NULL
         else
         {
           return NULL;
         }
    }
}

//Returns a const reference to the back element
std::string const & ULListStr::back() const
{
    if((head_==NULL) && (tail_==NULL))
    {
        return NULL;
    }
    return tail_->val[(tail_->last)-1];
}

//Returns a const reference to the front element
std::string const & ULListStr::front() const
{
    if((head_==NULL) && (tail_==NULL))
    {
        return NULL;
    }
    return head_->val[head_->first];
}
