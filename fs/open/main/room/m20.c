// This is a room made by roommaker.

inherit ROOM;

void create ()
{
  set ("short", "農戶");
  set ("long", @LONG
一間簡單的小房間，裡面擺設一看就知道這邊住的是標準的庄稼漢，牆壁上掛著
斗笠，蓑衣，但似乎沒有什麼有用的東西。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/main/room/M19",
  "north" : "/open/main/room/M16",
]));

  setup();
}
