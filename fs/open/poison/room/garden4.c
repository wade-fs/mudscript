// Room: /u/r/ranko/garden4.c
inherit ROOM;

void create ()
{
  set ("short", "毒園中央部份");
  set ("long", @LONG
這裡是靠近毒園的中央部份,此處所種的毒花,毒草也較一般所
常見到的毒性要來的強.也因此尋常毒物亦不敢輕異接近此處,除了
具有較猛烈毒性的毒物外,這裡已看不到其它的生物了。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"garden2.c",
  "west" : __DIR__"garden4-1.c",
  "south" : __DIR__"garden4-3.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/obj/source/rose_flower.c" : 2,
]));

  setup();
}
