inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("未設計之佈告欄",({"board"}));
	set("long","一個幫派設計的佈告欄");
	set("capacity",50);
	set("board_id","demon_castle");
	set("location","/open/clan/demon_castle/room/hall");
	setup();
}
