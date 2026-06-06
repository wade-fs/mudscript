inherit ROOM;

void create()
{  
   
   set("short","農莊別院");
   set ("long", @LONG
你來到一個小農莊，這似乎是整座島上唯一的建
築物，屋內是極為清幽的擺設，住在這的老農夫
像是知道些什麼．
                     
LONG);
   set("light_up", 1);
set("objects", ([ /* sizeof() == 2 */
  "/open/start/npc/hen" : 2,
  "/open/island/npc/farmer" : 1,
]));
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 4 */
 
   "south" : "/open/island/room/i12",
    

]));
  

 setup();
}

