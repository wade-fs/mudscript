// /clone/npc/chen_qing.c
// 陳青・丹鼎退門藥徒 (chen_qing) - 斷崖石棚驛站 (Ch.83)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("陳青");
    set_short(YEL "纏紗退門藥徒" NOR " 陳青");
    set_long("一名消瘦年輕的男子，雙手纏著層層發黑的舊麻布，指縫間隱隱滲出一絲淡淡的礦酸氣味。\n"
             "他沉默地縮在火塘角落，只顧著替同行的小女孩撥開烤焦的麥餅邊緣。\n");
    set_id(({ "chen_qing", "chen qing", "chenqing", "陳青", "退門藥徒" }));

    setup_archetype("F", 24);
    set("class", "gong");
    set("faction", "retired");
    set("roles", ({ "witness", "herbalist" }));
    set("home_room", "/d/wastes/north_road/post_station.c");

    add_response(({ "丹鼎", "藥田", "退門者", "潰爛" }),
        "陳青抬起腫脹發亮的眼睛，低聲道：「半個月前百草谷藥田水脈發酸，管事非逼著交不起靈石歲貢的外門雜役\n"
        "赤手進水溝挖根。我這雙手爛得見了骨頭，反被扣去半個月工錢賠償兩株枯死靈草……我沒膽量跟大長老鬧，只能趁夜逃下山。」");

    add_response(({ "水脈", "酸氣", "礦酸" }),
        "陳青指了指紗布邊緣沾著的一丁點灰黃結痂：「那水溝裡滲出來的酸氣帶著股鐵鏽和硫磺混在一起的怪味兒，\n"
        "聽山裡老藥農私下唸叨，似乎與後山地肺煙道近來排渣有關，可誰也不敢明著查。」");
}
