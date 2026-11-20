// /d/sects/taiqing/quiet_peak.c
// 太清後山・清修偏峰 (Ch.92：老松亭與簡素真人崖壁柴扉石屋)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太清後山・清修偏峰");
    set_long("紫霄殿後方人跡罕至的高寒偏峰，積雪壓低了山腰「老松亭」邊的老松枝椏。\n"
             "過了枯松往前，偏峰崖壁邊緣築著一間簡陋石屋與合攏的柴扉，苦修派長老簡素真人\n"
             "長年於此避宴清修；再往上穿過兩道雷符殿弟子把守的雲紋石門，便達頂端「升仙台」。\n"
             "西南回返【周天星律院】，往南下赴【天柱觀星台】，向北仰登上峰【升仙台石築靈堂】。\n");

    set_exits(([
        "southwest": "/d/sects/taiqing/star_law_hall.c",
        "south":     "/d/sects/taiqing/outer_observatory.c",
        "north":     "/d/sects/taiqing/ascension_platform.c",
    ]));

    set("is_outdoor", 1);
    spawn_npc("/clone/npc/jian_su.c");
    spawn_npc("/clone/npc/yuan_qing.c");
}
