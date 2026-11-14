// /d/counties/zhenfeng/tannery.c
// 鎮風縣 (Zhenfeng County) 房間 9/14：鎮風軍械修造所・百工皮革弓弩分舵 (【物】道等效資格考場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_branch_org("org_baigong");
    set_qual_path("wu");
    set_short("鎮風軍械修造所・百工分舵");
    set_long("寬敞的石砌大工坊內瀰漫著濃烈的熟牛油、松香與硝皮氣味。數十名匠人\n"
             "正將北塞雪狼皮與犛牛生皮浸泡硝池、反覆捶打成刀箭難入的雙層防寒硬甲，另一側\n"
             "則在校準複合重弓的牛筋弦張力。百工總會駐鎮風匠師【溫鐵衣】在此主理邊關匠籍。\n"
             "有志於【物】道的行者可在此參加考核（輸入 exam 或 考取），獲發與都城完全等效之\n"
             "【百工正式匠籍】。往南走出工坊即回【八方武館邊關分舵】。\n");

    set_exits(([
        "south": "/d/counties/zhenfeng/bafang_garrison.c",
    ]));

    set_has_guild(1);
    set_has_forge(1);
    set_is_outdoor(0);
    set_coordinate(1, 18, 0);
}
