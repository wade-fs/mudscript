#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "交叉路口");
  set ("long", @LONG

   你來到了一個廣大的山谷之中。前方似乎有一個建築物。
   東北方是一片山林群，樹木並不是很多。
   在一旁有豎立了一個標示牌(sign)
   

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 3   南方要接回後山的房間中*/
     "northeast" : __DIR__"hr2.c",
     "north" : __DIR__"hr5.c",
     "south" : "/open/killer/mon/room/wood14.c",   
]));
  set("item_desc", ([ /* sizeof() == 2 */
        "sign":" 殺手工會老大所在山區，\n如果不是來入籍的平民請儘速離開\n",
]));

  setup();
}
