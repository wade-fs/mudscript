// /u/j/judd/room/r14.c
inherit ROOM;

void create ()
{
  set ("short", "中堂後廳");
  set ("long", @LONG
後廳是供人休息的地方，也是儒門接待訪客的地方，這裡的桌椅
全部都是木製的，中間有一個圓桌，上面放滿了各式的水果(fruit)
，不但可以解渴，還可以止饑．
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "fruit" : "這些水果看起來好像很好吃說，但是偷吃是不好的行為．
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"r17.c",
]));
  set("light_up", 1);

  setup();
}
