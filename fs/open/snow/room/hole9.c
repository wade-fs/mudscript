// Room: /open/snow/room/hole9.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG
這是一個平凡的洞穴, 從洞穴的峭壁上流下來清涼的
泉水, 似乎是雪蒼山的雪融化而流下來的, 由於水清澈無
比, 使你想嘗嘗它的美味。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hole6",
]));

  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

	setup();
}
