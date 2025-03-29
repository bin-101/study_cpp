// 参考: https://murasame-labo.hatenablog.com/entry/2017/02/01/134046
#include <iostream>
#include <functional>

void hoge(int a, int b) {
    std::cout << "arg1=" << a << "   arg2=" << b << "\n";
}

int main() {
    // 第一引数を2に固定。std::bindでは最初のパラメータを_placeholders::_1が1番目の引数に対応する
    auto fn1 = std::bind(hoge, 2, std::placeholders::_1);
    
    // 引数の順番を逆にする（1番目の引数が2番目に、2番目の引数が1番目に渡される）
    auto fn2 = std::bind(hoge, std::placeholders::_2, std::placeholders::_1);
    
    fn1(5);   // 出力: arg1=2   arg2=5
    fn2(1,2); // 出力: arg1=2   arg2=1
    
    return 0;
}
