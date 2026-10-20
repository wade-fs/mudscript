// clone/npc/wall_tower_s_archerymaster.c
// 百步楊・弓兵教頭 (wall_tower_s_archerymaster) - 南城哨樓

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("百步楊");
    set_short(HIW "南城弓兵教頭" NOR " 百步楊");
    set_long("一位手指套著白玉扳指、背負鎮風硬弓的城防教頭。\n"
             "他坐鎮南城哨樓重型床弩陣地，精通軍陣開弦重射之術。\n");
    set_id(({ "wall_tower_s_archerymaster", "baibuyang", "bai bu yang", "archery master", "百步楊", "弓兵教頭" }));

    setup_archetype("D", 25);
    set("class", "wu_initiate");
    set("faction", "wu");
    set("roles", ({ "trainer", "guard", "info" }));
    set("schedule", "day");

    set_skill_to_teach("wu_cuigu", 100);
    set_skill_to_teach("wu_gong_sheshi", 100);
    set_skill_to_teach("wu_gong_yingshi", 100);

    add_response(({ "重弓", "開弦", "床弩", "箭術" }),
        "百步楊拍了拍身側的絞盤床弩：「軍陣開弦講究腰馬合一、氣血貫指！拉不開鎮風縣的百斤鐵胎弓，怎麼射穿大荒異獸的鐵骨鱗甲？」");
}
