#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
set_name(HIC+BBLU + "魔法寶鏡" + NOR,({"magic mirror","board"}));
set("long", @LONG

一個帶有魔法的神奇寶鏡，據說看了能夠讓人年輕十歲..

LONG);
set("location","/u/m/magic/workroom");
set("board_id","magic_b");
setup();
set("capacity",100);
}

