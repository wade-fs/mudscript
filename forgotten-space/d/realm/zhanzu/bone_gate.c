// /d/realm/zhanzu/bone_gate.c
// 戰祖裂谷・玄鐵巨骨哨卡 (Ch.139, 159-160 巨骨哨卡狙截與五年密牌交出)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("戰祖裂谷・玄鐵巨骨哨卡");
    set_long("兩根不知何種太古巨獸的弧形白骨交錯斜插在焦黑玄鐵峽道兩側，形成僅容兩騎並行的險關。\n"
             "每隔十數息大地重力便猛墜一拍、隨即反彈衰減半拍；若須率獵隊扼守狹道射截韓石督戰狂獸，\n"
             "可卡準重力衰減節拍據險阻截（hold gate）。\n"
             "向東北返【赤黑焦土邊坡】，向西入【戰祖外圍狩獵營】，向南通往【荒古鬥獸演武坑】。\n");

    set_exits(([
        "northeast" : "/d/realm/edge/scorch_border.c",
        "west"      : "/d/realm/zhanzu/hunting_camp.c",
        "south"     : "/d/realm/zhanzu/arena_pit.c",
    ]));
    set("is_outdoor", 1);

    set_touch("default", RED "哨卡巨骨表面佈滿刀箭劈砍的陳年凹痕，玄鐵閘樁在重力脈動下微微震手。" NOR);
    set_smell("default", HIR "乾涸獸血的銅腥氣、火油硝煙味與赤黑焦岩高熱烤出的硫磺塵氣。" NOR);
    set_listen("default", YEL "峽谷風聲如巨獸喘息，每逢重力驟墜便伴隨著地面石礫沉重叩擊聲。" NOR);
}

void init() {
    ::init();
    add_action("do_hold_gate", "hold");
}

int do_hold_gate(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "gate" && arg != "哨卡" && arg != "pass") {
        notify_fail("你要扼守哪裡？試試：hold gate\n");
        return 0;
    }

    tell_object(me, HIY "你與燕山、拓跋重配合重力衰減半拍同時出手，兩箭交錯精準貫穿重裝戰獸雙脛軟隙！\n" NOR);
    tell_object(me, HIG
        "【巨骨哨卡大捷與五年密牌（EV417）】\n"
        "龐然戰獸轟然跪倒堵死狹道，韓石狂獸督戰隊全面潰敗；燕山隨即從貼身皮袋掏出\n"
        "五年前與凡間軍需轉運暗線接頭的加密殘牌，將黑冰斷谷黑幕鎖死至下一紀元。\n" NOR);
    say(me->query_name() + " 藉重力衰減節拍死守巨骨哨卡，一舉截停了衝陣而來的戰祖督戰獸群！\n");

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "hold", "target": "gate" ]));
    }
    return 1;
}
