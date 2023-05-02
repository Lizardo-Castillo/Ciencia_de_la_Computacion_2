#include <iostream>

using namespace std;

class DynamicIntegerArray{
    private:
        int *data;
        int size;
    public:
        DynamicIntegerArray(){
            this -> size = 0;
            data = new int[0];
        }DynamicIntegerArray(int arr[], int size){
            this -> size = size;
            data = new int[size];
            for(int i = 0; i < size; i++){
                data[i] = arr[i];
            }
        }DynamicIntegerArray(const DynamicIntegerArray &o){
            this -> size = o.size;
            data = new int[o.size];
            for(int i = 0; i < o.size; i++){
                data[i] = o.data[i];
            }
        }void print(){
            std::cout << "[ ";
            for(int i = 0; i < size; i++){
                std::cout << data[i] << " ";
            }std::cout << "]" << std::endl;
        }~DynamicIntegerArray(){
            delete[] data;
        }void pushback(int value){
            int *a = new int[size + 1];
            for(int i = 0; i < size; i++){
                a[i] = data[i];
            }a[size] = value;
            delete[] data;
            size++;
            data = a;
        }void insert(int pos, int value){
            int *a = new int[size + 1];
            for(int i = 0; i < size; i++){
                if(i < pos){
                    a[i] = data[i];
                }else if(i >= pos){
                    a[i + 1] = data[i];
                }
            }a[pos] = value;
            delete[] data;
            size++;
            data = a;
        }void remove(int pos){
            int *a = new int[size - 1];
            for(int i = 0; i < size; i++){
                if(i < pos){
                    a[i] = data[i];
                }else if(i >= pos){
                    a[i] = data[i + 1];
                }
            }delete[] data;
            size--;
            data = a;
        }
};
int main()
{
    DynamicIntegerArray a;
    a.pushback(5);
    a.pushback(4);
    a.pushback(9);
    a.pushback(1);
    a.insert(0, 10);
    a.remove(0);
    a.print();

    return 0;
}
