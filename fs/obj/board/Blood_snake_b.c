inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("嗜血死亡排行榜",({"board"}));
	set("long","請(read)..");
	set("location","/open/clan/Blood_snake/room/hall");
	set("board_id","Blood_snake");
	set("capacity",50);
	set("make_clan","Blood_snake");
	setup();
}
