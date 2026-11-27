// d/city/center/yamen_prison.c
// 金石府死牢

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("府衙地牢・死牢");
    set_long("厚逾尺許的青黑玄武岩石壁阻絕了一切天光，唯有幾支松明火把跳動著慘淡火苗。\n"
             "空氣中瀰漫著濃烈的霉爛、鐵鏽與血腥臭味。沉重的生鐵鐐銬鎖在深處石壁上，\n"
             "獄頭鐵鐐張斜靠在刑椅上打盹，幾名獄卒正圍著木桶擲骰喝酒。\n"
             "西面穿過鑄鐵牢門可回到府衙正堂。\n");

    set_exits(([
        "west": "/d/city/center/yamen.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", HIB "青黑玄武岩牢壁濕冷滲水，生鐵鐐銬粗糲生鏽、重得令人手腕發沉。" NOR);
    set_smell("default", HIR "潮濕爛稻草霉臭、松明火把黑煙、鐵鏽與久散不去的濃烈血腥氣。" NOR);
    set_listen("default", WHT "牢房深處鐵鏈偶爾拖地叮噹一響，伴隨角落獄卒擲骰喝酒的壓低笑鬧。" NOR);

    spawn_npc("/clone/npc/yamen_prison_tieliaozhang.c");
    spawn_npc("/clone/npc/yamen_prison_zhaodegui.c");
    spawn_npc("/clone/npc/yamen_prison_hubaihu.c");
}
