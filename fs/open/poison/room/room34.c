inherit ROOM;

void create ()
{
  set ("short", "猴王洞");
  set ("long", @LONG
走著走著 ,突然看見一隻特別大的猴子 ,定神一看 ,原來是個人
披著猴皮 ,旁邊還有一群小猴子正端著水果 ,哇咧 ,這種人還是
少惹為妙的好。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room33",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/u/h/houng/mob/monkey1.c" : 1,
  "/open/poison/npc/ren.c" : 1,
]));

  setup();
}
