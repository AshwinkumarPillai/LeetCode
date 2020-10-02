bool isMonotonic(vector<int> &arr)
{
    bool notup = true;
    bool notdown = true;
    for (int i = 1; i < (int)arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            notup = false;
        }
        else if (arr[i] > arr[i - 1])
        {
            notdown = false;
        }
    }
    return notup || notdown;
}