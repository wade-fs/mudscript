// Room: /u/s/sueplan/newplan/area/room11
inherit ROOM;

void create ()
{
  set ("short", "天梁星");
  set ("long", @LONG
    上述各星座的主人，都是在死後被太白金星以導上天界的。其中
只有一位在沒有死以前就上天任神的。他就是周軍的元帥李天王。李天王
經過百戰，還沒有戰死，但是因缺少天神，太白金星就把未死的李天王帶
回天界，請他留駐於天梁星。
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"room10.c",
  "north" : __DIR__"jroom.c",
]));

  setup();
}
