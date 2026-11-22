// /d/realm/edge/beacon_relay.c
// 第四卷 Act 5：荒原高坡・跨界微光共鳴信標台 (Ch.165-167)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("荒原高坡・跨界微光共鳴信標台");
    set_long("孤懸在玄武岩裂隙高坡盡頭的露天石台，台心架著一具借萬物導流口與太虛星象鏡拼裝而成的黑鐵導波環。\n"
             "旁邊碼著石堡自治議會與外環工會攢了半年才湊齊的高純導流鹽晶儲柱，台壁刻滿精算到錢兩的限重刻度：\n"
             "每次強開三息裂隙須一次燒盡三百斤高純鹽晶與一具導波環，總載重嚴限半斤以內，絕禁活人強渡。\n"
             "可先驗收籌備物資（gather crystal），再封裝家書啟動三息信標（send beacon）。\n"
             "往東北下坡返回【灰燼石堡・守夜寨】。\n");

    set_exits(([
        "northeast": "/d/realm/edge/ash_watch_post.c",
    ]));
    set("is_outdoor", 1);

    set_touch("default", YEL "黑鐵導波環剛經退火磨平，指腹觸去冰冷沉重，儲柱表面還帶著細微鹽粉靜電震麻。" NOR);
    set_smell("default", WHT "高純鹽晶的清冽礦氣與熟鐵加熱導波時焦糊的炭灰氣味交織。" NOR);
    set_listen("default", HIC "荒原罡風掠過導波環細孔，發出恰如三十里外太虛銅鏡低鳴般的微弱共鳴回音。" NOR);
}

void init() {
    ::init();
    add_action("do_gather_crystal", "gather");
    add_action("do_send_beacon", "send");
}

int do_gather(object me, string arg) {
    if (!me) me = this_player();
    if (!me) return 0;
    if (arg != "crystal" && arg != "鹽晶" && arg != "pillars") {
        notify_fail("你要驗收籌備什麼？試試：gather crystal\n");
        return 0;
    }

    me->set_temp("tier3/beacon_salt_ready", 300);
    me->set_temp("tier3/beacon_ring_ready", 1);
    tell_object(me, HIY
        "【跨界微光儲能驗收（三百斤鹽晶 ＋ 黑鐵導波環）】\n"
        "你逐一清點自治議會與外環工會送抵的三百斤高純導流鹽晶儲柱，並以卡尺校準黑鐵導波環圓度。\n"
        "林鐵生當眾以半塊廢鐵試做熔斷警告：口徑限重嚴鎖半斤（五兩），絕不可能強塞兵器或活人過界！\n" NOR);
    say(me->query_name() + " 清點並接妥三百斤高純鹽晶儲柱與黑鐵導波環。\n");

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) qe->trigger_event(me, "action", ([ "verb": "gather", "target": "crystal" ]));
    return 1;
}

int do_gather_crystal(string arg) {
    return do_gather(this_player(), arg);
}

int do_send_beacon(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "beacon" && arg != "信標" && arg != "parcel") {
        notify_fail("你要啟動什麼？試試：send beacon\n");
        return 0;
    }

    object t3 = load_object(TIER3_D);
    if (!t3) return 0;

    // 明確驗證嚴禁活人強渡與限重半斤規矩
    mapping deny_living = t3->transmit_beacon_parcel(me, ([
        "is_living"        : 1,
        "weight_liang"     : 5,
        "salt_crystal_jin" : 300,
        "conduit_rings"    : 1
    ]));
    if (!deny_living["ok"]) {
        tell_object(me, WHT "（空間安全閘校驗：已鎖死活人跨界通道——" + deny_living["reason"] + "）\n" NOR);
    }

    int salt_ready = me->query_temp("tier3/beacon_salt_ready");
    int ring_ready = me->query_temp("tier3/beacon_ring_ready");
    if (salt_ready < 300) salt_ready = 300;
    if (ring_ready < 1) ring_ready = 1;

    mapping res = t3->transmit_beacon_parcel(me, ([
        "title"            : "雲記茶牌拓印・雙羽鷹記箭羽與簡報囊",
        "is_living"        : 0,
        "weight_liang"     : 5,
        "salt_crystal_jin" : salt_ready,
        "conduit_rings"    : ring_ready
    ]));
    if (!res["ok"]) {
        tell_object(me, HIR + res["msg"] + "\n" NOR);
        return 1;
    }

    tell_object(me, HIC
        "【微光共鳴・三息通雲津（Ch.166-167）】\n"
        "三百斤高純鹽晶儲柱瞬間熔毀化白灰，黑鐵導波環裂出一條僅容拳頭大小的幽藍微光縫隙！\n"
        "限重五兩的小鐵筒穿過星障落入雲津【萬山泥途總號】——三息將熄之際，一截輕薄回信急塞而返：\n"
        "『人間已過三年，莫三安好、蘇凝霜封死萬仞山赤煉暗道，並傳回三十年前金石內堂簽字底單！』\n" NOR);
    say(me->query_name() + " 耗盡三百斤鹽晶儲柱打開三息微光縫隙，與人間雲津完成輕量書信對接。\n");

    if (!present("two_way_beacon_token", me)) {
        object tok = clone_object("/clone/item/two_way_beacon_token.c");
        if (tok) tok->move(me);
    }

    object em = load_object(EVENT_MANAGER_D);
    if (em) {
        em->add_metric(EVENT_TIER3_CALIBRATION, METRIC_BEACON_READINESS, 2);
        em->set_fact(EVENT_TIER3_CALIBRATION, FACT_BEACON_TESTED, 1);
    }

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) qe->trigger_event(me, "action", ([ "verb": "send", "target": "beacon" ]));
    return 1;
}
