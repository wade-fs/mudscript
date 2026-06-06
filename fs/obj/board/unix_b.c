#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
set_name("天幻星石", ({ "Sky-star Board", "board" }) );
        set("location", "/u/u/unix/workroom");
        set("board_id", "unix_b");
        set("long", 
"UNIX的工作日誌-------------------------------------------" );        setup();
        set("capacity", 30);
}


