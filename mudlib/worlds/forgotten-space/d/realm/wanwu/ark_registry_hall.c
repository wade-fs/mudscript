// /d/realm/wanwu/ark_registry_hall.c
// 萬物主機城・九號離艦救生艙登錄廳 (Ch.138 拆解銅匣與「無主材料」判詞)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("萬物主機城・九號艙登錄廳");
    set_long("一排排鐫刻青金銘文的鋼鐵書架直抵穹頂，保存著太古船塢登錄總冊與外環物料帳單。\n"
             "案台上架著拆解太虛銅匣用的微米卡具，一側光幕正閃動著九號救生艙事故歸檔；\n"
             "可上前核對總冊並拆解太虛讀數銅匣（check manifest）。\n"
             "向西返【外環廢料回收場】，向東登【鋼鐵仲裁橋】，向下（down）入【九城離線總節點】。\n");

    set_exits(([
        "west" : "/d/realm/wanwu/scrap_ring.c",
        "east" : "/d/realm/wanwu/arbitration_bridge.c",
        "down" : "/d/realm/wanwu/nine_city_node.c",
    ]));
    set("is_outdoor", 0);

    set_touch("default", CYN "鋼鐵書架表面刻滿冰冷有序的太古幾何條文，案台卡具則透著機油潤滑的溫涼。" NOR);
    set_smell("default", WHT "封蠟銅函的乾燥松香、臭氧灰塵與冷卻油氣交疊在密閉高廳內。" NOR);
    set_listen("default", HIC "成排書架內部的機械算盤齒片定期滑動歸位，發出密密麻麻的清脆喀噠聲。" NOR);
}

void init() {
    ::init();
    add_action("do_check_manifest", "check");
}

int do_check_manifest(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "manifest" && arg != "總冊" && arg != "檔案") {
        notify_fail("你要核查什麼？試試：check manifest\n");
        return 0;
    }

    tell_object(me, HIC "你借工會機床拆開太虛讀數銅匣還清債務，隨即翻開《九號離艦救生艙登錄總冊》——\n" NOR);
    tell_object(me, HIY
        "【九號艙真相與無主材料裁定（Q1 核心前提）】\n"
        "1. 北荒冰層所埋方舟原是太古被天羅擊落的『九號離艦救生艙』，主機正受殘破舊律驅動自修。\n"
        "2. 凡未入當年離艦名冊之石堡十七批先輩後裔，登錄廳一律判為『無主可回收材料』。\n"
        "3. 更查出近期一批高純鹽晶粉被改帳轉列為『戰祖獵營耗損』——必須送往西南獵營對質！\n" NOR);
    say(me->query_name() + " 拆開太虛讀數銅匣並抄錄《九號離艦救生艙登錄總冊》與冒領轉帳單。\n");

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "check", "target": "manifest" ]));
    }
    return 1;
}
