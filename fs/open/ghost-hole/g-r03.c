#include <ansi.h>
inherit ROOM;
void create ()
{
        set("short",YEL + "幽冥道" + NOR);
        set("long",@LONG
陣陣的腥臭味不斷的撲鼻而來, 你忍不住的捏住
了鼻子, 地上偶爾會傳來陣陣的搖晃, 感覺很不舒服
, 南邊似乎有生物在那叫喊著, 或許你應該往那邊看
看..
LONG);
        set("exits",([
        "south":__DIR__"g-r04",
        "north":__DIR__"g-r02",
        ]));
        set("no_transmit",1);
        setup();
}
