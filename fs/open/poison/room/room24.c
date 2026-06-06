inherit ROOM;

void create ()
{
  set ("short", "路口");
  set ("long", @LONG
一條平凡的小路 ,卻有一個不平凡的人守在路口 ,哇咧 !真叫人
又好奇又害怕的說 :D~~~~~

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room23.c",
  "north" : __DIR__"room25.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/poison/npc/duan.c" : 1,
]));

  setup();
}
 int valid_leave(object me, string dir)
 {
        if(dir=="north"&&present("duan",environment(me)))
  {
    if(!me->query_temp("allow-north")&&!me->query_temp("playboy"))
    return notify_fail("段正淳攔住你的去路 ,說道 :本王有讓你進去嗎 ?\n");
   }
  return 1;
}

