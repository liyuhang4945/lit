// #include<iostream>
// #include<string>
// #include <time.h>
//
// using namespace std;
//
// #define DATETIME_LENGTH 15 // 包括空字符'\0'
// #define EMPTY_BLOCK 0x0000
// #define LAST_BLOCK 0xFFFF
// typedef struct FCB {
//	char name[8];
//	int size;
//	int first_block;
//	char type;
//	char datetime[15];
// };
//
// void getCurrentDateTime(char* dateTime) {
//     time_t currentTime;
//     struct tm* localTime;
//
//     time(&currentTime);
//     localTime = localtime(&currentTime);
//
//     // 格式化日期和时间并存储在字符数组中
//     snprintf(dateTime, DATETIME_LENGTH, "%04d%02d%02d %02d%02d",
//         localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
//         localTime->tm_hour, localTime->tm_min);
// }
//
//
////md//创建文件
////rd //删除文件
////mkdir
////del
// void Initial(FCB &p) {
//
// }
// int main() {
//     while () {
//
//     }
//     return 0;
// }
//
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 1024
#define MAX_NAME_LENGTH 8
#define EMPTY_BLOCK 0x0000
#define LAST_BLOCK 0xFFFF

struct FCB
{
    char name[MAX_NAME_LENGTH];
    int size;
    int first_block;
    char type;
    char datetime[15];
};

void initializeFAT(int *fat)
{
    int i;
    for (i = 0; i < 10000; i++)
    {
        fat[i] = EMPTY_BLOCK;
    }
    fat[10000] = LAST_BLOCK;
}

void createFCB(struct FCB *fcb, const char *name, int size, int first_block, char type)
{
    strncpy(fcb->name, name, MAX_NAME_LENGTH);
    fcb->size = size;
    fcb->first_block = first_block;
    fcb->type = type;

    // 获取当前日期和时间
    time_t now = time(NULL);
    strftime(fcb->datetime, sizeof(fcb->datetime), "%Y%m%d %H%M%S", localtime(&now));
}

void writeFCBtoDisk(struct FCB fcb)
{
    FILE *disk_file = fopen("virtual_disk.txt", "a");
    fprintf(disk_file, "%s %d %d %c %s\n", fcb.name, fcb.size, fcb.first_block, fcb.type, fcb.datetime);
    fclose(disk_file);
}

void writeFATtoDisk(int *fat)
{
    FILE *disk_file = fopen("virtual_disk.txt", "a");
    int i;
    for (i = 0; i < 10000; i++)
    {
        fprintf(disk_file, "%d ", fat[i]);
    }
    fprintf(disk_file, "\n");
    fclose(disk_file);
}

void readFATfromDisk(int *fat)
{
    FILE *disk_file = fopen("virtual_disk.txt", "r");
    fseek(disk_file, -1026, SEEK_END); // 移到倒数第二行（FAT表所在行）
    int i;
    for (i = 0; i < 10000; i++)
    {
        fscanf(disk_file, "%d", &fat[i]);
    }
    fclose(disk_file);
}

void createDir(char *dirname, struct FCB *parent_dir, int *fat)
{
    struct FCB new_dir;
    time_t now = time(NULL);
    snprintf(new_dir.name, MAX_NAME_LENGTH, "%.8s", dirname);
    new_dir.size = BLOCK_SIZE;
    new_dir.first_block = EMPTY_BLOCK;
    new_dir.type = '2'; // 目录类型
    strftime(new_dir.datetime, sizeof(new_dir.datetime), "%Y%m%d %H%M%S", localtime(&now));

    writeFCBtoDisk(new_dir);

    // 更新父目录的FCB信息
    parent_dir->size += BLOCK_SIZE;
    if (parent_dir->first_block == EMPTY_BLOCK)
    {
        parent_dir->first_block = LAST_BLOCK;
    }
    writeFCBtoDisk(*parent_dir);

    // 更新FAT表
    int i;
    for (i = 0; i < 10000; i++)
    {
        if (fat[i] == EMPTY_BLOCK)
        {
            fat[i] = LAST_BLOCK;
            break;
        }
    }
    writeFATtoDisk(fat);
}

void deleteDir(char *dirname, struct FCB *parent_dir, int *fat)
{
    FILE *disk_file = fopen("virtual_disk.txt", "r+");
    int found = 0;
    char line[1024];
    while (fgets(line, sizeof(line), disk_file))
    {
        struct FCB fcb;
        sscanf(line, "%s %d %d %c %s", fcb.name, &fcb.size, &fcb.first_block, &fcb.type, fcb.datetime);
        if (strncmp(fcb.name, dirname, MAX_NAME_LENGTH) == 0 && fcb.type == '2')
        {
            // 将目录项标记为已删除
            fseek(disk_file, -(int)strlen(line), SEEK_CUR);
            fprintf(disk_file, "%.8s %d %d %c %s\n", fcb.name, fcb.size, fcb.first_block, '0', fcb.datetime);
            found = 1;
            break;
        }
    }
    fclose(disk_file);

    // 更新父目录的FCB信息
    if (found)
    {
        parent_dir->size -= BLOCK_SIZE;
        writeFCBtoDisk(*parent_dir);
    }
    else
    {
        printf("目录不存在！\n");
    }
}

