// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "天池");
	set("long", @LONG
愈靠近湖泊不知怎地就愈覺得溫暖，在湖的
周圍完全看不到積雪，草木也恢復青翠的綠色，
而湖水也不結冰。用手輕輕一觸竟然還是溫的！
在這冰天雪地中竟還有如此的湖泊，令人猜想不
透。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"m5",
	"south" : __DIR__"m3",
]));
	set("outdoors", "1");

	setup();
}
