// /d/yunjin/mudway_store_cellar.c
// 雲津仙集・泥途商棧地下石室 (Ch.98-101：雙契鐵門地窖、五方對帳與三元剝離晶絲)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・泥途商棧地下石室");
    set_long("以林鐵生雙契精鋼暗鎖護衛的深宅地窖，牆角炭盆正燒著無煙烈礬耐火炭。\n"
             "正中一張寬厚榆木方桌舖著兩層煮沸消毒過的乾淨白麻布，旁擺精準沙漏、銅測溫片、\n"
             "熱水與碎冰木盆（五子協力行針震波剝離早期晶絲：strip filament）。木梯口立著披羊皮襖、\n"
             "拄硬棗木拐杖的瘸腿老丐莫三，身後地窖暗格妥善封藏著私盟密帳與五袋防潮物證。\n"
             "沿木梯向上返回【泥途商棧】。\n");

    set_exits(([
        "up": "/d/yunjin/mudway_store.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", WHT "地窖乾燥防潮的青石暗格壁面冰冷細膩，五袋油布密封物證袋摸上去沉實微涼。" NOR);
    set_smell("default", YEL "防潮石灰、油布封蠟與舊帳冊陳年紙灰安靜地沉在密閉石室裡。" NOR);
    set_listen("default", WHT "石室隔絕了街面風雪與人聲，偶爾只有莫三那根硬棗木拐杖輕點石面的篤篤聲。" NOR);

    spawn_npc("/clone/npc/mo_beggar.c");
}

void init() {
    ::init();
    add_action("do_strip", "strip");
}

int do_strip(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "filament" && arg != "crystal" && arg != "晶絲" && arg != "道化晶絲") {
        notify_fail("你想施展哪項三元協作處置？試試：strip filament\n");
        return 0;
    }
    message_vision("$N依五方協作節律就位：銀針雪線苔封護太淵穴經脈、不融黑鐵齒輪傳導高頻微震、\n"
                   "三分陽剛煞血溫熱護脈、沙漏控溫三成、周天星算牽引推離——終於穩穩抽出一條\n"
                   "半寸長淡青晶絲！術後實錄亦嚴正記明「左食中指神經麻木與半日短暫失憶」代價。\n", me);
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "strip", "target": "filament" ]));
    }
    return 1;
}
