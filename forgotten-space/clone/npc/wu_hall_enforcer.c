// clone/npc/wu_hall_enforcer.c
// 鐵面雷・執法教頭 (wu_hall_enforcer) - 八方武館正堂

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("鐵面雷");
    set_short(WHT "武館執法教頭" NOR " 鐵面雷");
    set_long("一位面沉似水、手持玄鐵家法軍棍的執法教頭，侍立於總教頭霸山身側，掌管武館門規與軍陣弓弩傳授。\n");
    set_id(({ "wu_hall_enforcer", "tiemian lei", "enforcer instructor", "鐵面雷", "執法教頭" }));

    setup_archetype("C", 35);
    set("class", "wu_initiate");
    set("faction", "wu");
    set("roles", ({ "trainer", "guard", "info" }));
    set("schedule", "24h");

    set_skill_to_teach("wu_cuigu", 100);
    set_skill_to_teach("wu_gong_sheshi", 100);
    set_skill_to_teach("wu_gong_yingshi", 100);

    add_response(({ "門規", "軍紀", "開弦", "重弓" }),
        "鐵面雷冷聲道：「入我八方武館，須守鐵血軍紀！持強凌弱者斷指逐出，臨陣退縮者以軍法從事！」");
}
