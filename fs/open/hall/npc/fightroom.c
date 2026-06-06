// Room: /u/o/onion/newroom.c

inherit ROOM;

void create ()
{
  set ("short", "洋蔥專用競技場");
  set ("long", @LONG
這裡有如羅馬競技場一般的景觀﹐中央的廣場非常遼闊﹐專供洋蔥
大大測試東東。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "up" : "/u/o/onion/workroom",
]));
  set("light_up",1);
  set("no_clean_up", 0);


  setup();
}
