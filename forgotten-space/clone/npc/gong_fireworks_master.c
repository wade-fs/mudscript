// clone/npc/gong_fireworks_master.c
// 焦烈・火藥督造官 (gong_fireworks_master) - 烈性火硝坊

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("焦烈");
    set_short(HIR "火藥督造官" NOR " 焦烈");
    set_long("一位眉毛被硝煙燎去半截、神色高度戒備的百工火器匠師。\n"
             "他受府衙兵備道與百工總會雙重委派，嚴密監管烈礬縣運來的硝石與硫磺配比，以及軍器局制式火雷管批號。\n");
    set_id(({ "gong_fireworks_master", "jiao lie", "jiaolie", "fireworks master", "焦烈", "火藥督造官", "督造官" }));

    setup_archetype("E", 30);
    set("class", "gong_initiate");
    set("faction", "gong");
    set("roles", ({ "guard", "info", "quest_target" }));
    set("schedule", "24h");

    add_response(({ "火藥", "硝石", "硫磺", "雷管", "黑石鋪" }),
        "焦烈沉下臉道：「硝火作乃官禁重地！每一批出庫的開山雷管皆烙有百工總會與兵備道雙重暗印——前陣子黑石關巡檢司申領的那批雷管竟流入私礦，兵備道正嚴查底冊！」");
}
