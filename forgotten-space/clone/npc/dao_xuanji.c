// clone/npc/dao_xuanji.c
// 宣道司道官 玄機真人 - 法道一階考核與受牒宗師

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("玄機真人");
    set_short(HIC "宣道司道官" NOR " 玄機真人");
    set_long("一位身披青白羽衣的清癯老道，雙眸深邃若萬古寒潭，周身環繞著若有若無\n"
             "的微茫靈光。他掌管金石府宣道司正堂，專司大乾度牒審定與法道入門考核。\n");
    set_id(({ "dao_hall_xuanji", "xuanji", "daoist master", "玄機真人", "真人" }));

    set_level(35);
    set_stat("int", 38);
    set_stat("spi", 40);
    set_stat("sen", 300);
    recalc_stats();

    add_response(({ "受牒", "考核", "轉職", "法道" }),
        "玄機真人淡淡道：「欲入我宣道司清虛門牆，需先明周虛微茫之理。汝可先登摘星台領取黃銅鏡，測繪西嵐氣流再來見吾。」");

    add_response(({ "大清洗", "古道", "天道" }),
        "玄機真人目光微凝，沉聲道：「天道有缺，紅塵濁氣瀰漫。我輩修行唯有借法偷天，切莫妄窺太古不可言之秘。」");
}

int do_chat(object me, string topic) {
    if (!me || !topic || topic == "") return 0;
    if (string_in(topic, "受牒, certify, 轉職")) {
        object q_engine = load_object(QUEST_ENGINE_D);
        if (q_engine) {
            return q_engine->trigger_quest_event(me, "talk", ({ "dao_hall_xuanji", "受牒" }));
        }
    }
    return 0;
}
