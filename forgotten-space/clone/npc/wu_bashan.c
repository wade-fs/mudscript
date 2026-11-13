// clone/npc/wu_bashan.c
// 八方武館總教頭 霸山 (wu_hall_bashan) - 力道一階考核與受牌宗師

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("霸山");
    set_short(HIR "八方武館總教頭" NOR " 霸山");
    set_long("一位身高近八尺、虎背熊腰的雄壯漢子，胸膛袒露，肌腱若青銅澆鑄。\n"
             "他曾隨軍征戰北天風塞，一身純陽氣血如烘爐滾燙，眼神如電，令人望而生畏。\n");
    set_id(({ "wu_hall_bashan", "bashan", "ba shan", "chief instructor", "霸山", "總教頭" }));

    setup_archetype("C", 50);
    set("class", "wu_initiate");
    set("faction", "wu");
    set("roles", ({ "trainer", "quest_giver", "quest_target" }));
    set("schedule", "24h");

    set_skill_to_teach("wu_cuigu", 100);
    set_skill_to_teach("wu_fuhu", 100);
    set_skill_to_teach("wu_kaishan", 100);
    set_skill_to_teach("wu_qixue", 100);

    add_response(({ "考核", "轉職", "力道", "武道" }),
        "霸山抱臂狂笑：「想入我八方武館？玄門那些虛頭巴腦的引氣法門在此一文不值！先去校場拔起重石鎖，再上擂台受趙教頭三記重拳！」");

    add_response(({ "受牌", "腰牌", "立誓" }),
        "霸山打量你的骨架氣血，點頭如雷：「好漢子！簽下軍令生死狀，這條黑鐵腰牌束帶就是你的了！」");

    add_response(({ "盤石", "初試", "鏢師帖", "四百斤" }),
        "霸山重重拍在你的肩頭，讚賞道：「好沉穩的盤石身法！單臂抗起四百斤重石步履不搖，下盤如老樹盤根！這面【八方鏢師總帖】非你莫屬，往後走遍大荒六縣，無人敢小覷！」");

    add_response(({ "走山令", "燕山", "殘牌", "舊檔" }),
        "霸山將軍撫摸著殘牌上的鷹翎箭記，虎目含悲：「這是燕老弟的親筆翎刻！五年前商會內堂重金買走北崖水文圖……這幫吸血的蛀蟲，燕兄弟若遭不測，老夫定親提長刀踏碎商會總堂！」");
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
