//七星陣
// by airke

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "森林");
	set("long", @LONG
這附近都是高聳入雲的樹木，偶而會有幾隻小鹿打從這兒走過。眺望
遠方似乎有座高塔矗立在那，上面覆滿了白色的積雪，已看不出原來建築
的色彩為何。前方有條道路，應該是通往高塔的。

LONG
	);
	
	set("exits", ([ /* sizeof() == 3 */
"north":__DIR__"g1.c",
        "pass" : __DIR__"c1",
]));
	set("outdoors", "1");

	setup();
}


