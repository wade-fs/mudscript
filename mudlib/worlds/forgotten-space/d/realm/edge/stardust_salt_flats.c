// /d/realm/edge/stardust_salt_flats.c
// 第四卷 Act 1：星塵鹽田與殘晶黑市 (Ch.129)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("荒原邊・星塵鹽田與殘晶黑市");
    set_long("低窪鹽礫坑內一片慘白結晶反光，鹽工們蒙面將粗鹽晶鏟入麻袋，外環牙人正守著全鐵板車驗貨。\n"
             "角落一張歪斜木桌底下竟墊著一塊刻有『九號離艦補給營』字樣的鏽蝕鐵牌；若要核對黑市預扣\n"
             "與晶柱暴漲帳目，可仔細查帳（audit market）。向西返回【灰燼石堡】，向東踏入【萬物主機城外環】。\n");

    set_exits(([
        "west" : "/d/realm/edge/ash_watch_post.c",
        "east" : "/d/realm/wanwu/scrap_ring.c",
    ]));
    set("is_outdoor", 1);

    set_touch("default", HIW "地面結晶鹽殼硬脆冰涼，桌角墊腳的鏽鐵牌邊緣竟刻著細密工整的太古輪輻徽記。" NOR);
    set_smell("default", CYN "濃烈嗆鼻的苦鹹鹽霜味與鐵板車輪軸滲出的陳年機油味交織。" NOR);
    set_listen("default", YEL "木耙鏟過鹽結晶的脆響，混著外環牙人用鐵尺敲打交割木板的冷硬噠噠聲。" NOR);

    spawn_npc("/clone/npc/salt_market_broker.c");
}

void init() {
    ::init();
    add_action("do_audit", "audit");
}

int do_audit(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "market" && arg != "鹽帳" && arg != "黑市") {
        notify_fail("你想核查什麼？試試：audit market\n");
        return 0;
    }

    tell_object(me, "你抽出算籌比對交割木板上的批號與缺印戳記，隨即俯身抹開桌角鏽鐵牌上的黑灰……\n");
    say(me->query_name() + " 抽出算籌核對交割木板批號，並彎身查看桌角墊腳的鏽鐵牌。\n");
    tell_object(me, HIY
        "【殘晶黑市核帳（倒數暗兆一）】\n"
        "你揭穿外環牙人不僅將下等返工石匣兌率暴漲三倍、更無預警『預扣三成戰備折抵』——\n"
        "顯見萬物外環正因某項限期急差而拼命囤料！同時你辨識出桌角墊腳鐵牌刻著『九號離艦・外圍四號補給營』！\n" NOR);

    object t3 = load_object(TIER3_D);
    if (t3) {
        t3->grant_k_from_experiment(me, "commerce", "audit_salt_market_deficit", ([
            "levy_pct"        : 30,
            "buyback_drop_pct": 70
        ]));
    }

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "audit", "target": "market" ]));
    }
    return 1;
}
