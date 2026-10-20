// clone/npc/gong_ouyang.c
// 府城百工總會匠首 歐陽大師 (gong_hall_ouyang) - 物道一階考核與受牒宗師

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("歐陽大師");
    set_short(HIY "百工總會匠首" NOR " 歐陽大師");
    set_long("一位鬚髮斑白的老匠人，手指粗短佈滿燙疤與老繭，但目光銳利如尺規。\n"
             "他身著鹿皮圍裙，腰間插著精銅游標尺與墨斗，掌理天下百工圖譜與正式匠籍。\n");
    set_id(({ "gong_hall_ouyang", "ouyang", "ouyang dashi", "master smith", "歐陽大師", "匠首" }));

    setup_archetype("E", 50);
    set("class", "gong_initiate");
    set("faction", "gong");
    set("roles", ({ "trainer", "quest_giver", "quest_target" }));
    set("schedule", "24h");

    set_skill_to_teach("gong_analysis", 100);
    set_skill_to_teach("gong_qiaojin", 100);
    set_skill_to_teach("gong_yingli", 100);
    set_skill_to_teach("gong_jiguan", 100);

    add_response(({ "考核", "轉職", "物道", "百工" }),
        "歐陽大師敲了敲煙袋鍋：「萬物皆有理，金石木皮各有筋骨應力。去地爐坊找莫錘辨材，再去木作大棚敲榫，合格了再來登籍！」");

    add_response(({ "匠籍", "烏木尺", "登記" }),
        "歐陽大師微笑道：「天生不足，巧具補之。天下萬物皆可為用，這柄天工烏木尺予你，莫要辱沒了百工之名。」");
}

int do_chat(object me, string topic) {
    if (!me || !topic || topic == "") return 0;
    if (string_in(topic, "匠籍, registry, 轉職")) {
        object q_engine = load_object(QUEST_ENGINE_D);
        if (q_engine) {
            return q_engine->trigger_quest_event(me, "talk", ({ "gong_hall_ouyang", "匠籍" }));
        }
    }
    return 0;
}
