inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("燄血修羅照妖鏡",({"board"}));
	set("long","鏡子不斷搖晃著...搖晃著... 搖晃著...搖晃著...搖晃著... 搖晃著...");
	set("board_id","Fireblood");
	set("make_clan","Fireblood");
	set("location","/open/clan/Fireblood/room/hall");
	set("capacity",50);
	setup();
}
