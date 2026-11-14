// /d/counties/zhenfeng/suibing_granary.c
// 鎮風縣 (Zhenfeng County) 房間 14/14：碎冰堡・軍屯地下糧窖 (對應卷二 Ch.62 邊軍欠餉與軍糧調撥)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_short("碎冰堡・軍屯地下糧窖");
    set_long("這座深挖於永凍土層下的巨型石窖，本是儲備邊關三軍冬糧的戰略要地。\n"
             "然而一排排木架上卻大半空置，僅存的幾十袋炒麵與鹹肉上還貼著金石商會高價折算\n"
             "抵充軍餉的封條——清楚映照出北關將校因軍餉長期遭拖欠而被迫受制於商會的結構困境。\n"
             "往南出窖可返回【碎冰堡・獵獸屯兵寨】。\n");

    set_exits(([
        "south": "/d/counties/zhenfeng/suibing_fort.c",
    ]));

    set_is_outdoor(0);
    set_coordinate(1, 17, -1);
}
