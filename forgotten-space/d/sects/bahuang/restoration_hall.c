// /d/sects/bahuang/restoration_hall.c
// 八荒武山・傷兵養息院 (Ch.93：長城內側傷兵紀錄與定心急鎮丸黑血病案)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("八荒武山・傷兵養息院");
    set_long("位於北線長城內側的低矮石屋院落，空氣裡瀰漫著濃重的金創散與苦澀湯藥味。\n"
             "後廊熱水房蒸騰著白霧，內院廂房門縫裡可見幾口盛著燒焦瀝青狀黑紅血塊的銅盆與\n"
             "未貼藥單的白色小瓷瓶；女醫官杜青禾正借暗黃油燈逐日謄錄氣血燥火與臟腑負荷簿\n"
             "（指令：inspect records）。向東走出院門回到【黑山煞血營】。\n");

    set_exits(([
        "east": "/d/sects/bahuang/black_mountain_camp.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", YEL "木榻邊緣光滑冰涼，煎藥陶罐與軍籍傷冊紙頁摸上去帶著乾燥微溫。" NOR);
    set_smell("default", HIG "濃烈辛辣的金瘡藥酒氣、艾灸焦味與傷兵繃帶滲出的淡淡血腥氣。" NOR);
    set_listen("default", WHT "帳內安靜壓抑，只有重傷武卒深沉的喘息聲與醫師翻閱傷病簿的紙頁聲。" NOR);

    spawn_npc("/clone/npc/du_qinghe.c");
}

void init() {
    ::init();
    add_action("do_inspect", "inspect");
}

int do_inspect(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "records" && arg != "病案" && arg != "藥瓶") {
        notify_fail("你想翻檢什麼？試試：inspect records\n");
        return 0;
    }
    message_vision("$N趁換藥空檔細看杜青禾案頭之體溫與脾胃衰弱統計表，並隔鼻一嗅瓷瓶氣味——\n"
                   "那股藏在藥氣底層的腥甜硫磺味，竟與黑石鋪地煞血精極為神似，且每月只見「丹鼎宗或雲津」配送記號！\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "inspect", "target": "records" ]));
    }
    return 1;
}
