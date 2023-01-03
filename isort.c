void shift_element (int* arr, int i)
{
    int temp;
    if (i==0)
        return;
    int size =  (int) sizeof(arr);
    if (i == size)
        *(arr+i+1) = *(arr+i);
    if(*(arr+i)+i+1 < size+1)
    while (i>=0)
    {
        temp = *(arr+i-1);
        *(arr+i) = *(arr+i-1);
        i--;
    }  
}

void insertion_sort(int *arr, int len)
{
	for(int i=1; i<len; i++)
	{
		int value = *(arr+i);
		int hole = i-1;
		while( hole>=0 && *(arr+ hole)>value)
		{
			shift_element((arr + i), i - hole);
			hole--;
		}
		*(arr + hole + 1) = value ;
	}
}