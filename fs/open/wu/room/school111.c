// Room: /u/d/devils/school11.c

inherit ROOM;

void create()
{
	set("short", "藏寶庫");
	set("long", @LONG
這是一間倉庫，堆滿了雜七雜八的物品，你放眼望去似乎沒有任何
稍有價值的東西，這裡的地板很乾淨，不像一般倉庫滿地灰塵，左邊角
落放著一個不起眼的箱子......
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "door" : "一個沒有把手的暗門，你可以推推看。
",
]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"school8",
]));

	setup();
}
