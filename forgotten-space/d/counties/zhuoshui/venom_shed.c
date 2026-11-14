// /d/counties/zhuoshui/venom_shed.c
// 濁水縣 (Zhuoshui County) 房間 8/15：濁水百草毒理棚・採百草毒理分號 (【物】道等效資格考場，對應卷二 Ch.64)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_branch_org("org_xinglin");
    set_qual_path("wu");
    set_short("濁水百草毒理棚・採百草分號");
    set_long("這間通風極佳的高腳竹棚內，擺滿了浸泡著腐骨水蜥毒囊、泥沼赤練蛇膽與\n"
             "地陰腐骨草的琉璃藥甕。都城採百草分堂特派毒理藥師【白青竹】在此主理劇毒提純\n"
             "與以毒攻毒之術（嚴格登錄每一份劇毒母液去向）。有志於【物】道醫毒分支的行者\n"
             "可在此參加考核（輸入 exam 或 考取），獲發與都城完全等效之【杏林坐堂行醫資格】。\n"
             "向西出棚即回【浮橋金砂水集】。\n");

    set_exits(([
        "west": "/d/counties/zhuoshui/market.c",
    ]));

    set_has_guild(1);
    set_is_outdoor(0);
    set_coordinate(7, 6, 0);
}
