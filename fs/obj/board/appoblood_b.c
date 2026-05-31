inherit BULLETIN_BOARD;
#include <ansi.h>
void create()
{
   set_name("魔血紀事", ({"board"}));
   set("location","/open/gsword/room1/blood1/r10");
   set("board_id","appoblood_b");
   set("long","血魔專屬紀事.. \n");
   setup();
   set("capacity", 50);
   set("master",({"appo"}));
}
