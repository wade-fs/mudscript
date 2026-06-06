#include <ansi.h>
inherit ROOM;
void create ()
{
        set("short",YEL"幽冥道"NOR"草屋");
        set("long",@LONG
幾個椅子擺滿了整個草屋, 可見得此草屋之小, 
屋內有個木桌, 感覺上像是在家裡面閒聊泡茶所用
的木桌, 整個感覺彷彿置身於人間界的平常住屋一
般, 十分的祥和...
LONG);
        set("exits",([
        "out":__DIR__"g-r05",
	"west":__DIR__"g-r09",
        ]));
        set("objects",([
        __DIR__"npc/wis-man":1,
        ]));
        set("no_transmit",1);
        setup();
}
