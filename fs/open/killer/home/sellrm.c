#include <ansi.h>
#include <room.h>
inherit ROOM;
                
void create ()
{
  set ("short", "殺手販賣部");
  set ("long", @LONG
這是殺手們接受特訓後的買東西的好地方。裡面應有盡有。  
如果只是想吃飽的話，可以到殺手餐廳處吃，會比較便宜哦。。。
如果想補充長期作戰所需的糧草與裝備，倒是不錯的選擇。

LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r19.c",
   ]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/npc/sellman.c" : 1,]));
  setup();
}
