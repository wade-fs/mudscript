// d/city/west/dao_roof.c
// 宣道司・偏殿屋頂 (測風窗口、法道考核第2階段)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("宣道司・偏殿屋頂");
    set_long("此處高踞於宣道司西側偏殿的琉璃青瓦屋脊之上。\n"
             "西面正對著青河上游峽谷風口，山嵐氣流自西向東獵獵灌入。\n"
             "凡人肉眼只覺微風拂面，唯有持【渾天黃銅鏡】凝神測繪 (survey_wind/測風)，\n"
             "方能藉由光線折射看清微茫靈機的風向夾角。\n"
             "向下 (down) 順石級可退回摘星觀象台。\n");

    set_exits(([
        "down": "/d/city/west/dao_observatory.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", CYN "琉璃青瓦屋脊被西來山嵐吹得冰涼光滑，踩上去須時刻留神腳下穩妥。" NOR);
    set_smell("default", HIC "來自青河上游峽谷的純淨草木山風直灌入懷，絲毫不見城中煙火濁氣。" NOR);
    set_listen("default", HIC "屋脊上長風獵獵呼嘯，偶爾傳來檐角銅鈴清脆而孤冷的叮噹一響。" NOR);
}

void init() {
    ::init();
    add_action("do_survey", "survey_wind");
    add_action("do_survey", "測風");
}

int do_survey(string arg) {
    object me = this_player();
    object mirror = present("dao mirror", me);
    if (!mirror) mirror = present("brass mirror", me);
    if (!mirror) {
        write("你手中缺少觀象測風必備的【渾天黃銅鏡】！\n");
        return 1;
    }

    write(CYN "你登上琉璃青瓦屋脊最高處，雙手平舉渾天黃銅鏡對準西南側山嵐風口...\n" NOR);
    write(HIY "黃銅鏡背的周天星度環軌微微轉動，鏡面上清晰映出青河水汽與天風交匯的三分夾角！\n" NOR);
    write(HIG "【你已將都城西側山嵐氣流軌跡悉數記於心神！】\n" NOR);

    object q_engine = load_object(QUEST_ENGINE_D);
    if (q_engine) {
        q_engine->trigger_event(me, "action", ([
            "verb": "survey_wind"
        ]));
    }
    return 1;
}
