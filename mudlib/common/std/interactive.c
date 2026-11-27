// std/interactive.c - 互動功能基底類別 (Mixin)
// 提供物件註冊動作指令的能力

void init() {
    // 子類別在此呼叫 add_action
}

void register_action(string func, string verb) {
    add_action(func, verb);
}
