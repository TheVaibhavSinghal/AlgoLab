#include <bits/stdc++.h>
using namespace std;

int noc = 0;
class q
{
    int a[5];

    int partition(int beg, int end)
    {

        int k = rand() % (end - beg) + beg;
        int pivot = a[k];
        cout << endl
             << "pivot:" << pivot;
        int i = beg, j = end;
        int t;
        while (i < j)
        {
            while (a[i] <= pivot && i <= end)
            {
                i++;
                noc++;
            }
            while (a[j] >= pivot && j > beg)
            {
                if (j == k && j > beg)
                {
                    j--;
                    continue;
                }
                j--;
                noc++;
            }
            if (i < j)
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
        t = a[j];
        a[j] = a[k];
        a[k] = t;

        return j;
    }

  public:
    void random()
    {
        for (int i = 0; i < 5; i++)
        {
            a[i] = rand() % 10;
        }
    }
    void quickSort(int, int);
    void print();
} s[3];
void q::quickSort(int beg, int end)
{
    if (beg < end)
    {
        int j = partition(beg, end);
        quickSort(beg, j - 1);
        quickSort(j + 1, end);
    }
}
void q::print()
{
    int i;
    for (i = 0; i < 5; i++)
        cout << a[i] << " ";
}
int main()
{
    srand(time(NULL));
    for (int i = 0; i < 3; i++)
        s[i].random();
    s[0].print();
    cout << endl;
    s[1].print();
    cout << endl;
    s[2].print();
    for (int i = 0; i < 3; i++)
    {
        s[i].quickSort(0, 4);
        cout << endl
             << "------------------------";
    }
    cout << endl;
    s[0].print();
    cout << endl;
    s[1].print();
    cout << endl;
    s[2].print();
    cout << "Number of avg comparisons = " << (float)noc / 3 << endl;
}
