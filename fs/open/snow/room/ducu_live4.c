#include <room.h>

inherit ROOM;

void create()
{
	set("short","聽風軒");
	set("long",@LONG
這裡是獨孤居裡的聽風軒﹐在這裡西面有一扇大窗﹐獨孤愁生前亦時常
來此﹐吹吹晚風﹐欣賞夕陽西沉的景象。在此窗戶上掛著一串風鈴﹐每當微
風吹來﹐發出一陣陣咚咚的聲音﹐令人陶醉不已。
 
LONG);
        set("exits", ([
	"south":__DIR__"ducu_live3",
        ]) );
	set("light_up",1);
	set("objects",([
	"/open/snow/npc/dugur.c" : 1,
	]));
        setup();
}
