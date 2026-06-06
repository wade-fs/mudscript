// Room: /u/d/devils/school7.c

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG
這裡是館主考較徒弟武功的地方,但由於徒弟日益增多,館主不再一一指
導,所有弟子需在此比武,獲勝弟子才能得到館主的親自指導．
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"school2",
  "south" : __DIR__"school6",
  "north" : __DIR__"school4",
  "east" : __DIR__"school8",
]));

        set("outdoors", "/open/wu");
        setup();
}
