#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
#include <new>

// In the constructor, m_size is initialized to zero.
static const int INITIAL_SIZE = 0;

template <typename T>
class Queue
        {
                private:

                /*
                 * This class of Queue is implemented using a list of Nodes.
                 * The first Node of the list is a dummy Node,
                 * means the first element of the Queue is at the second Node of the list.
                 * when having just the dummy Node, m_size is initialized to zero.
                */
                template <typename S>
        struct Node
        {
            S m_data;
            Node *m_nextNode = nullptr;

            /*
             * C'tor of Node
             *
             * @return
             *      A new empty instance of Node.
            */
            Node() = default;

            /*
             * Copy c'tor of Node
             *
             * @param n - A reference of an existing Node.
             * @return
             *      A copied instance of n.
            */
            Node(const Node& n) = default;


            /*
             * Assignment operator
             *
             * @param n - The Node to assign from.
             * @return
             *      default
            */
            Node& operator=(const Node& n) = default;


            /*
             * D'tor of Node class
             *
             * @return
             *      Deletes this instance of Node.
            */
            ~Node() = default;
        };

        Node<T> *m_head;
        Node<T> *m_tail;
        int m_size;

        public:
        /*
         * C'tor of Queue class
         *
         * @return
         *      A new empty instance of Queue.
        */
        Queue();


        /*
         * Copy c'tor of Queue class
         *
         * @param q - A reference of an existing Queue instance.
         * @return
         *      A copied instance of q.
        */
        Queue(const Queue<T> &q);


        /*
         * D'tor of Queue class
         *
         * @return
         *      Deletes this instance of Queue.
        */
        ~Queue();


        /*
         * Assignment operator
         *
         * @param q - The Queue to assign from.
         * @return
         *      default
        */
        Queue& operator=(const Queue<T>& q);


        /*
         * Inserts a new element at the end of the queue and assigns data to it.
         *
         * @param data - A reference of the data to assign to the newly inserted element.
         * @return
         *      void
        */
        void pushBack(const T& data);


        /*
         * Returns the data of the first element of the Queue.
         *
         * @return
         *      A reference to the data of the first element of the Queue.
        */
        T& front();


        /*
         * Returns the data of the first element of the Queue when Queue is const.
         *
         * @return
         *      A const reference to the data of the first element of the Queue.
        */
        const T& front() const;


        /*
         * Deletes the first element of the Queue.
         *
         * @return
         *      void
        */
        void popFront();


        /*
         * Returns the number of elements in Queue.
         *
         * @return
         *      Size of Queue.
        */
        int size() const;


        class Iterator;


        /*
         * Returns an Iterator of the first element of Queue.
         *
         * @return
         *      An Iterator of the first element of Queue.
        */
        Iterator begin();

        /*
         * Returns an Iterator to after the last element of Queue.
         *
         * @return
         *      An Iterator to after the last element of Queue.
        */
        Iterator end();


        class ConstIterator;
        /*
         * Returns a const Iterator of the first element of Queue.
         *
         * @return
         *      A const Iterator of the first element of Queue.
        */
        ConstIterator begin() const;

        /*
         * Returns a const Iterator to after the last element of Queue.
         *
         * @return
         *      A const Iterator to after the last element of Queue.
        */
        ConstIterator end() const;

        /*
         * This exception will be thrown
         * if there is an attempt to perform an operation on an empty Queue,
         * when it is considered illegal.
        */
        class EmptyQueue {};
        };


template<typename T>
class Queue<T>::Iterator
        {
                private:

                Queue<T>::Node<T> * m_pointer;

        friend class Queue<T>;

        public:

        /*
         * C'tor of Iterator class
         *
         * @param pointer - the node that the Iterator points to.
         * @return
         *      A new Iterator.
        */
        Iterator(Node<T>* pointer);

        /*
         * Copy c'tor of Iterator class
         *
         * @param it - A reference of an existing Iterator.
         * @return
         *      A copied Iterator.
        */
        Iterator(const Iterator& i) = default;

        /*
         * D'tor of Iterator class
         *
         * @return
         *      Deletes this Iterator.
        */
        ~Iterator() = default;


        /*
         * Assignment operator
         *
         * @param i - The Iterator to assign from.
         * @return
         *      default
        */
        Iterator& operator=(const Iterator& i) = default;


        /*
         * Returns a reference data which the Iterator points to.
         *
         * @return
         *      A reference to the data which the Iterator points to.
        */
        T& operator*();


        /*
         * Sets the Iterator to point to the next node of the one it points to,
         * and then returns a reference to the updated Iterator.
         *
         * @return
         *      A reference to the next node of the one this Iterator points to.
        */
        Iterator& operator++();

        /*
         * Check if this Iterator points to the same node as i.
         *
         * @param i - The Iterator to compare with.
         * @return
         *          True if this Iterator does not point to the same node as i.
         *          False otherwise
         */
        bool operator!=(const Iterator& i) const;

        /*
         * This exception will be thrown
         * if there is an attempt to perform an operation on an Iterator,
         * when it is considered illegal.
        */
        class InvalidOperation{};
        };


