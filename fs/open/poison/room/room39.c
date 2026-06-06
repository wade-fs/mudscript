inherit ROOM;

void create ()
{
  set ("short", "小屋");
  set ("long", @LONG
一塵不染的小屋中 ,放滿了竹製的家具 ,再配上爐子上煮茶的香
氣 ,真是讓人有一種超脫塵俗的感覺 ,一切的利祿功名 ,到了這
裡都彷彿成為薄暮輕煙 .....屋主是個文雅的書生 ,看起來是個
好人。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"room38",
]));
   set("objects", ([ /* sizeof() == 1 */
   "/open/poison/npc/batking2.c" : 1,
 ]));

  setup();
}
