#include <ansi.h>
inherit BULLETIN_BOARD;
								
void create()
{
	set_name( HIY + "舞者公會記事版" + NOR ,({"dancer board", "board"}));
	set("location","/open/capital/room/dancer");
	set("board_id","dancerc");
	set("long",	"這是留言與記事之處。\n");
	setup();
	set("capacity", 50);
       set("master",({"cgy"}));
}
							
