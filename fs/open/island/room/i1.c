inherit ROOM;

void create()
{  
   
   set("short","神仙島上");
   set ("long", @LONG
在你眼前的是一望無際的沙灘，深藍色天空橫過
一道七彩的虹，四周的景色均是中原所難見到，地上
盡是奇花異草，在白色的瑩瑩沙粒中顯得格外的豔麗
芬芳，東邊是一片草原．                     
LONG);
   set("light_up", 1);
        set_heart_beat(1);
 set("exits", ([ /* sizeof() == 4 */

   "west" : "/open/island/room/island",
    "east" : "/open/island/room/i3",
  "south" : "/open/island/room/i5",
]));
   set("outdoors", "/open/main");

 setup();
}


