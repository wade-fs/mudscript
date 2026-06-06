// Room: /u/o/ookami/newarea/aa0.c 
inherit ROOM;
 
void create ()
{
  set ("short", "點蒼山腳");
  set ("long", @LONG
這裡是平南城附近的名山--點蒼山,四周碧草如茵,不時還能看到可
愛的小兔子在草叢中飛躍,往前方一看,雄偉的山峰就聳立在前方, 聽說
山中有一座著名的寺廟--天龍寺,是段家歷代高手出家為僧的名寺,令你
不禁想要一探究竟
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/ping/room/to_tai.c",
  "east" : __DIR__"aa1.c",
]));
  set("outdoors", "/u/o/ookami/newarea");

  setup();
  replace_program(ROOM);
}
