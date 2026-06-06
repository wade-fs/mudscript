// Room: /u/l/lotus/girl/w5.c
inherit ROOM;

void create ()
{
  set ("short", "曬衣場");
  set ("long", @LONG
兩株枝葉不茂盛的小樹, 樹旁曬衣架上曬了姑娘們的衣裳, 隨風
飄呀飄的.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"w6.c",
  "east" : __DIR__"w4",
]));
  set("outdoors", "/u/l");

  setup();
}
