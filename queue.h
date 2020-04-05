
#ifndef RADICSORT_QUEUE_H
#define RADICSORT_QUEUE_H
#define SIZE 1000000
using namespace std;

template <class T>
class Queue{
    T array[SIZE]{};
    int first,last=-1;
    int queueSize=0;

public:
    void sortHigh(int n, int *tab)
    {
        int pom, j;
        for(int i = 1; i < n; i++)
        {

            pom = tab[i];
            j = i-1;

            while(j >= 0 && tab[j] > pom)
            {
                tab[j+1] = tab[j];
                --j;
            }
            tab[j+1] = pom;
        }
    }
    void sortLow(int n, int *tab)
    {
        int pom, j;
        for(int i = 1; i < n; i++)
        {

            pom = tab[i];
            j = i-1;

            while(j >= 0 && tab[j] < pom)
            {
                tab[j+1] = tab[j];
                --j;
            }
            tab[j+1] = pom;
        }
    }
    void pushHigh(T x){
        if(isExist(x)){
            cout << "This element is exist in queue " << endl;
            return;
        } else if(first==-1){
            first++;
            last++;
            array[last]=x;
            ++queueSize;
        }else if(queueSize==SIZE){
            cout << "Queue is FULL" << endl;
        }else{
            array[queueSize] = x;
            queueSize++;
           sortHigh(queueSize,array);

        }
    }
    void pushLow(T x){
        if(isExist(x)){
            cout << "This element is exist in queue " << endl;
            return;
        } else if(first==-1){
            first++;
            last++;
            array[last]=x;
            ++queueSize;
        }else if(queueSize==SIZE){
            cout << "Queue is FULL" << endl;
        }else{
            array[queueSize] = x;
            queueSize++;
            sortLow(queueSize,array);
        }
    }
    int front(){
        if(queueSize != 0)
            return array[first];
    }
    T pop(){
        T toDelete=-1;
        if(queueSize==0){
            cout<< "Queue is EMPTY" << endl;
        }else{
            toDelete=array[0];
            for (int i = 0; i < queueSize - 1; i++) {
                array[i] = array[i + 1];
            }
            --queueSize;
        }
        return toDelete;
    }
    T popAddEnd(){
        T toDelete=-1;
        if(queueSize==0){
            cout<< "Queue is EMPTY" << endl;
        }else{
            toDelete=array[queueSize-1];
            --queueSize;
        }
        return toDelete;
    }
    bool isEmpty(){
        return (queueSize==0);
    }
    int size(){
        return queueSize;
    }
    bool isExist(T x){
        for (int i = 0; i < queueSize; ++i) {
            if(array[i] == x){
                return true;
            }
        }
        return false;
    }
    Queue& operator=(const Queue *newQueue) {
        for (int i = 0; i < newQueue-> queueSize; i++) {
            array[i] = newQueue -> array[i];
        }
        first = newQueue->first;
        last = newQueue->last;
        queueSize = newQueue->queueSize;
        return *this;
    }
    void print(){
        for (int i = 0; i < queueSize; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};
#endif //RADICSORT_QUEUE_H