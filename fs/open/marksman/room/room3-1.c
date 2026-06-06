// Room: /open/marksman/room/room3-1
inherit ROOM;

void create ()
{
  set ("short", "客棧客房");
  set ("long", @LONG
這是一間普通的客房，裡面的裝設並不豪華，不過一樣也不缺，
可謂麻雀雖小，卻五臟具全呀。裡面擺著一張床，和一套木製的桌倚
客房的牆上擺滿了雕功一流的弓，椅子上正坐著一位白髮蒼桑的老人
。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/marksman/npc/old_man" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"room1-18",
]));

  setup();
}
