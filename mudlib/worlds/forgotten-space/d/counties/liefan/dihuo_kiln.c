// /d/counties/liefan/dihuo_kiln.c
// 烈礬縣 (Liefan County) 房間 12/14：地火堡・三座官造耐火大窯 (對應卷二 Ch.63 特級耐火白泥出貨底單 & 30天 Stage 2)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_short("地火堡・官造耐火大窯");
    set_long("三座高達兩丈的饅頭形耐火大窯引地底真火助燃，專門燒製能承受萬度高溫\n"
             "的百工特級耐火磚與熔煉坩堝。窯旁值班石屋的鐵匣內，留存著三個月前金石商會\n"
             "內堂以「金蓮環刀印」一次提領三萬斤【烈礬特級耐火白泥】與高純金剛砂的原始出貨底單——\n"
             "正是私造黑石鋪【丙字柒號】血精除渣坩堝的源頭鐵證！往南可退回【地火堡・耐火窯工聚落】。\n");

    set_stage_desc(2, "因抗議百工分舵壓價與重罰，地火堡三座官造大窯集體封門熄火罷工，生銅與耐火料斷供！");

    set_exits(([
        "south": "/d/counties/liefan/dihuo_fort.c",
    ]));

    add_item("kiln_ledger", "窯場出貨底冊，清楚記載商會內堂三個月前憑金蓮環刀印提走三萬斤特級耐火白泥。");
    set_has_forge(1);
    set_coordinate(6, 15, 0);
}
