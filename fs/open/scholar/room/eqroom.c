// Room: /open/start/room/eqroom
inherit ROOM;

void create ()
{
  set ("short", "儒門休息室");
  set ("long", @LONG
這是儒門專用的休息室兼儲藏室，在此地
可以躲開敵人的追趕，也可以靜靜的在此地練
功，當你想前往平南城時，請打(plan)，若想
前往中央繹站，只要打(literate)即可前往．
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"r17.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/boy.c" : 1,
]));

  setup();
}
 void init()
{
add_action("do_plan","plan");
add_action("do_literate","literate");
}
int do_plan()
{
  object me;
  me = this_player();
  if(me->query("class")!="scholar")
 return notify_fail("只有儒生能用。\n");
 me->move("/open/ping/room/road3");
  return 1;
}
int do_literate()
{
object me;
me=this_player();
if(me->query("family/family_name")!="儒門")
return notify_fail("只有儒生能用。\n");
me->move("/open/center/room/inn.c");
return 1;
}
