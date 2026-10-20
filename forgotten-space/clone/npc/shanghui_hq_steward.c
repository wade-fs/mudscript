// clone/npc/shanghui_hq_steward.c
// 錢算子・商會總執事 (shanghui_hq_steward) - 金石商會總堂

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("錢算子");
    set_short(CYN "金石商會總執事" NOR " 錢算子");
    set_long("一位身穿玄色暗紋長衫、眼神陰鷲老辣的商會內堂總執事。\n"
             "他是副會長錢百川的心腹帳房，貼身保管著商會內堂重簾後的機關鎖匙，守衛通往地下天字一號密室的暗道。\n");
    set_id(({ "shanghui_hq_steward", "qian suanzi", "steward qian", "chamberlain", "錢算子", "商會總執事", "商會執事" }));

    setup_archetype("H", 30);
    set("class", "mortal");
    set("faction", "shanghui");
    set("roles", ({ "gatekeeper", "info", "quest_target" }));
    set("schedule", "24h");

    add_response(({ "天字一號", "密室", "重簾", "暗賬", "坩堝" }),
        "錢算子皮笑肉不笑地攔在重簾前：「總堂後室乃商盟元老密議重地，底下那座太古玄鐵密室更是封鎖了三十年，沒有【天門引】古令，誰也別想往下走一步！」");
}
