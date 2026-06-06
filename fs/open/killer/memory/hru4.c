#include <room.h>

inherit ROOM;

void create()
{
           set("short","紫霞組");
         set("long",@LONG
	
	紫霞組是負責守護通吃小築的安全，但是因為工會老大並不喜歡人家保護，
	所以與紅葉組與銀狼組一樣，只能守護在工會老大的附近。
	因此，紫霞組特地安排人鎮守通吃小築左翼。
 
LONG);
        set("exits", ([
    "east":__DIR__"hru1.c",
        ]) );
        set("objects",([
          "/open/killer/npc/magnpc2.c":2,]));
        setup();
}
