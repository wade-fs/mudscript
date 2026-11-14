// /d/counties/liefan/yamen.c
// 烈礬縣 (Liefan County) 房間 3/14：烈礬縣衙・礦稅與火政堂

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_short("烈礬縣衙・礦稅火政堂");
    set_long("烈礬縣衙大堂以耐火紅磚鋪地，堂上高懸「謹防地火」鐵牌。由於全縣產出\n"
             "之高純硝石與硫磺皆屬官禁火器配料，縣丞與百工督辦每日在此聯署核銷各礦井的\n"
             "火藥領用牌票。往南出衙即回【銅礬硃砂大集】，向西穿過月洞門則是【烈礬鎮煞火祠】。\n");

    set_exits(([
        "south": "/d/counties/liefan/market.c",
        "west":  "/d/counties/liefan/fire_shrine.c",
    ]));

    set_is_outdoor(0);
    set_coordinate(7, 14, 0);
}
