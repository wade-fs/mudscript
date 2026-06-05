#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
set_name(HIY + "汽車衛星導航視窗" + NOR, ({"board"}));
set("location","/u/f/ferrai/workroom.c");
set("board_id","ferrai_b");
set("long",HIY + "透過衛星的傳輸,你可以把所的資料記憶上去\n" + NOR);
    setup();
set("capacity", 80);
}


