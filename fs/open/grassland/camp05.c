// Room: /open/grassland/camp01
#include <ansi.h>
inherit ROOM;
int get = 10;
void create ()
{
  set ("short", "伙房");
  set ("long", @LONG
這個帳棚裡面充滿著各種燒煮工具，整個蒙古大軍的伙食都是由此處所
提供的，這裡除了工具之外，還擺放著一些食材，看來如果有需要可以
偷偷的偷(steal)一點走。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r12",
]));
  set("no_transmit", 1);
  set("no_scale", 1);

  setup();
}
void init()
{
  add_action("do_steal","steal");
}
void reset()
{
  ::reset();
  get = 10;
}
int do_steal(string item)
{
  object r;
  object me;
  if(!item || (item != "rice" && item != "糯米"))
    return notify_fail("你要偷些什麼？\n");
  if(get == 0 )
    return notify_fail("你已經把這裡的糯米給偷完了。\n");
  get--;
  me = this_player();
  r = new(__DIR__"/obj/rice.c");
  r->move(this_player());
  if(me->query_temp("control"))
    me->set_temp("control_rice",1);
  write(HIW"你成功\的偷取到糯米。\n"NOR);
  return 1;
}
