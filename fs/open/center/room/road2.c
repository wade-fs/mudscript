// Room: /u/p/powell/room/r2.c

inherit ROOM;

void create ()
{
  set ("short", "大馬路");
	set( "build", 12 );
  set ("long", @LONG
由中央驛站一路向西走來, 這附近正是靠近驛站的繁華地帶, 附近
商家雲集, 使你精神一振, 開始準備補充一切冒險所需, 這條路往北走
就是這附近唯一的藥店, 往南走則是間打鐵鋪。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/center/npc/sparrow" : 3,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/center/room/drug",
  "south" : "/open/center/room/iron",
  "west" : "/open/main/room/r26",
  "east" : "/open/trans/room/room4",
]));

  setup();
}
// by babe 防止 mob 進入                   
//int valid_leave( object me, string dir )   
//{                                          
//        if( dir=="east" && !userp(me) )    
//                return 0;                  
//                                           
//        return ::valid_leave( me, dir );   
//}                                          

