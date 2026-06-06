// Room: /open/poison/room/room2
inherit ROOM;

void create ()
{
  set ("short", "內室");
  set ("long", @LONG
這是獵人家內室，室內佈置不像一般獵戶，北面牆上掛
了幾幅字畫，地上擺了一些盆栽，看來相當清靜高雅，西側
有一布簾，上面繡了一幅巨大的聖火像，似乎其後隱藏些什
麼。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"path1",
  "east" : __DIR__"room3",
]));
  set("light_up", 1);

  setup();
}
