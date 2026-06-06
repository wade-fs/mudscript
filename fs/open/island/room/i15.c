inherit ROOM;

void create()
{  
   
   set("short","農田");
   set ("long", @LONG
金黃色的麥穗低低的垂下來，四週還有用木頭做
起來的小籬笆，還有稀疏的擺著幾個稻草人，真是幅
美麗的農莊景緻．                     
LONG);
   set("light_up", 1);
set("objects", ([ /* sizeof() == 2 */
  "/open/start/npc/sparrow" : 2,
  "/open/start/obj/bogle" : 1,
]));
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 4 */
 
   "west" : "/open/island/room/i3",
    "south" : "/open/island/room/i13",
  
]));
   set("outdoors", "/open/main");

 setup();
}
