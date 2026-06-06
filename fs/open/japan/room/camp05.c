inherit ROOM;

void create()
{
  set ("short", "晒衣場");
  set ("long", @LONG
一堆洗乾淨的衣服，正飄蕩在晒衣場上。旁邊一口水井，看起來除了一般
供隊士洗衣服之外，好像也提供隊士日常生活所須。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"camp06.c",
    "west" : __DIR__"camp03.c",
  ]));
  setup();
}