template<typename T>
class Queue<T>::ConstIterator
        {
                private:

                Node<T>* m_pointer;

        friend class Queue<T>;

        public:

        /*
         * C'tor of const Iterator class
         *
         * @param pointer - the node that the const Iterator points to.
         * @return
         *      A new const Iterator.
        */
        ConstIterator(Node<T>* pointer);

        /*
         * Copy c'tor of const Iterator class
         *
         * @param i - The const Iterator to copy construct from.
         * @return
         *      A copied const Iterator.
        */
        ConstIterator(const ConstIterator& i) = default;

        /*
         * D'tor of const Iterator class
         *
         * @return
         *      Deletes this const Iterator.
        */
        ~ConstIterator() = default;

        /*
         * Assignment operator
         *
         * @param it - The const Iterator to assign from.
         * @return
         *      default
        */
        ConstIterator& operator=(const ConstIterator& i) = default;

        /*
         * Returns a reference data which the const Iterator points to.
         *
         * @return
         *      A reference to the data which the const Iterator points to.
        */
        const T& operator*() const;

        /*
         * Sets the const Iterator to point to the next node of the one it points to,
         * and then returns a reference to the updated const Iterator.
         *
         * @return
         *      A reference to the next node of the one this const Iterator points to.
        */
        ConstIterator& operator++();

        /*
         * Check if this const Iterator points to the same node as i.
         *
         * @param i - The const Iterator to compare with.
         * @return
         *          True if this const Iterator does not point to the same node as i.
         *          False otherwise
         */
        bool operator!=(const ConstIterator& i) const;

        /*
         * This exception will be thrown
         * if there is an attempt to perform an operation on a const Iterator,
         * when it is considered illegal.
        */
        class InvalidOperation {};
        };


template<typename T>
Queue<T>::Iterator::Iterator(Node<T>* pointer): m_pointer(pointer)
        {}

template<class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
    if (this->m_size == INITIAL_SIZE)
    {
        return Iterator(nullptr);
    }
    return Iterator(this->m_head->m_nextNode);

}

template<typename T>
typename Queue<T>::Iterator Queue<T>::end()
{
    return Iterator(nullptr);
}

template<typename T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
/* InvalidOperation exception is thrown if the iterator has no next */
if(this->m_pointer == nullptr)
{
throw Queue<T>::Iterator::InvalidOperation();
}

this->m_pointer = this->m_pointer->m_nextNode;
return *this;
}

template<typename T>
T& Queue<T>::Iterator::operator*()
{
return this->m_pointer->m_data;
}

template<typename T>
bool Queue<T>::Iterator::operator!=(const Iterator& i) const
{
return this->m_pointer != i.m_pointer;
}


template<typename T>
Queue<T>::ConstIterator::ConstIterator(Node<T>* pointer): m_pointer(pointer)
        {}

template<typename T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
if (this->m_size == INITIAL_SIZE)
{
return ConstIterator(nullptr);
}

return ConstIterator(this->m_head->m_nextNode);
}

template<typename T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
return ConstIterator(nullptr);
}

template<typename T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
/* InvalidOperation exception is thrown if the iterator has no next */
if(this->m_pointer == nullptr)
{
throw Queue<T>::ConstIterator::InvalidOperation();
}
this->m_pointer = this->m_pointer->m_nextNode;
return *this;
}

template<typename T>
const T& Queue<T>::ConstIterator::operator*() const
{
return this->m_pointer->m_data;
}

template<typename T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& i) const
{
return this->m_pointer != i.m_pointer;
}


template<typename T>
Queue<T>::Queue() : m_head(new Node<T>()), m_tail(this->m_head), m_size(INITIAL_SIZE)
        {}

