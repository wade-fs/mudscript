// Room: /u/s/smore/room/suking/suking3.c

inherit ROOM;

void create ()
{
  set ("short", "府衙大廳");
  set ("long", @LONG
走進這大廳，周圍肅穆的氣氛讓你不敢四處亂看，不過你依
然可以感覺得到四周的裝設氣派堂皇，又不流於俗套，可見大將
軍左正也不是一個只會打戰的草包.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : "/open/gsword/room/suking1",
  "west" : "/open/gsword/room/suking4",
  "north" : "/open/gsword/room/suking6",
  "east" : "/open/gsword/room/suking2",
]));

  set("light_up", 1);

  setup();
}
