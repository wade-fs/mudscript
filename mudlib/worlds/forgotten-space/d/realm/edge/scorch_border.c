// /d/realm/edge/scorch_border.c
// 第四卷 Act 1：赤黑焦土・西南獵界邊坡 (Ch.133)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("赤黑焦土・西南獵界邊坡");
    set_long("腳下玄武岩在此逐漸轉為泛著暗紅鐵鏽光的赤黑火山焦岩，空氣裡浮動著硫磺血氣與壓迫重力。\n"
             "遠方濃霧裡不時傳來戰祖骨號聲，幾群原本深伏地穴的低階荒獸正慌亂地往東北方向竄逃。\n"
             "下方背陰赤岩底縫露出一截被黑灰半掩的新鮮刻痕，可貼地拂灰拓印（rub mark）。\n"
             "向東北退返【玄武岩風道】，向西南深入（southwest）則是【戰祖巨骨哨卡】。\n");

    set_exits(([
        "northeast" : "/d/realm/edge/basalt_ridge.c",
        "southwest" : "/d/realm/zhanzu/bone_gate.c",
    ]));
    set("is_outdoor", 1);

    set_touch("default", RED "焦岩表面滾燙粗糙，背陰石縫底面的三道人工刀痕棱角竟仍十分銳利。" NOR);
    set_smell("default", HIR "刺鼻的焦土硫磺、微腥荒獸血氣與被壓緊的乾燥黑灰味。" NOR);
    set_listen("default", YEL "遠處裂谷濃霧中斷續傳來急促低沉的戰祖骨哨催徵聲，伴隨雜獸奔竄的碎石響。" NOR);

    spawn_npc("/clone/npc/bastion_young_hunter.c");
}

void init() {
    ::init();
    add_action("do_rub", "rub");
}

int do_rub(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "mark" && arg != "鷹記" && arg != "刻痕") {
        notify_fail("你要拓印什麼？試試：rub mark\n");
        return 0;
    }

    tell_object(me, HIY "你滑進背陰赤岩縫拂去黑灰，仔細量定風化砂層厚度，將石面暗記完整拓入蠟紙！\n" NOR);
    say(me->query_name() + " 貼近赤黑岩縫拂去黑灰，將石面暗記拓印入蠟紙。\n");
    tell_object(me, HIG
        "【燕山鷹記實證（FS-03／倒數暗兆三）】\n"
        "三道「左撇收腕・雙羽隱括」燕家暗記僅有三至五年風化，證實大伯燕山確曾活著進入西南獵道！\n"
        "同時你記下了此帶裂谷荒獸提前躁動、戰祖外營心核配額驟加三成的異常軍情。\n" NOR);

    object t3 = load_object(TIER3_D);
    if (t3) {
        t3->grant_k_from_experiment(me, "force", "track_scorch_prey", ([
            "prey_stride_cadence" : 4,
            "recoil_damping_ratio": 70
        ]));
    }

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "rub", "target": "mark" ]));
    }
    return 1;
}
