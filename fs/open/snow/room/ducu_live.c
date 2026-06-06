#include <room.h>

inherit ROOM;

void create()
{
	set("short","獨孤小徑");
          set("long",@LONG
這是一條小路﹐往北通往獨孤愁生前所住的獨孤居﹐往南則是
通往獨孤陵﹐由於感念獨孤愁的關係﹐雪蒼派弟子將獨孤陵設在獨
孤居旁邊﹐而獨孤愁的家室仍居住在獨孤居﹐以便日夜追思獨孤愁
的英容。
LONG);
        set("exits", ([
	"south":__DIR__"ducu_room_in",
	"north":__DIR__"ducu_live1",
        ]) );
	set("light_up",1);
        setup();
}
