#include <room.h>
inherit ROOM;
 void create()
{
  set("short", "玩家議見發表室");
  set("long", @LONG
  各位...最近本派非非非非非常之冷清,因此希望玩家能夠多多建議一些
也歡迎暫時灌水亦可....
                       玩家可開始在此留言了....no idea.




LONG);
        set("exits", ([ /* sizeof() == 1 */
	"south":__DIR__"r3",
	"west":"/open/killer/room/r0.c",
  ]));
       setup();
        call_other("/obj/board/killerwiz_b","???");
}
int valid_leave(object me, string dir)
{
  if (me->query("class")!="killer" && dir=="west")
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
