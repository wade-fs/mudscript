// Room: /open/main/room/L15.c

#include "/open/open.h"
inherit ROOM;

void create()
{
	set("short", "台地");
	set( "build", 24 );
	set("long", @LONG
    這是一塊微微高起的台地，稀稀疏疏的長起了幾叢雜草，
幾塊石塊雜亂分佈，更顯得這裡的荒涼.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r42",
  "west" : __DIR__"L14",
  "north" : __DIR__"s25",
  "east" : __DIR__"r39",
]) );

  set("outdoors", "/open/main" );

  setup();
}

void init()
{
  object me=this_player();

  if (!me->query("quests/help_water_god") &&
       me->query_temp("quests/help_water_god") >= 3)
    me->move(MAIN_ROOM"L15_q");
  else if (!me->query("quests/badman_license") &&
       me->query_temp("quests/badman_license") >= 3)
    me->move(MAIN_ROOM"L15_q");
}
