// clone/npc/gong_alchemy_sunxiansheng.c
// 孫先生・藥坊管事 (gong_alchemy_sunxiansheng) - 丹丸物性坊

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("孫先生");
    set_short(HIG "百草藥坊管事" NOR " 孫先生");
    set_long("一位戴著細麻口罩、手執銅藥秤的中年藥師，正仔細核驗成批運入的洗靈草與毒囊。\n"
             "他主持百工總會的丹丸物性坊，專責將青河縣靈草與濁水縣異獸毒囊提純萃取為官制金創藥與解毒散。\n");
    set_id(({ "gong_alchemy_sunxiansheng", "sunxiansheng", "sun xiansheng", "alchemist sun", "孫先生", "藥坊管事" }));

    setup_archetype("F", 25);
    set("class", "gong_initiate");
    set("faction", "gong");
    set("roles", ({ "trainer", "shop", "info" }));
    set("schedule", "day");

    set_skill_to_teach("gong_analysis", 100);
    set_skill_to_teach("gong_xingzhen", 100);
    set_skill_to_teach("gong_fengdu", 100);

    add_response(({ "金創藥", "解毒散", "萃取", "青河", "毒囊" }),
        "孫先生端詳著瓷瓶道：「药毒同源，全在份量與火候。青河縣的洗靈草能固本培元，而濁水縣的黑水蟾毒若以明礬中和七分，便是破除血煞的奇藥！」");
}
