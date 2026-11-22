// /d/realm/zhanzu/arena_pit.c
// 戰祖魔殿・荒古鬥獸演武坑 (Ch.150-151 降壓煙彈＋力場扣具救燕山與九礦奴)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("戰祖魔殿・荒古鬥獸演武坑");
    set_long("深鑿於地底百丈的圓形玄鐵血坑，四周高牆密佈觀戰骨欄與沉重精鋼牢籠。\n"
             "鐵籠內關押著被監軍韓石疑心鎖押的燕山與九名礦奴，暗渠鐵閘卡死著重型插銷；\n"
             "須配合降壓煙彈麻痺頭獸嗅覺，並以可拆卸力場扣具強拔牢籠插銷救人（unlock cage）。\n"
             "向北沿排水暗道返【玄鐵巨骨哨卡】。\n");

    set_exits(([
        "north" : "/d/realm/zhanzu/bone_gate.c",
    ]));
    set("is_outdoor", 0);

    set_touch("default", RED "鬥獸坑玄鐵柵欄冰冷黏膩，插銷縫隙滲著乾涸暗血與礦油焦灰。" NOR);
    set_smell("default", HIR "濃烈刺鼻的獸糞血腥、生鐵鏽味與降壓藥煙散開後的微苦辛氣。" NOR);
    set_listen("default", YEL "鐵籠內重鎖撞擊聲與上方骨欄督戰鼓點震得耳膜發麻。" NOR);
}

void init() {
    ::init();
    add_action("do_unlock_cage", "unlock");
}

int do_unlock_cage(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "cage" && arg != "lock" && arg != "牢籠") {
        notify_fail("你要拆解什麼？試試：unlock cage\n");
        return 0;
    }

    tell_object(me, HIC "你順風擲出降壓煙彈麻痺三階頭獸，隨即以可拆卸力場扣具死死卡住牢籠精鋼插銷將其撬開！\n" NOR);
    tell_object(me, HIY
        "【鬥獸坑突圍與真實犧牲（EV413）】\n"
        "燕山與九名礦奴衝進排水暗道脫險，但熟路斷後的老獵手劈斷牽引繩永久留在了閘門之後……\n"
        "燕山緊攥著五年前的加密殘牌，壓下哀慟隨隊撤回石堡。\n" NOR);
    say(me->query_name() + " 撬開鬥獸坑精鋼牢籠插銷，硬生生救出燕山與九名礦奴突圍而出！\n");

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "unlock", "target": "cage" ]));
    }
    return 1;
}
