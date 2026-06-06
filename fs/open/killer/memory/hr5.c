#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

   你來到了一個細長的的山路之中。四周傳來陣陣的殺氣。
   北方是一間小莊園，目前還不是看得很清楚。
   在一旁有豎立了一個標示牌(sign)
   

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 3   南方要接回後山的房間中*/
     "north" : __DIR__"hr7.c",
     "south" : __DIR__"hr1.c",   
]));
  set("item_desc", ([ /* sizeof() == 2 */
        "sign":" 前方是通吃小築，內有迷鎮，請速離開\n",
]));
 set("objects",([
  "/open/killer/npc/spy4.c":1,]));
  setup();
}
