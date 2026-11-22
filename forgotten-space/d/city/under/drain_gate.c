// d/city/under/drain_gate.c
// 城下暗渠・廢棄水閘

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城下暗渠・廢棄水閘");
    set_long("此處是一道早已鏽蝕死鎖的太古鑄鐵千斤水閘。\n"
             "渾濁的暗河水流自鐵柵孔隙間狂暴宣洩而出，直通城外護城河深水區盲道。\n"
             "岩壁上刻滿了走私水鬼留下的暗記與抓痕。\n"
             "向東踏著濕滑石階可退回古暗渠水網樞紐。\n");

    set_exits(([
        "east": "/d/city/under/canal_hub.c",
        "up":   "/d/city/wall/moat.c",
    ]));

    set("is_underground", 1);

    set_touch("default", HIB "閘門粗鐵鍊冰冷滑膩、爬滿水藻，踩在半浸水的石階上寒意直刺腳心。" NOR);
    set_smell("default", MAG "濃烈發酵的城市暗渠淤泥臭氣與鐵鏽潮味，令人忍不住掩鼻。" NOR);
    set_listen("default", CYN "污水穿過生鏽閘門鐵柵發出的嘩啦湍流聲在陰暗水道裡迴盪不絕。" NOR);

    spawn_npc("/clone/npc/under_drain_gate_diver.c");
}
