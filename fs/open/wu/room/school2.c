// Room: /u/d/devils/school2.c

#include <room.h>
#include <ansi.h>




inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG
你走進正晴武館的練武場,進門處兩排長凳，分坐八名勁裝結束的漢子
，個個腰板筆挺顯出一股英悍之氣，令你心中不自覺得恐慌了起來...
此處往東直走便是正晴武館大廳，西邊是正晴武館大門(open door)
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "west" : (: look_door,     "west" :),
]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"school5",
  "north" : __DIR__"school3",
  "west" : __DIR__"school1",
  "east" : __DIR__"school7",
]));
        create_door("west", HIR + "鏤花紅檜大門" + NOR, "east", DOOR_CLOSED);

       set("outdoors", "/open/wu");
	setup();
}
