// /d/counties/panmu/timber_wharf.c
// 盤木縣 (Panmu County) 擴展生活翼：倒影澗木排下水碼頭與松脂烘房

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_short("盤木縣・木排下水碼頭");
    set_long("倒影澗東岸水流較緩的寬闊石灘，木客們在這裡將山上拖下來的冷杉原木\n"
             "削去枝椏、打孔穿藤，再用濕浸過的雙股粗棕繩與鐵箍捆紮成十丈長的木排 (raft)。\n"
             "岸邊還搭著一座冒著琥珀香氣的小松脂烘房，牆上掛滿備用竹篙與絞盤。\n"
             "向西走過卵石灘即回【倒影澗・古林界碑】。\n");

    set_exits(([
        "west": "/d/counties/panmu/daoying_stream.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);
    set_touch("default", YEL "浸水的冷杉原木表皮冰涼滑溜，粗棕繩抓在手裡又硬又粗糙、微微滲出松脂黏意。" NOR);
    set_smell("default", GRN "濃得化不開的鮮冷杉木屑味、松脂烘房的焦甜樹脂香與冰冷山澗水汽。" NOR);
    set_listen("default", CYN "木客齊聲喊著「一二、拉！」的扎排號子聲，混著原木互相碰撞的沉悶「咚咚」聲。" NOR);

    mapping lash_rule = ([
        "targets": ({ "raft", "timber", "木排", "原木", "" }),
        "sp_cost": 12,
        "sensory_msg": GRN "你踩穩濕滑的冷杉木幹，用粗麻繩繞過鐵箍連打三個死扣，將整排沉重的山林原木牢牢鎖緊！" NOR,
        "train_stat": ([ "str": 10, "con": 8 ]),
        "exp_gain": 14,
        "quest_verb": "lash",
        "quest_target": "raft"
    ]);
    add_action_rule("lash", lash_rule);
    add_action_rule("綁排", lash_rule);

    spawn_npc("/clone/npc/folk/panmu_raftsman.c");
}
