// /d/counties/zhenfeng/yamen_vault.c
// 鎮風縣 (Zhenfeng County) 房間 4/14：衛所地下案卷室・走山令舊檔 (對應卷二 Ch.62 燕隼查大伯燕山舊案)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_short("衛所地下案卷室・走山令舊檔");
    set_long("這間開鑿於防風城基巨岩下的乾燥石室，整齊存放著鎮風衛所三十年來的\n"
             "邊關出入簽押冊與外荒斥候陣亡撫恤卷宗。在標註「天星二十三年（五年前）」的\n"
             "鐵皮木櫃底層，鎖著一份加蓋金石商會內堂黑蓮印的《外荒走山令僱傭具結冊》——\n"
             "上面赫然按著大伯「燕山」的血指印，記錄其受僱深入極北裂谷勘探血精母脈後遭\n"
             "商會私衛封谷滅口的鐵證！向上拾級 (up) 可返回【鎮風縣衛所・邊防軍政廳】。\n");

    set_exits(([
        "up": "/d/counties/zhenfeng/yamen.c",
    ]));

    add_item("archive_cabinet", "標註『天星二十三年・外荒走山令』的鐵皮檔案櫃，內存燕山受商會僱傭入荒的原始簽押底單。");
    set_is_outdoor(0);
    set_coordinate(-1, 17, -1);
}
