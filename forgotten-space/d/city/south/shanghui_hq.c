// d/city/south/shanghui_hq.c
// 金石商會總堂 (錢百川副會長、天字一號密室入口線索)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石商會・總堂");
    set_long("整座大殿以珍稀黃花梨木與青田玉石裝點，豪富大氣，彰顯巨賈底蘊。\n"
             "正堂太師椅上端坐著商會副會長錢百川，兩側數名賬房執事手捧紫檀算盤正清點銀票。\n"
             "堂後重簾深鎖，傳聞藏有通往城下史前太古遺蹟的【天字一號密室】入口。\n"
             "向東走出商會大門，即可回到六縣專材長街。\n");

    set_exits(([
        "east": "/d/city/south/market_special.c",
        "down": "/d/city/under/shang_secret.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/south_qianbaichuan.c");
    spawn_npc("/clone/npc/shanghui_hq_steward.c");
}
