#include <ansi.h>
#include <room.h>
inherit ROOM;
                
void create ()
{
  set ("short", "綠雲組內部");
  set ("long", @LONG
	挖勒.....走錯路啦，這又是一條鬼斧神工通道，

	筆直的天然通道，讓你很難去想像這是怎麼產生的？

	看來該才應該走另外一個方向的道路，才找的到綠雲組組長的所在地。
	
LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"g4.c",
  "west" : __DIR__"g9.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
      "can" : "爐中火焰正鼎沸，試著將富士山秘草煉化吧。 ",]));
  setup();
}

/* 以後在加上有關殺手醫生的迷，利用search 
void init()
{
add_action("do_secret",({"secret"}));
}

int do_secret()
{
 object me;

 me=this_player();
 if(me->query("class") != "killer")
 return 0;
 tell_object(me,"這房間果然有秘密！！發現了通道，你立刻走了過去\n");
 me->move(__DIR__"mimirm.c");
}
*/
