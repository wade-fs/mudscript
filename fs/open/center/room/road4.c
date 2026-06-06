  inherit ROOM;

void create ()
{
  seteuid(getuid());

  set ("short", "大馬路");
	set( "build", 66 );
  set ("long", @LONG
經過漫長的爬山涉水, 終於來到可以暫時停下來休息幾天的地方, 這裡
是從京城通往北方與西南方的戰略要點, 自前朝起就有這個中央驛站的存在,
據說當時是為連絡京城與邊界而建立, 至今仍能發揮其驛站的功能, 由這裏
往東走可回到京城, 北邊的商店老板聽說消息極為靈通, 南邊則是一家錢莊,
由於多次被洗劫, 在安全防護上已經是全國最佳。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/center/npc/dog" : 2,
]));
  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
  "west" : "/open/trans/room/room4",
  "north" : "/open/center/room/store",
  "south" : "/open/center/room/bank",
  "east" : "/open/main/room/r27",
]));

  setup();
}
// by babe 防止 mob 進入                   
//int valid_leave( object me, string dir )   
//{                                          
//        if( dir=="west" && !userp(me) )    
//                return 0;                  
//                                           
//        return ::valid_leave( me, dir );   
//}          
