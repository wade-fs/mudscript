// Room: /d/snow/sroad2.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 雪亭鎮街道");
  set ("long", @LONG
這裡是雪亭鎮的街道﹐你的北邊有一家客棧﹐從這裡就可以聽到客
棧裡人們飲酒談笑的聲音﹐街道往東不遠處有個轉角往北﹐如果你往東
直走就是上山的小徑了﹐往西則可以走到車馬來往絡繹不絕的官道。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/snow/npc/farmer" : 2,
]));
  set("outdoors", "snow");
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"school",
  "west" : __DIR__"sroad3",
  "east" : __DIR__"sroad1",
]));

  setup();
}
