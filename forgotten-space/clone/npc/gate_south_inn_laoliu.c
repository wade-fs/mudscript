// clone/npc/gate_south_inn_laoliu.c
// 老劉・棧主 (gate_south_inn_laoliu) - 南關車馬小棧

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("老劉");
    set_short(YEL "車馬小棧棧主" NOR " 老劉");
    set_long("一位肩搭白毛巾、滿臉風霜卻笑呵呵的半百掌櫃。\n"
             "他早年也是從南嶺山溝裡走出來的挑夫，對黑石鋪與盤木、重石逃難來的鄉民頗為照拂。\n");
    set_id(({ "gate_south_inn_laoliu", "laoliu", "lao liu", "innkeeper liu", "老劉", "棧主" }));

    setup_archetype("J", 10);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "shop", "info", "service" }));
    set("schedule", "24h");

    add_response(({ "黑石鋪", "流民", "落腳", "鄉親" }),
        "老劉嘆了口氣：「聽說黑石鋪北崖塌了礦、又鬧了大獸潮，能活著走到南關都是命大！先喝碗熱麥茶暖暖身子吧。」");

    add_response(({ "雜工", "門路", "三日通牒", "活計", "緩衝信物" }),
        "老劉壓低聲音指點道：「沒有一階度牒在城裡只能待三天！不想被趕去亂葬崗的話，要麼去金石學塾找陸夫子抄書領青衿，要麼去遠行車馬大院找駱鏢頭扛大木領短褐，或者去杏林醫館找白先生當試藥童領藥囊！」");

    add_response(({ "夜議", "案卷", "六大缺口", "密會" }),
        "老劉警惕地朝門外張望，悄悄關上二樓廂房木門：「幾位小哥小妹快請進！二樓最裡面那間背街靜房我已替你們留好了，熱茶點心管夠，有什麼要事關起門來商量，外頭巡丁隔著牆聽不見！」");
}
