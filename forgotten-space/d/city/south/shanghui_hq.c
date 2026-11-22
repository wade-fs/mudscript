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

    set_touch("default", HIY "商會總堂花梨木地板打蠟得光滑冰涼，紫檀長案擺著精緻紫砂茶具與算盤。" NOR);
    set_smell("default", YEL "高級龍涎香、名貴茶葉與總堂密賬房裡淡淡的防潮樟木香。" NOR);
    set_listen("default", WHT "外街喧囂被厚重石牆隔開，堂內只偶爾響起錢百川撥動金算盤的清冷珠聲。" NOR);

    spawn_npc("/clone/npc/south_qianbaichuan.c");
    spawn_npc("/clone/npc/shanghui_hq_steward.c");
}
