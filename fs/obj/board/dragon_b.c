inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("$HIY$龍神轉世錄$NOR$",({"board"}));
	set("long","一個幫派設計的佈告欄");
	set("board_id","dragon");
	set("make_clan","dragon");
	set("location","/open/clan/dragon/room/hall");
	set("capacity",50);
	set("master",({"roman"}));
	setup();
}
