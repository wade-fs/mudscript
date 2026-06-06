#include <room.h>

inherit ROOM;

void create()
{
           set("short","紫霞組組長辦公室");
         set("long",@LONG
	
	紫霞組是負責守護通吃小築的安全，但是因為工會老大並不喜歡人家保護，
	所以與紅葉組與銀狼組一樣，只能守護在工會老大的附近。
	因為尋常人根本進不了天靈老人的身邊，所以由紫霞組最強的組長楊小七鎮守。
	相傳楊小七是楊小邪的知心好友，兩人的友情並非尋常人可以得知。
 
LONG);
        set("exits", ([
	"south":__DIR__"hru1.c",
        ]) );
        set("objects",([
          "/open/killer/npc/hu_fa4.c":1
	,]));
        setup();
}
