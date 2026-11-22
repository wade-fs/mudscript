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
             "初入石堡須熄燈避檢（douse lamps）、實測阻尼（test damping）或改鑄暖爐（forge stove）；\n"
             "後續更可在此地窖對帳算準九十日倒數（converge ledger）、簽下工役互助密約（sign compact）、\n"
             "組盾偏折太虛星鎖（deflect scan），或熔爐備戰校準夜（prepare war）。\n"
             "向南上坡返玄武岩風道，向北攀登【太虛白玉階座】，向東下溝為【星塵鹽田】，向西穿石門為【邊緣醫棚】。\n");

    set_exits(([
        "south" : "/d/realm/edge/basalt_ridge.c",
        "north" : "/d/realm/taixu/white_jade_steps.c",
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
    add_action("do_converge_ledger", "converge");
    add_action("do_sign_compact", "sign");
    add_action("do_deflect_scan", "deflect");
    add_action("do_prepare_war", "prepare");
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

int do_converge_ledger(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "ledger" && arg != "對帳" && arg != "倒數") {
        notify_fail("你要匯總什麼？試試：converge ledger\n");
        return 0;
    }
    tell_object(me, HIY "五人將鹽晶預扣三成、頻率夜飄、心核加徵與三極抄本併上同一張時間軸——\n"
                    "【九十日倒數確證（EV410）】三百年天羅大校準暨全境肅清期確已預熱，僅餘九十日！\n" NOR);
    say(me->query_name() + " 在石案室完成五方對帳，算準距離三百年大校準僅餘最後九十日！\n");
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) qe->trigger_event(me, "action", ([ "verb": "converge", "target": "ledger" ]));
    return 1;
}

int do_sign_compact(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "compact" && arg != "密約" && arg != "互助") {
        notify_fail("你要簽署什麼？試試：sign compact\n");
        return 0;
    }
    tell_object(me, HIG "鹽晶採工、外環二十四站維修工與戰祖獵營代表共同在桑皮紙上壓下指印，締結《三極維護工役互助密約》！\n" NOR);
    say(me->query_name() + " 串聯三極底層代表簽立《三極維護工役互助密約》。\n");
    object t3 = load_object(TIER3_D);
    if (t3) {
        if (!t3->has_k(me, "commerce")) {
            t3->grant_k_from_experiment(me, "commerce", "audit_salt_market_deficit", ([ "levy_pct": 30, "buyback_drop_pct": 70 ]));
        }
        t3->unlock_u_via_path(me, "commerce", "three_pole_labor_compact", ([ "twenty_four_stations": 24, "twelve_salt_sheds": 12 ]));
    }
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) qe->trigger_event(me, "action", ([ "verb": "sign", "target": "compact" ]));
    return 1;
}

int do_deflect_scan(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "scan" && arg != "星鎖" && arg != "光柱") {
        notify_fail("你要偏折什麼？試試：deflect scan\n");
        return 0;
    }
    tell_object(me, HIC "你架起三面銅箔頻率反射盾配合衡真殘缺校正表，以『無星向量偏折網』硬生生將紫黑星鎖光柱偏折三息！\n"
                    "五十餘名老弱名冊保住，但高塔反震令你雙目留下一片雪白殘影。\n" NOR);
    say(me->query_name() + " 展開無星向量護幕與反射盾，強行將太虛星鎖掃描光柱偏折三息！\n");
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) qe->trigger_event(me, "action", ([ "verb": "deflect", "target": "scan" ]));
    return 1;
}

int do_prepare_war(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "war" && arg != "備戰" && arg != "十日") {
        notify_fail("你要籌備什麼？試試：prepare war\n");
        return 0;
    }
    tell_object(me, HIY "石堡拆掉三座備用暖爐熔成匯流井分流總栓與黑鐵導流針，藥爐備料與三線人員分派完畢！\n" NOR);
    say(me->query_name() + " 完成最後十日三線戰備整合與器具拆鑄。\n");
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) qe->trigger_event(me, "action", ([ "verb": "prepare", "target": "war" ]));
    return 1;
}
