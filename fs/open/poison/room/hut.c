// Room: /u/r/ranko/hut.c
inherit ROOM;

void create ()
{
  set ("short", "小茅屋");
  set ("long", @LONG
一間以茅草搭成的茅屋，裡面堆放著一些雜物，似乎是農夫們堆放
器具的地方，亦是小孩子玩耍的場所。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"f5.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/child.c" : 2,
]));

  setup();
}

void init()
{
 object me = this_player();
 if(userp(me))
  {
   me->set("startroom","/open/wiz/courthouse");
  }
}
