// Room: /u/u/unfinished/room/is10.c
inherit ROOM;

void create ()
{
  set ("short", "樹林");
  set ("long", @LONG
你身在茂盛的樹林之中, 樹葉遮蔽了陽光, 森林中一片黑暗, 從四周不時傳
來奇異動物的叫聲, 在這陰暗的空間聽起來格外陰森詭異. 在野獸的嚎叫聲中,
你隱約聽見在你的東邊有些許流水的聲音. 東邊的地勢似乎比較高聳, 而在北邊
久是樹林的出口.
LONG);

  set("outdoors", "/u/u");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"is14.c",
  "east" : __DIR__"is11.c",
  "south" : __DIR__"is6",
]));

  setup();
}
