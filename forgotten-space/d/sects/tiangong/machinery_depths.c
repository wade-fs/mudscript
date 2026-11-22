// /d/sects/tiangong/machinery_depths.c
// 天工閣・萬機地窟 (Ch.95：十丈巨靈神機、黑鐵齒輪磁吸共鳴與赤煉強裝衝突)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("天工閣・萬機地窟");
    set_long("穿過數重包鐵石門與青銅閘門，來到地下二十丈被掏空的數十丈巨型岩石穹窟。\n"
             "地肺深處傳來低沉嗡鳴，中央玄鐵底座上赫然半跪矗立著十丈高的天工鎮山重器【巨靈神機】\n"
             "——左臂足有兩間屋粗，胸腔維修鐵門敞開著，旁邊搭起臨時三層木質腳手架（指令：inspect core）。\n"
             "值守匠師季衡手抱《地窟安全閘巡檢簿》守於台前，長老赤煉眼神狂熱地盯著主軸動力槽。\n"
             "向上沿斜行石道可返【地火鍛兵台】，向東則是封存異質能源的【萬機四號庫房】，北面緊閉之\n"
             "玄鐵暗門與東北上方檢修井暗道分連【黑山長城西段缺口】暨【問道天台救援邊緣】。\n");

    set_exits(([
        "up":      "/d/sects/tiangong/forge_yard.c",
        "east":    "/d/sects/tiangong/vault_four.c",
        "north":   "/d/sects/bahuang/west_wall_breach.c",
        "northup": "/d/yunjin/crystal_poison_edge.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", HIB "十丈巨靈神機的不融黑鐵底座冷硬如玄冰，木質腳手架卻被地底氣流烘得微溫。" NOR);
    set_smell("default", YEL "地下穹窟特有的陳年機油味、冷鐵氣息與一絲令人不安的暗紅晶塵焦味。" NOR);
    set_listen("default", HIR "地肺深處傳來巨型軸承緩慢轉動般的低沉嗡鳴，震得腳下玄鐵底座微微發麻。" NOR);

    spawn_npc("/clone/npc/ji_heng.c");
    spawn_npc("/clone/npc/chi_lian.c");
}

void init() {
    ::init();
    add_action("do_inspect", "inspect");
    add_action("do_install", "install");
}

int do_install(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "rig" && arg != "feedback" && arg != "連動台" && arg != "回授台") {
        notify_fail("你想改裝什麼機械結構？試試：install rig\n");
        return 0;
    }
    message_vision(HIY "$N牢記『人使錘子、錘子不能反過來使喚人』之訓，當眾拒絕將本命神識接入七根太古神經導線！\n"
                       "以【太古不融黑鐵齒輪】翻砂鍛成複合合金副軸，裝妥『三段式可拆卸機械力回授連動台』與三個\n"
                       "可隨時拔掉卡榫輪換的標準操作席，不用一克血精令十丈巨靈神機誤差不超半厘平穩行出軍禮！\n" NOR, me);
    if (!present("detachable_feedback_spec", me)) {
        object ob = clone_object("/clone/item/detachable_feedback_spec.c");
        if (ob) {
            ob->move(me);
            tell_object(me, HIY "你獲發並封存《三段式可拆卸機械力回授連動台圖紙》。\n" NOR);
        }
    }
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "install", "target": "rig" ]));
    }
    return 1;
}

int do_inspect(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "core" && arg != "shaft" && arg != "神機" && arg != "主軸") {
        notify_fail("你想檢修什麼？試試：inspect core\n");
        return 0;
    }
    message_vision("$N爬上木架靠近「巨靈神機」敞開的胸腔大軸，立時感應到腰間太古不融黑鐵\n"
                   "齒輪發出劇烈磁吸共鳴！借礦燈細察，次級銅管內壁亦佈滿接觸高能暗紅晶柱後\n"
                   "殘留的「脆化麻點」，並伴隨每月三次不明規律脈衝震顫。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "inspect", "target": "core" ]));
    }
    return 1;
}
