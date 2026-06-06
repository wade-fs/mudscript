#include <room.h>

inherit ROOM;

void create()
{
           set("short","工會老大所在處");
	set( "build", 12 );
         set("long",@LONG
	
	在你眼前的只是一些普通的擺設，普通的令你難以相信，
	這會是殺手工會老大的休息與辦公場所。
	這房間另外有通向另外四間房間，不知道是不是有機關存在。
 
LONG);
        set("exits", ([
           "south":__DIR__"hr7.c",
	"north":__DIR__"hru5.c",
    "west":__DIR__"hru4.c",
    "east":__DIR__"hru3.c",
        ]) );
        set("objects",([
          "/daemon/class/killer/black.c":1,]));
        setup();
}
