// Room: /u/s/sueplan/newplan/area/room4
inherit ROOM;

void create ()
{
  set ("short", "武曲星");
  set ("long", @LONG
武王就位後，一面積極從從事滅殷復仇，一面施行德政，使人民安
居樂業，自己也享天壽後才去世。太白金星很佩服武王討紂的英勇武功
，便請他的靈魂永住武曲星，掌管『財富』和『武勇』。因為他在世期
間武功既好，又積極謀求人民的財富。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/scholar_show.c" : 1,
]));
  set("light_up", 1);
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room5.c",
  "south" : __DIR__"room3.c",
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if(dir=="enter"&&present("scholar",environment(me)))
  {
  return notify_fail("你發覺有人擋在你面, 不讓你過!!!\n");
  }
  return 1;
}
