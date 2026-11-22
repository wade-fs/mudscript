// /d/realm/edge/ash_watch_post.c
// 第四卷 Act 1：灰燼石堡・守夜寨 (Ch.127, 128, 132, 134)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("灰燼石堡・守夜寨");
    set_long("半嵌在玄武岩溝壑裡的矮石窯聚落，牆外架著削尖獸骨拒馬，兩盞防風油燈在牆口微晃。\n"
             "牆角擺著粗石鐵砧、卡尺與幾具鎖死銅箍的報廢蓄能石匣；守夜長老戚老頭正警惕巡視。\n"
             "初入石堡須先熄滅外燈避開巡檢機隼（douse lamps），亦可實測洞天法則阻尼（test damping），\n"
             "或動手將報廢石匣改造成省料換芯暖爐（forge stove）。\n"
             "向南上坡返玄武岩風道，向東下溝為【星塵鹽田】，向西穿石門為【邊緣醫棚】。\n");

    set_exits(([
        "south" : "/d/realm/edge/basalt_ridge.c",
        "east"  : "/d/realm/edge/stardust_salt_flats.c",
        "west"  : "/d/realm/edge/edge_clinic.c",
    ]));
    set("is_outdoor", 0);

    set_touch("default", YEL "石案與矮牆抹滿防風焦油與黑炭灰，鐵砧角落擺著一塊溫熱的可拆換活榫樣品。" NOR);
    set_smell("default", WHT "苦苔燃煙、陳年焦油、粗鹽濕氣與熟鐵退火時的淡淡金屬焦味混成一氣。" NOR);
    set_listen("default", HIG "石窯內偶爾爆出鹽晶暖爐的輕微噼啪聲，外牆總能聽見鐵弩上弦與低聲咳嗽。" NOR);

    spawn_npc("/clone/npc/ash_warden_qi.c");
}

void init() {
    ::init();
    add_action("do_douse", "douse");
    add_action("do_test_damping", "test");
    add_action("do_forge_stove", "forge");
}

int do_douse(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "lamps" && arg != "lamp" && arg != "燈") {
        notify_fail("你要熄滅什麼？試試：douse lamps\n");
        return 0;
    }
    tell_object(me, "你依戚老頭喝令迅速拍熄牆外兩盞防風油燈，收斂身上兵器與靈機波動退入石階地窯。\n");
    say(me->query_name() + " 迅速拍熄牆外兩盞防風油燈，隱入石階地窯陰影。\n");
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "douse", "target": "lamps" ]));
    }
    return 1;
}

int do_test_damping(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "damping" && arg != "阻尼" && arg != "skill") {
        notify_fail("你想測試什麼？試試：test damping\n");
        return 0;
    }
    object t3 = load_object(TIER3_D);
    int eff_cost = t3 ? t3->query_effective_skill_cost(me, "fa", 20) : 60;
    int eff_pct = t3 ? t3->query_effective_power_pct(me, "fa") : 50;
    tell_object(me, sprintf(HIR
        "【洞天空間阻尼實測】\n"
        "你嘗試運轉凡間舊招——此間無二十八宿中繼且幾何張力極重，基礎消耗瞬間飆升至 %d（3倍基準 20），\n"
        "而實際打出威力僅剩 %d%%！唯有建立 K 認知並重塑 U 運用，方能破除此地高耗鐵律。\n" NOR,
        eff_cost, eff_pct));
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "test", "target": "damping" ]));
    }
    return 1;
}

int do_forge_stove(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "stove" && arg != "暖爐" && arg != "core") {
        notify_fail("你想改鑄什麼？試試：forge stove\n");
        return 0;
    }
    tell_object(me, HIY "你架起精鋼卡尺尋得報廢石匣的偏心退刀縫，不毀銅膽而用粗鐵改出雙向活榫換芯暖爐！\n" NOR);
    say(me->query_name() + " 以精鋼卡尺拆開報廢石匣銅箍，改鑄出一座可拆卸換芯暖爐。\n");
    tell_object(me, HIG "滿窯老弱圍到換芯暖爐旁烘暖雙手——原本燒三日即廢的晶柱只需清渣添鹽粉即可續燒，省下七成耗材！\n" NOR);

    object t3 = load_object(TIER3_D);
    if (t3) {
        t3->grant_k_from_experiment(me, "craft", "disassemble_salt_casing", ([
            "tolerance_gap": 2,
            "slag_clog_site": "inner_collar"
        ]));
        t3->unlock_u_via_path(me, "craft", "removable_stove_build", ([
            "tenon_prototype"      : 1,
            "three_day_burn_verify": 1
        ]));
    }

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "forge", "target": "stove" ]));
    }
    return 1;
}
