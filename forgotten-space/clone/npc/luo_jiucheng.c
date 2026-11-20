// /clone/npc/luo_jiucheng.c
// 羅九秤・萬山商埠公所掌印 (luo_jiucheng) - 雲津仙集・萬山商埠公所 (Ch.84, Ch.90)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("羅九秤");
    set_short(HIW "萬山商埠公所掌印" NOR " 羅九秤");
    set_long("五十五歲的瘦削老吏，衣領永遠整齊扣緊，手中捏著一桿擦得鋥亮的紫銅小秤。\n"
             "他曾任跨州行商稽核，只看契約版本、交割時限與實物擔保，不徇私情也不受空頭人情。\n");
    set_id(({ "luo_jiucheng", "luo jiucheng", "luo", "羅九秤", "掌印" }));

    setup_archetype("A", 48);
    set("class", "mortal");
    set("faction", "yunjin_office");
    set("roles", ({ "official", "arbiter", "quest" }));
    set("home_room", "/d/yunjin/public_office.c");

    add_response(({ "登記", "商棧登記", "跨州信印", "保證金" }),
        "羅九秤用枯瘦的指尖夾起信印照著窗光檢視雙重飛錢暗記，平淡道：「金石商會與通寶總號的跨州信印是真的。\n"
        "依萬山商埠公約，持印者免三年觀察期，但信印不代表免除本地保證金與倉損擔保。兩千枚下品靈石票的履約保證金，\n"
        "或由雲海票號出具足額實物倉單抵押保書，二者必須擇一。」");

    add_response(({ "租約", "貨損", "規則", "泥途" }),
        "羅九秤在契約邊緣輕敲兩下，正色道：「雲津不認英雄，只認帳本。西街貨棧區租約寫明『貨損自負、逾期三日扣倉』。\n"
        "凡在公所掛牌之商號，須留存雙聯交割底單；倘若遇雪災延誤而依約賠清違約金，公所照樣記一筆甲等履約信用。」");
}
