// Room: /open/ping/room/west
inherit ROOM;

void create()
{
  set ("short", "懸空吊橋");
  set ("long", @LONG
你走上了一座吊橋,瀾滄江就在你的腳下,河面上一團團白霧
罩在滾滾江流之上,陽光照得江水金蛇亂舞,放眼不盡,令人胸懷
大暢.
LONG);

  set("outdoors", "/open/ping");
  setup();
}
