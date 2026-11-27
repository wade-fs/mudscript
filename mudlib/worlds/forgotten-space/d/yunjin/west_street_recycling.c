// /d/yunjin/west_street_recycling.c
// 雲津西街・萬寶封存空倉暨無毒炭料集中回收廠（Ch.115, Ch.120：陶生與老苦力安置與雲津新約簽署處）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津西街・無毒炭料回收廠暨議事新倉");
    set_long("原屬萬寶閣未涉案之西街空置條石大倉，在羅九秤查封清算萬寶閣資產後改建重組。\n"
             "天井架起防毒通風煙道、標準磅秤與安全規程木牌，安排缺指老工頭陶生與十幾戶停爐後\n"
             "曾面臨斷炊失業的窯工老師傅領防毒裝備在此再造無毒防寒炭暨處理無害廢料\n"
             "（代表簽署雲津新約暨回收試辦條約：sign treaty）。向東走上【石牌坊迎風口】，向南通【西街貨棧區】。\n");

    set_exits(([
        "east":  "/d/yunjin/stone_arch_quarantine.c",
        "south": "/d/yunjin/western_warehouse_street.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", WHT "標準磅秤鐵盤冰冷擦得鋥亮，壓成方塊的無毒防寒炭觸手緊實不掉粉。" NOR);
    set_smell("default", HIG "通風煙道抽走了濁氣，只剩乾燥木炭與新製防毒麻布口罩裡的淡淡艾草氣。" NOR);
    set_listen("default", HIY "窯工老師傅互相招呼過磅的穩重腳步聲與炭塊整齊碼進竹筐的清脆敲擊聲。" NOR);
}

void init() {
    ::init();
    add_action("do_sign", "sign");
}

int do_sign(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "treaty" && arg != "accord" && arg != "新約" && arg != "協約") {
        notify_fail("你想簽署哪一份條約？試試：sign treaty\n");
        return 0;
    }
    message_vision("$N連同顧蘭舟、羅九秤與三大掌門見證代表落押蓋印《雲津萬山臨時互市與救濟協約》，\n"
                   "並當場出具泥途暨雲海票號新條子：設西街無毒廢料暨防寒炭集中回收廠安置失業窯工，\n"
                   "同時明確自警「三大名山核心武力猶在，這只是脆弱改革的第一步」。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "sign", "target": "treaty" ]));
    }
    return 1;
}
