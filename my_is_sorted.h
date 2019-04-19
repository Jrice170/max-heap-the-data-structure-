

template <typename T>
bool my_is_sorted(T array[],int size)
{


    for(int i =0;i<size-1;i++)
    {

        if(array[i] < array[i+1])
        {

            return false;

        }

    }
    return true;

}
