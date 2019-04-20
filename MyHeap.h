///




#include <iostream>




template <typename T>
class MyHeap
{
   private:

     T * Heap;  // pointer to heap array

     int Maxsize; // maximum size of the heap

     int n; // number in the heap right now

     void swap(T &a, T &b)
     {
        T temp = a;
        a = b;
        b = temp;

     }

     void buildHeap()
     {
         int i,j;
         T key;
         for(int i = 1; i < Maxsize; i++)
         {
             key = Heap[i];
             j = i - 1;
             while(j >= 0 && Heap[j] > key)
             {
                 Heap[j+1] = Heap[j];
                 j = j - 1;
             }

             Heap[j + 1] = key;

         }
         /// reverse ourder
         int count = 0;
         int index_fall = Maxsize - 1;
         int index_rize = 0;
         while(count < Maxsize/2)
         {
             T value_transfer = Heap[index_rize];
             Heap[index_rize] = Heap[index_fall];
             Heap[index_fall] = value_transfer;
             index_rize++;
             index_fall--;

             count++;
         }
         return;
     }




   public:
        MyHeap()
        {
          Maxsize = 1;
          n = 0;
          Heap  = new T[Maxsize];
        }

        ~MyHeap()
        {
           delete[] Heap;
        }

       MyHeap(T * h,int max)
       {
            Maxsize = max;
            Heap =  new T[Maxsize];
            n = 0;
            for(int i = 0; i < max;i++)
            {
                Heap[i] = h[i];
                n++;
            }
            buildHeap();/// found it
       }


       MyHeap<T> & operator=(const MyHeap<T> &source)
       {
            clear();

            Maxsize = source.Maxsize;
            n = source.n;
            Heap = new T[Maxsize];
            for(int i =0;i<source.n;i++)
            {
                Heap[i] = source.Heap[i];
            }

            //return *this;
       }

       MyHeap(const MyHeap<T> & source)
       {
          //clear();
          Maxsize = source.Maxsize;
          n = source.n;

          Heap = new T[Maxsize]; // alocate computer mem

          for(int i=0;i<source.n;i++)
          {
              Heap[i] = source.Heap[i];
          }
       }



       int capacity()
       {
          return Maxsize;
       }

       int size()const
       {
         return n;
       }


       /// organise in the right ourder

       bool empty()const
       {
          return (n==0);
       }


       void clear()
       {
          delete[] Heap;
          Maxsize = 0;
          n = 0;
          Heap = nullptr;
       }

       void print()
       {
          for(int i =0;i < size();i++)
          {
              std::cout<<" "<<Heap[i];
          }
          std::cout<<std::endl;
       }

       T & top()const
       {
          if(!empty())
          {
              // top element
              return Heap[0];
          }
       }


       void reserve(int new_cap)
       {
          if(new_cap > capacity())
          {
              T * pointer = new T[new_cap];

              for(int i =0;i<n;i++)
              {
                pointer[i] = Heap[i];
              }

              Maxsize = new_cap;
              delete[] Heap;
              Heap = pointer;
          }
       }

       // shrink size of the array to fit size

       void shrink_to_fit()
       {
          /// proof
          int new_capacity = 2* n;
          T * pointer = new T[new_capacity];
          // complexity n [0,1,2,3,4....n-1]
          for(int i =0;i<size();i++)
          {
              pointer[i] = Heap[i];
          }
          Maxsize = new_capacity; // set new capacity
          delete[] Heap; // delete old mem
          Heap = pointer; // transfer new mem
       }


       void push(const T & value_to_push)
       {
              //std::cout<<"before"<<std::endl;
             if(n>=Maxsize || Maxsize <= 0)
             {
               reserve(Maxsize+1);
             }
             //std::cout<<"after"<<std::endl;

             Heap[n++] = value_to_push;

             buildHeap();
        }

       void pop()
       {
          if(size() > 0)
          {
              for(int i =0; i< n-1;i ++)
              {

                Heap[i] = Heap[i+1];


              }

              n--;
              buildHeap();

          }
          if((size())<(capacity())/(4))
          {
            shrink_to_fit();
          }
       }
};
