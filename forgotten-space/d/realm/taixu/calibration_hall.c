// /d/realm/taixu/calibration_hall.c
// 太虛神宮・三百年天羅校準偏殿 (Ch.157-158 柳清虛偏星一度半決戰點)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太虛神宮・三百年校準偏殿");
    set_long("空曠高聳的白玉圓頂偏殿，地面刻滿對準凡間二十八宿天羅座標的銀線幾何網。\n"
             "中央立著主校準導流陣柱，陣柱底座留著四道可供嵌入黑鐵分流針的微細夾角槽；\n"
             "校準夜子時脈衝垂落之際，須趁亂插針偏轉主陣脈一度半（insert needle）。\n"
             "向南下行（southdown）返【白玉升空階座】，向北走入【靜謐玉化晶核塔】。\n");

    set_exits(([
        "southdown" : "/d/realm/taixu/white_jade_steps.c",
        "north"     : "/d/realm/taixu/crystal_tower_core.c",
    ]));
    set("is_outdoor", 0);

    set_touch("default", HIB "銀線陣槽周圍寒氣刺骨，指尖逼近時能感應到強烈的張力切線拉扯。" NOR);
    set_smell("default", HIW "純淨卻令人窒息的寒玉粉氣味，隱約混著一絲電弧燒灼銅針的焦痕。" NOR);
    set_listen("default", CYN "殿頂銅星盤緩慢轉動時發出沉穩卻冰冷的齒輪扣合聲，像無數沙漏同步倒數。" NOR);
}

void init() {
    ::init();
    add_action("do_insert", "insert");
}

int do_insert(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "needle" && arg != "針" && arg != "分流針") {
        notify_fail("你要插入什麼？試試：insert needle\n");
        return 0;
    }

    tell_object(me, HIY "你頂住主陣脈狂暴威壓，將四枚黑鐵分流針沿著幾何切角精準嵌入主陣柱底座！\n" NOR);
    tell_object(me, HIC
        "【北塔偏星一度半核心角位（EV416）】\n"
        "萬丈紫黑校準脈衝受分流針與向量牽引微撥偏折『一度半』，擦過石堡與凡間雲頂座標轟入\n"
        "萬里外無人玄武岩空域！高塔承受反震強制停擺，主簿嚴平私挪假帳亦當殿敗露！\n" NOR);
    say(me->query_name() + " 沿殿柱陰影嵌入黑鐵分流針，強行將主校準陣脈偏折一度半！\n");

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "insert", "target": "needle" ]));
    }
    return 1;
}
