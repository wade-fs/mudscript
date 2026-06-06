#include <room.h>
inherit ROOM;
 void create()
{
  set("short", "殺手報報室");
  set("long", @LONG
           -------  給我報報，我給你全世界  --------
       殺手總壇，目前擴建中。如果有任何蟲蟲，請儘速回報。
       如果蟲蟲夠大隻的話，天才小渡會透露一些總壇資料。
       呵。。。總壇是為殺手設計的。請好康的，不要亂說出去。
       不然被迫改掉，我可不管。大家請在此留言.....

LONG);
        set("exits", ([ /* sizeof() == 1 */
            "north":__DIR__"r0.c",
            "south":__DIR__"floorm.c",
  ]));
       setup();
        call_other("/obj/board/killerwiz_b","???");
}
int valid_leave(object me, string dir)
{
  if (me->query("class")!="killer" && dir=="north")
 return notify_fail("這是殺手的禁地!由於你沒練霸雨螫魂,故你無法進入!\n");

return ::valid_leave(me,dir);
}
void init()
{
  add_action("do_pass","pass");
}
int do_pass()
{
  object me;
  me = this_player();
  me->move("/open/center/room/inn");
  return 1;
}
