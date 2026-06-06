#include <ansi.h>
#include <room.h>
inherit ROOM;
                
void create ()
{
  set ("short", "近戰武器販賣處");
  set ("long", @LONG
這是葉秀殺特地引進的販賣處，以免殺手在沒有武器的情形下離開總壇而遇害
如果想補充長期作戰所需的裝備，倒是不錯的選擇。

LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"foodrm.c",
   ]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/npc/lee.c" : 1,]));
  setup();
}
