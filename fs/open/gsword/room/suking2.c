// Room: /u/s/smore/room/suking/suking2.c

inherit ROOM;

void create ()
{
  set ("short", "府衙大廳");
  set ("long", @LONG
走進這大廳，周圍肅穆的氣氛讓你不敢四處亂看，不過你依
然可以感覺得到四周的裝設氣派堂皇，又不流於俗套可見大將軍
左正也不是一個只會打戰的草包.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : "/open/gsword/room/suking3",
  "north" : "/open/gsword/room/suking7",
  "east" : "/open/gsword/room/suking9",
]));

  set("light_up", 1);

  setup();
}
