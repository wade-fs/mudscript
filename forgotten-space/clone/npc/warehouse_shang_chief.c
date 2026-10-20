// clone/npc/warehouse_shang_chief.c
// 丁鐵鎖・商會大庫庫頭 (warehouse_shang_chief) - 商會一至三號大庫

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("丁鐵鎖");
    set_short(WHT "商會大庫庫頭" NOR " 丁鐵鎖");
    set_long("一位腰挎銅鎖與皮鞭、牽著兩頭兇悍巡夜惡犬的精壯庫頭，看守著商會一至三號大庫。\n");
    set_id(({ "warehouse_shang_chief", "ding tiesuo", "warehouse chief", "丁鐵鎖", "大庫庫頭", "庫頭" }));

    setup_archetype("K", 20);
    set("class", "mortal");
    set("faction", "shanghui");
    set("roles", ({ "guard", "info", "quest_target" }));
    set("schedule", "24h");

    add_response(({ "密箱", "三號庫", "走私", "巡夜犬", "大庫" }),
        "丁鐵鎖緊了緊手裡的狗鏈，冷冷道：「一號庫存青河藥，二號庫存盤木料，至於最裡頭上著雙重鐵鎖的三號暗庫……那是錢副會長親自過問的私貨，閒人少打聽！」");
}
