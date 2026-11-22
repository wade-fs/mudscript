// /d/realm/zhanzu/hunting_camp.c
// 戰祖外圍・狩獵奴役營 (Ch.139-140 斷目燕山重逢、拓跋重與韓石剋扣假帳)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("戰祖外圍・狩獵奴役營");
    set_long("以破獸皮與焦木搭成的狹窄獵營棚架，牆邊堆滿帶血的獸骨與待驗心核籃筐。\n"
             "監軍韓石正拿算牌催逼季度九具三階心核配額，百夫長拓跋重暗中替傷員少劃損耗，\n"
             "獨眼老獵頭燕山則沉默站在營門陰影裡；若要藉戰神圖騰共鳴在重力衰減半拍破殺\n"
             "狂暴熔岩骨鬣獸並取得暗倉線索，可趁隙出手狩獵（hunt beast）。向東返【玄鐵巨骨哨卡】。\n");

    set_exits(([
        "east" : "/d/realm/zhanzu/bone_gate.c",
    ]));
    set("is_outdoor", 1);

    set_touch("default", YEL "棚柱上綁滿浸了乾血的粗麻繩與磨鈍的骨矛，重力沉降時雙膝如負百斤砂袋。" NOR);
    set_smell("default", RED "血腥氣、獸皮騷味、劣質止血草灰與監軍爐火烤肉的油煙混雜。" NOR);
    set_listen("default", HIR "鐵鏈拖地聲、受傷獵奴的低抑咳喘與深谷裡熔岩骨鬣獸的狂暴低吼此起彼落。" NOR);

    spawn_npc("/clone/npc/zhanzu_packmaster_tuo.c");
    spawn_npc("/clone/npc/zhanzu_quartermaster_han.c");
    spawn_npc("/clone/npc/yan_shan.c");
    spawn_npc("/clone/npc/lava_bone_beast.c");
}

void init() {
    ::init();
    add_action("do_hunt_beast", "hunt");
}

int do_hunt_beast(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "beast" && arg != "骨鬣獸" && arg != "lizard") {
        notify_fail("你要狩獵什麼？試試：hunt beast\n");
        return 0;
    }

    tell_object(me, HIR "你放棄強行催爆全身氣血，閉目傾聽重力井沉降後那轉瞬即逝的衰減半拍——\n" NOR);
    tell_object(me, HIY
        "【力道 U 覺醒・無聲截息穿貫（Ch.140）】\n"
        "兩記勁道咬尾貫穿三階熔岩骨鬣獸頸椎軟縫！獨眼大伯燕山認出燕家手筆卻冷面相告：\n"
        "『這裡誰也救不了誰的菩薩心腸！韓石冒領的鹽晶粉暗藏於萬物城外三號廢鹽倉。』\n" NOR);
    say(me->query_name() + " 卡準裂谷重力衰減半拍連發無聲絕殺，擊倒了撲營的熔岩骨鬣獸！\n");

    object t3 = load_object(TIER3_D);
    if (t3) {
        t3->grant_k_from_experiment(me, "force", "time_gravity_pulse", ([
            "pulse_interval_beats": 10,
            "totem_resonance"     : 1
        ]));
        t3->unlock_u_via_path(me, "force", "totem_gravity_pulse", ([
            "half_beat_release": 1,
            "bone_mane_kill"   : 1
        ]));
    }

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "hunt", "target": "beast" ]));
    }
    return 1;
}
