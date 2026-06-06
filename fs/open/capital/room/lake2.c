// Room: /open/capital/room/lake2
inherit ROOM;

void create ()
{
  set ("short", "芙蓉湖畔");
	set( "build", 12 );
  set ("long", @LONG
更靠近湖了。有幾條小舟閒散得盪在湖心，非常愜意。這湖不大，
卻非常秀麗，像是世外桃源，和京城裡的吵雜喧鬧完全格格不入。你不
儘感謝大自然的鬼斧神工。北邊有座精巧的涼亭。

LONG);


  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lake1",
]));
  set("outdoors", "/open/capital");
  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
