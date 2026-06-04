inherit BULLETIN_BOARD;
#include <ansi.h>
 
void create()
{
    set_name(HIW + "影評版" + NOR, ({ "board" }) );
    set("location", "/u/d/daniel/workroom");
    set("board_id", "daniel_b");
    set("long", "你秀逗喔!?這有啥好看,就是給你 post 用的.\n" );
    setup();
    set("capacity", 100);
    set("master",({ "daniel" }) );
}
