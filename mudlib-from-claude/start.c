// mudlib/start.c
// 告訴編譯器：我要繼承 room.c 的所有變數和方法！
inherit "/std/room.c";

void create() {
    // 呼叫父類別的 create() 進行基本初始化
    ::create(); 
    
    // 覆寫（Override）這個房間特有的屬性
    set_short(" MudScript 起點站");
    set_long("你站在一個閃耀著程式碼光芒的神秘房間裡。\n" + 
             "空氣中飄浮著 {} 和 [] 的符號。\n");
}

void init() {
    // 當玩家進入房間時，給他一個特殊的測試指令
    add_action("do_jump", "jump");
}

int do_jump(string arg) {
    write("你高興地在這個起點站跳了起來！\n");
    return 1;
}
