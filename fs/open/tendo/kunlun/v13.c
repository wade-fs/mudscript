// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "望月樓");
	set("long", @LONG
這兒是客棧的第二層樓，可以從這清楚地看
到整個村莊的鳥瞰和南邊清澈見底的河水，晚上
可以看到河上倒掛的彎月和漁船上點點的燈光。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"down"  : __DIR__"v12",
]));
	set("objects", ([ /* sizeof() == 2 */
          ]));

	set("light_up",1);
	set("outdoors", "0");

	setup();
}
