inherit ROOM;

void create ()
{
  set ("short", "豬舍");
  set ("long", @LONG
一進門就聞到一股腥味 ,天哪 .....怎麼會跑到豬舍來ㄋ ?眼看
著他們一步步的逼近 ,喔喔 !真是噁心死了。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room29",
]));
  set("objects", ([ /* sizeof() == 3 */
  "/open/poison/npc/pig3.c" : 2,
  "/open/poison/npc/pig2.c" : 1,
  "/open/poison/npc/pig1.c" : 1,
]));

  setup();
}
