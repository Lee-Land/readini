//
// Created by xiamingjie on 2022/1/19.
//

#include <fstream>
#include <iostream>
#include "iniconfig.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please input config file." << endl;
        return 1;
    }

    string file(argv[1]);
    fstream input(file, ios::in);

    ini::IniConfig iniConfig;

    try {
        //解析
        iniConfig.parse(input);
    } catch (const ios_base::failure& e1) {
        cerr << e1.what() << endl;
    } catch (const ini::ErrorLog& e2) {
        cerr << e2.what() << endl;
    }

    cout << "遍历查找: " << endl;
    //遍历
    for (int i = 0; i < iniConfig.size(); i++) {
        try {
            auto parameter = iniConfig[i];
            for (const auto &p: parameter) {
                cout << p.first << "=" << p.second << endl;
            }
        } catch (const out_of_range& e) {
            cerr << e.what() << endl;
        }
    }

    cout << endl << "键值对查找: " << endl;

    //键值查找
    ini::Parameters mysql = iniConfig["MySQL"];
    string host = mysql["host"].asString();
    int port = mysql["port"].asInt();
    string user = mysql["user"].asString();
    string pwd = mysql["password"].asString();

    cout << "主机: " << host << endl;
    cout << "端口: " << port << endl;
    cout << "用户名: " << user << endl;
    cout << "密码: " << pwd << endl;

    return 0;
}