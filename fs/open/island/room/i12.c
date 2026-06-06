inherit ROOM;

void create()
{  
   
   set("short","農田");
   set ("long", @LONG
金黃色的麥穗低低的垂下來，四週還有用木頭做
起來的小籬笆，還有稀疏的擺著幾個稻草人，真是幅
美麗的農莊景緻，北邊則有戶人家的炊煙冉冉升起．                     
LONG);
   set("light_up", 1);
set("objects", ([ /* sizeof() == 2 */
  "/open/start/npc/hen" : 2,
  "/open/start/obj/bogle" : 1,
]));
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 4 */
 "east" : "/open/island/room/m3",
   "west" : "/open/island/room/i9",
    "north" : "/open/island/room/i8",
  
]));
   set("outdoors", "/open/main");

 setup();
}

