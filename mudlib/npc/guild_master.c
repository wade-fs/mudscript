#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name("公會會長 艾德蒙");
    set_short(HIW("冒險者公會會長") + " 艾德蒙");
    set_long("一位看起來經驗豐富的人類戰士，他是這間公會的負責人。\n他穿著一套擦得發亮的銀色鎧甲，眼神中透著威嚴。\n");
    set_id(({"edmund", "guild master", "master", "會長"}));
    set_race("human");
    set_level(30);
    set_stat(STAT_STR, 25);
    set_stat(STAT_CON, 25);
    recalc_stats();
    hp = max_hp;

    set_chat_topic("job", "最近東邊的草原有狼群出沒，你可以去看看。");
    set_chat_topic("工作", "最近東邊的草原有狼群出沒，你可以去看看。");
    set_chat_topic("guild", "這裡提供冒險者休息與交流的場所。");
    set_chat_topic("公會", "這裡提供冒險者休息與交流的場所。");
    set_chat_topic("help", "新手的話，可以先去[鐵匠鋪|go west]找索林買把武器，或者去[藥劑店|go south]備些藥水。");
    set_chat_topic("幫助", "新手的話，可以先去[鐵匠鋪|go west]找索林買把武器，或者去[藥劑店|go south]備些藥水。");
    set_chat_topic("newbie", "這裡是新手村，是所有偉大冒險的起點。");
    set_chat_topic("新手", "這裡是新手村，是所有偉大冒險的起點。");
    set_chat_topic("topics", "你可以問我關於：[工作|ask master job]、[幫助|ask master help]、[公會|ask master guild]、[地圖|ask master map]。");
    set_chat_topic("話題", "你可以問我關於：[工作|ask master job]、[幫助|ask master help]、[公會|ask master guild]、[地圖|ask master map]。");
    set_chat_topic("map", "新手村由 8x8 的區域組成。我們現在在 (4,5)。中央廣場在正南方 (4,4)。");
    set_chat_topic("地圖", "新手村由 8x8 的區域組成。我們現在在 (4,5)。中央廣場在正南方 (4,4)。");
}
