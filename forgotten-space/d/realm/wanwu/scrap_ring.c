// /d/realm/wanwu/scrap_ring.c
// 萬物主機城・青金外環廢料回收場 (Ch.137, 145, 147, 155)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("萬物主機城・青金外環廢料回收場");
    set_long("青金幾何電路與堆成山丘的報廢金屬構件延伸至荒漠盡頭，三號運料車軸卡死在檢修槽內。\n"
             "維修總工頭齊九軸正核驗外環工友公差，稽核司主事陳楷則抱著考勤木板巡視；\n"
             "暗處三號拆解線更藏著灰紋跨界掮客。此間可實測試工修軸（repair axle）、\n"
             "於暗洞伏擊走私掮客（ambush broker），或依公差條例發動外環停工（declare strike）。\n"
             "向西返【星塵鹽田】，向東入【九號艙登錄廳】，向南下探【一級能量匯流井】。\n");

    set_exits(([
        "west"  : "/d/realm/edge/stardust_salt_flats.c",
        "east"  : "/d/realm/wanwu/ark_registry_hall.c",
        "south" : "/d/realm/wanwu/conduit_well.c",
    ]));
    set("is_outdoor", 1);

    set_touch("default", YEL "青金外環鋼板被地底機房餘熱烤得發燙，廢料堆裡滿是細碎銳利的車床鐵屑。" NOR);
    set_smell("default", CYN "濃重的機油、高溫電弧焦臭與生鐵氧化粉塵味撲鼻而來。" NOR);
    set_listen("default", HIY "數百具巨型齒輪永不停歇的沉重齒合轟鳴，震得腳底與胸腔隱隱共鳴。" NOR);

    add_action_rule("audit_stations", ([
        "targets": ({ "stockpile_bypass", "clause_audit" }),
        "quest_verb": "audit_stations",
        "quest_target_from_arg": 1,
        "usage_msg": "請選擇二十四座維修站應對稽查之策：audit_stations stockpile_bypass（分倉轉運）或 audit_stations clause_audit（公差清點）。",
        "sensory_msgs": ([
            "stockpile_bypass": HIY "你依齊九軸暗號調動推車將無主料件拆分轉入各維修工位分帳，陳楷帶人到場只見賬物兩清！" NOR,
            "clause_audit": HIC "你按外環保養規範為二十四座工位掛齊公差核驗牌，正面逼退陳楷試圖強行清零之手令！" NOR
        ]),
        "exp_gain": 18
    ]));

    spawn_npc("/clone/npc/wanwu_auditor_qi.c");
    spawn_npc("/clone/npc/wanwu_inspector_chen.c");
    spawn_npc("/clone/npc/cross_realm_broker.c");
}

void init() {
    ::init();
    add_action("do_repair_axle", "repair");
    add_action("do_ambush_broker", "ambush");
    add_action("do_declare_strike", "declare");
}

int do_repair_axle(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "axle" && arg != "車軸" && arg != "運料車軸") {
        notify_fail("你要檢修什麼？試試：repair axle\n");
        return 0;
    }

    tell_object(me, HIY "你不用半點靈力符文，單憑分寸卡尺與可拆活榫敲鬆卡死的三號運料車軸，公差嚴絲合縫！\n" NOR);
    tell_object(me, HIG "齊九軸拍案發出試工核驗牌，並借出工會機床助你替太虛衡真道人補鍛三枚穩壓銅芯！\n" NOR);
    say(me->query_name() + " 純熟地藉卡尺與可拆活榫修順了三號運料車軸，贏得齊九軸試工認可。\n");

    object t3 = load_object(TIER3_D);
    if (t3) {
        t3->grant_k_from_experiment(me, "craft", "audit_wanwu_scrap_axle", ([
            "axle_play_mm"     : 2,
            "sleeve_heat_limit": 120
        ]));
        t3->unlock_u_via_path(me, "craft", "wanwu_scrap_bench", ([
            "qi_bench_pass"       : 1,
            "modular_joint_sample": 1
        ]));
    }

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "repair", "target": "axle" ]));
    }
    return 1;
}

int do_ambush_broker(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "broker" && arg != "掮客" && arg != "smuggler") {
        notify_fail("你要伏擊誰？試試：ambush broker\n");
        return 0;
    }

    tell_object(me, HIR "你趁夜色停機空窗期封死三號拆解線暗洞，當場制伏灰紋掮客並奪下走私鐵箱！\n" NOR);
    tell_object(me, HIY "箱角清晰烙著凡間天工閣『赤火』篆印與雲津私盟近年貨單，徹底坐實赤煉跨界暗道！\n" NOR);
    say(me->query_name() + " 突襲三號拆解線暗洞，制伏灰紋跨界掮客並奪回赤火走私殘箱！\n");

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "ambush", "target": "broker" ]));
    }
    return 1;
}

int do_declare_strike(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "strike" && arg != "停工" && arg != "公差") {
        notify_fail("你要宣告什麼？試試：declare strike\n");
        return 0;
    }

    tell_object(me, HIW "你與齊九軸聯合二十四座零件供應站援引《安全公差檢核條例》，掛出『全面停爐複驗』木牌！\n" NOR);
    tell_object(me, HIG "陳楷死守的『季度自修達成率』一夜暴跌穿線，三極巨構後勤鏈首現真實卡殼！\n" NOR);
    say(me->query_name() + " 與外環維修工會齊聲掛出公差複驗停工牌，二十四座供應站瞬間靜默停機！\n");

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "declare", "target": "strike" ]));
    }
    return 1;
}
