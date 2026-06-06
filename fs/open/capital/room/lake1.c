// Room: /open/capital/room/lake1
inherit ROOM;

void create ()
{
  set ("short", "湖邊小徑");
	set( "build", 24 );
  set ("long", @LONG
雜草叢生的小路，地面的石板縫裡都長滿了雜草。前面有一座涼亭
，依希看得到亭裡的人影。這離湖很近，看著平靜無波的湖面不禁有海
闊天空的感覺。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r24",
  "east" : __DIR__"lake2",
]));
  set("outdoors", "/open/capital");

  setup();
}
