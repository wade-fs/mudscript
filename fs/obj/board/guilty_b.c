inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HBMAG+HIY + "犯罪公佈及上訴版" + NOR,({"board"}));
set("location","/open/wiz/guilty_room");
set("board_id","guilty");
set("long","給wiz公佈犯罪人所犯的罪,及給犯罪者有上訴的機會\n");
setup();
set("capacity",300);
replace_program(BULLETIN_BOARD);
}
