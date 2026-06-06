inherit ROOM;

void create()
{  
   
   set("short","望天崖");
   set ("long", @LONG
這裡是神仙島的最北端，由此地望去，只見海天
一色，碧藍的海上綴著點點粼光，偶爾有幾隻海鷗悠
然的從天上滑過，帶著鹹味的海風，自你的臉上輕拂
而過，令人心曠神怡．                     
LONG);
   set("light_up", 1);
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 4 */

   "southwest" : "/open/island/room/i1",
    "south" : "/open/island/room/i3",
  "southeast" : "/open/island/room/i15",
]));
   set("outdoors", "/open/main");

 setup();
}


