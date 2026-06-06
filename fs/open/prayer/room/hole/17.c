///open/prayer/room/hole/17.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	你慢慢撥開蜘蛛網來到這裡，眼前這也比剛剛空曠多了，空氣比較
	清新，周圍也比較乾淨，你心中竊竊自喜，但還是不能大意，以免
	橫屍荒野..

LONG	);
 
    set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/bird" : 1,		
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"3",
  "west":__DIR__"16",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
