// Room: /open/gsword/room/gsword3-8.c
inherit ROOM;

void create ()
{
  set ("short", "春秋閣");
	set( "build", 1 );
  set ("long", @LONG
春秋閣裡擺滿了桌椅 ,排列整齊 ,數十位新進的劍童正專心的朗頌詩書 ,
跟外面百人練劍的情景相比 ,似乎又是另一個世界 .西首有個小講臺 ,一張古
樸的書桌放置其上 ,應該就是老師授課所在 ,南邊一排陽台 ,架在峭壁之巔
弟子們於課餘之暇 ,往往喜歡倚著欄竿 ,觀賞遠方的蜀中城 .

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : "/open/gsword/room/g2-4.c",
]));

  set("objects", ([ /* sizeof() == 2 */
   "/daemon/class/swordsman/sauhu":1,
   "/open/gsword/npc/student":2,
]));

  set("light_up", 1);

  setup();
}
