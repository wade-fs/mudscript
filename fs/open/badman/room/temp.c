// Room: /open/badman/room/temp
inherit ROOM;

void create()
{
  set ("short", "暫存區");
  set ("long", @LONG
這裡用來放一些過渡的東東....
LONG);

  set("no_clean_up", 1);
  setup();
}
