// /clone/npc/song_zhiwei.c
// 宋知微・太清周天星律院掌院 (song_zhiwei) - 周天星律院 (Ch.86)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("宋知微");
    set_short(HIW "周天星律院掌院" NOR " 宋知微");
    set_long("五十七歲的清瘦女道長，寡言冷峻，左手袖口與指尖常年留有磨蹭松煙墨錠的淡黑印痕。\n"
             "她是太清宮內主張保存原始星曆觀測資料的制度派，只認可可重複檢驗的實測誤差數據。\n");
    set_id(({ "song_zhiwei", "song zhiwei", "zhiwei", "宋知微", "掌院" }));

    setup_archetype("G", 82);
    set("class", "dao");
    set("faction", "taiqing");
    set("roles", ({ "master", "scholar", "quest" }));
    set("home_room", "/d/sects/taiqing/star_law_hall.c");

    add_response(({ "誤差", "雲梯", "公差", "外門經生" }),
        "宋知微細看手中寫滿數字的粗麻布，冷清的眸底掠過一絲震動：「能算得快，太清每年都挑得出十幾個；\n"
        "但在問心陣星煞壓頂時不肯磕頭，還能冷靜把東北測星柱滯後千分之三息的誤差老實抄下來的人，十幾年沒見過了。\n"
        "歸入星律院為外門上等經生，明日領《初階觀測誤差核校簿》。」");

    add_response(({ "星圖校讀", "藏星秘閣", "星曆" }),
        "宋知微按住墨跡未乾的氣朔實測錄：「要進入藏星秘閣翻檢六百年舊檔，光憑口頭猜測遠遠不夠。\n"
        "先把近三十年冬至暴風雪與雲津氣壓的誤差對照表算清，再憑我的限時手令去找檔案老吏余守拙領卷。」");
}
