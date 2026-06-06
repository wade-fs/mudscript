// Room: /open/wu/room/luroom14.c
// 瀧山武館的花園
inherit ROOM;
void create()
{
        set("short", "小溪邊");
	set( "build", 12 );
        set("long", @LONG
這裏是瀧山武館的花園南方的小溪,清徹見底的小溪,讓人好想下去玩水
一般,從上面更可以看見水下有許多生物,如魚、蝦..等,聽聽溪流聲,便
可以消除,平日緊張的生活步調。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"luroom12",
        "east" : __DIR__"luroom16",
        "west" : __DIR__"luroom13",
]));
        setup();
}
