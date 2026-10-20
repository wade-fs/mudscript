// clone/npc/wu_bashan.c
// 八方武館總教頭 霸山 - 力道一階考核與受牌宗師

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("霸山");
    set_short(HIR "八方武館總教頭" NOR " 霸山");
    set_long("一位身高近八尺、虎背熊腰的雄壯漢子，胸膛袒露，肌腱若青銅澆鑄。\n"
             "他曾隨軍征戰北天風塞，一身純陽氣血如烘爐滾燙，眼神如電，令人望而生畏。\n");
    set_id(({ "wu_hall_bashan", "bashan", "chief instructor", "霸山", "總教頭" }));

    set_level(40);
    set_stat("str", 45);
    set_stat("con", 42);
    set_stat("kee", 800);
    recalc_stats();

    add_response(({ "考核", "轉職", "力道", "武道" }),
        "霸山抱臂狂笑：「想入我八方武館？玄門那些虛頭巴腦的引氣法門在此一文不值！先去校場拔起重石鎖，再上擂台受趙教頭三記重拳！」");

    add_response(({ "受牌", "腰牌", "立誓" }),
        "霸山打量你的骨架氣血，點頭如雷：「好漢子！簽下軍令生死狀，這條黑鐵腰牌束帶就是你的了！」");
}

int do_chat(object me, string topic) {
    if (!me || !topic || topic == "") return 0;
    if (string_in(topic, "受牌, pledge, 轉職")) {
        object q_engine = load_object(QUEST_ENGINE_D);
        if (q_engine) {
            return q_engine->trigger_quest_event(me, "talk", ({ "wu_hall_bashan", "受牌" }));
        }
    }
    return 0;
}
