inherit ROOM;

void create ()
{
  set ("short", "石室");
  set ("long", @LONG

石室的牆壁相當平整而且光滑，你抬頭往上看，似乎有一個小洞可以通往
外面，不過對你來說那個小洞實在太高了，除非身長一丈才有可能攀上那
個小洞。

LONG);

  set("light_up",0);
  set("exits", ([ /* sizeof() == 1 */
  "south" :__DIR__"c1-2.c",
  
]));

  setup();
}
