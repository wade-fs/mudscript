// /d/counties/zhuoshui/miasma_shrine.c
// 濁水縣 (Zhuoshui County) 房間 6/15：濁水鎮水祠・宣道司辟瘴觀 (【法】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_branch_org("org_xuandaosi");
    set_qual_path("fa");
    set_short("濁水鎮水祠・宣道司辟瘴觀");
    set_long("這座鎮壓於黑水河彎高阜上的青石道觀，大殿四角立著四尊鎮水鐵犀，陣眼\n"
             "日夜散發出清心辟瘴的淡青微光，將大澤湧上的腐骨毒瘴隔絕在外。宣道司外派道官\n"
             "【滄浪道人】在此主持水脈淨化與符道辟瘴考核。有志於【法】道的行者可在此申請\n"
             "地方初階度牒考核（輸入 exam 或 考取），獲發與都城宣道司完全等效之【大乾觀象受牒度牒】。\n"
             "往南下階可返回【濁水縣署】。\n");

    set_exits(([
        "south": "/d/counties/zhuoshui/yamen.c",
    ]));

    set_has_guild(1);
    set_is_outdoor(0);
    set_coordinate(5, 7, 0);
}
