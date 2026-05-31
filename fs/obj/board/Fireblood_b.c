inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
	set_name("[1m[31m燄血[33m修羅[37m照妖鏡[0m",({"board"}));
	set("long","[1m[32m鏡子不斷搖晃著...搖晃著... 搖晃著...搖晃著...搖晃著... 搖晃著...[0m");
	set("board_id","Fireblood");
	set("make_clan","Fireblood");
	set("location","/open/clan/Fireblood/room/hall");
	set("capacity",50);
	setup();
}
