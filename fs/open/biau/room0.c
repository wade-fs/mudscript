// Room: /open/su/room/biau_room1.c

inherit ROOM;

void create()
{
	set("short", "鑣局外堂");
	set("long", @LONG
    你一進到這裏,便感到一陣陣嚴靜肅穆的氣分,沒錯,這裏就是武威鑣局的外堂,
    和門外的感覺完全不同.
    在大堂之上,擺著兩張太師椅,坐著兩個人----趙鼎天(Ting-Tan Sau)和妻子--
    王素素(Sue-Sue Wang).
    從擺設看來,兩人該都是習武之人,但是,牆上卻有一張張山水,教人疑惑.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"opening1",
  "north" : __DIR__"room6",
  "east" : __DIR__"room1",

]));
	set("objects", ([ /* sizeof() == 2 */
//  "/u/j/jcder/npc/ting.c" : 1,
  "/u/j/jcder/npc/wang.c" : 1,
]));

	setup();
}
