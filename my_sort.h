/// max to int main(int argc, char const *argv[]) {
  /* code */




template <typename T>
void my_sort(T Array[],int size)
{
    int i, j;
    T key;
    for(i = 1; i < size; i++)
    {

        key = Array[i];
        j = i - 1;
        while(j >= 0 && Array[j] > key)
        {

            Array[j+1] = Array[j];
            j = j - 1;


        }

        Array[j + 1] = key;

    }
    /// reverse ourder
    int count = 0;
    int index_fall = size - 1;
    int index_rize= 0;
    while(count < size/2)
    {



        T value_transfer = Array[index_rize];
        Array[index_rize] = Array[index_fall];
        Array[index_fall] = value_transfer;
        index_rize++;
        index_fall--;

        count++;

    }
    return;


}
