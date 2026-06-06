// Room: /open/bonze/npc//room/s13.c
inherit ROOM;

void create ()
{
  set ("short", "$HIY$戒律堂$NOR$");
  set ("long", @LONG

一踏進這裡你可以感覺周圍的氣氛與以往有所不同,堂中掛著一幅
金剛畫像,讓你不自覺神經繃緊起來,看來這裡就是少林寺中專門讓
犯錯弟子修行的地方-戒律堂

LONG);

  set("outdoors", "/open/bonze/npc//room");
  set("objects", ([ /* sizeof() == 1 */
  "/open/bonze/npc/konsen.c" : 1,
]));
  
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"s12.c",
]));

  setup();
}
