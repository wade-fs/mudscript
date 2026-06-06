// Room: /open/gsword/room/g6-5.c
inherit ROOM;

void create ()
{
  set ("short", "懸崖邊");
  set ("long", @LONG
你來到思過崖的邊緣，這裡的山壁較為緩和，西邊一條羊腸小徑，直
通崖頂，雖頗為陡峭，但對你來說，似乎算不了什麼！
 
LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");

  set("exits", ([ /* sizeof() == 2 */
   "westup" : "/open/gsword/room/g6-6.c",
  "southwest" : "/open/gsword/room/g6-4",
]));

  setup();
}
