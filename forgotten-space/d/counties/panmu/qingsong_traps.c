// /d/counties/panmu/qingsong_traps.c
// 盤木縣 (Panmu County) 房間 12/14：青松塢・獵場防獸陷阱帶 (30天衝突線：獵戶防獸)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("panmu");
    set_short("青松塢・防獸陷阱帶");
    set_long("密林深處的腐葉層下暗藏著青松塢老獵戶精心佈設的竹籤陷坑、翻板套索与\n"
             "塗抹雄黃藥粉的絆馬繩。樹幹上刻著明顯的獵戶警示刀痕，以防外人誤踩。然而\n"
             "北側幾處關鍵陷阱已被拖拽原木的滑車強行輾毀，留下凌亂的野豬與山狼腳印。\n"
             "向西可退回【青松塢・獵戶山村】。\n");

    set_stage_desc(1, "林班民夫越過界碑拖拽原木，輾壞了外圍三處防獸竹籤坑。");
    set_stage_desc(2, "青松塢獵戶在林道口重新釘下鐵齒捕獸夾並扣押滑車，雙方拔刀對峙。");
    set_stage_desc(3, "連夜秋雨沖毀林坡，受驚的大荒黑背山狼群順著缺口竄入陷阱帶外圍！");
    set_stage_desc(4, "商會林班認罰重立界碑，百工匠人協助獵戶在缺口加裝了連環機簧拒馬。");

    set_exits(([
        "west": "/d/counties/panmu/qingsong_hamlet.c",
    ]));

    set_coordinate(5, 4, 0);
}
