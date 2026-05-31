inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("[24m龍[13m之[25m岩[0m",({"board"}));
	set("long","聖域內所有的大小事情都公佈在這粒大岩之上");
	set("board_id","dragon-world");
	set("capacity",50);
	set("make_clan","dragon-world");
	set("location","/open/clan/dragon-world/room/hall");
	setup();
}
