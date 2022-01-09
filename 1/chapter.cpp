/*
1.c++程序的模块叫什么：函数
2.#include<iostream>是做什么用的：这将导致在最终的编译之前，使用iostream的文件内容替换该编译指令
3.using namespace std是做什么用的：使得程序可以使用std命名空间内的定义
4.什么语句可以用来打印短句“Hello，world”，然后开始新的一行
    cout<<"Hello,world\n";
5.什么语句可以用来创建名为cheeses的整数数量：int cheeses;
*/

#include<iostream>
using namespace std;

int main(){
    char* name = "ljc";
    char* address = "zhongguo,neimenggu";

    cout<< name<<","<<address;
}