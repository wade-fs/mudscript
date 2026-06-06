 // Room: /u/p/powell/room/r3.c

inherit ROOM;

void create ()
{
  set ("short", "大馬路");
	set( "build", 77 );
  set ("long", @LONG
這條大馬路可是貫穿驛站南北的青石板大道, 尤其威武鑣局就在附近, 
整條街更顯的熱鬧非凡, 車水馬龍, 過個街道可得小心一點, 別讓來往的馬
車給撞了, 由此往東走, 就是江湖上最有信譽的車馬行, 往西走就是威武鑣
局的總行。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"biau",
  "north" : "/open/trans/room/room4",
  "south" : "/open/main/room/r31",
  "east" : __DIR__"car",
]));
set("objects", ([ /* sizeof() == 1 */
      ]));
  set("outdoors", "/open/main");

  setup();
}
// by babe 防止 mob 進入                   
//int valid_leave( object me, string dir )
//{                                          
//        if( dir=="north" && !userp(me) )    
//                return 0;                  
//                                           
//        return ::valid_leave( me, dir );   
//}                        
