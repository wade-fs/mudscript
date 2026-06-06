inherit ROOM;

void create ()
{
  set ("short", "山間小徑");
  set ("long", @LONG
沿路森林蔭蔭鬱鬱 ,鳥語花香 ,更有許多的猴子迴盪於山谷之間
 ,看的令人心曠神怡 ,真是一個好地方。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room34.c",
  "east" : __DIR__"room32",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/u/h/houng/mob/monkey1.c" : 1,
]));

  setup();
}
