// /d/counties/zhongshi/stone_guild.c
// 重石縣 (Zhongshi County) 房間 6/14：重石石作總坊・百工分舵 (【物】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhongshi");
    set_branch_org("org_baigong");
    set_qual_path("wu");
    set_short("重石石作總坊・百工分舵");
    set_long("這座宏偉的石拱工坊乃府城百工總會駐重石縣之石作與生鐵鍛造分舵。院內\n"
             "擺放著測試條石抗壓極限的千斤墜錘架與精準的墨斗卡尺。百工石作大匠韓老雕之姪\n"
             "【韓千鈞】在此主持地方匠籍核驗，凡能憑錘聲辨出條石暗裂並精準放樣者，皆可請試\n"
             "驗技（輸入 exam 或 考取），登錄名冊成為正經領籍的【百工正式匠籍】。\n"
             "向西返回【石鐵大集】，往東則通往石工聚居的【穿山寨】。\n");

    set_exits(([
        "west": "/d/counties/zhongshi/market.c",
        "east": "/d/counties/zhongshi/chuanshan_camp.c",
    ]));

    set_has_forge(1);
    set_has_guild(1);
    set_is_outdoor(0);
    set_coordinate(-2, 6, 0);
}
