// clone/npc/gong_leather_wenniangzi.c
// 溫娘子・鞣皮名匠 (gong_leather_wenniangzi) - 百鞣皮甲坊

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("溫娘子");
    set_short(MAG "百鞣皮甲坊名匠" NOR " 溫娘子");
    set_long("一位挽著高髻、腰繫牛皮工具袋的幹練婦人，雙手靈巧地穿引著浸油生牛筋線。\n"
             "她能將盤木縣的韌生筋與鎮風縣的荒獸厚皮縫製成刀箭難傷的戰陣硬甲與避風革囊。\n");
    set_id(({ "gong_leather_wenniangzi", "wenniangzi", "wen niangzi", "tanner wen", "溫娘子", "鞣皮名匠" }));

    setup_archetype("E", 28);
    set("class", "gong_initiate");
    set("faction", "gong");
    set("roles", ({ "shop", "trainer", "info" }));
    set("schedule", "day");

    set_skill_to_teach("gong_analysis", 100);
    set_skill_to_teach("gong_qiaojin", 100);

    add_response(({ "皮甲", "鞣皮", "生筋", "獸皮", "馬具" }),
        "溫娘子飛針走線頭也不抬：「鎮風縣獵來的荒原狼皮要經明礬水浸泡七日，再以盤木縣的生鹿筋雙線密縫，做成內襯軟甲，比笨重鐵甲輕便三倍！」");
}
