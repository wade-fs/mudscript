// Room: /open/badman/room/forest12.c
// written by powell 96.4.26@FS

inherit ROOM;

void create ()
{
  set ("short", "惡人森林");
  set ("long", @LONG
你走進了一大片森林之中，走著走著你才發現四周的景物似乎
一直都沒變過，讓你完全失去了方向。原來這裡就是著名的惡人森
林，據說只有惡人谷的人知道如何順利通過這片森林。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"forest08",
  "west"  : __DIR__"forest09",
  "south" : __DIR__"forest11",
  "east"  : __DIR__"forest04",
]));
  set("outdoors", "/open/badman");

  set("objects", ([ /* sizeof() == 4 */
  "/open/badman/npc/wolf.c" : 4,
  ]));

  setup();
}

void init()
{
  add_action("do_search","search");
}
int do_search()
{
  object who;
  who = this_player();
  tell_object(who,"\n你發現了一個小洞...便順著洞口鑽了進去\n\n");
  tell_object(who,"\n......爬啊...爬啊......爬啊....\n\n");
  tell_object(who,"\n...爬啊..終於爬到出口了,你不禁喘了一口氣.\n\n");
  who->move("/open/badman/room/wolf01.c");
  tell_room(this_object(),"你只看到"+who->query("name")+"彎了身子,一下子就不見了\n");
  return 1;
}
