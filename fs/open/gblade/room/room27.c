// Room: /u/m/moner/tree/room4.c
inherit ROOM;

void create ()
{
  set ("short", "小徑");
  set ("long", @LONG

這是一條羊腸小徑，往前望去，只見白石夌崎，或如鬼怪，或似 
猛獸，縱橫拱立，路上苔鮮斑駁，藤蘿掩映間，只餘這條小路蜿延向前。
前方傳來陣陣的花香，吸著香氣，你不禁有些頭暈目眩。

LONG);

  set("light_up", 1);
  set("outdoors", "wind");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room28.c",
  "east" : __DIR__"room5.c",
]));

  setup();
}
