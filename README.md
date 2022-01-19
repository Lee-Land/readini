# IniConfig
*.ini文件解析工具

## 运行测试
```shell
mkdir build && cd build
cmake .. && make
./readini filepath
```
## 使用方法
> test.ini内容

```ini
; MySQL配置
[MySQL]
host=127.0.0.1
port=3306
user=root
password=123456
```
> 在你的项目中引入iniconfig.h头文件
```c++
#include <iostream>
#include <fstream>
#include "iniconfig.h"

using namespace std;

int main() {
    string file("file.ini");
    fstream input(file, ios::in);
    
    Ini::IniConfig iniConfig;
    
    try {
        //解析
        iniConfig.parse(input);
    } catch (const ios_base::failure& e1) {
        cerr << e1.what() << endl;
    } catch (const Ini::ErrorLog& e2) {
        cerr << e2.what() << endl;
    }
    
    Ini::Parameters mysql = iniConfig["MySQL"];
    string host = mysql["host"];
    string port = mysql["port"];
    string user = mysql["user"];
    string pwd = mysql["password"];
    
    cout << "主机: " << host << endl;
    cout << "端口: " << port << endl;
    cout << "用户名: " << user << endl;
    cout << "密码: " << pwd << endl;
    return 0;
}
```