// Room: /u/o/ookami/newarea/aa1 
inherit ROOM;
 
void create ()
{
  set ("short", "點蒼山腳");
  set ("long", @LONG
這裡是平南城附近的名山--點蒼山,四周碧草如茵,不時還能看到可
愛的小兔子在草叢中飛躍,往前方一看,雄偉的山峰就聳立在前方, 聽說
山中有一座著名的寺廟--天龍寺,是段家歷代高手出家為僧的名寺,令你
不禁想要一探究竟,前方出現了一條小徑,似乎是往山上走去
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"aa2.c",
  "west" : __DIR__"aa0",
]));
  set("outdoors", "/u/o/ookami/newarea");

  setup();
  replace_program(ROOM);
}
