inherit ROOM;

void create ()
{
  set ("short", "北院走廊");
  set ("long", @LONG
這裡是天龍寺的北院,從這裡往外望去就是陡峭的山壁了,而往南側
看去便是兜率大士院,這也是天龍寺中的一個有名的建築物。
LONG);

  set("exits", ([ /* sizeof() == 2 */
   "east" : __DIR__"aa29",
   "west" : __DIR__"aa20",
]));
}
