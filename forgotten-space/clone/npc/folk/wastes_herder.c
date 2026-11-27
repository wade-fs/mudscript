// clone/npc/folk/wastes_herder.c
// 北荒老牧戶烏蘭・北荒南沿凍土牧戶避風棚（與三宗勘探線無關的普通塞外牧民） (Ch.102-119)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("老牧戶烏蘭");
    set_short(WHT "塞外牧民" NOR " 烏蘭");
    set_long("一位穿著厚重破舊生羊皮袍、臉頰被黑風凍出兩團高原紅的五十餘歲塞外老牧人。\n"
             "他祖輩就在黑山長城北門外幾里地的避風坳放牧耐寒黃羊，既不懂什麼太古方舟也不摻和宗門爭鬥，只盼今年暴雪別凍死羊群。\n");
    set_id(({ "wastes_herder", "wulan", "herder", "老牧戶烏蘭", "烏蘭", "牧戶" }));

    setup_archetype("B", 14);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "herder", "info" }));
    set("no_combat", 1);

    add_response(({ "黃羊", "走失", "羊群", "幫忙", "差事" }),
        "烏蘭焦急地搓著戴破皮手套的手道：「昨夜那陣妖風一吹，我群裡那頭領頭的獨角黃羊驚跑了，順著腳印好像逃往西邊的【黑山長城北關雪道】去！好心的行旅若是肯過去雪道那頭幫我把羊牽回來（herd goat），我送你一塊乾羊乳酪跟一百五十文錢！」");
    add_response(({ "雪原", "三宗", "世道" }),
        "烏蘭往火塘裡丟了塊乾牛糞嘆道：「南邊來的穿大袍貴人們一隊隊往北邊深谷裡鑽，把我們牧羊的草坡都壓壞了……這冬天越來越邪門。」");
}
