// clone/npc/yamen_prison_zhaodegui.c
// 趙德貴・前商隊二掌櫃（階下囚，yamen_prison_zhaodegui） - 府衙死牢

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("趙德貴");
    set_short(RED "死牢階下囚" NOR " 趙德貴 (前商隊二掌櫃)");
    set_long("昔日在黑石鋪趾高氣揚的金石商會二掌櫃，如今披頭散髮、手腳戴著三十斤重的玄鐵鐐銬蜷縮在死牢稻草堆裡。\n"
             "他因毒殺大掌櫃蘇遠山、私盜礦脈除渣黑釜並勾結胡百戶意圖屠村滅口，在黑石關前被陳鎮山主帥下令鎖拿押入府城死牢。\n");
    set_id(({ "yamen_prison_zhaodegui", "zhao degui", "zhaodegui", "degui", "steward zhao", "趙德貴", "趙管事" }));

    setup_archetype("H", 15);
    set("class", "mortal");
    set("faction", "shanghui");
    set("roles", ({ "quest_target", "info" }));
    set("schedule", "24h");

    add_response(({ "蘇遠山", "黑釜", "坩堝", "收貨人", "錢百川", "口供" }),
        "趙德貴雙手死死抓著牢門鐵欄，驚恐嘶聲道：「別殺我！我全招！【金石內造・丙字柒號】的紫銅除渣坩堝是從商會三號大庫秘密調出來的！北崖提純出來的地煞精錠，全都是由城下暗渠運進總堂交給錢百川副會長的心腹執事……我只是條跑腿的狗啊！」");
}
