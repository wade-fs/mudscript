// clone/npc/inn_main_qianbuhuan.c
// 錢不換・大掌櫃 (inn_main_qianbuhuan) - 金石大客棧（金石商會眼線）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("錢不換");
    set_short(HIY "金石大客棧掌櫃" NOR " 錢不換");
    set_long("一位身穿團花錦袍、滿面春風卻眼神滴溜亂轉的富態掌櫃。\n"
             "他是金石商會副會長錢百川的同族堂弟，明面上打理這座三層雕樑石樓大客棧，\n"
             "暗地裡卻是錢百川安插在內城十字樞紐的重要眼線，專一刺探外埠客商與各路修士的底細。\n");
    set_id(({ "inn_main_qianbuhuan", "qianbuhuan", "qian buhuan", "innkeeper qian", "錢不換", "大掌櫃" }));

    setup_archetype("H", 20);
    set("class", "mortal");
    set("faction", "shanghui");
    set("roles", ({ "shop", "info", "broker" }));
    set("schedule", "24h");

    add_response(({ "住宿", "客棧", "打尖", "外埠", "消息" }),
        "錢不換笑瞇瞇地拱手：「客官裡邊請！咱這金石大客棧可是府城頭一號的金字招牌，六縣來的豪商與宣道司、百工總會的貴客都在樓上雅間歇腳呢！」");

    add_response(({ "錢百川", "商會", "蘇凝霜", "眼線" }),
        "錢不換眼神閃爍了一下，乾笑道：「商會副會長正是家兄，蘇老掌櫃在南嶺出了事，家兄也是日夜操勞啊……客官若是見著蘇家大小姐，還請通傳一聲。」");
}
