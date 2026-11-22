// /d/realm/edge/basalt_ridge.c
// 第四卷 Act 1：玄武岩風道・風蝕高台 (Ch.127, 131, 133)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("灰燼邊緣・玄武岩風道");
    set_long("被狂風削出利刃般棱角的墨黑玄武岩溝壑，地脈深處偶爾傳來極微弱的齒輪共鳴震動。\n"
             "風蝕高台青石板上還留著用炭筆與松煙墨畫下的砂塵偏折切線，旁側有一頭遊蕩的灰甲砂蜥。\n"
             "若要順著風砂軌跡與太古測量銅尺測算大氣張力，可嘗試（measure vector）。\n"
             "往北下坡即是炊煙源頭【灰燼石堡】，往西南則通往赤黑焦土獵界，往南退回碎石高原。\n");

    set_exits(([
        "south"     : "/d/realm/peach_plateau.c",
        "north"     : "/d/realm/edge/ash_watch_post.c",
        "southwest" : "/d/realm/edge/scorch_border.c",
    ]));
    set("is_outdoor", 1);

    set_touch("default", CYN "玄武岩壁冷如生鐵，貼地石縫間隱約可感到高頻空間微震與風砂切刮。" NOR);
    set_smell("default", WHT "乾燥鹽霜、鐵鏽粉塵與一絲極淡的松煙墨氣在冷風裡打轉。" NOR);
    set_listen("default", HIY "細砂沿固定幾何切線貼地滑掠的沙沙聲，夾雜著測量銅尺的微弱嗡鳴。" NOR);

    spawn_npc("/clone/npc/gray_sand_lizard.c");
}

void init() {
    ::init();
    add_action("do_measure", "measure");
}

int do_measure(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "vector" && arg != "張力" && arg != "向量") {
        notify_fail("你想測算什麼？試試：measure vector\n");
        return 0;
    }

    tell_object(me, HIC "你伏在冰冷的玄武岩高台前，將耳朵貼近太古測量銅尺，仔細記錄貼地砂塵的偏折切線……\n" NOR);
    say(me->query_name() + " 伏在玄武岩高台前，用測量銅尺細細核對砂塵偏折軌跡。\n");
    tell_object(me, HIY
        "【幾何向量實測（K × U 突破／倒數暗兆二）】\n"
        "你比對前後兩組炭筆刻痕，赫然發現底層空間振動頻率竟在每夜子丑之間規律微幅上飄半厘！\n"
        "隨即你放棄往天空硬灌靈氣，順著張力切線微撥一分——狂風竟自動在身前捲成幾乎零耗的無星護幕！\n" NOR);

    object t3 = load_object(TIER3_D);
    if (t3) {
        t3->grant_k_from_experiment(me, "law", "measure_basalt_wind", ([
            "copper_ruler_drift": 5,
            "dust_vector_trace" : "tangent_ne"
        ]));
        t3->unlock_u_via_path(me, "law", "wind_sand_copper_ruler", ([
            "tangent_sketch"       : 1,
            "low_cost_barrier_test": 1
        ]));
    }

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "measure", "target": "vector" ]));
    }
    return 1;
}