void createFile(char *filename, int size, struct FCB *parent_dir, int *fat)
{
    struct FCB new_file;
    time_t now = time(NULL);
    snprintf(new_file.name, MAX_NAME_LENGTH, "%.8s", filename);
    new_file.size = size;
    new_file.first_block = EMPTY_BLOCK;
    new_file.type = '1'; // 文件类型
    strftime(new_file.datetime, sizeof(new_file.datetime), "%Y%m%d %H%M%S", localtime(&now));

    writeFCBtoDisk(new_file);

    // 更新父目录的FCB信息
    parent_dir->size += size;
    if (parent_dir->first_block == EMPTY_BLOCK)
    {
        parent_dir->first_block = LAST_BLOCK;
    }
    writeFCBtoDisk(*parent_dir);

    // 更新FAT表
    int i, count = 0;
    for (i = 0; i < 10000 && count < size / BLOCK_SIZE; i++)
    {
        if (fat[i] == EMPTY_BLOCK)
        {
            fat[i] = LAST_BLOCK;
            if (count == 0)
            {
                parent_dir->first_block = i;
                writeFCBtoDisk(*parent_dir);
            }
            count++;
        }
    }
    writeFATtoDisk(fat);
}

void deleteFile(char *filename, struct FCB *parent_dir, int *fat)
{
    FILE *disk_file = fopen("virtual_disk.txt", "r+");
    int found = 0;
    char line[1024];
    while (fgets(line, sizeof(line), disk_file))
    {
        struct FCB fcb;
        sscanf(line, "%s %d %d %c %s", fcb.name, &fcb.size, &fcb.first_block, &fcb.type, fcb.datetime);
        if (strncmp(fcb.name, filename, MAX_NAME_LENGTH) == 0 && fcb.type == '1')
        {
            // 将文件项标记为已删除
            fseek(disk_file, -(int)strlen(line), SEEK_CUR);
            fprintf(disk_file, "%.8s %d %d %c %s\n", fcb.name, fcb.size, fcb.first_block, '0', fcb.datetime);
            found = 1;
            break;
        }
    }
    fclose(disk_file);

    // 更新父目录的FCB信息
    if (found)
    {
        parent_dir->size -= BLOCK_SIZE;
        writeFCBtoDisk(*parent_dir);
    }
    else
    {
        printf("文件不存在！\n");
    }

    //// 更新FAT表
    // int i;
    // for (i = parent_dir->first_block; fat[i] != LAST_BLOCK;) {
    //     int next_block = fat[i];
    //     fat[i] = EMPTY_BLOCK;
    //     i = next_block;
    // }

    //// 最后一个块也要设置为空
    // fat[i] = EMPTY_BLOCK;
    writeFATtoDisk(fat);
}
int FAT[10000];
int main()
{
    initializeFAT(FAT);

    struct FCB root_dir;
    createFCB(&root_dir, "root", BLOCK_SIZE, EMPTY_BLOCK, '2');
    writeFCBtoDisk(root_dir);
    writeFATtoDisk(FAT);

    char command[256];
    while (1)
    {
        printf("$ ");
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "MD", 2) == 0)
        {
            char dirname[MAX_NAME_LENGTH];
            sscanf(command, "MD %s", dirname);
            createDir(dirname, &root_dir, FAT);
            printf("目录创建成功！\n");
        }
        else if (strncmp(command, "RD", 2) == 0)
        {
            char dirname[MAX_NAME_LENGTH];
            sscanf(command, "RD %s", dirname);
            deleteDir(dirname, &root_dir, FAT);
            printf("目录删除成功！\n");
        }
        else if (strncmp(command, "MK", 2) == 0)
        {
            char filename[MAX_NAME_LENGTH];
            int size;
            sscanf(command, "MK %s %d", filename, &size);
            createFile(filename, size, &root_dir, FAT);
            printf("文件创建成功！\n");
        }
        else if (strncmp(command, "DEL", 3) == 0)
        {
            char filename[MAX_NAME_LENGTH];
            sscanf(command, "DEL %s", filename);
            deleteFile(filename, &root_dir, FAT);
            printf("文件删除成功！\n");
        }
        else
        {
            printf("无效的命令！\n");
        }
    }

    return 0;
}
