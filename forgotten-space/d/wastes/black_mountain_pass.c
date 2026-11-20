// /d/wastes/black_mountain_pass.c
// 黑山長城北關雪道（Ch.102 聯合勘探隊出關通道暨 EV323 獸潮防線接口）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("北荒裂谷・黑山長城北關雪道");
    set_long("黑山長城北門外彷彿將天地劈成兩半的嚴寒雪道，背後是八荒武山青黑巨石長城關牆，\n"
             "前方則連綿至終年黑風卷雪的北荒大裂谷。雪道旁立著界碑與勘探車隊車轍印；往西三百步\n"
             "雪地邊搭著幾間搖搖欲墜的草頂木棚【失蹤者家屬互助所】，正北踏入【北荒南沿入口】，\n"
             "往南穿關返回【北線長城巡防牆暨關口】。\n");

    set_exits(([
        "south": "/d/sects/bahuang/great_wall_gate.c",
        "west":  "/d/wastes/missing_families_hall.c",
        "north": "/d/wastes/south_approach.c",
    ]));

    set("is_outdoor", 1);
}
