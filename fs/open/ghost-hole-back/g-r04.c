#include <ansi.h>
inherit ROOM;
void create ()
{
        set("short",YEL"幽冥道"NOR"小村");
        set("long",@LONG
你走進了幽冥界唯一的小村莊, 這裡可以說是
幽冥裡與人間界最相似的地方了, 只有少數幾個觀
念與人類相同的魔物住在這裡, 在你西邊是販賣幽
冥界所有雜物的地方, 東邊則是讓來到幽冥界人們
所休息的地方...
LONG);
        set("exits",([
        "south":__DIR__"g-r05",
	"west":__DIR__"g-r06",
	"east":__DIR__"g-r07",
        "north":__DIR__"g-r03",
        ]));
        set("no_transmit",1);
        setup();
}
