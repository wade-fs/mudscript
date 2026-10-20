// clone/npc/gong_mochui.c
// 千錘地爐坊大師 莫錘 (gong_forge_mochui)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("莫錘");
    set_short(HIR "鍛造大師" NOR " 莫錘");
    set_long("一位上身精赤、揮舞著六十斤精鋼重錘的赤面壯漢。\n"
             "地爐烈火熊熊倒映在他眼中，身後堆疊著來自烈礬縣的粗銅錠與重石縣生鐵。\n");
    set_id(({ "gong_forge_mochui", "mochui", "mo chui", "blacksmith", "莫錘", "莫大師", "鍛造大師" }));

    setup_archetype("E", 40);
    set("class", "gong_initiate");
    set("faction", "gong");
    set("roles", ({ "trainer", "quest_target" }));
    set("schedule", "24h");

    set_skill_to_teach("gong_analysis", 100);
    set_skill_to_teach("gong_qiaojin", 100);
    set_skill_to_teach("gong_yingli", 100);
    set_skill_to_teach("gong_cuihuo", 100);

    add_response(({ "辨材", "摸骨", "考核", "礦石", "鍛造" }),
        "莫錘粗聲道：「閉上眼睛摸！用心感受烈礬赤銅的滑膩與重玄鐵礦的沉澀！能盲辨生鐵核，方具開爐鍛造之基。」");
}

int do_chat(object me, string topic) {
    if (!me || !topic || topic == "") return 0;
    if (string_in(topic, "辨材, identify, 考核, test")) {
        object q_engine = load_object(QUEST_ENGINE_D);
        if (q_engine) {
            return q_engine->trigger_quest_event(me, "talk", ({ "gong_forge_mochui", "辨材" }));
        }
    }
    return 0;
}
