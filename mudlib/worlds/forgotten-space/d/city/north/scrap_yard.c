// d/city/north/scrap_yard.c
// 百工坊外・官造廢鐵回爐區（Tier 1 城北工匠日常支翼：分揀殘件、熔渣冷卻與學徒補貼）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("百工坊外・官造廢鐵回爐區");
    set_long("百工坊北側圍牆外一處露天砂石大場，堆成了數座冒著餘溫的黑褐色鐵渣與報廢零件小山。\n"
             "鍛壞的軸承、炸裂的生鐵坩堝片、斷裂的礦鎬頭與生鏽鉚釘在此按材質分類堆放，等著重新回爐。\n"
             "幾名學徒戴著牛皮手套拿磁鐵與短鐵鉤在渣堆裡翻撿尚能改鍛農具的好鋼料。\n"
             "往南穿過鐵柵門即回熱浪滾滾的【百工坊・鍛造區】。\n");

    set_exits(([
        "south": "/d/city/north/gong_forge.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", RED "剛從爐裡清出的鐵渣堆依然微微燙手，指尖能摸出脆生鐵斷口與好熟鐵斷面的明顯差異。" NOR);
    set_smell("default", YEL "冷卻後的焦炭灰味、鐵鏽氧化的腥氣與微弱焦油潤滑劑味道混雜在空氣裡。" NOR);
    set_listen("default", WHT "長鐵鉤翻動金屬廢料發出嘩啦刺耳的摩擦聲，背景裡是南邊鍛造區從不停歇的重錘悶響。" NOR);

    mapping sort_rule = ([
        "targets": ({ "scrap", "iron", "廢鐵", "鐵渣", "" }),
        "sp_cost": 10,
        "sensory_msg": WHT "你戴好粗麻護手拿鐵鉤在渣堆裡耐心翻檢，憑手掂分量與斷面晶粒分出三大塊回爐熟鐵胚，省了坊裡不少新礦。" NOR,
        "train_stat": ([ "per": 10, "str": 8 ]),
        "exp_gain": 12,
        "quest_verb": "sort",
        "quest_target": "scrap"
    ]);
    add_action_rule("sort", sort_rule);
    add_action_rule("分揀", sort_rule);

    spawn_npc("/clone/npc/folk/county_worker.c");
}
