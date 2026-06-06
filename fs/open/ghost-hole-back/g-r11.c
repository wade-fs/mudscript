#include <ansi.h>
inherit ROOM;
void create ()
{
        set("short",YEL"幽冥道"NOR);
        set("long",@LONG
腳底踏的很不實在，彷彿站在稀鬆的土壤上面，
一點厚實感也沒有，四周偶爾總是會傳來陣陣血腥的
惡臭味，你無法搞清楚自己身處何處。
LONG);
        set("exits",([
        "west":__DIR__"g-r10",
        "north":__DIR__"g-r12",
        ]));
        set("no_transmit",1);
        setup();
}
