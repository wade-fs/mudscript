inherit ROOM;

void create()
{  
   
   set("short","草原");
   set ("long", @LONG
在你眼前的是一片綠波輕漾，微風帶來一陣陣的
青草香氣，原野間滿佈著不知名的小花，遠遠的才看
的到幾棵大樹，令人悠然的陶醉其中．                     
LONG);
   set("light_up", 1);
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 4 */
 "west" : "/open/island/room/i5",
   "south" : "/open/island/room/i4",
    "north" : "/open/island/room/i3",
  "east" : "/open/island/room/i13",
]));
   set("outdoors", "/open/main");

 setup();
}
