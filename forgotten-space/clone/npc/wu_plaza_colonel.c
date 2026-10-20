// clone/npc/wu_plaza_colonel.c
// 岳千軍・操練都尉 (wu_plaza_colonel) - 八方武館外校場

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("岳千軍");
    set_short(HIR "武館操練都尉" NOR " 岳千軍");
    set_long("一位手提熟銅霸王鞭、站在演武大校場點將台上的魁梧都尉，正督導百名武館弟子對拆演武与摔角。\n");
    set_id(({ "wu_plaza_colonel", "wu_plaza_wrestling", "yue qianjun", "colonel yue", "wrestling instructor", "岳千軍", "操練都尉", "都尉" }));

    setup_archetype("C", 30);
    set("class", "wu_initiate");
    set("faction", "wu");
    set("roles", ({ "trainer", "info" }));
    set("schedule", "day");

    set_skill_to_teach("wu_cuigu", 100);
    set_skill_to_teach("wu_fuhu", 100);
    set_skill_to_teach("wu_panshi", 100);

    add_response(({ "石鎖", "演武", "淬骨", "考核" }),
        "岳千軍指向校場中央那排重石縣特選的三百斤重玄石鎖：「力道入門第一關——雙臂發力拔起這尊三百斤石鎖 (lift_stone)！氣血浮動者趁早滾回市井喝茶！」");
}