template <typename T>
Queue<T>::Queue(const Queue<T>& q)
{
try
{
this->m_head = new Node<T>();
}
catch(const std::bad_alloc& e)
{
throw e;
}
this->m_tail = this->m_head;
this->m_size = INITIAL_SIZE;

for(typename Queue<T>::ConstIterator it = q.begin(); it != q.end(); ++it)
{
try
{
this->pushBack(*it);
}
/* when catching std::bad_alloc exception, the successfully allocated elements before will be freed */
catch(const std::bad_alloc& e)
{
while(this->m_size > INITIAL_SIZE)
{
this->popFront();
}
delete this->m_head;
throw e;
}
}
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q)
{
if(this == &q)
{
return *this;
}

Node<T>* dummyNode = new Node<T>();
Node<T>* temp = dummyNode;

for(typename Queue<T>::ConstIterator it = q.begin(); it != q.end(); ++it)
{
try
{
temp->m_nextNode = new Node<T>();
temp = temp->m_nextNode;
temp->m_data = *it;
}
/* when catching std::bad_alloc exception, the successfully allocated elements before will be freed */
catch(const std::bad_alloc& e)
{
while(dummyNode != nullptr)
{
Node<T>* toDelete = dummyNode;
dummyNode = dummyNode->m_nextNode;
delete toDelete;
}
throw e;
return *this;
}
}

while(this->m_size > INITIAL_SIZE)
{
this->popFront();
}
this->m_head->m_nextNode = dummyNode->m_nextNode;
this->m_tail = temp;
this->m_size = q.size();
delete dummyNode;
return *this;
}

template <typename T>
Queue<T>::~Queue()
{
    while( this->m_size > INITIAL_SIZE)
    {
        this->popFront();
    }
    delete this->m_head;
}

template <typename T>
void Queue<T>::pushBack(const T& data)
{
this->m_tail->m_nextNode = new Node<T>();
this->m_tail = this->m_tail->m_nextNode;
this->m_tail->m_data = data;
++this->m_size;
}

template <typename T>
const T& Queue<T>::front() const
{
/* EmptyQueue exception is thrown if the Queue is empty, because front does not exist.*/
if(this->m_size == INITIAL_SIZE)
{
throw Queue<T>::EmptyQueue();
}
return this->m_head->m_nextNode->m_data;
}

template <typename T>
T& Queue<T>::front()
{
    /* EmptyQueue exception is thrown if the Queue is empty, because front does not exist.*/
    if(this->m_size == INITIAL_SIZE)
    {
        throw Queue<T>::EmptyQueue();
    }
    return this->m_head->m_nextNode->m_data;
}

template <typename T>
void Queue<T>::popFront()
{
    /* EmptyQueue exception is thrown if the Queue is empty, because front does not exist.*/
    if(this->m_size == INITIAL_SIZE)
    {
        throw Queue<T>::EmptyQueue();
    }

    Node<T>* toDelete = this->m_head->m_nextNode;
    if(toDelete == this->m_tail)
    {
        this->m_tail= this->m_head;
    }
    else
    {
        this->m_head->m_nextNode= toDelete->m_nextNode;
    }
    delete toDelete;
    --this->m_size;
}

template <typename T>
int Queue<T>::size() const
{
return this->m_size;
}

/*
 * Filters a given queue according to a given condition.
 *
 * @param q - A Queue to filter.
 * @param func - A function to filter the Queue according to.
 *
 * @return
 *      A filtered instance of q.
*/
template <typename T, typename S>
Queue<T> filter(const Queue<T>& q, S func)
{
if(q.size() == INITIAL_SIZE)
{
return q;
}

Queue<T> newQueue;
for(typename Queue<T>::ConstIterator it = q.begin(); it != q.end(); ++it)
{
if(func(*it))
{
try
{
newQueue.pushBack(*it);
}
catch(std::bad_alloc& e)
{
throw e;
}
}
}
return newQueue;
}

/*
 * Apply a transform on a given Queue according to a given way.
 *
 * @param q - A Queue to transform.
 * @param func - A function which apply a transform on a given value.
 *
 * @return
 *      void
*/
template <typename T, typename S>
void transform(Queue<T>& q, S func)
{
for(typename Queue<T>::Iterator it = q.begin(); it != q.end(); ++it)
{
func(*it);
}
}

#endif