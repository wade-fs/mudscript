// /clone/npc/zhou_tieshan.c
// 周鐵山・八荒退門武師 (zhou_tieshan) - 斷崖石棚驛站 (Ch.83)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("周鐵山");
    set_short(CYN "斷臂退門武師" NOR " 周鐵山");
    set_long("一名三十五六歲的壯碩漢子，身上的粗布武服胸口處留著一塊明顯被撕去徽記的針腳。\n"
             "他的右袖空蕩蕩地垂著，左手握緊護著身旁裹棉被的妻女，眼神像受傷的孤狼般帶著疲憊與警惕。\n");
    set_id(({ "zhou_tieshan", "zhou tieshan", "tieshan", "周鐵山", "退門武師" }));

    setup_archetype("C", 36);
    set("class", "wu");
    set("faction", "retired");
    set("roles", ({ "witness", "craftsman" }));
    set("home_room", "/d/wastes/north_road/post_station.c");

    add_response(({ "八荒", "退門者", "歲貢", "黑山營" }),
        "周鐵山低頭看著空蕩蕩的右袖，冷笑一聲：「三年前賣了兩畝薄田湊齊靈石進黑山營，頭一年還算風光。\n"
        "到了第二年要繳『煞血歲貢』，交不出靈石的就得去頂最前頭的塌牆缺口。我的右臂被鐵背荒狼咬碎，\n"
        "養息院只給貼便宜止血灰，逼我劈一輩子柴抵藥債，不然就領十兩遣散費滾下山。」");

    add_response(({ "雲津", "泥途", "修補", "生計" }),
        "周鐵山緊緊攥住手裡的紙條，聲音沙啞了幾分：「南歸八百里大雪不好走，我妻小拖不起。\n"
        "若金石南關那頭站不住腳，等你們在雲津西街把【泥途商棧】的牌子掛穩了，老子左手修雪橇皮帶一樣利索，不偷不搶也能掙口熱飯。」");
}
