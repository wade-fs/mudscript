///open/prayer/room/hole/6.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	走到此處，忽然驚覺四處邪氣陣陣，地上血跡未乾，顯然這裡有
	過一陣廝殺，強烈的殺氣讓你感到危機，看來還是小心為妙....
        在洞穴的一個角落有一位身受重傷的人在那裡，你是否要過去看
	看呢??

LONG	);
 
    set("objects", ([ /* sizeof() == 2 */
  "/open/prayer/npc/crab-ox" : 1,		
  "/open/prayer/npc/hurter" : 1,		

]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"8.c",
  "south":__DIR__"4.c",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}
