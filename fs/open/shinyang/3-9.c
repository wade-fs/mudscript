// Room: /u/w/whatup/area/shinyang/3-9.c
inherit ROOM;

void create ()
{
  set ("short", "襄陽城驛站");
  set ("long", @LONG
這裡是襄陽城的驛站，這裡旅客絡繹不絕，貨物上下十分的頻繁
，真不愧是中原著名的交通要衝貨物往來之地！這裡是前外塞外之地
必經的城市，在這裡可以看到形形色色的人種。
LONG);

  set("no_transmit", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/oldman" : 2,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"3-8.c",
]));
  set("no_auc", 1);
  set("light_up", 1);

  setup();
}
