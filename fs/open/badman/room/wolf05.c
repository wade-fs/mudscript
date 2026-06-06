inherit ROOM;
void create()
{
  set ("short","狼谷");
  set ("long", @LONG
走到這裡 ,眼前便只是面山壁 ,而旁邊便只是幾塊突出的岩石罷了
 .雖然憑你的武功仍能走在上面 ,但掉到下面的山谷中可不是好玩的 ,
還是順著原路回去吧 .

LONG);

  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wolf02.c",
  ]));

  set("objects", ([ /* sizeof() == 2 */
  "/open/badman/npc/wolf.c" : 2,
]));
  setup();
}
