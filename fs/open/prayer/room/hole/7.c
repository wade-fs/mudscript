///open/prayer/room/hole/7.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	濃厚的血腥味撲鼻而來，但你不以為意，在這江湖上行走，早就
	過慣刀口上過活的日子，地上足跡非常明顯，巡著足跡不知會通
	往哪裡??越往裡走，那陰暗的感覺就越來越明顯!!地上都是黏稠
	的液體，讓人行走的越發困難!!

LONG	);
 
    set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/ditail-snake2" : 1,		//雙頭響尾蛇
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"17",
  "north":__DIR__"5",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
