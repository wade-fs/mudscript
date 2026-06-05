inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HBRED+HIY + "bugs公佈版" + NOR,({"board"}));
set("location","/open/wiz/bug_room");
set("board_id","bug");
set("long","給wiz公佈bugs用的,請勿隨意亂post,報bug請直接打record,thx\n");
setup();
set("capacity",300);
replace_program(BULLETIN_BOARD);
}
