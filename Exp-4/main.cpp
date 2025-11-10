#include "Queue.cpp"
Queue<int> YANGHVI(int n);

int main()
{
    Queue<int> q, t;
    q = YANGHVI(10);
    cout << "\nThe resultant Queue------\n";
    t = q;
    t.display();
}

Queue<int> YANGHVI(int n)
{
    Queue<int> q;                   //队列初始化
    q.push(1);
    q.push(1);
    int s = 0, t;
    for (int i = 1; i <= n; i++)
    {                               //逐行计算
        cout << endl;
        q.push(0);
        for (int j = 1; j <= i + 2; j++)
        {                           //下一行
            q.pop(t);
            s = s + t;
            q.push(s);
            s = t;
            if (j != i + 2) cout << s << ' ';
        }
    }
    return q;
}