#include <iostream>
using namespace std;
typedef struct PCB_type
{
    char name[20]; // 进程名
    char state;    // 进程状态  、r 执行 w 就绪  B 阻塞
    int Cpu_Time;
    int Used_Time;
    int Arrive_Time;
    struct PCB_type *next; // 下一个
} PCB_type;

typedef struct QueueNode
{
    PCB_type PCB;
    QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *head, *tail;
} Queue;

void printPCBInfo(QueueNode *p)
{
    printf("\t%s|\t%c |\t%d\t|\t%d\n", p->PCB.name, p->PCB.state, p->PCB.Used_Time, p->PCB.Cpu_Time);
}
// 创建队列
void createQueue(Queue &q)
{
    q.head = q.tail = new QueueNode;
    q.head->next = nullptr;
}
// 节点入队
void enterQueue(Queue &q, QueueNode *&p)
{
    p->next = nullptr;
    q.tail->next = p;
    q.tail = p;
}
void traverseQueue(Queue &q)
{
    QueueNode *p = q.head->next;
    while (p)
    {
        printf("P进程名字|进程状态|进程已用CPU时间|还需要运行的时间\n");
        printPCBInfo(p);
        p = p->next;
    }
}
// 删除队首节点
QueueNode *deleteQNode(Queue &q)
{
    if (q.head == q.tail)
    {
        return nullptr;
    }
    QueueNode *p = q.head->next;
    q.head->next = p->next;
    if (q.tail == p)
    {
        q.tail = q.head;
    }
    return p;
}

void dispatch(Queue &readyQ, Queue &blockQ, Queue &runQ)
{
    int count = 0;
    int counter = 5;
    while (true)
    {
        if (readyQ.head != readyQ.tail || blockQ.head != blockQ.tail)
        { // ready 队列不为空，或者blocked 队列不为空
            if (readyQ.head != readyQ.tail)
            {
                QueueNode *p = deleteQNode(readyQ); // 取ready 队首元素、插入run队列
                p->PCB.state = 'r';
                cout << p->PCB.name << endl;
                cout << endl;
                p->PCB.Cpu_Time--;
                p->PCB.Used_Time++;
                if (p->PCB.Cpu_Time > 0)
                {
                    p->PCB.state = 'w'; // 置就绪
                    enterQueue(readyQ, p);
                }
                else
                {
                    delete p;
                    p = nullptr;
                }
                traverseQueue(readyQ);
            }
            else
            {
                count++;
            }
            if (count == count)
            {
                if (blockQ.head != blockQ.tail)
                {
                    QueueNode *p = deleteQNode(blockQ);
                    enterQueue(readyQ, p);
                }
            }
        }
        else
        {
            return;
        }
    }
}

void initialTest(Queue &ready, Queue &blockQ)
{
    QueueNode *p1 = new QueueNode;
    p1->PCB.name[0] = 'a';
    p1->PCB.name[1] = '\0';
    p1->PCB.state = 'w'; //
    p1->PCB.Cpu_Time = 6;
    p1->PCB.Used_Time = 1;
    p1->PCB.Arrive_Time = 0;
    enterQueue(ready, p1);
    QueueNode *p2 = new QueueNode;
    p2->PCB.name[0] = 'b';
    p2->PCB.name[1] = '\0';
    p2->PCB.state = 'w'; //
    p2->PCB.Cpu_Time = 4;
    p2->PCB.Used_Time = 1;
    p2->PCB.Arrive_Time = 0;
    enterQueue(ready, p2);
    // block Q
    QueueNode *p3 = new QueueNode;
    p3->PCB.name[0] = 'c';
    p3->PCB.name[1] = '\0';
    p3->PCB.state = 'B'; //
    p3->PCB.Cpu_Time = 3;
    p3->PCB.Used_Time = 0;
    p3->PCB.Arrive_Time = 0;
    enterQueue(blockQ, p3);

    QueueNode *p4 = new QueueNode;
    p4->PCB.name[0] = 'd';
    p4->PCB.name[1] = '\0';
    p4->PCB.state = 'B'; //
    p4->PCB.Cpu_Time = 6;
    p4->PCB.Used_Time = 0;
    p4->PCB.Arrive_Time = 0;
    enterQueue(blockQ, p4);

    QueueNode *p5 = new QueueNode;
    p5->PCB.name[0] = 'e';
    p5->PCB.name[1] = '\0';
    p5->PCB.state = 'B'; //
    p5->PCB.Cpu_Time = 2;
    p5->PCB.Used_Time = 0;
    p5->PCB.Arrive_Time = 0;
    enterQueue(blockQ, p5);
}
int main()
{
    Queue readyQ;
    Queue blockQ;
    Queue runQ;
    createQueue(readyQ);
    createQueue(blockQ);
    createQueue(runQ);
    initialTest(readyQ, blockQ);
    dispatch(readyQ, blockQ, runQ);
    return 0;
}
