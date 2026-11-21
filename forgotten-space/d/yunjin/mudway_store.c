// /d/yunjin/mudway_store.c
// 雲津仙集・泥途商棧 (Ch.84, Ch.85, Ch.90：五子自由樞紐與朔望暗網)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・萬山泥途總號");
    set_long("萬山廣場西街口最沉穩氣派的青石兩進商號，簷下新懸一塊烏木燙金大匾——\n"
             "【萬山泥途總號】。牆角碼著數十垛烈礬無煙耐火炭與發往長城、三宗隔離區的藥草石灰，\n"
             "榆木大案擺著公開開放查帳的《萬山共治分權與透明互保章程》（指令：decentralize ledger），\n"
             "屋角夥計阿四與管事邱禾正忙著與八家商戶代表核對交割單。揭開後屋暗門可下入地下石室。\n"
             "向東出門回到【西街貨棧區】，向下走進【泥途商棧地下石室】。\n");

    set_exits(([
        "east": "/d/yunjin/western_warehouse_street.c",
        "down": "/d/yunjin/mudway_store_cellar.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/qiu_he.c");
    spawn_npc("/clone/npc/a_si.c");
}

void init() {
    ::init();
    add_action("do_decentralize", "decentralize");
}

int do_decentralize(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "ledger" && arg != "charter" && arg != "權力" && arg != "章程") {
        notify_fail("你想執行什麼分權公開措施？試試：decentralize ledger\n");
        return 0;
    }
    message_vision(HIY "$N斷然拒卻太清採買管事私許的精炭壟斷免稅特權，甘願月少四成利銀而在萬山議事廳\n"
                       "公開貼出《萬山共治分權章程》：每月接受八商號聯組無預警查帳、拆分六條平行標段、\n"
                       "逾萬票調度須邱禾／顧蘭舟／八家代表三方會簽！不入任何仙門亦憑契約公信立人間錨點。\n" NOR, me);
    if (!present("wanshan_charter_deed", me)) {
        object ob = clone_object("/clone/item/wanshan_charter_deed.c");
        if (ob) {
            ob->move(me);
            tell_object(me, HIY "你簽妥並收執《萬山共治分權章程暨交接總錄》。\n" NOR);
        }
    }
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "decentralize", "target": "ledger" ]));
    }
    return 1;
}
