inherit ROOM;

void create ()
{
  set ("short", "斜坡");
	set( "build", 12 );
  set ("long", @LONG
這裡是高原邊緣的斜坡，沿路景觀隨著高度的提升而改變，
濕暖平地的闊葉林越來越稀少，取而代之的是針葉林和草本類。
道路往東下坡和北上坡展開，分別通往華東地區和蒙古高原。
LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"entrance1",
  "northup" : __DIR__"entrance3",
]));

  setup();
}
