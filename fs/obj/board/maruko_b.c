inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIR"丸子販賣機"NOR,({"board"}));
 set("location","/open/clan/maruko.c");
set("board_id","maruko");
set("long","這是讓一串大丸子的討論佈告欄\n");
setup();
set("capacity",50);
replace_program(BULLETIN_BOARD);
}
