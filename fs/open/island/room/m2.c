inherit ROOM;

void create()
{  
   
   set("short","活火山");
   set ("long", @LONG
四週溫度漸漸高了起來，走沒幾分鐘便汗下
如雨，跟島上其它處的美景相較，這裡彷彿是地
獄一般．                    
LONG);
   set("light_up", 1);
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 4 */

 "east" : "/open/island/room/m5", 
   "north" : "/open/island/room/m1",
  "south" : "/open/island/room/m3",  

]));
  
  set("outdoors", "/open/main"); setup();
}

