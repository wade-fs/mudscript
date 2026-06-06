// Room: /u/p/powell/room/gstore.c

inherit ROOM;

void create ()
{
  set ("short", "妓院");
  set ("long", @LONG
這是一家有名的妓院, 名叫麗春院, 由於人來人往不少, 因此
除了一樓後院當嫖客暫留的房間以外, 這大廳還充當客棧, 二樓以
上則全部當作廂房了. 不過老鴇最近悶悶不樂, 聽說水仙姑娘被惡
人谷的十大惡人抓走了, 外頭雖然人多, 卻沒人知道惡人谷位於何
處, 看來英雄救美的機會到了.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tree",
  "east" : __DIR__"road1.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/center/npc/hoodlum" : 1,
  "/open/center/npc/harlot" : 1,
]));
  set("light_up", 1);

  setup();
}
