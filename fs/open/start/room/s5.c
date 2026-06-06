// Room: /open/start/room/s5.c

inherit ROOM;

void create ()
{
  set ("short", "凌雲村");
	set( "build", 2215 );
  set ("long", @LONG
平靜安詳的村莊，兩旁見到的都是平凡的民舍，
沒有什麼特殊的建築，遠向南方望去是一片綠油油的
稻田，有幾個農夫正在辛勤的耕作。
你注意到新立了個路標 (sign) 。

LONG);
  set("item_desc", ([ /* sizeof() == 1 */
	"sign" : @ITEM
儒門由此往南二, 往西, 往南六, 往西, 往南
ITEM,
  ]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/start/npc/vendor" : 1,
]));
  set("outdoors", "/open/start");
  set("exits", ([ /* sizeof() == 4 */
  "west" : "/open/start/room/s4",
  "south" : "/open/start/room/s8",
  "north" : "/open/start/room/s9",
  "east" : "/open/start/room/s10",
]));

  setup();
}
