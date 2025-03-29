/*
参考: https://murasame-labo.hatenablog.com/entry/2017/02/01/134046
メンバ関数の第一引数にthisがあると解釈していい？
std::bindは指定した関数からstd::functionを作るもの
*/
#include <iostream>
#include <functional>

struct Hoge {
    // メンバ関数callback：内部でhogeを呼び出す
    void callback(int n) {
        hoge(n);
    }
    void hoge(int n) {
        std::cout << "Hoge::hoge(" << n << ")\n";
    }
};

// コールバックを受け取る関数。std::functionを使ってコールバック関数を抽象化
void setCallback(std::function<void(int)> fn) {
    fn(5);
}

int main() {
    Hoge h;
    // std::bindでHoge::callbackとオブジェクトhを束縛
    setCallback(std::bind(&Hoge::callback, &h, std::placeholders::_1));
    return 0;
}
