inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIC"圓桌騎士團"HIY"團誌"NOR,({"board"}));
set("location","/open/clan/Knights/hall.c");
set("board_id","Knights_b");
set("long","這是圓桌騎士團用來交流的留言版。\n");
setup();
set("capacity",50);
replace_program(BULLETIN_BOARD);
}
