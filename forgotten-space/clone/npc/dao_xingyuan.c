// clone/npc/dao_xingyuan.c
// 觀星師 星淵 - 宣道司摘星台主事

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("星淵");
    set_short(CYN "摘星台觀星師" NOR " 星淵");
    set_long("一位面色蒼白、神情冷峻的中年道官，眉心點著一顆硃砂法印。\n"
             "他身旁架設著多具青銅渾天儀與透鏡，正專注地推演周天星宿軌跡。\n");
    set_id(({ "dao_observatory_xingyuan", "xingyuan", "stargazer", "星淵", "觀星師" }));

    set_level(25);
    set_stat("int", 32);
    set_stat("spi", 30);
    recalc_stats();

    add_response(({ "考核", "轉職", "銅鏡", "鏡" }),
        "星淵打量你一番：「凡胎肉眼難窺天道。此乃【渾天黃銅鏡】，持此鏡登偏殿屋頂測候風向 (survey_wind)，記下角度再來。」");
}

int do_chat(object me, string topic) {
    if (!me || !topic || topic == "") return 0;
    if (string_in(topic, "考核, test, 銅鏡, mirror")) {
        object q_engine = load_object(QUEST_ENGINE_D);
        if (q_engine) {
            int ret = q_engine->trigger_quest_event(me, "talk", ({ "dao_observatory_xingyuan", "考核" }));
            if (!present("dao mirror", me) && !present("brass mirror", me)) {
                object mirror = clone_object("/clone/item/dao_mirror.c");
                if (mirror) {
                    mirror->move(me);
                    tell_object(me, HIG "【星淵取出一面渾天黃銅鏡鄭重交到你手中！】\n" NOR);
                }
            }
            return ret;
        }
    }
    return 0;
}
