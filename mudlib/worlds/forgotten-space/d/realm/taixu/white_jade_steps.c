// /d/realm/taixu/white_jade_steps.c
// 太虛神宮・白玉升空階座 (Ch.135-136 衡真道人、嚴平與玉化晶核初窺)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太虛神宮・白玉升空階座");
    set_long("萬丈雲霧托舉著這道純白星輝玉石長階，台階兩側整齊碼放著石堡苦力背送上山的鹽晶筐。\n"
             "階座外壓著冰冷秩序威壓，執律閣主簿嚴平偶爾提燈巡查鹽晶成色，觀測院的衡真道人則\n"
             "守在階側偏棚抄錄風壓誤差；若要趁隙抄對老化日誌並收下銅匣，可暗中抄錄（copy log）。\n"
             "向南下階返回【灰燼石堡】，往北上登（northup）進入【三百年校準偏殿】。\n");

    set_exits(([
        "south"   : "/d/realm/edge/ash_watch_post.c",
        "northup" : "/d/realm/taixu/calibration_hall.c",
    ]));
    set("is_outdoor", 1);

    set_touch("default", HIW "白玉石階滑潤冰寒，指腹貼上卻能感到一層令神識發緊的高頻秩序震顫。" NOR);
    set_smell("default", CYN "高空稀薄冷霧裡混著高純導流鹽晶的清冽鹹氣與一絲老舊銅鏽。" NOR);
    set_listen("default", HIC "苦力踏階的沉重喘息聲之上，隱約響著玉石高塔深處恆定而冷酷的脈流低鳴。" NOR);

    spawn_npc("/clone/npc/taixu_observer_heng.c");
    spawn_npc("/clone/npc/taixu_clerk_yanping.c");
}

void init() {
    ::init();
    add_action("do_copy_log", "copy");
}

int do_copy_log(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "log" && arg != "日誌" && arg != "抄本") {
        notify_fail("你想抄錄什麼？試試：copy log\n");
        return 0;
    }

    tell_object(me, HIW "你避開主簿嚴平的燈影，將【逆星斷碑拓片】與衡真觀測院的誤差日誌並排校對——\n" NOR);
    tell_object(me, HIC
        "【太虛高階實證（K × U 路徑二／跨極債務一）】\n"
        "你確認「每夜頻率上飄」正是三百年校準預熱增量，且高塔正靠吞噬新進修士的玉化晶核維生！\n"
        "衡真將鎖死讀數銅匣交予你，託請萬物外環匠師代為補鍛三枚穩壓銅芯還債。\n" NOR);
    say(me->query_name() + " 借抄寫風壓表作掩護，暗暗核對完太虛校準誤差日誌。\n");

    object t3 = load_object(TIER3_D);
    if (t3) {
        t3->grant_k_from_experiment(me, "law", "inspect_taixu_steps", ([
            "step_incline_angle"  : 15,
            "salt_resonance_delta": 3
        ]));
        t3->unlock_u_via_path(me, "law", "taixu_calibration_log", ([
            "heng_log_diff"         : 1,
            "reverse_star_alignment": 1
        ]));
    }

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "copy", "target": "log" ]));
    }
    return 1;
}
