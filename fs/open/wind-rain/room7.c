// by roger
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","芙蓉湖畔");
set ("long", @LONG
    市肆依然熱鬧，賣針線的小開跟一個打扮得花枝招展的小丫鬟正在
打情罵俏，一名家丁正在替公子哥兒的主人卸下馬鞍，另一名正在清洗
下馬石。買雞的正在和賣雞的講價錢，大概忘了竹籠裡的那些雞不同意
所以咯咯亂叫地十分厲害。馬房裡的馬匹，因飼料不甚滿意，也長嘶起
來，交織成一片。
LONG);



  set("exits", ([
            "east"  : __DIR__"room4",
            "west"  : __DIR__"room8",
                ]));

       

        setup();
}
