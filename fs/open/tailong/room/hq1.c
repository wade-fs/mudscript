inherit ROOM;

void create ()
{
  set ("short", "地底密室");
  set ("long", @LONG
完全沒有光線的密室，但是空氣卻不會很悶，空間狹小
可以看得出來是被人隨便弄出來的。

LONG);

  set("exits", ([
  "north" : __DIR__"hq2",
]));
  set("no_magic",1);
  set("no_kill",1);
  set("no_fight",1);
  set("no_transmit",1);

  setup();
}

