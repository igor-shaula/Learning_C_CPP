#include <iostream>
using namespace std;

int main()
{
    cout << "how many sum operations do you need? ";
    int dimension;
    cin >> dimension;
    int a[dimension], b[dimension], holder[dimension];

    // filling source arrays with initial data
    for (int i = 0; i < dimension; i++)
    {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < dimension; i++)
    {
        holder[i] = a[i] + b[i];
        cout << a[i] << '+' << b[i] << '=' << holder[i] << endl;
    }

    return 0;
}