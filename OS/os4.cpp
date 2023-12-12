#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;
// 定义进程状态

typedef enum
{

    READY,

    BLOCKED

} ProcessState;

// 设备结构体

typedef struct
{
    char name[20];

    ProcessState state;

    struct Process* process;

} Device;

queue<Device*> DeviceQ;
// 控制器结构体

typedef struct
{
    char name[20];

    ProcessState state;

    struct Process* process;

} Controller;

queue<Controller*> ControllerQ;
// 通道结构体

typedef struct
{
    char name[20];

    ProcessState state;

    struct Process* process;

} Channel;
queue<Channel*> ChannelQ;

// 进程结构体

typedef struct Process
{
    char name[20];

    ProcessState state;

    Device* allocatedDevice;

    Controller* requestedController;

    Channel* requestedChannel;

} Process;

// 分配设备函数

void allocateDevice(Process* process)
{
    if (!DeviceQ.empty() && process->allocatedDevice == NULL)
    {
        Device* d = DeviceQ.front();
        DeviceQ.pop();
        process->state = BLOCKED;
        process->allocatedDevice = d;
        cout << process->name << "被分配了" << d->name << endl;
    }
    else
    {
        cout << "无可用设备" << endl;
    }
}

// 释放设备函数

void releaseDevice(Process* process)
{
    if (process->allocatedDevice != NULL)
    {
        DeviceQ.push(process->allocatedDevice);
        process->state = READY;
        cout << process->name << "释放了" << process->allocatedDevice->name
             << endl;
        process->allocatedDevice = NULL;
    }
    else
    {
        cout << "无被分配得设备请先分配再释放" << endl;
    }
}

// 请求控制器函数

void requestController(Process* process)
{
    if (!ControllerQ.empty() && process->requestedController == NULL)
    {
        Controller* c = ControllerQ.front();
        ControllerQ.pop();
        process->state = BLOCKED;
        cout << process->name << "被分配了" << c->name << endl;
        process->requestedController = c;
    }
    else
    {
        cout << "无可用控制器，分配失败" << endl;
    }
}

// 释放控制器函数

void releaseController(Process* process)
{
    if (process->requestedController != NULL)
    {
        ControllerQ.push(process->requestedController);
        process->state = READY;
        cout << process->name << "释放了" << process->requestedController->name
             << endl;
        process->requestedController = NULL;
    }
    else
    {
        cout << "没有被分配得控制器请先分配再释放" << endl;
    }
}

// 请求通道函数

void requestChannel(Process* process)
{
    if (!ChannelQ.empty() && process->requestedChannel == NULL)
    {
        Channel* c = ChannelQ.front();
        ChannelQ.pop();
        process->state = BLOCKED;
        cout << process->name << "被分配了" << c->name << endl;
        process->requestedChannel = c;
    }
    else
    {
        cout << "无可用通道" << endl;
    }
}

// 释放通道函数

void releaseChannel(Process* process)
{
    if (process->requestedChannel != NULL)
    {
        ChannelQ.push(process->requestedChannel);
        process->state = READY;
        cout << process->name << "释放了" << process->requestedChannel->name
             << endl;
        process->requestedChannel = NULL;
    }
    else
    {
        cout << "没有被分配得通道请先分配再释放" << endl;
    }
}

int main()
{
    // 创建设备、控制器、通道和进程对象

    Device keyboard = {"键盘", READY, NULL};

    Device mouse = {"鼠标", READY, NULL};

    Device printer = {"打印机", READY, NULL};

    Device monitor = {"显示器", READY, NULL};
    DeviceQ.push(&keyboard);
    DeviceQ.push(&mouse);
    DeviceQ.push(&printer);
    DeviceQ.push(&monitor);
    Controller controller1 = {"Controller1", READY, NULL};

    Controller controller2 = {"Controller2", READY, NULL};

    Controller controller3 = {"Controller3", READY, NULL};
    ControllerQ.push(&controller1);
    ControllerQ.push(&controller2);
    ControllerQ.push(&controller3);
    Channel channel1 = {"Channel1", READY, NULL};

    Channel channel2 = {"Channel2", READY, NULL};
    ChannelQ.push(&channel1);
    ChannelQ.push(&channel2);
    Process process1 = {"Process1", READY, NULL, NULL, NULL};

    Process process2 = {"Process2", READY, NULL, NULL, NULL};
    Process process3 = {"Process3", READY, NULL, NULL, NULL};
    // 分配设备和控制器示例
    cout<<"process1 申请键盘"<<endl;
    allocateDevice(&process1);
    
    requestController(&process1);

    requestChannel(&process1);

    cout<<"process2 申请鼠标"<<endl;
    allocateDevice(&process2);

    requestController(&process2);

    requestChannel(&process2);
    cout<<"process3 申请打印机"<<endl;
    allocateDevice(&process3);
    
    requestController(&process3);

    requestChannel(&process3);
    // 释放设备和控制器示例

    releaseDevice(&process1);

    releaseController(&process1);

    releaseChannel(&process1);

    requestChannel(&process3);

    releaseDevice(&process2);

    releaseController(&process2);

    releaseChannel(&process2);

    releaseDevice(&process3);

    releaseController(&process3);

    releaseChannel(&process3);
    return 0;
}