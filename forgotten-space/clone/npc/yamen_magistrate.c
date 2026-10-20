// clone/npc/yamen_magistrate.c
// 秦正明・金石府尹 (yamen_magistrate) - 金石府衙正堂

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("秦正明");
    set_short(HIY "金石府尹" NOR " 秦正明");
    set_long("一位身著四品緋紅官袍、面容威嚴深沉的中年大員，端坐於府衙正堂明鏡高懸牌匾之下。\n"
             "在大乾皇權式微的邊境時代，他周旋於宣道司、八方武館、百工總會與金石商會四大勢力之間，\n"
             "以務實手腕維持金石府城與六大外縣的世俗秩序。\n");
    set_id(({ "yamen_magistrate", "qin zhengming", "magistrate qin", "magistrate", "秦正明", "金石府尹", "府尹" }));

    setup_archetype("A", 35);
    set("class", "mortal");
    set("faction", "yamen");
    set("roles", ({ "quest_giver", "info" }));
    set("schedule", "day");

    add_response(({ "共治", "秩序", "三日通牒", "金石府" }),
        "秦正明緩緩撫過驚堂木：「金石府城聚居百萬生民，外有大荒煞潮，內有紅塵萬丈。本府與三司商盟共立『三日通牒』與『絕靈法網』，皆為保一城生計不墜。」");

    add_response(({ "黑石鋪", "會審", "趙德貴", "胡百戶" }),
        "秦正明目光微冷：「黑石鋪礦難與走私軍火一案牽連甚廣，趙德貴與胡百戶已收押死牢。若有人能從死牢口供與商會底帳中查出幕後收貨真兇，本府必秉公重賞！」");
}
