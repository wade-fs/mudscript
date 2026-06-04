#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
set_name(HIC + "寒依留言板" + NOR,({"leoa board","board"}));
set("location","/u/l/leoa/workroom");
set("board_id","leoa_b");
set("long","寒依給人留話的板子。\n");
setup();
set("capacity",555);
}
