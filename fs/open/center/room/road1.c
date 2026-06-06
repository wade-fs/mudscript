                              // Room: /u/p/powell/room/r1.c

inherit ROOM;

void create ()
{
  set ("short", "大馬路");
	set( "build", 821 );
  set ("long", @LONG
這是一條筆直的大馬路, 往北可以通到北邊神秘的沙漠王國,
南邊是中央驛站的大廣場, 東邊是一家駱馱行, 要往沙漠王國的商
旅可以在那兒買到你想要的上等貨色. 西邊則是一家妓院, 大概是
為了疏解旅途困頓而設的吧? 竟然常常客滿哩.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/main/room/r19",
  "west" : "/open/center/room/gstore",
  "south" : "/open/trans/room/room4",
  "east" : "/open/center/room/loto",
]));

  set("outdoors", "/open/main");

  setup();
}
// by babe 防止 mob 進入                   
//int valid_leave( object me, string dir )   
//{                                          
//        if( dir=="south" && !userp(me) )    
//                return 0;                  
//                                           
//        return ::valid_leave( me, dir );   
//}                                          


