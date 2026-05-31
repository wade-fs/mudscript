#include <ansi.h>
inherit BULLETIN_BOARD;
								
void create()
{
	set_name( HIC "夜夢小築記事版" NOR ,({"dancer board", "board"}));
	set("location","/open/dancer/room/start");
	set("board_id","dancer");
	set("long",	"這是留言與記事之處。\n");
	setup();
	set("capacity", 50);
       set("master",({"cgy","lum"}));
}
							
