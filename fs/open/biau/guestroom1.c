// Room: /u/o/onion/room/r_room2.c

inherit ROOM;

void create()
{
	set("short", "鏢局客房");
	set("long", @LONG
一間乾乾淨淨的客房,桌子上連一點灰塵都沒有,可知打掃這裡的僕人是多認真的了.
客房裡還放著一張雕工精美的紅檜大床,床頭上雕著蟠龍浮雲,床尾刻著水池青蓮,你
心想著連客房都如此氣派,想必此鏢局的聲勢和威望有多高了...
    這個房間的角落裡還放了一面古銅的鏡子(mirror),隱隱泛出青光..
LONG
	);
set("item_desc", ([
	"mirror" : "
	你仔細的往鏡中一瞧,才赫然發現自己長的實在是～有～夠～醜～..
	你不禁悲從中來,嚎啕大哭..\n"
	]));

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room3",
]));
	set("valid_startroom", "1");

	setup();
}
