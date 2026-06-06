// Room: /open/death/watchtower
inherit ROOM;

void create()
{
  set ("short", "望鄉台");
  set ("long", @LONG
你現在站在第三殿宋帝王所轄的望鄉臺上，這裡是陰間唯一可看到
陽間的地方，此處佔滿了死後卻還懷念著陽間親人的鬼魂，臺上刻著『
登臺遙望舊家鄉』。
LONG);

  set("light_up", 1);
  set("outdoors", "/open/death");
  setup();
}
