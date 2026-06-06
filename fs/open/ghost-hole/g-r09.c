#include <ansi.h>
inherit ROOM;
void create ()
{
        set("short",YEL"幽冥道"NOR"草屋");
        set("long",@LONG
簡單的裝飾品掛滿了整個茅草屋, 這些裝飾看來
與在人間界可以看到的裝飾品並無兩樣, 由此可見得
住這的人十分嚮往人間界...
LONG);
        set("exits",([
        "east":__DIR__"g-r08",
        ]));
        set("no_transmit",1);
        setup();
}
