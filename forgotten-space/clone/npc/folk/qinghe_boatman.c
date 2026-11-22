// clone/npc/folk/qinghe_boatman.c
// 老船工柳伯・青河縣蘆花渡（水文擺渡、量水尺與藥農船幫日常）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("老船工柳伯");
    set_short(CYN "青河老船工" NOR " 柳伯");
    set_long("一位皮膚被太陽與河風曬成深銅色、光著腳板踩在竹蓆上的老撐篙船工。\n"
             "他在青河擺渡三十多年，不用看縣衙告示，只看蘆葦根部的濕痕就能猜出上游水閘放沒放水。\n");
    set_id(({ "qinghe_boatman", "old liu", "boatman", "老船工柳伯", "柳伯", "船老大" }));

    setup_archetype("C", 8);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "ferry", "info" }));
    set("no_combat", 1);

    add_response(({ "水勢", "擺渡", "水尺", "船運", "差事" }),
        "柳伯磕了磕旱煙鍋望向東北方：「今早起河水又落了半寸，也不知漕運碼頭那根紅白水尺到底淹到幾格了。勞駕小哥去【青河縣・漕運駁船碼頭】幫老漢實測一下水尺（check_gauge），回來報個準信，好讓蘆花渡的採藥小船決定幾時出港！」");
    add_response(({ "洗靈草", "藥農", "道觀" }),
        "柳伯搖頭壓低聲道：「上面定神道觀修壩蓄水，咱們平底小船最遭殃。藥草曬乾了運不出去，一斤洗靈草在渡口只能換半斤糙米！」");
}
