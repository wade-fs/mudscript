// Room: /open/gsword/room/testroom
inherit ROOM;

void create()
{
  set ("short", "空房間");
  set ("long", @LONG
這是一間什麼都沒有的房間。
LONG);

  set("outdoors", "/open/gsword");
  setup();
}
