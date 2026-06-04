inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
set_name(HIB + "紛落的雨滴" + NOR,({"board"}));
set("location","/u/g/guetenr/workroom");
set("board_id","guetenr_b");
set("long","雨水化為細絲不斷地飄落著...\n");
setup();
set("capacity",119);
}
